#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int generateRandomNumber(int n)
{
    srand(time(NULL));
    return rand() % n;
}

int greater(char char1, char char2)
{
    if (char1 == char2)
    {
        return -1;
    }

    else if ((char1 == 'r') && (char2 == 's'))
    {
        return 1;
    }
    else if ((char2 == 'r') && (char1 == 's'))
    {
        return 0;
    }

    else if ((char1 == 'p') && (char2 == 'r'))
    {
        return 1;
    }
    else if ((char2 == 'p') && (char1 == 'r'))
    {
        return 0;
    }

    else if ((char1 == 's') && (char2 == 'p'))
    {
        return 1;
    }
    else if ((char2 == 's') && (char1 == 'p'))
    {
        return 0;
    }
}
int main()
{
    int playerScore = 0, compScore = 0, temp;
    char playerChar, compChar;
    char dict[] = {'r', 'p', 's'};
    printf("Welcome to The ROCK PAPER And SCISSOR.\n");
    for (int i = 0; i < 3; i++)
    {
        //Generate  Player's Input
        printf("Player 1 Turn:\n");
        printf("Choose 1 for Rock, 2 for Paper and 3 for Scissor's \n");
        scanf("%d", &temp);
        playerChar = dict[temp - 1];
        printf("You choose %c\n\n", playerChar);

        //Generate Computer's Input
        printf("Computer's Turn:\n");
        printf("Choose 1 for Rock, 2 for Paper and 3 for Scissor's \n");
        temp = generateRandomNumber(3) + 1;
        compChar = dict[temp - 1];
        printf("CPU choose %c\n\n", compChar);

        //Compare the Score.
        if (greater(compChar, playerChar) == 1)
        {
            compScore += 1;
            printf("CPU Got It! \n\n");
        }

        else if (greater(compChar, playerChar) == -1)
        {
            compScore += 1;
            playerScore += 1;
            printf("Draw! \n\n");
        }

        else
        {
            playerScore += 1;
            printf("You Got It! \n\n");
        }
    }
    printf("You: %d\nCPU: %d\n", playerScore, compScore);
    if (playerScore > compScore)
    {
        printf("You Won the Game!\n");
    }
    else if (playerScore > compScore)
    {
        printf("CPU Won the Game!\n");
    }
    else
    {
        printf("Match Draw.\n");
    }

    return 0;
}