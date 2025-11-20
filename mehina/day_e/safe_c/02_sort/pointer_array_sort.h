/*------------------------------------------------------
* Filename: [pointer_array_sort.h]
* Description: [sorts an array of pointers to objects given a compare function]
* Author: [Kiran Kabaso]
-------------------------------------------------------*/

/*------------------------------------------------------
* Function Name - [pointer_array_sort]
*
* Function Purpose - [sorts an array of pointers to objects given a compare function]
*
* Parameters –  [
* IN: void** ptr_array - pointer to an array of pointers,
* IN: int ptr_array_size - the pointers array size,
* IN: int compare(void*, void*) - a function pointer that returns a number grater then 0 if the first pointer points to a something grater then the one the second pointer points to]
*
* Return Values - NONE
*
* Author - [Kiran Kabaso]
-------------------------------------------------------*/
void pointer_array_sort(void** ptr_array, int ptr_array_size, int compare(const void*, const void*));
