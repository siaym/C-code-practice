#include<stdio.h>
int main (){
int m,n;
int i,j;
scanf("%d %d",&m,&n);
int x[m][n],sum=0;

for ( i = 0; i < m; i++)
{ 
    for ( j = 0; j < n; j++)
    {
        scanf("%d",&x[i][j]);
        sum=sum+x[i][j];
    }
    
}
printf("sum=%d",sum);

return 0;

}