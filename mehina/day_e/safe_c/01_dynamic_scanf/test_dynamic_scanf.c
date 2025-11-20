/*------------------------------------------------------
* Filename: [dynamic_scanf.h]
* Description: [test dynamic_scanf]
* Author: [Kiran Kabaso]
-------------------------------------------------------*/


#include <stdio.h>
#include "dynamic_scanf.h"
#include <stdlib.h>
/*------------------------------------------------------
* Function Name - [main]
*
* Function Purpose - [test dynamic_scanf]
*
* Parameters –  NONE
*
* Return Values - [0]
*
* Author - [Kiran Kabaso]
-------------------------------------------------------*/
int main() {
  printf("please enter a string\n");
  char *ptr = dynamic_scanf();
  if (ptr == NULL){
    printf("alloc fail");
    return 1;
  }
  printf("the inputed string is:\n");
  printf("%s\n", ptr);
  free(ptr);
  // printf("the inputed elemets are:\n");
  // for (int i = 0; (*(ptr+i) != '\0') ; i++){
  //   printf("element is %c\n",*(ptr + i));
  // }
  return 0;
}