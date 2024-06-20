/* Chapter 8 exercise 16 */

/* NDEBUG가 정의되어 있으면, 매크로 assert()는 무시된다. 각자의 시스템은 과연
 * 기대한 것처럼 작동하는가? 다음 프로그램을 시험해 보아라.

    #define NDEBUG

    #include <assert.h>

    int main(void)
    {
        int a = 1, b = 2;
        
        assert(a > b);
        return 0;
    }

 */

#define NDEBUG

#include <assert.h>

int main(void)
{
    int a = 1, b = 2;
    
    assert(a > b);
    return 0;
}