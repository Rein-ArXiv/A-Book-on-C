/* Chpater 7 exercise 15 */

/* 특정한 년의 다음날을 출력하는 프로그램을 작성하여라. 프로그램은 두 정수, 예
 * 를 들어 17 May를 나타내는 17과 5를 입력으로 받아들여, 다음날인 18 May를 출
 * 력해야 한다. 프로그램에서 열거형을 사용하고, 다음날이 다른 달로 넘어갈 때 특
 * 히 주의하여라.
 */

#include <stdio.h>

enum month {January = 1, Feburary, March, April, May, June, July, August, September, October, November, December};
typedef enum month month;

month next_month(month m) {
    return (m == December) ? January : m + 1;
}

void print_month_name(month m) {
    const char* month_names[] = {"January", "February", "March", "April", "May", "June",
                                 "July", "August", "September", "October", "November", "December"};
    printf("%s\n", month_names[m-1]);
}

int main(void)
{
    int year, mon, day;
    printf("Input day and month: ");
    scanf("%d %d", &day, &mon);

    month current_month = (month) mon;

    const int days_month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if(day == days_month[current_month]){
        current_month = next_month(current_month);
        day = 1;
    }

    else{
        day++;
    }

    printf("Next day is %d ", day);
    print_month_name(current_month);
    return 0;
}
