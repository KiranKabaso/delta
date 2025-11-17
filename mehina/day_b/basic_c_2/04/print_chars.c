/*------------------------------------------------------
* Filename: [print_chars]
* Description: [Brief description of the program here]
* Author: [Kiran Kabaso]
-------------------------------------------------------*/

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define ROW_SIZE 15
#define MAX_DIGITS 10

int str_to_integer(char* str, int size);

/*------------------------------------------------------
* Function Name - [main]
*
* Function Purpose - [demonstrates proper documentation]
*
* Parameters –  NONE
*
* Return Values - [0, 1]
*
* Author - [Kiran Kabaso]
-------------------------------------------------------*/
int main() {
  int number = 0;
  char char_to_print = '0';
  char inputted_word[MAX_DIGITS+1];
  printf("Please enter a number\n");
  scanf("%s", inputted_word);

  //check if the input is a number
  for (int i = 0; i < MAX_DIGITS; i++){
    if (inputted_word[i] == '\0'){ //end of input
      break;
    } else if (!isdigit(inputted_word[i])){
      printf("bad Input!\n");
      exit(1);
    }
  }

  //get the inputted number
  number = str_to_integer(inputted_word, MAX_DIGITS+1);

  //find the correct char to print
  if (!(number % 2)){
    char_to_print = '*';
  }else if(!(number % 3)){
    char_to_print = '^';
  }else if (!(number % 5)){
    char_to_print ='%';
  }else{
    char_to_print = '@';
  }

  //print the correct char
  for (int i =0; i <number; i++){
    for (int i =0; i <number; i++){
      printf("%c", char_to_print);
    }
    printf("\n");
  }

  return 0;
}


/*------------------------------------------------------
* Function Name - [str_to_integer]
*
* Function Purpose - [find the integer value of its string representation]
*
* Parameters –  [char* string_location, string_size]
*
* Return Values - [int value]
*
* Author - [Kiran Kabaso]
-------------------------------------------------------*/
int str_to_integer(char* str, int size){
  int number = 0;
  int multiplier = 1;
  for (int i = 0; i < size; i++){
    if (str[i] == '\0'){
      break;
    }
    number += (str[i] - 48); //0 ascii value
    number *= 10;
  }
  number /= 10;
  return number;

}