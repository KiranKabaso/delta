/*------------------------------------------------------
* Filename: [get_input_array.h]
* Description: [get an input array from the user and return it once the input is not an number]
* Author: [Kiran Kabaso]
-------------------------------------------------------*/

typedef struct{
  int* array_ptr;
  int size;
} array_struct;

/*------------------------------------------------------
* Function Name - [Function Name here]
*
* Function Purpose - [get an input array from the user and return it once the input is not an number]
*
* Parameters –  NONE
*
* Return Values - [OUT - array_struct -> [array_ptr , array size]]
*
* Author - [Kiran Kabaso]
-------------------------------------------------------*/
array_struct get_input_array();