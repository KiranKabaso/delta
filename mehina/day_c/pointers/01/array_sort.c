/*------------------------------------------------------
* Filename: [array_sort]
* Description: [get an array and sort an array of pointers to its members]
* Author: [Kiran Kabaso]
-------------------------------------------------------*/

#include <stdio.h>
#include <ctype.h>

#define ARRAY_SIZE 10
#define MAX_DIGITS_IN_NUMBER 100
#define ZERO_CHAR_VALUE_ASCII 48

/*------------------------------------------------------
* Function Name - [sort_array]
*
* Function Purpose - [sort the pointers array]
*
* Parameters –  [IN - int array[] -> array of the pointed values, const int *ptrs_array[] -> the array of the pointers(to be sorted)]
*
* Return Values - NONE
*
* Author - [Kiran Kabaso]
-------------------------------------------------------*/
void sort_array(int array[], const int *ptrs_array[]);

/*------------------------------------------------------
* Function Name - [swap]
*
* Function Purpose - [swap between two pointer in the array]
*
* Parameters –  [IN - const int *ptrs_array[] -> the pointers array, IN - int index_1, IN - int index_2]
*
* Return Values - NONE
*
* Author - [Kiran Kabaso]
-------------------------------------------------------*/
void swap(const int *ptrs_array[], int index_1, int index_2);

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
int main() {

  int array[ARRAY_SIZE] = {0};
  const int *ptrs_array[ARRAY_SIZE] = {0};

  //fill ptr array
  for (int i = 0; i < ARRAY_SIZE; i++){
    ptrs_array[i] = array + i;
  }

  //get user input
  get_numbers(array);

  //print the array before the sort
  printf("the pointers array saved addresses and the values in them:\n");
  printf("[\n");
  for (int i = 0; i < ARRAY_SIZE; i++){
    printf("(value: %d address: %x)\n", *ptrs_array[i], ptrs_array[i]);
  }
  printf("]\n");

  //sort
  sort_array(array, ptrs_array);

  //print the array after the sort
  printf("the sorted array is:\n[\n");
  for (int i = 0; i < ARRAY_SIZE; i++){
    printf("(value: %d address: %x)\n", *ptrs_array[i], ptrs_array[i]);
  }
  printf("]\n");

  return 0;
}

void sort_array(int array[], const int *ptrs_array[]){
  for (int i = 0; i < ARRAY_SIZE; i++){
    for (int j = i+1; j < ARRAY_SIZE; j++){
      if (*ptrs_array[i] > *ptrs_array[j]){
        swap(ptrs_array, i, j);
      }
    }
  }
}

void swap(const int *ptrs_array[], int index_1, int index_2){
  const int *tmp = ptrs_array[index_1];
  ptrs_array[index_1] = ptrs_array[index_2];
  ptrs_array[index_2] = tmp;
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