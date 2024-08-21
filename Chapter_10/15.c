/* Chapter 10 exercise 15 */

/* 이중 연결 선형 리스트의 원소는 다음과 같이 정의된다.

    typedef struct dllist {
        DATA d;
        struct dllist *prev;
        struct dllist *next;
    } ELEMENT;

 * 이것에는 멤버가 하나 더 추가되었지만, 리스트상의 이동을 더 쉽게 해준다.
 * 삽입과 제거를 수행하는 반복적 루틴을 작성하여라.
 */