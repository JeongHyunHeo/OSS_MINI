#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "base.h"
#include "extras.h"
#include "record.h"

#define MAX_RECORDS 1000
#define FILE_NAME "record.txt"
FILE* fp = NULL;

void input_handler(char[], Record records[], int* count);
void display_menu();

int count = 0;
int saveFile(Record records[], int* count);

// main function
int main(){
  Record records[MAX_RECORDS];

  int count = openFile(records);

  char user_input[64] = "";
  while(strcmp(user_input, "99") != 0){
    display_menu();
    printf("\nSelect a menu> ");
    fgets(user_input, 64, stdin);
    user_input[strlen(user_input)-1] = '\0';
    input_handler(user_input, records, count);
  }

  return 0;
}


// Function: input_handler()
// Input: record - array of Records; this may contain empty elements in the middle
// Output: none
// - Handles the user input and invokes functions that correspond to the user input
void input_handler(char input[], Record records[], int* count){

    if(!strcmp(input, "1"))
        print_book(records, count);
    if(!strcmp(input, "2"))
        add_book(records, count);
    if(!strcmp(input, "3"))
        search_book(records, count);
    if(!strcmp(input, "4"))
        delete_book(records, count);
    if(!strcmp(input, "5"))
        defragmentation(records, count);
    if(!strcmp(input, "6"))
        sort(records, count);
    else if(!strcmp(input, "99")){
      saveFile(records, count);
      printf("Terminating... bye!\n");
    }
    else
        printf("Unknown menu: %s \n\n", input);
}



// Function: display_menu()
// Input: none
// Output: none
void display_menu(){

    // TODO: Modify this function as you need
    printf("******************************\n");
    printf("Book Management System \n");
    printf("******************************\n");
    printf(" 1. List all\n");
    printf(" 2. Add books\n");
    printf(" 3. Search\n");
    printf(" 4. Delete books\n");
    printf(" 5. defragment space\n");
    printf(" 6. sort data in alphabetical order\n");
    printf(" 99. Quit\n");
}
