/* Chapter 8 exercise 6 */

/* 각자의 시스템에서는 미리 정의된 모든 매크로를 이용할 수 있는가? 다음 코드를
 * 수행해 보아라.

    printf("%s%s\n%s%s\n%s%d\n%s%d\n%s%s\n",
        "__DATE__=", __DATE__,
        "__FILE__=", __FILE__,
        "__LINE__=", __LINE__,
        "__STDC__=", __STDC__,
        "__TIME__=", __TIME__);

 */

#include <stdio.h>

int main(void)
{
    printf("%s%s\n%s%s\n%s%d\n%s%d\n%s%s\n",
    "__DATE__=", __DATE__,
    "__FILE__=", __FILE__,
    "__LINE__=", __LINE__,
    "__STDC__=", __STDC__,
    "__TIME__=", __TIME__);
}
