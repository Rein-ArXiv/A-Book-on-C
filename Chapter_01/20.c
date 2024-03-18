/* Chapter 1 exercise 20 */

/* ANSI C에서 printf() 함수는 출력한 문자의 개수를 int 형으로 리턴한다.
 * 이것이 어떻게 동작되는지를 알아보기 위해 다음 코드를 포함하는 프로그램을
 * 작성하여라.
 
    int cnt;

    cnt = printf("abc abc");
    printf("\nNo. of characters printed : %d\n", cnt);

 * 이 프로그램의 결과는 무엇인가? 만일 첫 번째 printf()의 제어 문자열을
 * "abc\nabc \n" 또는 "\abc\0abc\0"으로 수정한다면 무엇이 출력되겠는가?
 */

#include <stdio.h>

int main(void)
{
    int cnt;

    cnt = printf("abc abc");          // cnt = 7
    //cnt = printf("abc\nabc \n");    // cnt = 9
    //cnt = printf("abc\0abc\0");     // cnt = 3
    
    printf("\nNo. of characters printed : %d\n", cnt);
    return 0;
}