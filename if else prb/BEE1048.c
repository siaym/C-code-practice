#include<stdio.h>
int main (){
    double salary, increase,newsalary;
    int percent;
    scanf("%lf", &salary);

    if (salary<=400)
    {
        percent =15;
    }
    else if(salary<=800){
        percent=12;
    }
    else if (salary <= 1200.00) {
        percent = 10;
    } 
    else if (salary <= 2000.00) {
        percent = 7;
    } else {
        percent = 4;
    }

     increase = salary * percent / 100.0;
    newsalary = salary + increase;
     printf("Novo salario: %.2lf\n", newsalary);
    printf("Reajuste ganho: %.2lf\n", increase);
    printf("Em percentual: %d %%\n", percent);

    return 0;

}