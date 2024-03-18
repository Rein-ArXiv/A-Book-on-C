/* Chapter 2 exercise 9 */

/* 파운드와 온스를 킬로그램과 그램으로 변환하는 상호작용하는 프로그램을 작성하여라.
 * main() 함수 위에 정의되는 기호 상수를 이용하여라.
 */

#include <stdio.h>

#define POUND_TO_KILO 0.4536
#define OZ_TO_GRAM 28.35

int main(void)
{
	double pound, oz;
	double kilo, gram;

	printf("파운드와 온스를 입력하세요: ");
	scanf("%lf %lf", &pound, &oz);
	
	kilo = pound * POUND_TO_KILO;
	gram = oz * OZ_TO_GRAM; 

	printf("%lf 파운드는 %lf 킬로그램이고, %lf 온스는 %lf 그램입니다.\n", pound, kilo, oz, gram);
	return 0;
}