/*------------------------------------------------------
* Filename: [print_value_addr.c]
* Description: [get ARRAY_SIZE characters and numbers and print them]
* Author: [Kiran Kabaso]
-------------------------------------------------------*/
#include <stdio.h>
#include <ctype.h>

#define ARRAY_SIZE 8
#define MAX_DIGITS_IN_NUMBER 100
#define ZERO_CHAR_VALUE_ASCII 48

/*------------------------------------------------------
* Function Name - [get_characters]
*
* Function Purpose - [gets an array and fills it with user input characters]
*
* Parameters –  [IN - char characters[ARRAY_SIZE]]
*
* Return Values - NONE
*
* Author - [Kiran Kabaso]
-------------------------------------------------------*/
void get_characters(char characters[ARRAY_SIZE]);

/*------------------------------------------------------
* Function Name - [get_numbers]
*
* Function Purpose - [gets an array and fills it with user input numbers]
*
* Parameters –  [IN - int array[]]
*
* Return Values - NONE
*
* Author - [Kiran Kabaso]
-------------------------------------------------------*/
void get_numbers(int array[]);

/*------------------------------------------------------
* Function Name - [is_number]
*
* Function Purpose - [check if a string represents a number]
*
* Parameters –  [IN - const char string[ARRAY_SIZE] -> "123"]
*
* Return Values - [1, 0]
*
* Author - [Kiran Kabaso]
-------------------------------------------------------*/
int is_number(const char string[ARRAY_SIZE]);


/*------------------------------------------------------
* Function Name - [number_from_string]
*
* Function Purpose - [convert a string representation of a number and return the int representation]
*
* Parameters –  [IN - const char string[ARRAY_SIZE] -> "123"]
*
* Return Values - [int number -> 123]
*
* Author - [Kiran Kabaso]
-------------------------------------------------------*/
int number_from_string(const char string[ARRAY_SIZE]);

/*------------------------------------------------------
* Function Name - [main]
*
* Function Purpose - [get ARRAY_SIZE characters and numbers and print them]
*
* Parameters –  NONE
*
* Return Values - [0]
*
* Author - [Kiran Kabaso]
-------------------------------------------------------*/
int main() {
  int numbers[ARRAY_SIZE] = {0};
  char characters[ARRAY_SIZE] = {0};
  printf("Please enter %d numbers and afterward %d characters\n", ARRAY_SIZE, ARRAY_SIZE);
  get_numbers(numbers);
  get_characters(characters);

  //print the numbers:
  printf("the inputted numbers and their location are:\n");
  for (int i = 0; i < ARRAY_SIZE; i++){
    printf("number %d at %x\n", numbers[i], numbers + i);
  }

  char *characters_ptr = characters;
  printf("the inputted characters and their location are:\n");
  for (int i = 0; i < ARRAY_SIZE; i++){
    printf("character %c at %x\n", *characters_ptr, characters_ptr);
    ++characters_ptr;
  }
  return 0;
}


void get_characters(char characters[ARRAY_SIZE]){
  for (int i = 0; i < ARRAY_SIZE; i++){
    scanf("%c", characters + i);
  }
}

void get_numbers(int array[ARRAY_SIZE]){
  int i = 0;
  while(i < ARRAY_SIZE){
    char input[MAX_DIGITS_IN_NUMBER+1] = {0};
    scanf("%s ", input);
    if(is_number(input)){
      array[i] = number_from_string(input);
      ++i;
    }
  }
}

int is_number(const char string[MAX_DIGITS_IN_NUMBER]){
  for (int i = 0; i < ARRAY_SIZE; i++){
    if (string[i] == '\0'){
      break;
    }
    if (!(isdigit(string[i]))){
      return 0;
    }
  }
  return 1;
}

int number_from_string(const char string[ARRAY_SIZE]){
  int number = 0;
  for (int i = 0; i < ARRAY_SIZE; i++){
    if (string[i] == '\0'){
      break;
    }
    number *= 10;
    number += string[i] - ZERO_CHAR_VALUE_ASCII;
  }
  return number;
}