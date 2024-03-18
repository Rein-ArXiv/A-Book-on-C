/* Chapter 2 exercise 18 */

/* 컴파일러는 프로그램을 단지 문자의 스트림으로 보지만, 프로그램의 윤곽을 좋게하는
 * 것은 사람이 프로그램을 쉽게 읽을 수 있도록 하기 때문에 좋은 프로그래밍 기법이다.
 * 다음을 보자.
	
	int main(void
	) {float qx,
	zz,
	tt;printf("gimme 3"
	); scanf
	( "%f%f    %f", &qx, &zz
	,&tt);printf("averageis=%f",
	(qx+tt+zz)/3.0); return
	0
	;}

 * 이 코드는 읽기 어려워도, 컴파일되고 실행된다. 이 프로그램을 작성하고 수행하여
 * 잘 수행되는지를 확인해 보아라. 이제 공백과 주석을 사용하여 읽기 쉽고 문서화가
 * 잘된 프로그램으로 다시 작성해 보아라. 힌트: 헤더 파일을 포함시키고 qx, zz,
 * tt를 위한 새로운 식별자를 선택하여라.
 */

#include <stdio.h>

int main(void)
{
	float a, b, c;
	float average;

	printf("Input 3 floats: ");
	scanf("%f %f %f", &a, &b, &c);

	average = (a + b + c) / 3.0;

	printf("Average is %f\n", average);
	return 0;
}