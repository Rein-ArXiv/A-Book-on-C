/* Chapter 8 exercise 14 */

/* 다음 코드의 출력을 쓰고, 설명하여라.

    #define GREETINGS(a, b, c) \
            printf(#a ", " #b ", and " #c ": Hello!\n")

    int main(void)
    {
        GREETINGS(Alice, Bob, Carole);
        return 0;
    }

 */

#define GREETINGS(a, b, c) \
        printf(#a ", " #b ", and " #c ": Hello!\n")

int main(void)
{
    GREETINGS(Alice, Bob, Carole);
    return 0;
}