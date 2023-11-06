/***************************************************************************
     * Name(s) Maritza Mozo, Gabriela Roznawska                            *
     * Assignment name (Project 2 - "Guess My Number")                     *
     *                                                                     *
     * Assignment for March 6th 2023                                       *
     ***********************************************************************/

    /* *********************************************************************
     * Academic honesty certification:                                     *
     *   Written/online sources used:                                      *
     *   - CSC161 reading "Pseudo-Random Numbers" for 2/27/23              *
     *   - CSC161 lab instructions "Project 2: Guess My Number" for 3/1/23 *
     *                                                                     *
     *   Help obtained                                                     *
     *     - Class mentor Ziya Xu                                          *
     *     - Professor Barbara Johnson                                     *
     *                                                                     *
     *                                                                     *
     *   My/our signature(s) below confirms that the above list of sources *
     *   is complete AND that I/we have not talked to anyone else          *
     *   (e.g., CSC 161 students) about the solution to this problem       *
     *                                                                     *
     *   Signature: Maritza Mozo, Gabriela Roznawska                       *
     ***********************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void is_equal(int guess, int randomnumber, int i)                                               //start of function that will check if the user's valid input is higher, lower, or equal to the program's random  generated number.
{
  if ((guess < randomnumber) && (i < 10))                                                                     //tests if guess is less than randomnumber
    {
      printf("Wrong guess. The correct number is higher than %d.\n", guess);                    //if guess is less, prints statement telling user it is higher
    }
  else if ((guess > randomnumber) && (i < 10))                                                               //tests if guess is higher than randomnumber
    {
      printf("Wrong guess. The correct number is lower than %d.\n", guess);                     //if guess is higher, prints statement telling user it is lower
    }
  else if (guess == randomnumber)                                                                                         //tests everything else, which should only pass if user guesses correctly
    {
      printf("Congratulations! You guessed the correct number, %d, in %d tries!\n", guess, i);  //prints congratulations statement and tells the user how many tries it took to guess the right number
    }
}

void is_valid(int guess, int randomnumber, int i)                                               //start of function that will check if the user's input meets preconditions
{
  if ((!((guess >= 1) && (guess <= 100))) && (i < 10))                                           //checks if user's input is NOT a positive integer between 1 and 100, inclusively
    printf("Invalid input. Please guess a positive integer between 1 and 100, inclusively.\n"); //if not, prints statement that tells the user to try again and tells them they used up a guess
  else                                                                                                               //else statement that passes only if the user's input meets preconditions
    is_equal(guess, randomnumber, i);                                                                                //calls is_equal function to begin testing if the user's input is greater than, less than, or equal to the randomnumber
  
}

void is_ten(int guess, int randomnumber, int i)                                                                    //start of function that occurs when a user reaches 10 guesses. 
{
  if ((i == 10) && (guess != randomnumber))                                                                        //tests if i, the number of guesses, is 10 AND guess is not equal to randomnumber
    {
    printf("Sorry, you did not guess the correct number within ten tries.\n");                                   //prints statement that tells the user they did not guess the right number within ten guesses
    printf("The correct number was %d.\nRestart the program to play again. \n", randomnumber);                   //prints statement that tells the user the correct number and to restart to play again
    }
}


int main ()                                                                                          //start of main program that will take in an user's input
  
{
  srand((unsigned)time(NULL));                                                                          //seeds random number generator based on current time
  int maxvalue = 100;                                                                                   //set maximum range for generated random number
  int randomnumber = (rand()+1) % maxvalue;                                                             //generates a random number 
  int i = 1;
  int guess = 0;

  printf ("\n");
  printf("%d\n", randomnumber); // testing range 
  printf("This program generates random number in the range 1-100.\n");
  printf("User needs to guess generated number based on the clues given by the program. The clues indicate whether the guessed number was lower or higher than the generated number\n");
  printf("User has 10 chances to guess the correct number. They will be congratulated for successeeding, and encouraged to try again if they fail.\n");
  printf("Let's begin the game!\n");
  printf("\n");
  
  while ((i <= 10) && (guess != randomnumber))
    {
     printf ("\n");
     printf("Please guess randomly generated number. You input has to be a positive integer between 1 and 100 (inclusive).\n");
     scanf("%d", &guess);
     is_valid (guess, randomnumber, i);
     is_ten(guess, randomnumber, i);
     i++;
    }
  return 0;
}
