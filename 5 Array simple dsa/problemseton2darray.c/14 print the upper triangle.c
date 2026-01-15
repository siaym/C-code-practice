#include<stdio.h>
int main (){
    int m,n;
    printf("enter row and colum ");
scanf("%d %d", &m, &n);

int x[m][n];
 
    printf(" input matrix: \n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d",&x[i][j]);
        }
        
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j>=i)
            {
                printf("%d",x[i][j]);
            }else
            printf("0");
            
        }
        printf("\n");
    }
    return 0;
}