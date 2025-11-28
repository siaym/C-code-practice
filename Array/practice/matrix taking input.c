#include<stdio.h>
int main (){

int a[3][4];
int i,j;

for (int i = 0; i < 3; i++)
{
    for ( j = 0; j < 4; j++)
    {
        printf("A[%d][%d] = ",i,j);
        scanf("%d",&a[i][j]);
    }
    printf("\n");
    
}
for (int i = 0; i < 3; i++)
{
    for ( j = 0; j < 4; j++)
    {
        printf("%d",a[i][j]);
    
    }
        printf("\n");
}

}