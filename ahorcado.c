#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h> //for the booleans
#include <string.h> // for fgets to actually work lmao

//global variables
int count = 0; //for counting letters & spaces
char input; // the input of every time the player (P2) is asked to put a letter
bool bingo; // boolean to verify if the player guessed a letter(s)
const int SPACE = ' '; //constant for the space input
bool found_space = 0; //boolean to determin if we found a space
int counting_spaces = 0;

char exit_input; //the exit input of the program

//==============[functions]========================

//function to count the letters (and return the number)
int manyLetters(char arr[], int n){
	//let's hide the word to start the game
	
	//counting characters and spaces
	for(int i = 0; i < n; i++){
		if(arr[i] == SPACE) {
			found_space =1;
			++counting_spaces;
			--count;
		}
	  if(arr[i] != '\0') ++count;
		else break;
	}
	--count;
	//print how many letters the word has
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\t--the word has %d letters--\n\n", count );
	return count;
}

//just for printing spaces
void spaces(){
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
}

//ahorcados game by Erick #178145
//========== main=============
int main(void){
	//lifes
	int lifes;

	//the introduction of the game & players
	printf("\n\t --Welcome to ahorcados--\n\n");
	printf("\n\t --INSTRUCCIONS\n");
	puts("- One player has to choose a random word (P1)");
	puts("- The other player has to guess letter by letter the random word (P2)");
	printf("\n");

	//input of the name player one
	char P1[30];
	puts("please put name of Player 1");
	fgets(P1, 30, stdin);
	printf("--Welcome %s(P1)\n\n", P1);

	//input of the name player two
	char P2[30];
	puts("please put name of Player 2");
	fgets(P2, 30, stdin);
	printf("--Welcome  %s(P2)\n\n\n", P2);

	//input of the word
	char word[25];
	puts("READ INSTRUCCIONS");
	puts("P1 pls put the word and press enter");
	puts("make sure P2 is not watching ;)");
	fgets(word, 25, stdin);
	spaces();
	manyLetters(word,25);
	
	//letting the user choose the amount of lives
	puts("choose amount of lives");
	scanf("%d", &lifes);
	if(lifes < 4){
		printf("\n--\"%d\" is not a fair number\n", lifes);
		printf("minimun of lifes is 5\n");
		lifes = 5;
		printf("\nYou have %d lifes\n\n", lifes);
	}else 
		printf("\nYou have %d lifes\n\n", lifes);
	
	//declaring hidden array
	char hidden[25]; 
	int corrected_loop;
	// the game condition counts how many words have been spottet
	int win = count;

	// if we did find a space in the words we correct the loop to make it "ignore" the space
	if (found_space == 1)
	corrected_loop = count + counting_spaces;
	//else we don't correct anything
	else
	corrected_loop = win;
	
	printf("\n%d letters to be found\n", win);

	//initializing hidden array
	for(int i = 0; i < corrected_loop ; i++){
		//if we encounter a space, just ignore
		if(word[i] == SPACE){
			hidden[i] = '|';
		} //else we print the '_'
		else {
		hidden[i] = '_';
		}
	}

	//printing hidden arr
	for(int i = 0; i < corrected_loop; i++) printf("%c ", hidden[i]);
	printf("\n\n");

		//game loop
	while (lifes > 0) {
		printf("put letter\n");
		scanf("%s", &input);
		bingo= 0;
		for(int i = 0; i < corrected_loop; i++){
			// if the input is not correct we continue checking
			if(word[i] != input) continue;
			
			// if the input is correct we trigger the boolean for the following lines of code
			else {
				bingo = 1;
				//replace the array
				hidden[i] = input;
				//very important to rest the amount of letters we have not guessed
				--win;
				continue;
			}
		}
		
		//if we haven't won we continue
		if(win > 0){
			;
		} else {
			// else we end the game
			printf("\tword: ");
			for(int i = 0; i < corrected_loop; i++){
					printf("%c ", hidden[i]);
			}
			//yei u guessed the word
			printf("\n\n\t--You guessed the word!!!\n");
			break;
		}
		
		//if the boolean was not triggered means that we have not guessed any letters
		if(bingo == 0 && lifes > 0) {
			printf("\n");
			//we rest our lifes
			--lifes;
			puts("Nope!");
			printf("You have %d lifes left!\n", lifes);
			//priting the current guesses
			for(int i = 0; i < corrected_loop; i++){
					printf("%c ", hidden[i]);
			}
			printf("\n");
		}
		//else we anyways print the letters guessed and continue
		else {
				printf("\n");
				puts("Great job!");
				printf("You have %d lifes left!\n", lifes);
				// printing current guesses 
				for(int i = 0; i < corrected_loop; i++){
					printf("%c ", hidden[i]);
			}
				printf("\n");
		}
				
			
	} //end of game loop

	//if we lost we display the word
	if(lifes == 0){
			printf("\n");
			puts("You lost!");
			printf("the word was ");
			for(int i = 0; i < count; i++) printf("%c ", word[i]);
			printf("\n");
		}
	
	//to close the app
	puts("Press any key to exit");
	scanf("%c", &exit_input);

	return 0;
} //end of main

