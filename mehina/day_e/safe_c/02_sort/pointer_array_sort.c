/*------------------------------------------------------
* Filename: [pointer_array_sort.c]
* Description: [sorts an array of pointers to objects given a compare function]
* Author: [Kiran Kabaso]
-------------------------------------------------------*/

#include "pointer_array_sort.h"
/*------------------------------------------------------
* Function Name - [swap]
*
* Function Purpose - [swap to void* pointers]
*
* Parameters –  [IN: void** ptr_array - the array, IN: int index1 - first element index, IN: int index1 - second element index]
*
* Return Values - NONE
*
* Author - [Kiran Kabaso]
-------------------------------------------------------*/
void swap(void** ptr_array, int index1, int index2);

void pointer_array_sort(void** ptr_array, int ptr_array_size, int compare(const void*, const void*)) {
  for (int i = 0; i < ptr_array_size; i++){
    for (int j = i; j < ptr_array_size; j++){
      if(compare(ptr_array[i], ptr_array[j]) < 0){
        swap(ptr_array, i, j);
      }
    }
  }
  return;
}

void swap(void** ptr_array, int index1, int index2){
  void* tmp = ptr_array[index1];
  ptr_array[index1] = ptr_array[index2];
  ptr_array[index2] = tmp;
  return;
}