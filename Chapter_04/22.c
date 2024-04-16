/* Chapter 4 exercise 22 */

/* st1, st2, st3의 세 문장이 있다고 가정하자. if-else 문을 사용하여, int 변수 i
 * 의 값을 검사하고, 그에 따라 각기 다른 조합의 문장을 실행하도록 하려고 한다.
 * 다음 표는 세 가지 조합을 보여주고 있다.
 
    i   수행     |   i   수행     |   i   수행
    1   st1      |   1   st2      |   1   st1, st2
    2   st2      |   2   st1, st3 |   2   st1, st2
    3   st3      |   3   st1      |   3   st2, st3

 * 이 표와 같이 수행하는 3개의 프로그램을 작성하여라. 사용자가 i 값을 입력할 수
 * 있도록 프로그램을 작성하고, 제어의 흐름이 표에서 기술된 동작과 일치하는지 조
 * 사할 수 있도록 적절한 printf() 문을 사용하여라. 즉, 다음과 같은 문장을 사용
 * 할 수 있을 것이다.

    if (i == 1)
        printf("statement_1 executed\n");

 */

#include <stdio.h>

void st1();
void st2();
void st3();

int main(void)
{
    int i;

    printf("Input i: ");
    scanf("%d", &i);

    // First Program
    printf("First Program\n");
    if (i == 1)
        st1();
    else{
        if (i == 2){
            st2();
        }
        else{
            st3();
        }
    }
    printf("First Program End\n\n");
     
    // Second Program
    printf("Second Program\n");
    if (i == 1){
        st2();
    }
    else{
        st1();

        if (i == 2){
            st3();
        }
    }
    printf("Second Program End\n\n");

    // Third Program
    printf("Third Program\n");
    
    st2();
    if (i == 3){
        st3();
    }
    else{
        st1();
    }
    printf("Third Program End\n\n");

    return 0;
}

void st1(){
    printf("statement_1 executed\n");
}

void st2(){
    printf("statement_2 executed\n");
}

void st3(){
    printf("statement_3 executed\n");
}