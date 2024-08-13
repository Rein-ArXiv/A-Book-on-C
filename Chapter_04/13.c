/* Chapter 4 exercise 13 */

/* n으로 정수 값을 하나 읽어 들여서, n이 양수이면 n에서 2 * n까지의 정수의 합
 * 을 구하고, n이 음수이면 2 * n에서 n까지의 정수의 합을 구하려고 한다. 이것을
 * 수행하는 2개의 프로그램을 작성하여라. 단, 한 프로그램은 for 루프를 사용하고,
 * 다른 하나는 while 루프를 사용하도록 하여라.
 */

#include <stdio.h>

int main(void)
{
    int n, i;
    int sum = 0;

    scanf("%d", &n);

    if (n >= 0){
        for(i = n; i <= 2*n; i++){
            sum += i;
        }
    }

    else{
        for (i = n; i >= 2*n; i--){
            sum += i;
        }
    }

    printf("For loop program Sum: %d\n", sum);

    sum = 0;

    if (n >= 0){
        i = n;
        while (i <= 2*n){
            sum += i;
            ++i;
        }
    }

    else{
        i = n;
        while (i >= 2*n){
            sum += i;
            --i;
        }
    }

    printf("While loop program Sum: %d\n", sum);
    return 0;
}
