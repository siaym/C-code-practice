#include <stdio.h>
#include <string.h>
#include <time.h>
#include "../include/rental.h"
#include "../include/fleet.h"
#include "../include/ui.h"
#include "../include/utils.h"

static Rental rentals[MAX_RENTALS];
static int rentalCount = 0;

void saveRentalsBinary() {
    FILE *fp = fopen("data/rentals.dat", "wb");
    if(fp) {
        fwrite(&rentalCount, sizeof(int), 1, fp);
        fwrite(rentals, sizeof(Rental), rentalCount, fp);
        fclose(fp);
    }
}

void loadRentalsBinary() {
    FILE *fp = fopen("data/rentals.dat", "rb");
    if(fp) {
        fread(&rentalCount, sizeof(int), 1, fp);
        fread(rentals, sizeof(Rental), rentalCount, fp);
        fclose(fp);
    }
}

void rentVehicle(const char* customerUsername) {
    char vID[20];
    printHeader("VEHICLE RENTAL CHECKOUT");
    displayVehicles();

    getchar();
    printf("\nEnter Vehicle ID you want to rent: ");
    scanf("%[^\n]s", vID);

    // Find vehicle in system
    extern Vehicle vehicles[MAX_VEHICLES];
    extern int vehicleCount;
    int vIndex = -1;

    for(int i=0; i<vehicleCount; i++) {
        if(strcmp(vehicles[i].id, vID) == 0) {
            vIndex = i;
            break;
        }
    }

    if(vIndex == -1 || vehicles[vIndex].available == 0) {
        printf(ANSI_COLOR_RED "\n[Error] Vehicle is either invalid or currently unavailable!\n" ANSI_COLOR_RESET);
        return;
    }

    strcpy(rentals[rentalCount].customerName, customerUsername);
    printf("Enter Phone Contact: ");
    scanf("%s", rentals[rentalCount].customerPhone);
    printf("Enter Rental Period (in days): ");
    scanf("%d", &rentals[rentalCount].expectedDays);

    strcpy(rentals[rentalCount].vehicleID, vID);
    rentals[rentalCount].rentStartTime = time(NULL);
    rentals[rentalCount].returned = 0;
    rentals[rentalCount].totalBill = rentals[rentalCount].expectedDays * vehicles[vIndex].rentPerDay;

    // Mark vehicle unavailable
    vehicles[vIndex].available = 0;
    rentalCount++;

    saveRentalsBinary();
    saveVehiclesBinary();
    logAuditAction("RENT_VEHICLE", vID);

    printf(ANSI_COLOR_GREEN "\n[Booking Confirmed] Total Estimated Bill: $%.2f\n" ANSI_COLOR_RESET, rentals[rentalCount-1].totalBill);
}

void returnVehicle() {
    char vID[20];
    getchar();
    printf("Enter Vehicle ID being returned: ");
    scanf("%[^\n]s", vID);

    int rIndex = -1;
    for(int i=0; i<rentalCount; i++) {
        if(strcmp(rentals[i].vehicleID, vID) == 0 && rentals[i].returned == 0) {
            rIndex = i;
            break;
        }
    }

    if(rIndex == -1) {
        printf(ANSI_COLOR_RED "No active running rental found for this Vehicle ID.\n" ANSI_COLOR_RESET);
        return;
    }

    rentals[rIndex].actualReturnTime = time(NULL);
    rentals[rIndex].returned = 1;

    // Time calculations using difftime
    double secondsElapsed = difftime(rentals[rIndex].actualReturnTime, rentals[rIndex].rentStartTime);
    double daysElapsed = secondsElapsed / (60 * 60 * 24);
    if(daysElapsed < 1.0) daysElapsed = 1.0; // Minimum 1-day billing block

    float finalBill = rentals[rIndex].totalBill;
    
    // Dynamic late return fee enforcement
    if(daysElapsed > rentals[rIndex].expectedDays) {
        double lateDays = daysElapsed - rentals[rIndex].expectedDays;
        float latePenalty = lateDays * 50.0; // $50 penalty flat per overdue day
        finalBill += latePenalty;
        printf(ANSI_COLOR_YELLOW "\n[Notice] Vehicle returned late by %.1f days! Late penalty added: $%.2f\n" ANSI_COLOR_RESET, lateDays, latePenalty);
    }

    // Restore vehicle availability in catalog
    extern Vehicle vehicles[MAX_VEHICLES];
    extern int vehicleCount;
    for(int i=0; i<vehicleCount; i++) {
        if(strcmp(vehicles[i].id, vID) == 0) {
            vehicles[i].available = 1;
            break;
        }
    }

    saveRentalsBinary();
    saveVehiclesBinary();
    logAuditAction("RETURN_VEHICLE", vID);

    printf(ANSI_COLOR_GREEN "\nVehicle Return Completed Successfully. Final Bill to Pay: $%.2f\n" ANSI_COLOR_RESET, finalBill);
}

void displayRentals() {
    if(rentalCount == 0) {
        printf("No rental transactions logged.\n");
        return;
    }
    printHeader("SYSTEM RENTAL TRANSACTIONS HISTORY");
    printf("%-15s | %-12s | %-10s | %-10s | %-10s\n", "Customer", "Vehicle ID", "Days", "Total ($)", "Status");
    printf("---------------------------------------------------------------\n");
    for(int i=0; i<rentalCount; i++) {
        printf("%-15s | %-12s | %-10d | $%-9.2f | %s\n",
            rentals[i].customerName,
            rentals[i].vehicleID,
            rentals[i].expectedDays,
            rentals[i].totalBill,
            rentals[i].returned ? "Returned" : ANSI_COLOR_YELLOW "Running" ANSI_COLOR_RESET);
    }
}