#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define POINTS 300
#define TURNS 3
#define MAX 21
#define LUCKM 8


int PCThrow(void);
int userThrow(int aim);

int main(void)
{
    srand(time(NULL));

    int PCPoints = POINTS;
    int userPoints = POINTS;
    int PCThrown = 0;
    int userThrown = 0;
    int userAim = 0;

    do
    {
        // computer's turn
        printf("It's computer's turn.\n");

        for (int i = 0; i < TURNS; i++)
        {
            PCThrown = PCThrow();

            if (PCThrown == 0)
                printf("Computer missed the target!\n\n");
            else if (PCPoints >= PCThrown)
            {
                PCPoints -= PCThrown;
                printf("Good job, computer threw %i, its score is %i\n\n", PCThrown, PCPoints);
            }
            else
            {
                printf("Computer threw too much.\n\n");
                break;
            }

            if (PCPoints == 0)
                break;
        }

        // player's turn
        printf("It's your turn.\n");

        for (int j = 0; j < TURNS; j++)
        {
            do
            {
                printf("Where do you want to aim? (integer from 1 to 20) ");
                scanf(" %i", &userAim);
            } while (userAim < 1 || userAim > 20);

            userThrown = userThrow(userAim);

            if (userThrown == 0)
                printf("You missed the target!\n\n");
            else if (userPoints >= userThrown)
            {
                userPoints -= userThrown;
                printf("Good job, you threw %i, your score is %i\n\n", userThrown, userPoints);
            }
            else
            {
                printf("You threw too much.\n\n");
                break;
            }

            if (userPoints == 0)
                break;
        }
    }
    while ((PCPoints != 0) && (userPoints != 0));

    if (PCPoints == 0)
    {
        printf("Computer won!\n");
        return 0;
    }
    else if (userPoints == 0)
    {
        printf("Congratulations, you won!\n");
        return 0;
    }
}

int PCThrow(void)
{
    int throw = rand() % MAX;
    int luck = rand() % LUCKM;

    if (luck == 0)
    {
        printf("Computer didn't get lucky.\n");
        return throw;
    }

    else if (throw % luck == 2)
    {
        printf("Lucky throw, double points!\n");
        return throw * 2;
    }
    else if (throw % luck == 3)
    {
        printf("Lucky throw, triple points!\n");
        return throw * 3;
    }
    else if (throw % luck == 4)
    {
        printf("BULLSEYE!\n");
        return 50;
    }
    else if (throw % luck == 5)
    {
        printf("Computer hit outer bullseye!\n");
        return 25;
    }
    else
    {
        printf("Computer didn't get lucky.\n");
        return throw;
    }
}

int userThrow(int aim)
{
    int throw = rand() % MAX;
    int luck = rand() % LUCKM;

    if (luck == 0)
    {
        printf("You didn't get lucky.\n");
        return throw;
    }
    else if (throw % luck == 1)
    {
        printf("Good aim!\n");
        return aim;
    }
    else if (throw % luck == 2)
    {
        printf("Lucky throw, double points!\n");
        return aim* 2;
    }
    else if (throw % luck == 3)
    {
        printf("Lucky throw, triple points!\n");
        return aim * 3;
    }
    else if (throw % luck == 4)
    {
        printf("BULLSEYE!\n");
        return 50;
    }
    else if (throw % luck == 5)
    {
        printf("You hit outer bullseye!\n");
        return 25;
    }
    else
    {
        printf("You didn't get lucky.\n");
        return throw;
    }
}
