/* Chapter 5 exercise 27 */

/* 하노이 탑 프로그램을 수행해 보아라. n개의 원반이 A 탑에 있을 때, 이 문제를
 * 풀기 위해 몇 번의 이동이 필요한가? n이 64일 때, 매일 한 원반만 이동한다면,
 * 모든 원반을 C로 옮기기 위해 몇 년이 걸리겠는가? 만일 수도사가 1초에 원반 하
 * 나를 옮길 수 있다면, 세상이 끝나기 전에 모든 원반을 옮길 수 있을까?
 */

#include "hanoi.h"

int cnt = 0;

int main(void)
{
    int n;

    n = get_n_from_user();
    assert(n > 0);

    // Move n disks from tower A to tower C, using tower B as an intermediate tower.

    move (n, 'A', 'B', 'C');
    return 0;
}