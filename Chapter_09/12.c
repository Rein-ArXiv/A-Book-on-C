/* Chapter 9 exercise 12 */

/* 연습 문제 11번에서 작성한 프로그램에 한 학급의 평균을 계산하고 이 평균을 출
 * 력하는 class_average() 함수를 추가하여라. 이때 A 학점은 4점이고, B 학점은
 * 3점 등으로 한다.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENT 100

typedef struct {
    char name[50];
    int id;
    char grade;
} student;

int read_students(student *students, int max_students)
{
    int count = 0;
    while (scanf("%s %d %c", students[count].name, &students[count].id, &students[count].grade) == 3){
        count++;
        if (count >= max_students) break;
    }
    return count;
}

int compare_students(const void *a, const void *b)
{
    student *studentA = (student *)a;
    student *studentB = (student *)b;
    
    if (studentA -> grade != studentB -> grade){
        return studentA -> grade - studentB -> grade;
    }
    else {
        return strcmp(studentA -> name, studentB -> name);
    }
}

void class_average(student* students, int count)
{
    double average;
    double sum = 0.0;
    for (int i = 0; i < count; i++){
        switch (students[i].grade){
            case 'A':
                sum += 4;
                break;
            case 'B':
                sum += 3;
                break;
            case 'C':
                sum += 2;
                break;
            default:
                break;
        }
    }
    average = sum / (double) count;
    printf("Class Average grade: %lf\n", average);
}

void print_students(student* students, int count)
{
    for (int i = 0; i < count; i++){
        printf("%s\t%d\t%c\n", students[i].name, students[i].id, students[i].grade);
    }
}

int main(void)
{
    student students[MAX_STUDENT];
    
    int count = read_students(students, MAX_STUDENT);
    qsort(students, count, sizeof(student), compare_students);
    print_students(students, count);
    class_average(students, count);
    return 0;
}