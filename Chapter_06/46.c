/* Chapter 6 exercise 46 */

/* 고대 이집트인들은 상형문자를 사용하였다. 이 시스템에서는 모음이 없고 자음만
 * 이 있다. 일반적으로 모음을 사용하지 않는 영어를 이해할 수 있겠는가? 시험적으
 * 로 주어진 문자가 모음이면 1을 리턴하고, 그렇지 않으면 0을 리턴하는 is_vowel()
 * 함수를 작성하여라. 이 함수를 사용하여 표준 입력 파일에서 읽고 모음을 삭제한
 * 후 표준 출력 파일에 쓰는 프로그램을 작성하여라. 재지정을 사용하여 영문 문서를
 * 입력으로 한 후 이 프로그램을 검사하여라.
 */

#include <stdio.h>
#include <string.h>

int is_vowel(char c);

int main(void)
{
    FILE *input_file = fopen("input.txt", "r");
    FILE *output_file = fopen("output.txt", "w");

    if (input_file == NULL || output_file == NULL){
        fprintf(stderr, "Error opening file.\n");
        return 1;
    }

    char c;
    while ((c = fgetc(input_file)) != EOF){
        if (!is_vowel(c)){
            fputc(c, output_file);
        }
    }

    fclose(input_file);
    fclose(output_file);
    return 0;
}

int is_vowel(char c)
{
    int result = 0;
    char vowel[10] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    for (int i = 0; i < 10; i++){
        if (c == vowel[i]){
            result = 1;
            break;
        }
    }
    return result;
}