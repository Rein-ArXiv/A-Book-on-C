/* Chapter 2 exercise 30 */

/* 컴파일러를 호출하면, 시스템은 먼저 전처리기를 호출한다. 이 연습문제에서는 어떤 일이 일어나는지
 * 알아보기 위해 일부러 전처리 오류가 발생하도록 하였다. 다음 프로그램을 실행하여 보아라.

	#incl <stdixx.h> // two errors on this line

	int main(void)
	{
		printf("Try me.\n");
		return 0;
	}

 * 만일 #incl를 #include로 수정하면 어떻게 되겠는가?
 */

#incl <stdixx.h> // two errors on this line

int main(void)
{
	printf("Try me.\n");
	return 0;
}