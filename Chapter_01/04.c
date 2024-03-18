/* Chapter 1 exercise 4 */

/* marathon 프로그램의 다음 문장에서 void를 삭제하여라
  
    int main(void)
 
 * 이 수정된 프로그램을 컴파일하여라. 컴파일할 때 경고 메시지가 발생하는가?
 * 아마 그렇지 않을 것이다. (자세한 내용은 5.3절 "함수 원형"을 참조하여라.)
 * 그 다음 main() 함수의 몸체에서 다음 문장을 삭제하여라
 
    return 0;
 
 * 이 수정된 프로그램을 컴파일해 보고 컴파일 중에 경고 메시지가 발생하는지 확인하여라.
 * 아마 경고 메시지가 발생할 것이다. 만일 경고 메시지가 나오지 않았다면,
 * 컴파일러의 경고 단계를 한 단계 높게 설정한 후 다시 컴파일해 보아라. 일반이 좋다.
 * 프로그래밍의 원칙 중 하나는 "컴파일러가 경고 메시지를 발생하지 않게 하여라"이다.
 * 따라서 프로그래머는 모든 경고들이 제거될 때까지 계속해서 코드를 수정하고 보완해야 한다.
 */

#include <stdio.h>

int main()
{
    int miles, yards;
    float kilometers;
    
    miles = 26;
    yards = 385;
    kilometers = 1.609 * (miles + yards / 1760.0);
    printf("\nA marthon is %f kilometers. \n\n", kilometers);
}

/* No warning*/