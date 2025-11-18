/*------------------------------------------------------
* Filename: [encryption.c]
* Description: [implement and test the decryption function]
* Author: [Kiran Kabaso]
-------------------------------------------------------*/

#include <stdio.h>
#define DECRYPT_MOVE_FORWARD_STEPS 5
#define DECRYPT_MOVE_BACKWARDS_STEPS 4
#define DECRYPT_DIVISION_BY 7
#define DECRYPT_DECREASE_AMOUNT 5

#define MESSAGE_LENGTH 26

/*------------------------------------------------------
* Function Name - [switch_halfs]
*
* Function Purpose - [switches the first and second half of the array]
*
* Parameters –  [IN - int array[]]
*
* Return Values - NONE
*
* Author - [Kiran Kabaso]
-------------------------------------------------------*/
void switch_halfs(int array[]);

/*------------------------------------------------------
* Function Name - [decrease_with_previous]
*
* Function Purpose - [from the (first_index) it decreases all members by the previous member circularly (not including first_index)]
*
* Parameters –  [IN - int array[], IN - int first_index]
*
* Return Values - NONE
*
* Author - [Kiran Kabaso]
-------------------------------------------------------*/
void decrease_with_previous(int array[], int first_index);

/*------------------------------------------------------
* Function Name - [circular_move_steps_backwards]
*
* Function Purpose - [shift the array (steps) steps backwards]
*
* Parameters –  [IN - int array[], IN - int steps]
*
* Return Values - NONE
*
* Author - [Kiran Kabaso]
-------------------------------------------------------*/
void circular_move_steps_backwards(int array[], int steps);

/*------------------------------------------------------
* Function Name - [divide_at_even_indexes]
*
* Function Purpose - [divide all members at an even index of the array by devisor]
*
* Parameters –  [IN - int array[], IN - int devisor]
*
* Return Values - NONE
*
* Author - [Kiran Kabaso]
-------------------------------------------------------*/
void divide_at_even_indexes(int array[], int devisor);

/*------------------------------------------------------
* Function Name - [decrease_all_members]
*
* Function Purpose - [decrease all members of the array by the amount]
*
* Parameters –  [IN - int array[], IN - int amount]
*
* Return Values - NONE
*
* Author - [Kiran Kabaso]
-------------------------------------------------------*/
void decrease_all_members(int array[], int amount);

/*------------------------------------------------------
* Function Name - [convert_array_int_to_char]
*
* Function Purpose - [transfers the sources array value from int to char and puts it in target]
*
* Parameters –  [IN - char target[], IN - int source[]]
*
* Return Values - NONE
*
* Author - [Kiran Kabaso]
-------------------------------------------------------*/
void convert_array_int_to_char(char target[], int source[]);

/*------------------------------------------------------
* Function Name - [decryption]
*
* Function Purpose - [decrypts an array of numbers and prints the decrypted message]
*
* Parameters –  [IN - int array[]]
*
* Return Values - NONE
*
* Author - [Kiran Kabaso]

to decrypt the function will perform all encryption steps in revers.
the decryption will perform the following steps.
switch first and second half.
decrease every member with its previous member in order from the start.
move all members in circular DECRYPT_MOVE_FORWARD_STEPS steps forward.
divide every number in an even index by DECRYPT_DIVISION_BY.
move all members in circular DECRYPT_MOVE_BACKWARDS_STEPS steps backwards.
decrease all members by DECRYPT_DECREASE_AMOUNT.
change all numbers to their matching chars.
end decryption.
-------------------------------------------------------*/
void decryption(int array[]);
/*------------------------------------------------------
* Function Name - [main]
*
* Function Purpose - [test the decryption function]
*
* Parameters –  NONE
*
* Return Values - [0]
*
* Author - [Kiran Kabaso]
-------------------------------------------------------*/
int main() {
    int input_array[MESSAGE_LENGTH] = {0};
    for (int i = 0; i < MESSAGE_LENGTH; i++){
      scanf("%d", input_array+i);
    }
    decryption(input_array);

    return 0;
}

void decryption(int array[]){
  char decrypted_word[MESSAGE_LENGTH+1] = {0};
  switch_halfs(array);
  decrease_with_previous(array, 0);
  circular_move_steps_backwards(array, (MESSAGE_LENGTH-DECRYPT_MOVE_FORWARD_STEPS));
  divide_at_even_indexes(array, DECRYPT_DIVISION_BY);
  circular_move_steps_backwards(array, DECRYPT_MOVE_BACKWARDS_STEPS);
  decrease_all_members(array, DECRYPT_DECREASE_AMOUNT);

  convert_array_int_to_char(decrypted_word, array);

  printf("%s", decrypted_word);

  return;
}

void switch_halfs(int array[]){
  int tmp[MESSAGE_LENGTH/2] = {0};

  //store the first half;
  for (int i = 0; i < MESSAGE_LENGTH/2; i++){
    tmp[i] = array[i];
  }

  //switch the values
  for (int i = 0; i < MESSAGE_LENGTH - MESSAGE_LENGTH/2; i++){
    if (!(MESSAGE_LENGTH%2)){
      array[i] = array[i + (MESSAGE_LENGTH - MESSAGE_LENGTH/2)];
      array[i + (MESSAGE_LENGTH - MESSAGE_LENGTH/2)] = tmp[i];
    }
    else{
      array[i] = array[i + (MESSAGE_LENGTH - MESSAGE_LENGTH/2) + 1];
      array[i + (MESSAGE_LENGTH - MESSAGE_LENGTH/2) + 1] = tmp[i];
    }

  }

  return;
}

void decrease_with_previous(int array[], int first_index){
  for (int i = first_index+1; i < MESSAGE_LENGTH; i++){
    array[i] -= array[i-1];
  }
  if (first_index != 0){
    array[0] -= array[MESSAGE_LENGTH-1];
  }
  for (int i = 1; i < first_index; i++){
    array[i] -= array[i-1];
  }

  return;
}

void circular_move_steps_backwards(int array[], int steps){
  int array_copy[MESSAGE_LENGTH] = {0};
  //save a copy of the array
  for (int i = 0; i < MESSAGE_LENGTH; i++){
    array_copy[i] = array[i];
  }

  //transfer from the copy so no values would be overwritten before their transfer.
  for (int i = 0; i < MESSAGE_LENGTH; i++){
    array[i] = array_copy[((i+steps)%MESSAGE_LENGTH)];
  }

  return;
}

void divide_at_even_indexes(int array[], int devisor){
  for (int i = 0 ; i < MESSAGE_LENGTH ; i = (i + 2)){
    array[i] /= devisor;
  }

  return;
}

void decrease_all_members(int array[], int amount){
  for (int i = 0 ; i < MESSAGE_LENGTH ; i++){
    array[i] -= amount;
  }

  return;
}

void convert_array_int_to_char(char target[], int source[]){
  for (int i = 0 ; i < MESSAGE_LENGTH ; i++){
    target[i] = source[i];
  }

  return;
}