/* Chapter 10 exercise 1 */

/* 다음 코드가 왜 컴파일 오류를 발생시키는가? 컴파일이 올바르게 되도록 코드를
 * 수정하여라.

    struct husband {
        int age;
        char name[10];
        struct wife spouse;
    } a;

    struct wife {
        int age;
        char name[10];
        struct husband spouse;
    } b;   

 */

#include <stdio.h>

struct husband;
struct wife;

struct husband {
    int age;
    char name[10];
    struct wife *spouse;
} a;

struct wife {
    int age;
    char name[10];
    struct husband *spouse;
} b;

int main(void)
{
    struct husband a = {30, "Bob", NULL};
    struct wife b = {28, "Alice", NULL};

    a.spouse = &b;
    b.spouse = &a;

    printf("Husband: %s, Age: %d, Wife: %s, Age: %d\n",
            a.name, a.age, a.spouse -> name, a.spouse -> age);
    printf("Wife: %s, Age: %d, Husband: %s, Age: %d\n",
            b.name, b.age, b.spouse -> name, b.spouse -> age);

    return 0;
}
