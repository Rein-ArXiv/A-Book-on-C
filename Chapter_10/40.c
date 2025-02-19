/* Chapter 10 exercise 40 */

/* (과제) 희소 다항식 ADT를 구현하여라. 다항식의 영이 아닌 항들을 표현하기 위
 * 해 연결 리스트를 사용하여라. 각 항은 실수 계수와 멱이다. 다항식을 다루는 패
 * 키지를 작성하여라. 이 패키지는 다항식을 입력하고 출력할 수 있어야 하고, 다항
 * 식의 덧셈, 뺄셈, 곱셈, 복사가 가능해야 한다. 
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct TermNode
{
    double coeff;
    int exp;
    struct TermNode* Next;
} TermNode;

typedef TermNode* Polynomial;

void add_term(Polynomial *poly, double coeff, int exp)
{
    TermNode **current = poly;
    
    while (*current != NULL && (*current) -> exp > exp)
    {
        current = &((*current) -> Next);
    }

    if (*current != NULL && (*current) -> exp == exp)
    {
        (*current) -> coeff += coeff;
        if ((*current) -> coeff == 0.0)
        {
            TermNode *temp = *current;
            *current = temp -> Next;
            free(temp);
        }
    }
    else
    {
        TermNode *new_node = (TermNode *)malloc(sizeof(TermNode));
        new_node -> coeff = coeff;
        new_node -> exp = exp;
        new_node -> Next = *current;
        *current = new_node;
    }
}

Polynomial input_polynomial()
{
    Polynomial new_poly = NULL;
    double coeff;
    int exp;
    
    printf("각 항을 입력하세요. (계수 coeff 멱 exp) 형태로 입력하며, 0 0 을 입력하여 종료합니다.\n");
    printf("예시: 3 1 => 3x\n\n");
    printf("입력: ");

    while (1)
    {
        scanf("%lf %d", &coeff, &exp);
        if (coeff == 0.0 && exp == 0)
        {
            break;
        }
        else
        {
            add_term(&new_poly, coeff, exp);
        }
    }
    return new_poly;
}

void print_polynomial(Polynomial poly)
{
    if (poly == NULL)
    {
        printf("0\n");
        return;
    }

    TermNode *current = poly;

    while(current != NULL)
    {
        if (current -> coeff != 1.0 || current -> exp == 0)
        {
            printf("%.2f", current -> coeff);
        }
        if (current -> exp > 0)
        {
            printf("x");
            if (current -> exp > 1)
            {
                printf("^%d", current -> exp);
            }
        }
        if (current -> Next != NULL)
        {
            if (current -> Next -> coeff > 0)
            {
                printf(" + ");
            }
            else
            {
                printf(" ");
            }
        }
        current = current -> Next;
    }
    printf("\n");
}

Polynomial add_polynomials(Polynomial a, Polynomial b)
{
    Polynomial result = NULL;
    TermNode **current = &result;

    TermNode *p = a, *q = b;

    while (p && q)
    {
        TermNode *node = (TermNode *)malloc(sizeof(TermNode));

        if (p -> exp > q -> exp)
        {
            node -> coeff = p -> coeff;
            node -> exp = p -> exp;
            p = p -> Next;
        }
        else if (p -> exp < q -> exp)
        {
            node -> coeff = q -> coeff;
            node -> exp = q -> exp;
            q = q -> Next;
        }
        else
        {
            double sum = p -> coeff + q -> coeff;

            if (sum == 0.0)
            {
                free(node);
                p = p -> Next;
                q = q -> Next;
                continue;
            }

            node -> coeff = sum;
            node -> exp = p -> exp;
            p = p -> Next;
            q = q -> Next;
        }
        node -> Next = NULL;
        *current = node;
        current = &((*current) -> Next);
    }

    while (p)
    {
        TermNode *node = (TermNode *)malloc(sizeof(TermNode));

        node -> coeff = p -> coeff;
        node -> exp = p ->exp;
        node -> Next = NULL;
        *current = node;
        current = &((*current) -> Next);
        p = p -> Next;
    }
    while (q)
    {
        TermNode *node = (TermNode *)malloc(sizeof(TermNode));

        node -> coeff = q -> coeff;
        node -> exp = q -> exp;
        node -> Next = NULL;
        *current = node;
        current = &((*current) -> Next);
        q = q -> Next;
    }

    return result;
}

Polynomial subtract_polynomials(Polynomial a, Polynomial b)
{
    Polynomial result = NULL;
    TermNode **current = &result;

    TermNode *p = a, *q = b;

    while(p && q)
    {
        TermNode *node = (TermNode *) malloc(sizeof(TermNode));
        if (p -> exp > q -> exp)
        {
            node -> coeff = p -> coeff;
            node -> exp = p -> exp;
            p = p -> Next;
        }
        else if (p -> exp < q -> exp)
        {
            node -> coeff = q -> coeff;
            node -> exp = q -> exp;
            q = q -> Next;
        }
        else
        {
            double diff = p -> coeff - q -> coeff;
            if (diff == 0.0)
            {
                free(node);
                p = p -> Next;
                q = q -> Next;
                continue;
            }
            node -> coeff = diff;
            node -> exp = p -> exp;
            p = p -> Next;
            q = q -> Next;
        }
        node -> Next = NULL;
        *current = node;
        current = &((*current) -> Next);
    }

    while (p)
    {
        TermNode *node = (TermNode *)malloc(sizeof(TermNode));

        node -> coeff = p -> coeff;
        node -> exp = p -> exp;
        node -> Next = NULL;
        *current = node;
        current = &((*current) -> Next);
    }

    while (q)
    {
        TermNode *node = (TermNode *)malloc(sizeof(TermNode));

        node -> coeff = -(q -> coeff);
        node -> exp = q -> exp;
        node -> Next = NULL;
        *current = node;
        current = &((*current) -> Next);
    }
    return result;
}

Polynomial multiply_polynomials(Polynomial a, Polynomial b)
{
    Polynomial result = NULL;

    for (TermNode *p = a; p; p = p -> Next)
    {
        for (TermNode *q = b; q; q = q -> Next)
        {
            double coeff = p -> coeff * q -> coeff;
            int exp = p -> exp + q -> exp;
            add_term(&result, coeff, exp);
        }
    }
    return result;
}

Polynomial copy_polynomial(Polynomial src)
{
    Polynomial dest = NULL;
    TermNode **current = &dest;
    TermNode *p = src;

    while (p)
    {
        TermNode *node = (TermNode *)malloc(sizeof(TermNode));
        node -> coeff = p -> coeff;
        node -> exp = p ->exp;
        *current = node;
        current = &((*current) -> Next);
    }
    return dest;
}

void free_polynomial(Polynomial poly)
{
    TermNode *current = poly;

    while (current)
    {
        TermNode *temp = current;
        current = current -> Next;
        free(temp);
    }
}

int main(void)
{
    Polynomial first_poly, second_poly;

    printf("첫 번째 다항식을 입력해주세요.\n");
    first_poly = input_polynomial();
    printf("첫 번째 다항식: ");
    print_polynomial(first_poly);

    putchar('\n');
    printf("두 번째 다항식을 입력해주세요.\n");
    second_poly = input_polynomial();
    printf("두 번째 다항식: ");
    print_polynomial(second_poly);

    printf("첫 번째 다항식과 두 번째 다항식의 합한 결과:\n");
    print_polynomial(add_polynomials(first_poly, second_poly));

    putchar('\n');
    printf("첫 번째 다항식에서 두 번째 다항식을 뺀 결과:\n");
    print_polynomial(subtract_polynomials(first_poly, second_poly));

    putchar('\n');
    printf("첫 번째 다항식과 두 번째 다항식을 곱한 결과:\n");
    print_polynomial(multiply_polynomials(first_poly, second_poly));

    free_polynomial(first_poly);
    free_polynomial(second_poly);

    return 0;
}