#include<stdio.h>
int main (){
    int x,y,z;
    int max,mid ,min;
    scanf("%d %d %d", &x, &y, &z);

    if (x<y && x<z)
    {
         min =x;
    }
    else if (y<z && y<x)
    {
         min=y;
    }
    else
   {  min=z;}

    if (x >= y && x >= z) max = x;
    else if (y >= x && y >= z) max = y;
    else max = z;

mid = x + y + z - min - max;

  printf("%d\n%d\n%d\n\n", min, mid, max);

    printf("%d\n%d\n%d\n", x, y, z);

    
}