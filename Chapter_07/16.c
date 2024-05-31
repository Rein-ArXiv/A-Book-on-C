/* Chapter 7 exercise 16 */

/* 20세기의 날짜는 day/month/year 형태의 정수들로 표시할 수 있다. 예를 들어,
 * 1/7/33은 1933년 7월 1일을 나타낸다. day, month, year를 압축해서 저장하는 함
 * 수를 작성하여라. day는 31개, month는 12개, year는 100개의 다른 값을 가질 수
 * 있다. 따라서 day를 나타내기 위해서는 5비트면 되고, month는 4비트, year는 7비
 * 트면 된다. 이 함수는 day, month, year를 정수로 입력받아서 16비트 정수에 패킹
 * 하는 것이다. 언패킹을 수행하는 다른 함수도 작성해 보아라. 그리고 작성한 함수
 * 를 검사하는 프로그램도 작성하여라.
 */

#include <stdio.h>

// Day - 5 bit, Month - 4 bit, Year - 7 bit
unsigned int pack_date(int day, int month, int year){
    unsigned int packing = (day & 0x1F) | ((month & 0x0F) << 5) | ((year & 0x7F) << 9);
    return packing;
}

void unpack_date(unsigned int packed_date, int *day, int *month, int *year){
    *day = packed_date & 0x1F;
    *month = (packed_date >> 5) & 0x0F;
    *year = (packed_date >> 9) & 0x7F;
}

int main(void)
{
    int day, month, year;
    unsigned int packed_date;

    printf("Please enter the day, month, and year (e.g., 1 7 33 for July 1, 1933): ");
    scanf("%d %d %d", &day, &month, &year);
    
    packed_date = pack_date(day, month, year);

    printf("Packed date: %u\n", packed_date);

    int unpacked_day, unpacked_month, unpacked_year;
    unpack_date(packed_date, &unpacked_day, &unpacked_month, &unpacked_year);
    printf("Unpacked date: %d/%d/%d\n", unpacked_day, unpacked_month, unpacked_year + 1900);
    return 0;
}
