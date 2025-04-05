#include <stdio.h>

int main(void)
{
    int fork(void), value;

    value = fork();
    value = fork();
    printf("In main: value = %d\n", value);
    return 0;
}