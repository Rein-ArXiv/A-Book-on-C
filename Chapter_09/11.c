/* Chapter 9 exercise 11 */

/* data 파일에 학생 이름, 학번, 성적 등의 목록을 저장하여라. 예를 들면 다음과
 * 같은 형태로 저장한다.

    Casanova    910017  A
    Smith       934422  C
    Jones       878766  B
    .....

 * 이 파일에서 자료를 읽어 struct student 형의 배열에 저장하는 reorder라는
 * 프로그램을 작성하여라. 프로그램 수행은 다음과 같은 재지정 명령을 사용하면
 * 된다.

    reorder < data

 * 이 프로그램은 또한 성적순으로 학생 이름과 성적을 출력하는 기능도 가지고 있
 * 어야 한다. 성적순으로 출력할 때 A 학점 받은 학생들을 먼저 출력하고, 그 다음
 * B 학점 순으로 출력한다. 같은 학점을 받은 학생들은 이름 순으로 출력한다.
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
    
    return 0;
}