/*------------------------------------------------------
* Filename: [test_pointer_array_sort.c]
* Description: [test pointer_array_sort]
* Author: [Kiran Kabaso]
-------------------------------------------------------*/

#include "dynamic_scanf.h"
#include "pointer_array_sort.h"
#include <stdio.h>
#include <ctype.h>

#define ARRAY_SIZE 5

/*------------------------------------------------------
* Function Name - [compare_by_alphabet]
*
* Function Purpose - [compares between two strings by length]
*
* Parameters –  [IN: const void* str1, IN: const void* str2]
*
* Return Values - [1 -if str1 is first in alphabetical order, -1 if opposite, 0 if equal in alphabetical order]
*
* Author - [Kiran Kabaso]
*alphabetical order - (a to z upper case wins on tie, if both strings tie the shorter wins, the rest doesn't affect the order)
-------------------------------------------------------*/
int compare_by_alphabet(const void* str1, const void* str2);

/*------------------------------------------------------
* Function Name - [compare_by_length]
*
* Function Purpose - [compares between two strings by length]
*
* Parameters –  [IN: const void* str1, IN: const void* str2]
*
* Return Values - [1 -if str1 is longer then str2, -1 if opposite, 0 if equal length]
*
* Author - [Kiran Kabaso]
-------------------------------------------------------*/
int compare_by_length(const void* str1, const void* str2);

/*------------------------------------------------------
* Function Name - [print_pointers_array]
*
* Function Purpose - [print the items a pointer array points to]
*
* Parameters –  [IN: char** ptr_array, IN: int size - array size]
*
* Return Values - NONE
*
* Author - [Kiran Kabaso]
-------------------------------------------------------*/
void print_pointers_array(char** ptr_array, int size);

/*------------------------------------------------------
* Function Name - [main]
*
* Function Purpose - [test pointer_array_sort]
*
* Parameters –  NONE
*
* Return Values - [0]
*
* Author - [Kiran Kabaso]
-------------------------------------------------------*/
int main() {
  char* string_array[ARRAY_SIZE] = {NULL};

  //get input
  for (int i = 0; i < ARRAY_SIZE ; i++){
    printf("Enter a string: ");
    char* str = dynamic_scanf();
    if (str == NULL){
      printf("alloc fail");
      return 1;
    }
    string_array[i] = str;
  }

  pointer_array_sort((void*)string_array, ARRAY_SIZE, compare_by_alphabet);
  print_pointers_array(string_array, ARRAY_SIZE);
  pointer_array_sort((void*)string_array, ARRAY_SIZE, compare_by_length);
  print_pointers_array(string_array, ARRAY_SIZE);

  return 0;
}

int compare_by_alphabet(const void* str1, const void* str2){
  char* char_str1 = (char*)str1;
  char* char_str2 = (char*)str2;
  int i = 0;
  while(1){
    if ((char_str1[i] == '\0') && (char_str2[i] == '\0')){
      return 0;
    } else if(char_str1[i] == '\0'){
      return 1;
    } else if(char_str2[i] == '\0'){
      return -1;
    }//both strings don't end at this char check if both are alphabet
    else if ((isalpha(char_str1[i]) != 0) && (isalpha(char_str2[i]) != 0)){ //case where both are alphabet
      if (tolower(char_str1[i]) == tolower(char_str2[i])){ //both are the same letter
        if (isupper(char_str1[i]) && islower(char_str2[i])){
          return 1;
        } else if (isupper(char_str2[i]) && islower(char_str1[i])){
          return -1;
        } //else they are the samecontinue with i++
      } else if (tolower(char_str1[i]) < tolower(char_str2[i])){ // one has a smaller letter
        return 1;
      } else if (tolower(char_str1[i]) > tolower(char_str2[i])){ // one has a smaller letter
        return -1;
      }
    }else if((isalpha(char_str1[i]) != 0)){ //only one is alphabet
      return 1;
    }else if((isalpha(char_str2[i]) != 0)){ //only one is alphabet
        return -1;
    } else{ //both letters are not alphabet -> equal order
      return 0;
    }
    i++;
  }
}

int compare_by_length(const void* str1, const void* str2){
  char* char_str1 = (char*)str1;
  char* char_str2 = (char*)str2;

  int i = 0;
  while(1){
    if ((char_str1[i] == '\0') && (char_str2[i] == '\0')){
      return 0;
    }else if(char_str1[i] == '\0'){
      return -1;
    }else if(char_str2[i] == '\0'){
      return 1;
    }
    i++;
  }
}

void print_pointers_array(char** ptr_array, int size){
  int i = 0;
  for (int i = 0; i < size; i++){
    printf("%s", ptr_array[i]);
    if (i+1 != size){
      printf(",");
    }
  }
  printf("\n");
}