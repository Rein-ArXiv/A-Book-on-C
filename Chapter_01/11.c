/* Chapter 1 exercise 11 */

/* name과 age를 받아들인 후 다음 문장을 출력하는 프로그램을 작성하여라.
    
    Hello <name>, next year you will be <next_age>.
 
 * 여기서 next_age는 age + 1이다.
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXSTRING 100

int main()
{
    char c, name[MAXSTRING];
    int i, age;

    printf("Input your name: ");
    for (i=0; (c = getchar()) != '\n'; ++i){
        name[i] = c;
    }
    name[i] = '\0';

    printf("Input your age: ");
    scanf("%d", &age);

    printf("Hello %s, next year you will be %d.\n", name, age+1);
    return 0;
}