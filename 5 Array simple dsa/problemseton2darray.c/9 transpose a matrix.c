#include<stdio.h>
int main (){
    int m,n;
    printf("enter row and colum ");
scanf("%d %d", &m, &n);

int x[m][n];
int t[m][n];
 
    printf("matrix: \n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d",&x[i][j]);
        }
        
    }
    // //creating trans
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         t[i][j]=x[j][i];
    //     }
        
    // }
    printf("Transpose Matrix is:\n");
     for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d ",x[j][i]); // swap i and j
        }
        printf("\n");
    }

}