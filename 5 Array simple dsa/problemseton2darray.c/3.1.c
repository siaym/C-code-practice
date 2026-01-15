#include<stdio.h>
int main (){
    int m,n;
    scanf("%d %d", &m, &n);
    int x[m][n];

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j <n; j++)
        {
            scanf("%d",&x[i][j]);
        }
        
    }

        for (int i = 0; i < m; i++)
    {
        for (int j = 0; j <n; j++)
        {
            printf(" x[%d][%d]=%d\n ",i,j,x[i][j]);
        }
        
        
    }
    
}