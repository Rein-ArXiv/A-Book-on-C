#include <stdio.h>
#include <time.h>

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        // 현재 요소를 정렬된 부분과 비교하여 위치를 찾습니다.
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;            
        }
        arr[j + 1] = key;
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    // 시작 시간 기록
    clock_t start = clock();
    
    // 삽입 정렬 수행
    insertionSort(arr, n);
    
    // 끝 시간 기록
    clock_t end = clock();
    
    // 정렬 시간 계산 (밀리초 단위)
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;
    
    printf("정렬된 배열: ");
    printArray(arr, n);
    printf("정렬 시간: %f 밀리초\n", time_taken);

    return 0;
}
