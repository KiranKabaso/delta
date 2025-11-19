/*------------------------------------------------------
* Filename: [dynamic_struct.c]
* Description: [get two times from the user and add them]
* Author: [Kiran Kabaso]
-------------------------------------------------------*/

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

typedef struct{
  int hour;
  int minute;
  int second;
}day_time;

#define MAX_DIGITS_IN_NUMBER 100
#define ZERO_CHAR_VALUE_ASCII 48

/*------------------------------------------------------
* Function Name - [print_time]
*
* Function Purpose - [print the time]
*
* Parameters –  [day_time *day_time_ptr -> ptr to the time]
*
* Return Values - NONE
*
* Author - [Kiran Kabaso]
-------------------------------------------------------*/
void print_time(day_time *day_time_ptr);

/*------------------------------------------------------
* Function Name - [add_times]
*
* Function Purpose - [add two times and return a pointer to their sum]
*
* Parameters –  [day_time *day_time1 -> ptr to the time, [day_time *day_time2 -> ptr to the time]]
*
* Return Values - [day_time time -> [12, 12, 12] is equal to the time 12:12:12]
*
* Author - [Kiran Kabaso]
-------------------------------------------------------*/
day_time *add_times(day_time *time1, day_time *time2);

/*------------------------------------------------------
* Function Name - [get_time]
*
* Function Purpose - [gets a day_time from the user]
*
* Parameters –  NONE
*
* Return Values - [day_time time -> [12, 12, 12] is equal to the time 12:12:12]
*
* Author - [Kiran Kabaso]
-------------------------------------------------------*/
day_time* get_time();

/*------------------------------------------------------
* Function Name - [get_number_input]
*
* Function Purpose - [gets a number from the user]
*
* Parameters –  NONE
*
* Return Values - [int number]
*
* Author - [Kiran Kabaso]
-------------------------------------------------------*/
int get_number_input();

/*------------------------------------------------------
* Function Name - [is_number]
*
* Function Purpose - [check if a string represents a number]
*
* Parameters –  [IN - const char string[ARRAY_SIZE] -> "123"]
*
* Return Values - [1, 0]
*
* Author - [Kiran Kabaso]
-------------------------------------------------------*/
int is_number(const char* string);

/*------------------------------------------------------
* Function Name - [number_from_string]
*
* Function Purpose - [convert a string representation of a number and return the int representation]
*
* Parameters –  [IN - const char string[ARRAY_SIZE] -> "123"]
*
* Return Values - [int number -> 123]
*
* Author - [Kiran Kabaso]
-------------------------------------------------------*/
int number_from_string(const char* string);

/*------------------------------------------------------
* Function Name - [main]
*
* Function Purpose - [get two times from the user and add them]
*
* Parameters –  NONE
*
* Return Values - [0]
*
* Author - [Kiran Kabaso]
-------------------------------------------------------*/
int main() {
  printf("please enter a day time:\n");
  day_time *time1 = get_time();
  printf("please enter a day time:\n");
  day_time *time2 = get_time();
  if (!time1 || !time2){
    printf("alloc fail\n");
    return 1;
  }

  day_time *time3 = add_times(time1, time2);
  if (!time3){
    printf("alloc fail\n");
    return 1;
  }

  printf("the first time is:\n");
  print_time(time1);
  printf("the second time is:\n");
  print_time(time2);
  printf("the sum time is:\n");
  print_time(time3);

  free(time1);
  free(time2);
  free(time3);
  return 0;
}

void print_time(day_time *day_time_ptr){
  printf("time: %d:%d:%d\n", day_time_ptr->hour, day_time_ptr->minute, day_time_ptr->second);
}

day_time *add_times(day_time *time1, day_time *time2){
  day_time *time_ptr = (day_time*)malloc(sizeof(day_time));
  if (time_ptr == NULL){
    return NULL;
  }

  time_ptr->hour = (time1->hour + time2->hour)%24;
  time_ptr->minute = (time1->minute + time2->minute)%60;
  time_ptr->second = (time1->second + time2->second)%60;

  return time_ptr;
}


day_time* get_time(){
  int hour = 0;
  int minute = 0;
  int second = 0;

  //hour
  while(1){
    printf("please enter the hour\n");
    hour = get_number_input();
    if (hour >= 24 || hour < 0){
      printf("The hour mast be between 0 and 23. Please enter again\n");
      continue;
    }
    break;
  }

  //minute
  while(1){
    printf("please enter the minute\n");
    minute = get_number_input();
    if (minute >= 60 || minute < 0){
      printf("The minute mast be between 0 and 59. Please enter again\n");
      continue;
    }
    break;
  }

  //second
  while(1){
    printf("please enter the second\n");
    second = get_number_input();
    if (second >= 60 || second < 0){
      printf("The second mast be between 0 and 59. Please enter again\n");
      continue;
    }
    break;
  }

  day_time *time_ptr = (day_time*)malloc(sizeof(day_time));
  if (time_ptr == NULL){
    return NULL;
  }
  time_ptr->hour = hour;
  time_ptr->minute = minute;
  time_ptr->second = second;
  return time_ptr;
}

int get_number_input(){
  while(1){
    char string[MAX_DIGITS_IN_NUMBER+1] = {0};
    scanf("%s", string);
    //check the input is valid
    if(string[MAX_DIGITS_IN_NUMBER] != 0){
      printf("please enter a number with %d digits or less\n", MAX_DIGITS_IN_NUMBER);
      continue;
    }
    if (!is_number(string)){
      printf("please enter a number\n");
      continue;
    }
    //input is a number return
    return number_from_string(string);
  }
}



int is_number(const char* string){
  int i = 0;
  while (1){
    if (string[i] == '\0'){
      break;
    }
    if (!(isdigit(string[i]))){
      return 0;
    }
    ++i;
  }
  return 1;
}

int number_from_string(const char* string){
  int number = 0;
  int i = 0;
  while(1){
    if (string[i] == '\0'){
      break;
    }
    number *= 10;
    number += string[i] - ZERO_CHAR_VALUE_ASCII;
    ++i;
  }
  return number;
}