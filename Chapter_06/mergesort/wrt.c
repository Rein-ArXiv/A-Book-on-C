#include "mergesort.h"

void wrt(int key[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%4d%s", key[i], ((i < size - 1) ? "" : "\n"));
}
