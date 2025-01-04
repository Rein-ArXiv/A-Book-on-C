/* Chapter 10 exercise 37 */

/* weight 필드를 일반트리 구조체에 추가하여라. 그리고 다음을 수행하는 함수를
 * 작성하여라.

    1. 모든 노드의 weight 합을 계산한다.
    2. 최대 가중 경로를 계산한다. 여기서 노드 i로의 가중 경로는 루트 노드에서
       i 노드까지의 모든 노드에 대한 weight 합이다.

 * weight 값이 모두 양수라면, 최대 가중 경로는 루트에서 리프 노드까지의 가중
 * 경로 중 하나가 된다.
 */

#include <stdio.h>
#include <stdlib.h>

typedef int DATA;
typedef int WEIGHT;

struct general_node
{
   DATA d;
   WEIGHT w;
   struct general_node *child;
   struct general_node *sibling;
};

typedef struct general_node GNODE;
typedef GNODE *GTREE;

GTREE create_gnode(DATA d, WEIGHT w)
{
   GTREE new_node = (GTREE) malloc(sizeof(GNODE));

   if (new_node == NULL)
   {
      printf("Memory allocation failed.\n");
      return NULL;
   }
}
