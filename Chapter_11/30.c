/* Chapter 11 exercise 30 */

/* 다음은 무엇을 출력하겠는가?
 
    #include <stdio.h>

    int main(void)
    {
        printf("Hello!\n");         // 콘솔에 출력력
        fclose(stdout);
        printf("Goodbye!\n");       // 출력 X
        return 0;
    }

 */

 #include <stdio.h>

 int main(void)
 {
    printf("Hello!\n");
    fclose(stdout);
    printf("Goodbye!\n");
    return 0;
 }