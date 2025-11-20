/*------------------------------------------------------
* Filename: [dynamic_scanf.c]
* Description: [get an input string from the user]
* Author: [Kiran Kabaso]
-------------------------------------------------------*/

#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
#include "dynamic_scanf.h"
#define NEW_LINE 10


char* dynamic_scanf(){
  int input_char = 0;

  char* failed_return_value = NULL; //return this on failure

  char *current_array_ptr = (char*)malloc(sizeof(char));
  if (current_array_ptr == NULL){
    return failed_return_value;
  }

  unsigned int current_array_size = 1;
  unsigned int count_array_members = 0;

  do {
    input_char = getchar();
    if (input_char != NEW_LINE && input_char != EOF){
      if (count_array_members == current_array_size){//increase array size if needed
        //allocate a new array with more memory.
        if ((int)current_array_size < 0){ //check current_array_size will survive int conversion
          free(current_array_ptr);
          return failed_return_value;
        }
        char* current_array_ptr_tmp = (char*)malloc(sizeof(char)*((int)current_array_size)*2);
        if (current_array_ptr_tmp == NULL){
          free(current_array_ptr);
          return failed_return_value;
        }
        //copy the values to the new array
        for (int i = 0; i < count_array_members; i++){
          current_array_ptr_tmp[i] = current_array_ptr[i];
        }
        free(current_array_ptr);
        current_array_ptr = current_array_ptr_tmp;
        current_array_size *= 2U;
      }

      if ((int)count_array_members < 0){ //check count_array_members will survive int conversion
          free(current_array_ptr);
          return failed_return_value;
      }
      *(current_array_ptr + (int)count_array_members) = input_char;
      ++count_array_members;
    }


  } while(input_char != NEW_LINE && input_char != EOF); //condition

  //return the array without the extra spaces for more members.
  //construct a new array without the extra spaces. add 1 space for '\0'.

  if ((int)count_array_members < 0){ //check count_array_members will survive int conversion
    free(current_array_ptr);
    return failed_return_value;
  }
  char *new_array_ptr = (char*)malloc(sizeof(char)*((int)count_array_members) + 1); //add 1 for '\0'
  if(new_array_ptr == NULL){
    free(current_array_ptr);
    return failed_return_value;
  }
  //copy the values to the new array
  for (int i = 0; i < count_array_members; i++){
    new_array_ptr[i] = current_array_ptr[i];
  }
  new_array_ptr[count_array_members] = '\0'; //set the added char to '\0'.

  //free unneeded memory
  free(current_array_ptr);

  return new_array_ptr;
}
