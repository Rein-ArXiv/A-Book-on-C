/* Chpater 6 exercise 20 */

/* 회문은 앞뒤 어느 쪽으로 읽어도 똑같은 문자열을 뜻한다. 예를 들면, 다음과 같
 * 다.

    "ABCBA"     "123343321"     "otto"      "i am ma i"     "C"
 
 * 문자열 인자를 받아들여 회문이면 int 1을, 아니면 0을 리턴하는 함수를 작성하
 * 여라. UNIX 시스템을 사용한다면, /usr/dict/words 파일에 몇 개의 회문이 있
 * 는지 찾아보아라.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Palindrome(char *str, int len);

int main(void)
{
    char *sentence = NULL;
    int size = 0;
    int capacity = 10;
    char c;

    sentence = (char *) malloc(capacity * sizeof(char));

    printf("Enter a sentence: ");

    while ((c = getchar()) != '\n')
    {
        if (size == capacity - 1)
        {
            capacity *= 2;
            sentence = (char *) realloc(sentence, capacity * sizeof(char));
        }
        sentence[size++] = c;
    }
    sentence[size] = '\0';  // Null-terminate the string

    if (Palindrome(sentence, size))
    {
        printf("The sentence is palindrome.\n");
    }
    else
    {
        printf("The sentence is not palindrome.\n");
    }
}

int Palindrome(char *str, int len)
{
    int i, j, is_pal = 1;

    for(i = 0; i <= len / 2; i++){
        j = len - i - 1;

        if (str[i] != str[j]){
            is_pal = 0;
        }
    }
    return is_pal;
}