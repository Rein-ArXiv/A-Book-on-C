/* Chapter 10 exercise 34 */

/* 이진트리의 노드를 레벨 순으로 출력하는 함수를 작성하여라. 루트 노드는 레벨이
 * 0이다. 각 레벨은 이전 레벨 노드들의 자식 노드들로 구성된다. 먼저 루트 노드를
 * 출력하고, 그 다음 레벨 1에서 왼쪽 자식 노드와 오른쪽 자식 노드를 출력한다.
 * 계속 각 레벨별로 출력하는데, 출력하는 순서는 각 레벨의 왼쪽 노드에서 오른쪽
 * 노드로 출력한다. 이를 BFS 라고 한다.
 */

#include <stdio.h>
#include <stdlib.h>

typedef int DATA;

struct node
{
    DATA d;
    struct node *left;
    struct node *right;
};

typedef struct node NODE;
typedef NODE *BTREE;

BTREE create_node(DATA d)
{
    BTREE new_node = (BTREE) malloc(sizeof(NODE));

    if (new_node == NULL) {
        printf("Memory allocation failed.\n");
        return NULL;
    }

    new_node -> d = d;
    new_node -> left = NULL; 
    new_node -> right = NULL;
    return new_node;
}

struct queue_node{
    BTREE tree_node;
    struct queue_node* next;
};

struct queue{
    struct queue_node* front;
    struct queue_node* rear;
};

struct queue* create_queue()
{
    struct queue* queue = (struct queue*) malloc(sizeof(struct queue));
    queue -> front = queue -> rear = NULL;
    return queue;
}

int is_empty(struct queue* queue) {
    return queue -> front == NULL;
}

void enqueue(struct queue* queue, BTREE tree_node)
{
    struct queue_node* new_node = (struct queue_node*)malloc(sizeof(struct queue_node));
    new_node -> tree_node = tree_node;
    new_node -> next = NULL;

    if (queue -> rear == NULL) {
        queue -> front = queue -> rear = new_node;
        return;
    }

    queue -> rear -> next = new_node;
    queue -> rear = new_node;
}

BTREE dequeue(struct queue* queue)
{
    if (is_empty(queue)) return NULL;

    struct queue_node* temp = queue -> front;
    BTREE tree_node = temp -> tree_node;
    queue -> front = queue -> front -> next;

    if (queue -> front == NULL){
        queue -> rear = NULL;
    }

    free(temp);
    return tree_node;
}

BTREE insert(BTREE root, DATA d)
{
    BTREE new_node = create_node(d);

    if (root == NULL) {
        return new_node;
    }

    struct queue* queue = create_queue();
    enqueue(queue, root);

    while (!is_empty(queue)){
        BTREE current = dequeue(queue);

        if (current -> left == NULL){
            current -> left = new_node;
            break;
        }
        else{
            enqueue(queue, current -> left);
        }

        if (current -> right == NULL) {
            current -> right = new_node;
            break;
        }
        else {
            enqueue(queue, current -> right);
        }
    }

    free(queue);
    return root;
}

void bfs(BTREE root)
{
    if (root == NULL) {
        return;
    }

    struct queue* queue = create_queue();

    enqueue(queue, root);
    while (!is_empty(queue)){
        BTREE current = dequeue(queue);
        printf("%d ", current -> d);

        if (current -> left != NULL){
            enqueue(queue, current -> left);
        }
        if (current -> right != NULL){
            enqueue(queue, current -> right);
        }
    }
    printf("\n");

    free(queue);
}

int main(void)
{
    int data[] = {8, 4, 15, 2, 6, 17, 3, 1, 11, 24, 32};
    int n = sizeof(data) / sizeof(data[0]);
    BTREE root = create_node(data[0]);

    for (int i = 1; i < n; i++){
        insert(root, data[i]);
    }

    bfs(root);

    return 0;
}