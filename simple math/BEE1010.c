#include<stdio.h>
int main (){
    int p1,nup1,p2,nup2;
    float pp1,pp2,price;

    scanf("%d %d %f",&p1, &nup1 ,&pp1);
        scanf("%d %d %f",&p2, &nup2 ,&pp2);
        price=(nup1*pp1)+(nup2*pp2);

    printf("VALOR A PAGAR: R$ %.2f",price);


}