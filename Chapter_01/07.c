/* Chapter 1 exercise 7 */

/* 일반적으로 프로그램에서 모든 #include 행들은 파일의 시작 부분에 온다.
 * 그러나 반드시 시작 부분에 위치해야만 하는가? 1.4절의 pacific_sea 프로그램에서
 * #include 행을 다음과 같이 main()의 몸체에 오도록 수정해 보아라.
 *
 	int main(void)
 	{
		#include "pacific_sea.h"
		....

 * 이 수정된 프로그램을 수행시켜 보아라.
 */

/* In file pacific_sea.c      */
/* Measuring the Pacific Sea. */

int main(void)
{
	#include "pacific_sea.h"

	const int pacific_sea = AREA;	/* in sq kilometers */
	double acres, sq_miles, sq_feet, sq_inches;

	printf("\nThe Pacific Sea covers an area");
	printf(" of %d square kilometers.\n", pacific_sea);
	sq_miles = SQ_MILES_PER_SQ_KILOMETER * pacific_sea;
	sq_feet = SQ_FEET_PER_SQ_MILE * sq_miles;
	sq_inches = SQ_INCHES_PER_SQ_FOOT * sq_feet;
	acres = ACRES_PER_SQ_MILE * sq_miles;
	printf("In other units of measure this is:\n\n");
	printf("%22.7e acres\n", acres);
	printf("%22.7e square miles\n", sq_miles);
	printf("%22.7e square feet\n", sq_feet);
	printf("%22.7e square inches\n", sq_inches);
	return 0;
}