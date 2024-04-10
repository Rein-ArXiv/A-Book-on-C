/* Chapter 4 exercise 5 */

/* 다음 루프를 포함하는 프로그램을 작성하여라.

    while (scanf("%lf", &salary) == 1) {
        ......
    }

 * 루프의 몸체 부분에서 17%의 기본 원천 세금과 3%의 지방 세금을 계산한 후, 봉
 * 급과 함께 출력하여라. 그리고 출력되는 모든 봉급과 세금을 합하여, 프로그램에
 * 서 while 루프를 빠져 나올 때 그 합들을 출력하여라.
 */

#include <stdio.h>

int main(void)
{
	double salary;
    double baseTax, localTax;
    double totalSalary = 0.0f, totalBaseTax = 0.0f, totalLocalTax = 0.0f;

    while (scanf("%lf", &salary) == 1){
        baseTax = 0.17 * salary;
        localTax = 0.03 * salary;
        printf("Salary: %.2lf\nBase Tax: %.2lf\nLocal Tax: %.2lf\n", salary, baseTax, localTax);

        totalSalary += salary;
        totalBaseTax += baseTax;
        totalLocalTax += localTax;
    }

    printf("Total Salary: %.2lf\nTotal Base Tax: %.2lf\nTotal Local Tax: %.2lf\n", totalSalary, totalBaseTax, totalLocalTax);
    return 0;
}