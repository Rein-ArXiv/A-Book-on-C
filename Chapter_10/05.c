/* Chapter 10 exercise 5 */

/* concatenate(a, a)로 만들어지는 리스트를 그려보아라. 이때, a는 두 개의 원소
 * 를 갖는 리스트를 포인트한다고 가정한다. 만일 a가 포인트하고 있는 결과 리스트
 * 가 print_list(a)에 전달된다면 어떤 일이 발생하는가?
 */

#include <stdio.h>
#include <string.h>

typedef struct DATA{

} DATA;

typedef struct linked_list{
    DATA *d;
    struct linked_list* next;
} ELEMENT;

typedef ELEMENT *LINK;