#include<stdio.h>
int main(){
    int dd,mm,yy;
    scanf("%d/%d/%d", &dd, &mm, &yy);//in scanf when we enter slash it expect slash in the input
    printf("%02d/%02d/%02d\n",mm,dd,yy);//%02d forces 2 digits with leading zeros. 
    printf("%02d/%02d/%02d\n",yy,mm,dd);
    printf("%02d-%02d-%02d\n",dd,mm,yy);
    return 0;
    
}