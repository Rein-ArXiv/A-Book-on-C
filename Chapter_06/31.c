/* Chapter 6 exercise 31 */

/* 다음은 어떤 값을 출력하겠는가? 설명해 보아라.

    #include <stdio.h>

    void try_me(int [][3]); // void try_me(int *a[3])

    main()
    {
        int a[3][3] = {{2, 5, 7}, {0, -1, -2}, {7, 9, 3}};

        try_me(a);
        return 0;
    }

    void try_me(int (*a)[3])
    {
        printf("%d %d %d %d . . . infinity\n",
            a[1][0], -a[1][1], a[0][0], a[2][2]);
    }
 
 * 이제 try_me() 함수 정의의 헤더에서 매개변수 선언을 다음과 같이 수정해 보아
 * 라.

    int *a[3]

 * 컴파일러가 오류 메시지를 출력하는가? (그래야 한다.) 설명하여라.
 */

#include <stdio.h>

void try_me(int [][3]); // void try_me(int *a[3])

main()
{
    int a[3][3] = {{2, 5, 7}, {0, -1, -2}, {7, 9, 3}};

    try_me(a);
    return 0;
}

void try_me(int (*a)[3])
{
    printf("%d %d %d %d . . . infinity\n",
        a[1][0], -a[1][1], a[0][0], a[2][2]);
}