/* Chapter 7 exercise 17 */

/* 연습 문제 16번에서 언급한 패킹된 날짜를 입력받아서 패킹된 다음 날을 리턴하
 * 는 함수를 작성하여라. 그리고 연습 문제 15번에서 작성한 프로그램과 비교해 보
 * 아라.
 */
#include <stdio.h>

const int days_in_month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

unsigned int pack_date(int day, int month, int year) {
    return (day & 0x1F) | ((month & 0x0F) << 5) | ((year & 0x7F) << 9);
}

unsigned int next_pack_date(unsigned int packed_date) {
    int day = packed_date & 0x1F;
    int month = (packed_date >> 5) & 0x0F;
    int year = (packed_date >> 9) & 0x7F;

    day++;

    if ((year % 4 == 0) && (month == 2) && (day == 29)){
        ;
    }

    else if (day > days_in_month[month]) {
        day = 1;
        month++;
        if (month > 12) {
            month = 1;
            year++;
            if (year > 99) year = 0;
        }
    }
    
    return pack_date(day, month, year);
}

void unpack_date(unsigned int packed_date, int *day, int *month, int *year){
    *day = packed_date & 0x1F;
    *month = (packed_date >> 5) & 0x0F;
    *year = (packed_date >> 9) & 0x7F;
}

int main(void) {
    int day, month, year;
    printf("Please enter the day, month, and year (e.g., 1 7 33 for July 1, 1933): ");
    scanf("%d %d %d", &day, &month, &year);

    unsigned int packed_date = pack_date(day, month, year);
    printf("Packed date: %u\n", packed_date);

    unsigned int next_packed_date = next_pack_date(packed_date);
    printf("Next packed date: %u\n", next_packed_date);

    unsigned int next_day, next_month, next_year;
    unpack_date(next_packed_date, &next_day, &next_month, &next_year);
    printf("Next date: %d %d %d\n", next_day, next_month, next_year + 1900);

    return 0;
}
