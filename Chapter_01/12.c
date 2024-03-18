/* Chapter 1 exercise 12 */

/* 각 정수에 대한 거듭제곱을 다음 표와 같이 출력하는 프로그램을 작성하여라.

    :::::: A TABLE OF POWERS ::::::
    Integer    Square    3rd power    4th power    5th power
    -------    ------    ---------    ---------    ---------
         1          1            1            1            1
         2          4            8           16           32        
         3          9           27           81          243
 
 */

#include <stdio.h>

int main(void)
{
    printf("\n:::::: A TABLE OF POWERS ::::::\n");
    printf("Integer    Square    3rd power    4th power    5th power\n");
    printf("-------    ------    ---------    ---------    ---------\n");
    
    for (int i=1; i<=3; ++i)
        printf("%7d    %6d    %9d    %9d    %9d\n", i, i*i, i*i*i, i*i*i*i, i*i*i*i*i);
    return 0;
}