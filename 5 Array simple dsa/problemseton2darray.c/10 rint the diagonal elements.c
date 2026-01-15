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
      printf("Diagonal Elements:\n");
    for (int i = 0; i < n; i++)
        {
            printf("%d ",x[i][i]);
        }
        


}
