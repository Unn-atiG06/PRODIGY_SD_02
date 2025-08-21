#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void clear_input(void)
{
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF) { /* discard */ }
}

int main(void) 
{
    int secret, guess;
    int attempts;
    const int MIN = 1, MAX = 100;   // range of the secret number
    char play_again = 'y';

    // seed RNG once
    srand((unsigned int)time(NULL));

    printf("=== Guessing Game ===\n");
    printf("I picked a number between %d and %d. Try to guess it!\n", MIN, MAX);

    while (play_again == 'y' || play_again == 'Y') {

        secret = (rand() % (MAX - MIN + 1)) + MIN;   // random number in [MIN, MAX]
        attempts = 0;

        while (1)
          {
            printf("Enter your guess: ");
            if (scanf("%d", &guess) != 1)
            {
                printf("Please enter a valid integer.\n");
                clear_input();
                continue;              // don’t count invalid input
            }
            if (guess < MIN || guess > MAX) 
            {
                printf("Your guess must be between %d and %d.\n", MIN, MAX);
                continue;              // out-of-range doesn’t count
            }

            attempts++;

            if (guess < secret)
            {
                printf("Too low! Try again.\n");
            } else if (guess > secret)
            {
                printf("Too high! Try again.\n");
            } else
            {
                printf("🎉 Correct! The number was %d.\n", secret);
                printf("You guessed it in %d attempt%s.\n",
                       attempts, attempts == 1 ? "" : "s");
                break; // round finished
            }
        }

        clear_input();
        printf("\nPlay again? (y/n): ");
        scanf("%c", &play_again);
        clear_input();
        printf("\n");
    }

    printf("Thanks for playing! Goodbye.\n");
    return 0;
}
