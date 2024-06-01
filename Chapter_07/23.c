/* Chapter 7 exercise 23 */

/* "가위, 바위, 보" 게임에서, 무승부가 아닌 경우의 출력은 다음 중 하나이다. 

    You win.
    You lose.

 * 출력되는 메시지가 다음과 같은 형태가 되도록 프로그램을 수정하여라.

    You chose paper and I chose rock.   You win.

 */

#include <ctype.h>      // for isspace()
#include <stdio.h>      // for printf(), etc
#include <stdlib.h>     // for rand() and srand()
#include <time.h>       // for time()

enum p_r_s {paper, rock, scissors, game, help, instructions, quit};
enum outcome {win, lose, tie, error};

typedef enum p_r_s      p_r_s;
typedef enum outcome    outcome;

outcome compare(p_r_s player_choice, p_r_s machine_choice);
void prn_final_status(int win_cnt, int lose_cnt);
void prn_game_status(int win_cnt, int lose_cnt, int tie_cnt);
void prn_help(void);
void prn_instructions(void);
void report_and_tabulate(outcome result, int *win_cnt_ptr, int *lose_cnt_ptr, int *tie_cnt_ptr);

p_r_s selection_by_machine(void);
p_r_s selection_by_player(void);


int main(void)
{
    int win_cnt = 0, lose_cnt = 0, tie_cnt = 0;
    outcome result;
    p_r_s player_choice, machine_choice;

    srand(time(NULL));  // seed the random number generator
    prn_instructions();
    while ((player_choice = selection_by_player()) != quit){
        switch (player_choice){
            case paper:
            case rock:
            case scissors:
                machine_choice = selection_by_machine();
                result = compare(player_choice, machine_choice);
                report_and_tabulate(result, &win_cnt, &lose_cnt, &tie_cnt);
                break;
            
            case game:
                prn_game_status(win_cnt, lose_cnt, tie_cnt);
                break;
            case instructions:
                prn_instructions();
                break;
            case help:
                prn_help();
                break;
            default:
                printf("\nPROGRAMMER ERROR : Cannot get to here!\n\n");
                exit(1);
        }
    }
    prn_game_status(win_cnt, lose_cnt, tie_cnt);
    prn_final_status(win_cnt, lose_cnt);
    return 0;
}

outcome compare(p_r_s player_choice, p_r_s machine_choice)
{
    outcome result;

    char *p_choice;
    char *m_choice;


    switch(player_choice){
        case paper:
            p_choice = "paper";
            break;
        
        case rock:
            p_choice = "rock";
            break;

        case scissors:
            p_choice = "scissors";
            break; 
    }

    switch(machine_choice){
        case paper:
            m_choice = "paper";
            break;
        
        case rock:
            m_choice = "rock";
            break;

        case scissors:
            m_choice = "scissors";
            break; 
    }

    printf("You chose %s and I choise %s.\t", p_choice, m_choice);

    if (player_choice == machine_choice)
        return tie;
    else if(((player_choice + 1) % 3) == (machine_choice))
        return win;
    else if(player_choice == ((machine_choice + 1 ) % 3))
        return lose;
    else
        printf("\nPROGRAMMER ERROR : Unexpected choice!\n\n");
        exit(1);
}

void prn_final_status(int win_cnt, int lose_cnt)
{
    if (win_cnt > lose_cnt)
        printf("CONGRATULATIONS - You won!\n\n");
    else if (win_cnt == lose_cnt)
        printf("A DRAW - You tied!\n\n");
    else
        printf("SORRY - You lost!\n\n");
}

void prn_game_status(int win_cnt, int lose_cnt, int tie_cnt)
{
    printf("\n%s\n%s%4d\n%s%4d\n%s%4d\n%s%4d\n\n",
        "GAME STATUS",
        "   Win:    ", win_cnt,
        "   Lose:   ", lose_cnt,
        "   Tie:    ", tie_cnt,
        "   Total:  ", win_cnt + lose_cnt + tie_cnt);
}

void prn_help(void)
{
    printf("\n%s\n",
        "The following characters can be used for input:\n"
        "   p   for paper\n"
        "   r   for rock\n"
        "   s   for scissors\n"
        "   g   print the game status\n"
        "   h   help, print this list\n"
        "   i   reprint the instructions\n"
        "   q   quit the game\n");
}

void prn_instructions(void)
{
    printf("\n%s\n",
        "PAPER, ROCK, SCISSORS:\n"
        "   In this game p is for \"paper\", r is for \"rock\", and s is for \"scissors\".\n"
        "   Both the player and the machine will choose one of p, r, or, s.\n"
        "\n"
        "   There are other allowable inputs:\n"
        "       g for game status (the number of wins so far),\n"
        "       h for help,\n"
        "       i for instructions (reprint these instructions), \n"
        "       q for quit (to quit the game).\n"
        "\n"
        "   This game is played repeatedly until q is entered.\n"
        "\n"
        "   Good Luck!\n\n");
}


void report_and_tabulate(outcome result, int *win_cnt_ptr, int *lose_cnt_ptr, int *tie_cnt_ptr)
{
    switch (result)
    {
        case win:
            ++*win_cnt_ptr;
            printf("You win.\n");
            break;
        case lose:
            ++*lose_cnt_ptr;
            printf("You lose.\n");
            break;
        case tie:
            ++*tie_cnt_ptr;
            printf("A tie.\n");
            break;
        default:
            printf("\nPROGRAMMER ERROR : Unexpected result!\n\n");
            exit(1);
    }
}


p_r_s selection_by_machine(void)
{
    return ((p_r_s) (rand() % 3));
}

p_r_s selection_by_player(void)
{
    char c;
    p_r_s player_choice;

    printf("Input p, r, or s: ");
    while (isspace(c = getchar())); // skip the space

    switch (c){
        case 'p':
            player_choice = paper;
            break;
        case 'r':
            player_choice = rock;
            break;
        case 's':
            player_choice = scissors;
            break;
        case 'g':
            player_choice = game;
            break;
        case 'i':
            player_choice = instructions;
            break;
        case 'q':
            player_choice = quit;
            break;
        default:
            player_choice = help;
            break;
    }
    return player_choice;
}