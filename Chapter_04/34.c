/* Chapter 4 exercise 34 */

/* 다음 두 문장 중 옳은 것은 어느 것인가? switch 문의 구문을 살펴보고 먼저 답
 * 을 작성한 다음, 프로그램을 작성하여 검사해 보아라.

    switch (1);             // version 1
    switch (1)  switch(1);  // version 2

 */

#include <stdio.h>

int main(void)
{
    switch (1);             // ok
    switch (1)  switch(1);  // not ok

    return 0;
}