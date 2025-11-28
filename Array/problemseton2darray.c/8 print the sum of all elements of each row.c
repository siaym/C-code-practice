#include<stdio.h>
int main (){
    int m,n;
    printf("enter row and colum ");
scanf("%d %d", &m, &n);
int x[m][n];
int sum = 0;
 
    printf("matrix: \n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d",&x[i][j]);
        }
        
    }
    
    printf("\nThe sum matrix is: \n");
    
        for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            sum=sum + x[i][j];
            
        }
        printf("%d\n",sum);
    }
    
}