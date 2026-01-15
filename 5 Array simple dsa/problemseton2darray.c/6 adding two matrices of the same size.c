#include<stdio.h>
int main (){
int m,n;
int i,j;
scanf("%d %d",&m,&n);
int x[m][n];
int y[m][n];
int sum[m][n];

printf("Input ejements in the first matrix\n");
for ( i = 0; i < m; i++)
{ 
    for ( j = 0; j < n; j++)
    {
        printf("ejement-[%d][%d] : ",i,j);
        scanf("%d",&x[i][j]);
    }
    
}
printf("Input ejements in the second matrix\n");
for ( i = 0; i < m; i++)
{
    for ( j = 0; j < n; j++)
    {
        printf("ejement-[%d][%d] : ",i,j);
        scanf("%d",&y[i][j]);
    }
    
}
printf("The First matrix is : \n");
for ( i = 0; i < m; i++)
{ 
    for ( j = 0; j < n; j++)
    {
        printf(" %d",x[i][j]);
    }
    printf("\n");
}
 printf("The Second matrix is : \n");
    
for ( i = 0; i < m; i++)
{
    for ( j = 0; j < n; j++)
    {
        printf(" %d",y[i][j]);
    
    }
    printf("\n");
}
 printf("\nThe Addition of two matrix is :\n");
for ( i = 0; i < m; i++)
{
    for ( j = 0; j < n; j++)
    {
        sum[i][j]=x[i][j]+y[i][j];
        printf("%d ", sum[i][j]);
    
    }
    printf("\n");
}
return 0;

}