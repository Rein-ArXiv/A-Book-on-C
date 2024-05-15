/* Chpater 6 exercise 29 */

/* 기계 번역 문제에 많은 노력이 검증되고 있다. 원시적인 방법이 얼마나 성공적인
 * 가? 가장 일반적으로 사용되는 영어 단어 100개를 찾아보아라. John carroll(외)의
 * The American Heritage Word Frequency Book(Boston, Massachusetts :
 * Houghton Mifflin, 1971)을 참고하여라. 그 100개의 단어를 적고, 한영 사전에서
 * 그 단어들을 찾은 후 뜻을 적어보아라. 한글 문장을 영어로 번역하기 위해 다음과
 * 같은 두 배열을 사용하는 프로그램을 작성해 보아라.

    char *foreign[100], *english[100];

 * 100단어 대신 200단어를 사용하여 시도해 보아라. 이렇게 하면 프로그램은 더 효
 * 율적인 번역결과를 보여주는가?
 */

#include <stdio.h>
#include <string.h>

#define NUM_WORDS 100 // 200

int main(void) {
    char *english[NUM_WORDS] = {
        "the", "be", "to", "of", "and", "a", "in", "that", "have", "I", 
        // ...
    };
    char *foreign[NUM_WORDS] = {
        "그", "있다", "~에", "~의", "그리고", "하나", "~안에", "저것", "가지다", "나", 
        // ...
    };

    char sentence[1000]; // 입력 문장을 저장할 배열
    char *word;

    printf("번역할 한국어 문장을 입력하세요: ");
    fgets(sentence, sizeof(sentence), stdin); // 문장 입력

    // 문장을 단어 단위로 분리하여 번역
    word = strtok(sentence, " \n"); // 공백과 개행 문자로 단어 분리
    while (word != NULL) {
        for (int i = 0; i < NUM_WORDS; i++) {
            if (strcmp(word, foreign[i]) == 0) {
                printf("%s ", english[i]); // 번역된 단어 출력
                break;
            }
        }
        word = strtok(NULL, " \n"); // 다음 단어 분리
    }
    printf("\n");

    return 0;
}
