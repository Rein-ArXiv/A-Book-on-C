/* Chapter 1 exercise 24 */

/* a가 임의의 형의 배열이고 i는 int 형이라고 하자. 이때 a[i]를 이와 같은 의미를
 * 갖는 포인터 수식으로 표현할 수도 있다. 그 포인터 수식을 써라.
 */

#include <stdio.h>
#include <ctype.h>

#define MAXSTRING 100

int main(void)
{
    char *p, c, a[MAXSTRING];
    int length, i;

    printf("Input : ");

    for(i=0; (c = getchar()) != '\n'; ++i){
        a[i] = c;
    }
    a[i] = '\0';
    length = i;

    printf("i (input length = %d):", i-1);
    
    scanf("%d", &i);
    
    if (i > MAXSTRING || i > length){
        printf("You put bigger i. Exit.\n");
    }
    
    p = a;
    printf("Your input: %s\n", a);
    printf("i-th character by a[%d] : %c\n", i, a[i]);
    printf("i-th character by *(p + %d) : %c\n", i, *(p+i));
    return 0;
}