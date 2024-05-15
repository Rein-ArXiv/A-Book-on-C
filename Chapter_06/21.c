/* Chpater 6 exercise 21 */

/* 연습 문제 20번에서 작성한 함수의 비교 과정에서 공백과 대문자는 무시하도록
 * 수정하여라. 이 규칙을 사용하면 다음과 같은 것들도 회문이 된다.

    "Anna"      "A man a plan a canal Panama"       "ott o"
 
 * UNIX를 사용할 수 있으면, 이 함수를 사용했을 때 /usr/dict/words 파일에서
 * 얼마나 더 많은 회문을 추가로 찾을 수 있는지 수행해 보아라.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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

    i = 0;
    j = len - 1;

   while (i < j) {
        while(isspace(str[i]))
            i++;
        while(isspace(str[j]))
            j--;

        if (tolower(str[i]) != tolower(str[j])){
            is_pal = 0;
        }
        i++;
        j--;
    }
    return is_pal;
}