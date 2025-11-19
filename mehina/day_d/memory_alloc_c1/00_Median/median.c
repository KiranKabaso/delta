/*------------------------------------------------------
* Filename: [median.c]
* Description: [get an input array from the user and print its median]
* Author: [Kiran Kabaso]
-------------------------------------------------------*/
#define ZERO_CHAR_VALUE_ASCII 48

#include "get_input_array.h"
#include <stdio.h>
#include <stdlib.h>
/*------------------------------------------------------
* Function Name - [main]
*
* Function Purpose - [get an input array from the user and print its median]
*
* Parameters – NONE
*
* Return Values - [0]
*
* Author - [Kiran Kabaso]
-------------------------------------------------------*/
int main() {
  array_struct numbers_array = get_input_array();

  if (numbers_array.array_ptr == NULL){
    printf("alloc fail");
    return 1;
  }

  if (!numbers_array.size){ //if there are no elements
    printf("no numbers were inputted\n");
    return 0;
  }

  //sort the array
  for (int i = 0; i < numbers_array.size; i++){
    for (int j = i+1; j < numbers_array.size; j++){
      if (numbers_array.array_ptr[i] > numbers_array.array_ptr[j]){
        //swap
        int tmp = numbers_array.array_ptr[i];
        numbers_array.array_ptr[i] = numbers_array.array_ptr[j];
        numbers_array.array_ptr[j] = tmp;
      }
    }
  }

  //print the median
  if (!(numbers_array.size %2)){//even array
    float median = (numbers_array.array_ptr[numbers_array.size/2 - 1] + (numbers_array.array_ptr[numbers_array.size/2])) / (float)2;
    printf("the median is the average of %d and %d = %.2f", numbers_array.array_ptr[numbers_array.size/2-1], numbers_array.array_ptr[numbers_array.size/2], median);
  }else{ //odd
    printf("the median is the %d'th element: %d", numbers_array.size/2 + 1, numbers_array.array_ptr[numbers_array.size/2]);
  }

  free(numbers_array.array_ptr);

  return 0;
}
