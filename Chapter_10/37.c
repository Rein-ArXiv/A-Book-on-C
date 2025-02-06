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

   new_node -> d = d;
   new_node -> w = w;

   new_node -> child = NULL;
   new_node -> sibling = NULL;
}

int calculate_total_weight(GTREE root)
{
   if (root == NULL)
   {
      return 0;
   }

   int total_weight = root -> w;

   total_weight += calculate_total_weight(root -> child);
   total_weight += calculate_total_weight(root -> sibling);

   return total_weight;
}

int calculate_max_weighted_path(GTREE root, int current_sum)
{
   if (root == NULL)
   {
      return current_sum;
   }

   current_sum += root -> w;

   int max_child_path = current_sum;

   if (root -> child != NULL)
   {
      max_child_path = calculate_max_weighted_path(root -> child, current_sum);
   }

   int max_sibling_path = current_sum - root -> w;
   if (root -> sibling != NULL)
   {
      max_sibling_path = calculate_max_weighted_path(root -> sibling, current_sum - root -> w);
   }

   return (max_child_path > max_sibling_path) ? max_child_path : max_sibling_path;
}

int max_weighted_path(GTREE root)
{
   if (root == NULL)
   {
      return 0;
   }
   return calculate_max_weighted_path(root, 0);
}

int main() {
   GTREE root = create_gnode(1, 10);
   root->child = create_gnode(2, 20);
   root->child->sibling = create_gnode(3, 15);
   root->child->child = create_gnode(4, 25);
   root->child->child->sibling = create_gnode(5, 30);

   printf("Total weight of all nodes: %d\n", calculate_total_weight(root));
   printf("Maximum weighted path: %d\n", max_weighted_path(root));

   return 0;
}