/* Chapter 7 exercise 13 */

/* 룰렛 프로그램을 작성하여라. 룰렛은 무작위로 0에서 35 사이의 수 하나를 선택한
 * 다. 경기하는 사람은 짝수인지 홀수인지 맞추는 홀수/짝수 게임에 돈을 걸거나,
 * 특정 숫자를 맞추는 게임에 돈을 걸 수 있다. 룰렛의 결과가 0이면 짝수/홀수 게
 * 임에 건 돈은 모두 잃게 되고, 이 경우를 제외하고는 홀수/짝수 내기에서 이겼을
 * 경우 건 돈의 2배로 받는다. 경기하는 사람이 특정 숫자에 돈을 걸었고 룰렛의 결
 * 과가 그 숫자라면, 건 돈의 35배의 돈을 받는다. 이 룰렛 게임에서 한 게임당 1달
 * 러를 건다면, 10달러를 잃을 때까지 몇 게임이나 할 수 있겠는가?
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int roulette(void);

int main(void)
{
    int dollar = 10;
    int result;
    int game_count = 0;

    srand(time(NULL));

    int game;
    int betting;

    while (dollar > 0){
        game_count++;
        game = rand() % 2;  // Take even/odd game or number matching game
        if (game == 0){     // Matching Even or Odd
            betting = rand() % 2;

            result = roulette();
            if (result == 0){
                dollar -= 1;
            }
            else if((result % 2) == betting){
                dollar += 1;
            }
            else{
                dollar -= 1;
            }

            printf("Even/Odd game.          Your betting: %d,   Roulette Even/Odd: %d\n", betting, (result % 2));
        }   
        else{               // Matching roulette number
            betting = rand() % 36;
            result = roulette();
            if (betting == result){
                dollar += 35;
            }
            else{
                dollar -= 1;
            }
            printf("Number matching game.   Your betting: %d,    Roulette Number: %d\n", betting, result);
        }
    }

    printf("Your dollar is out. Game Count: %d\n", game_count);
    return 0;
}

int roulette(void)
{
    int number;
    for (int i = 0; i < rand(); i++){
        number = (rand() % 36);
    }
    return number;
}