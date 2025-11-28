#include<stdio.h>
int main (){
    int m,n;
scanf("%d %d", &m, &n);
int x[m][n];
int y[m][n];
int sub[m][n];
 
    printf("First matrix: \n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d",&x[i][j]);
        }
        
    }
    
    printf("\nsecond matrix: \n");
        for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d",&y[i][j]);
        }
        
    }
    printf("\nThe subtraction of two matrix is: \n");
    
        for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            sub[i][j]=y[i][j]-x[i][j];
            printf("%d",sub[i][j]);
        }
        printf("\n");
    }
    
}