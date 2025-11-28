#include<stdio.h>
int main (){
int m,n;
int i,j;
scanf("%d %d",&m,&n);
int x[m][n];

for ( i = 0; i < m; i++)
{ 
    for ( j = 0; j < n; j++)
    {
        scanf("%d",&x[i][j]);
    }
    
}
for ( i = 0; i < m; i++)
{ 
    for ( j = 0; j < n; j++)
    {
       printf(" %d",x[i][j]);
    }
     printf("\n");
}

return 0;

}