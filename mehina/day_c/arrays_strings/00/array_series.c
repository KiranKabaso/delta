/*------------------------------------------------------
* Filename: [array_series]
* Description: [test a function that gets an array of numbers and prints if its increasing, decreasing, constant or messed up]
* Author: [Kiran Kabaso]
-------------------------------------------------------*/

#include <stdio.h>
#include <ctype.h>

#define ARRAY_SIZE 15
#define MAX_DIGITS_IN_NUMBER 100
#define ZERO_CHAR_VALUE_ASCII 48

/*------------------------------------------------------
* Function Name - [print_array_type]
*
* Function Purpose - [check if an array is increasing, decreasing, constant or messed up]
*
* Parameters –  [int array[] -> array ptr, int size -> the array's size]
*
* Return Values - NONE
*
* Author - [Kiran Kabaso]

*if there is only one member in the array we will assume its constant as the function should only print once.
*we will not allow some members to be equal in increasing or decreasing arrays eg:[1, 2, 2, 3] is not increasing.
-------------------------------------------------------*/
void print_array_type(int array[], int size);

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
* Function Purpose - [get an array and sort an array of pointers to its members]
*
* Parameters –  NONE
*
* Return Values - [0]
*
* Author - [Kiran Kabaso]
-------------------------------------------------------*/

/*------------------------------------------------------
* Function Name - [main]
*
* Function Purpose - [test a function that gets an array of numbers and prints if its increasing, decreasing, constant or messed up]
*
* Parameters –  NONE
*
* Return Values - [0]
*
* Author - [Kiran Kabaso]
-------------------------------------------------------*/
int main() {
  int array[ARRAY_SIZE] = {0};
  printf("please enter the %d numbers of the array\n", ARRAY_SIZE);
  get_numbers(array);
  print_array_type(array, ARRAY_SIZE);

  return 0;
}

void print_array_type(int array[], int size){
  int is_increasing = 1;
  int is_decreasing = 1;
  int is_constant = 1;
  int last_value = array[0];
  //no need for is_messed_up as its the negation of all three.

  //check the type of the array and store that in the flags
  //i = 0 was handled at initialization of last_value.
  for (int i = 1; i < size; i++){
    if (is_constant && last_value != array[i]){
      is_constant = 0;
    }
    if (is_increasing && last_value >= array[i]){
      is_increasing = 0;
    }
    if (is_decreasing && last_value <= array[i]){
      is_decreasing = 0;
    }

    if ((!is_decreasing) && (!is_increasing) && (!is_constant)){ // no need to continue the array if messed up
      break;
    }
  }

  //print the correct output.
  if(is_constant){
    printf("The array is constant");
  } else if(is_increasing){
    printf("The array is increasing");
  } else if(is_decreasing){
    printf("The array is decreasing");
  }else {
    printf("The array is messed up");
  }

  return;
}

void get_numbers(int array[ARRAY_SIZE]){
  int i = 0;
  while(i < ARRAY_SIZE){
    char input[MAX_DIGITS_IN_NUMBER+1] = {0};
    scanf("%s", input);
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