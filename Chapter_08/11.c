/* Chapter 8 exercise 11 */

/* 8.7절에서 매크로 isacii()는 ctype.h에 있다고 하였다. 그러나 이 매크로는
 * ANSI C 문서에는 명시되어 있지 않다. (아마도 ANSI C 위원회는 ASCII 코드를
 * 다른 것에 비해 선호한다는 것을 보이고 싶지 않았던 것 같다.) 각자의 시스템에
 * 서, isascii() 매크로가 제공되는지 알아보아라.
 */

#include <stdio.h>
#include <ctype.h>

int main(void)
{
    char str[100] = "Hello, World!";
    
    printf("Original string: %s\n", str);
    for(int i=0; str[i] != '\0'; i++){
        if (isascii(str[i])){
            printf("%c is ascii.\n", str[i]);
        }
        else{
            printf("%c is non-ascii.\n", str[i]);
        }
    }
    return 0;
}