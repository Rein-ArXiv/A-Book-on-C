/* Chapter 4 exercise 33 */

/* 수학 연산 min(x, y)는 다음과 같은 조건부 수식으로 표현할 수 있다.

    (x < y) ? x : y

 * 유사한 방법으로 조건부 수식만을 사용하여 다음 수학 연산을 기술해 보아라.

    min(x, y, z)
    max(x, y, z, w)

 */

#include <stdio.h>
int min(int x, int y, int z);
int max(int x, int y, int z, int w);

int main(void)
{
    int x, y, z, w;
    int min_val, max_val;
    scanf("%d%d%d%d", &x, &y, &z, &w);
    printf("Min value in (x, y, z): %d\n", min(x, y, z));
    printf("Max value in (x, y, z, w): %d\n", max(x, y, z, w));

    return 0;
}

int min(int x, int y, int z)
{
    int min_value;
    min_value = x < y ? ((x < z) ? x : z) : ((y < z) ? y : z);

    return min_value;
}

int max(int x, int y, int z, int w)
{
    int max_value;
    max_value = (x > y) ? ((x > z) ? ((x > w) ? x : w) : ((z > w) ? z : w)) : ((y > z) ? ((y > w) ? y : w) : ((z > w) ? z : w));
    return max_value;
}