/* Chapter 7 exercise 14 */

/* 이전 달을 리턴하는 previous_month() 함수를 작성하여라. 이 함수는 다음과 같
 * 이 시작해야 한다.

    enum month {jan, feb, ..., dec};
    typedef enum month month;
 
 * jan이 함수의 인자로 전달되면, dec이 리턴되어야 한다. 또한, 달의 이름을 출력
 * 하는 함수도 작성하여라. 좀더 명확하게 말하자면, 열거자 jan이 인자로서 전달되
 * 면, January가 출력되어야 한다. 이러한 함수들을 호출하여 12 달의 표를 생성하
 * 고, 각 달의 이름 옆에 이전 달도 출력하는 main() 함수를 작성하여라. 주의:
 * printf() 함수를 사용하여 열거형 변수를 출력하면, 그 변수가 가진 열거자의 이
 * 름이 출력되는 것이 아니라 그와 대응되는 정수 값을 출력한다. 즉, 다음의 출력
 * 값은 jan이 아니라 0이다.
 
    printf("%d\n", jan);

 */

#include <stdio.h>

enum month {jan, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec};
typedef enum month month;

month previous_month(month m) {
    return (m == jan) ? dec : m - 1;
}

void print_month_name(month m) {
    const char* month_names[] = {"January", "February", "March", "April", "May", "June",
                                 "July", "August", "September", "October", "November", "December"};
    printf("%s", month_names[m]);
}

int main(void) {
    month m = jan;
    for (int i = 0; i < 12; i++) {
        month prev = previous_month(m);
        print_month_name(m);
        printf(" (Previous: ");
        print_month_name(prev);
        printf(")\n");
        m = (month)((m + 1) % 12);
    }
    return 0;
}
