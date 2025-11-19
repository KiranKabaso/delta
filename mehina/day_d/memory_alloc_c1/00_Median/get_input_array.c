/*------------------------------------------------------
* Filename: [get_input_array.c]
* Description: [get an input array from the user and return it once the input is not an number]
* Author: [Kiran Kabaso]
-------------------------------------------------------*/

#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
#include "get_input_array.h"
#define ZERO_CHAR_VALUE_ASCII 48



array_struct get_input_array(){
  char input_char = 0;

  array_struct failed_return_value = {NULL, 0}; //return this on failure

  int *current_array_ptr = (int*)malloc(sizeof(int));
  if (current_array_ptr == NULL){
    return failed_return_value;
  }

  int current_array_size = 1;
  int count_array_members = 0;

  int next_number_to_insert = 0;
  int is_next_number_to_insert_empty = 1;

  do {
    scanf("%c", &input_char);
    if (isdigit(input_char)){ //update next number to insert
      is_next_number_to_insert_empty = 0;
      next_number_to_insert *= 10;
      next_number_to_insert += (input_char - ZERO_CHAR_VALUE_ASCII);//convert the char digit to int
    }
    else if (isspace(input_char) && !is_next_number_to_insert_empty){ //add the next number to the array

      if (count_array_members == current_array_size){//increase array size if needed
        //allocate a new array with more memory.
        int* current_array_ptr_tmp = (int*)malloc(sizeof(int)*current_array_size*2);
        if (current_array_ptr_tmp == NULL){
          return failed_return_value;
        }
        //copy the values to the new array
        for (int i = 0; i < count_array_members; i++){
          current_array_ptr_tmp[i] = current_array_ptr[i];
        }
        free(current_array_ptr);
        current_array_ptr = current_array_ptr_tmp;
        current_array_size *= 2;
      }

      //insert next_number_to_insert at the end
      *(current_array_ptr + count_array_members) = next_number_to_insert;
      ++count_array_members;
      //reset next_number_to_insert for the next number
      next_number_to_insert = 0;
      is_next_number_to_insert_empty = 1;
    }

  } while(isdigit(input_char) || isspace(input_char)); //condition

  //add the last next_number_to_insert.
  if (!is_next_number_to_insert_empty){

    if (count_array_members == current_array_size){ //increase array size if needed
      int* current_array_ptr_tmp = (int*)malloc(sizeof(int)*(current_array_size+1));
      if (current_array_ptr_tmp == NULL){
        return failed_return_value;
      }
      //copy the values to the new array
      for (int i = 0; i < count_array_members; i++){
        current_array_ptr_tmp[i] = current_array_ptr[i];
      }
      free(current_array_ptr);
      current_array_ptr = current_array_ptr_tmp;
      ++current_array_size;
    }

    //insert next_number_to_insert at the end
    *(current_array_ptr + count_array_members) = next_number_to_insert;
    ++count_array_members;
    //reset next_number_to_insert for the next number
    next_number_to_insert = 0;
    is_next_number_to_insert_empty = 1;
  }

  //return the array without the extra spaces for more members.
  //construct a new array without the extra spaces.
  int *new_array_ptr = (int*)malloc(sizeof(int)*count_array_members);
  if(new_array_ptr == NULL){
    return failed_return_value;
  }
  //copy the values to the new array
  for (int i = 0; i < count_array_members; i++){
    new_array_ptr[i] = current_array_ptr[i];
  }

  //free unneeded memory
  free(current_array_ptr);

  //construct the return value
  if (count_array_members != 0){
    array_struct return_value = {new_array_ptr, count_array_members};
    return return_value;
  }else {
    array_struct return_value = {new_array_ptr, 0};
    return return_value;

  }

}


//main function used to test the get_input_array_function
// int main() {
//   array_struct a = get_input_array();
//   if (a.size == 0){
//     printf("alloc fail");
//     return 1;
//   }
//   printf("the inputed elemets are:\n");
//   for (int i = 0; i < a.size ; i++){
//     printf("element is %d\n",*(a.array_ptr + i));
//   }
//   return 0;
// }