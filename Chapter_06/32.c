/* Chapter 6 exercise 32 */

/* 0~2pi 구간에서 sin()과 cos() 함수를 화면에 그래프로 그리기 위해, 하나의
 * 문자와 화면의 크기에 맞는 2차원 배열을 선택하여라. 대부분의 화면에서 출력되
 * 는 한 문자의 영역이 정방형이 아니므로, 수평/수직 왜곡이 일어난다. 이 왜곡을
 * 제거할 수 있는지를 그래프를 가지고 실험해 보아라.
 */

#include <stdio.h>
#include <math.h>

#define PI 3.14159265359
#define WIDTH 80
#define HEIGHT 25

int main() {
    char graph[HEIGHT][WIDTH] = {0}; // 그래프를 저장할 2차원 배열
    double x, y;

    // sin() 함수 그래프 계산 및 저장
    for (x = 0; x <= 2 * PI + 0.01; x += 0.1) {
        y = sin(x);
        int row = (int)((HEIGHT - 1) * (1 - y) / 2); // y 값을 행 인덱스로 변환
        int col = (int)(WIDTH * x / (2 * PI)); // x 값을 열 인덱스로 변환
        graph[row][col] = '*'; // 그래프에 '*' 표시
    }

    // cos() 함수 그래프 계산 및 저장
    for (x = 0; x <= 2 * PI + 0.01; x += 0.1) {
        y = cos(x);
        int row = (int)((HEIGHT - 1) * (1 - y) / 2);
        int col = (int)(WIDTH * x / (2 * PI));
        graph[row][col] = '+'; // 그래프에 '+' 표시
    }

    // 그래프 출력
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (graph[i][j] == 0) {
                printf(" ");
            } else {
                printf("%c", graph[i][j]);
            }
        }
        printf("\n");
    }

    return 0;
}