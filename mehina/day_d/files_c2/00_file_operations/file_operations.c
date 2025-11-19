/*------------------------------------------------------
* Filename: [file_operations.c]
* Description: [Brief description of the program here]
* Author: [Kiran Kabaso]
-------------------------------------------------------*/

#include <stdio.h>

#define MAX_INPUT_STRING_LENGTH 100

void print_file_to_screen(const char *file_name);
void copy_file(const char *file_name1, const char *file_name2);
void print_file_stats(const char* file_name);
/*------------------------------------------------------
* Function Name - [main]
*
* Function Purpose - [demonstrates proper documentation]
*
* Parameters –  [file_name]
*
* Return Values - [0]
*
* Author - [Kiran Kabaso]
-------------------------------------------------------*/
int main(int argc, char *argv[]) {
  if(argc < 2){
    printf("please enter two file names after file_operations.exe\n");
    return 1;
  }

  char* file_name1 = argv[1];
  char* file_name2 = argv[2];
  //Q1
  printf("Q1\n");
  printf("starting print_file_to_screen on %s\n", file_name1);
  print_file_to_screen(file_name1);

  //Q2
  printf("Q2\n");
  printf("copying file %s to file %s\n", file_name1, file_name2);
  copy_file(file_name1, file_name2);
  printf("printing %s\n", file_name2);
  print_file_to_screen(file_name2);
  //Q3
  // printf("Q3\n");
  // printf("printing stats of file %s\n", file_name1);
  // print_file_stats(file_name1);
  // //Q4
  // printf("Q4\n");
  // printf("deleting one line from: %s\n", file_name2);
  // printf("please enter a line number to delete(from 0):\n");
  // int number = get_number();
  // printf("deleting line %d from: %s\n", &number, file_name2);
  // delete(file_name2, number);
  // printf("printing %s\n", file_name2);
  // //Q5
  // printf("Q5\n");
  // printf("checking string count in file: %s", file_name2);
  // char *string = get_string_from_user();
  // // printf("please enter a string to check in under %d chars:\n", MAX_INPUT_STRING_LENGTH);
  // int count_instances = count_string_in_file(file_name2, string);
  // printf("the string %s appears %d times in %s\n", string, count_instances, file_name2);

  return 0;
}


void print_file_to_screen(const char *file_name){
  FILE* file = fopen(file_name, "r");
  if (file == NULL){
    printf("could'nt open %s\n", file_name);
    return;
  }
  char read_char = 0;
  do{
    read_char = fgetc(file);
    if(read_char != EOF){
      printf("%c", read_char);
    }
  } while(read_char != EOF);

  if (fclose(file) != 0){
    printf("could'nt close %s\n", file_name);
    return;
  }

  return;
}

void copy_file(const char *file_name1, const char *file_name2){
  //open files
  FILE* file1 = fopen(file_name1, "r");
  if (file1 == NULL){
    printf("could'nt open %s\n", file_name1);
    return;
  }

  FILE* file2 = fopen(file_name2, "w");
  if (file2 == NULL){
    printf("could'nt open %s\n", file_name2);
    return;
  }

  char read_char = 0;
  do{
    read_char = fgetc(file1);
    if(read_char != EOF){
      fputc(read_char, file2);
    }
  } while(read_char != EOF);


  if (fclose(file1) != 0){
    printf("could'nt close %s\n", file_name1);
    if (fclose(file2) != 0){
      printf("could'nt close %s\n", file_name2);
    }
    return;
  }

  if (fclose(file2) != 0){
    printf("could'nt close %s\n", file_name2);
    return;
  }

  return;
}

// void print_file_stats(const char* file_name){
//   int char_count = 0;
//   int word_count = 0;
//   int line_count = 0;

//   int is_last_char_space = 0;
//   int is_last_char_new_line = 0;

//   FILE* file = fopen(file_name, "r");
//   if (file == NULL){
//     printf("could'nt open %s\n", file_name);
//     return;
//   }

//   int char_count = 0;
//   int word_count = 0;
//   int line_count = 0;



//   if (fclose(file) != 0){
//     printf("could'nt close %s\n", file_name);
//     return;
//   }

//   return;

// }