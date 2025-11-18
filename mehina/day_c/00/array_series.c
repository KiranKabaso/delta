/*------------------------------------------------------
* Filename: [array_series]
* Description: [test a function that gets an array of numbers and prints if its increasing, decreasing, constant or messed up]
* Author: [Kiran Kabaso]
-------------------------------------------------------*/

#include <stdio.h>

#define INPUT_ARRAY_SIZE 15
void print_array_type(int array[], int size);


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
  int array[INPUT_ARRAY_SIZE] = {0};
  printf("please enter the %d numbers of the array\n", INPUT_ARRAY_SIZE);
  for (int i = 0; i < INPUT_ARRAY_SIZE ; i++){
    scanf("%d", array + i);
  }
  print_array_type(array, INPUT_ARRAY_SIZE);

  return 0;
}




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
  } else if(is_increasing){
    printf("The array is decreasing");
  }else {
    printf("The array is messed up");
  }

  return;
}