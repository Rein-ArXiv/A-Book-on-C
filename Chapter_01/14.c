/* Chapter 1 exercise 14 */

/* C 시스템이 제공하는 표준 헤더 파일들은 하나 이상의 디렉토리에 있을 수 있다.
 * 예를 들어, UNIX 시스템에서 헤더 파일들은 /usr/include에 있다.
 * Turbo C에서는 \turboc\include, \tc\include, 또는 \bc\include 디렉토리에 있다.
 * 여러분이 사용하는 시스템에서 표준 헤더 파일 stdio.h가 어디에 있는지 찾아보아라.
 * 그리고 이 파일에서 printf() 함수가 선언된 행을 찾아보아라. 그 행은 다음과 같을 것이다.

    int printf(const char *format, ...);

  
 * 이 행은 함수 원형의 예이다. 함수 원형은 함수에 전달될 인자의 개수와 형, 그리고 함수에 의해
 * 리턴될 값의 형을 컴파일러에게 알려준다. 앞으로 설명하겠지만, 문자열은 char 포인터이며
 * char *로 나타낸다. format은 단지 프로그래머가 쉽게 이해할 수 있도록 하는 것으로,
 * 컴파일러는 이것을 무시한다. 따라서 printf() 함수 원형은 다음과 같이 쓸 수도 있다.

    int printf(const char *, ...);

 * const 키워드는 printf() 함수의 이낮로 전달되는 문자열이 변경될 수 없음을 컴파일러에게
 * 알려준다. 생략부호 ...는 나머지 인자들의 개수와 형이 변할 수 있음을 알려준다.
 * printf() 함수는 전달된 문자의 개수를 int 형으로 리턴하고, 오류가 발생하면 음수 값을 리턴한다.
 * 이 장의 첫 번째 예제 프로그램인 sea.c에서 #include 문을 지우고 그 대신 위에 있는 printf() 함수
 * 원형을 써라. 이렇게 수정한 프로그램을 컴파일하고 실행시켜 보아라.
 * 
 * 주의: stdio.h 헤더 파일에 있는 printf() 함수를 그대로 갖다 쓸 수도 있으나
 * 그러면 프로그램이 실행되지 않을 수 있다. (전처리기에 대한 자세한 내용은 8장을 참조하여라.)
 */

int printf(const char *format, ...);

int main(void)
{
    printf("from sea to shining C\n");
    return 0;
}


/* OS: Windows 10 64bit
 * Compiler: MSYS2
 * location: C:\msys64\ucrt64\include\stdio.h
 * code

__mingw_ovr
__attribute__((__format__ (gnu_printf, 1, 2))) __MINGW_ATTRIB_NONNULL(1)
int printf (const char *__format, ...)
{
  int __retval;
  __builtin_va_list __local_argv; __builtin_va_start( __local_argv, __format );
  __retval = __mingw_vfprintf( stdout, __format, __local_argv );
  __builtin_va_end( __local_argv );
  return __retval;
}

*/