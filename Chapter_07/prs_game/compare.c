#include "p_r_s.h"

outcome compare(p_r_s player_choice, p_r_s machine_choice)
{
    outcome result;

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