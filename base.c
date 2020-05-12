#include <stdio.h>
#include <string.h>

#include "base.h"

void print_book(Record records[], int* count){

  printf("=========================\n");
  printf("Book Management System : List all\n");
  printf("=========================\n");

  int i = 0;

  printf("ID\t\tName\t\tAuthor\t\tGenre\t\tQuantity\t\tISBN");
  while(i < *count){
    printf("%s\t\t%s\t\t%s\t\t%d\t\t%s\n", records[i].bookname, records[i].author, records[i].genre, records[i].quantity, records[i].isbn);;
    i++;
  }

  if(count == 0){
    printf("No records");
  }
}

void add_book(Record records[], int* count){
  int add = 0;
  int i = *count;

  printf("=========================\n");
  printf("Book Management System : Add books\n");
  printf("=========================\n");
  while(add == 1){
    printf("Book name: ");
    scanf("%s", records[i].bookname);
    printf("author: ");
    scanf("%s", records[i].author);
    printf("Genre: ");
    scanf("%s", records[i].genre);
    printf("Quantity: ");
    scanf("%d", &records[i].quantity);
    printf("ISBN: ");
    scanf("%s", records[i].isbn);
    *count++;

    printf("Add more?(Yes: 1, No:0):");
    scanf("%d", &add);
    }

  return;
}

void search_book(Record records[], int* count){
    char comm_num;
    char command_name;
    int comm;
    int i;

    if (&count > 0){
        printf("=========================\n");
          printf("Book Management System : Search books\n");
          printf("=========================\n");
        printf("1)by Bookname\n");
        printf("2)by Author\n");
        printf("3)by Genre\n");
        printf("4)by quantity\n");
        printf("5)by isbn\n");
        printf("-------------------------\n");
        printf("command> ");
        scanf("%s", &comm_num);
        printf("\n");

        switch(comm_num){
            case '1' :
                printf("========================\n");
                  printf("Book Management System : Search books by name\n");
                printf("========================\n");
                printf("Bookname: ");
                scanf("%s",&command_name);
                printf("\n");
                printf("ID\t\tName\t\tAuthor\t\tGenre\t\tQuantity\t\tISBN");

                for(i = 0 ; i < *count; i++){
                    if(!strcmp(&command_name, records[i].bookname)){
                        printf("%s\t\t\t%s\t\t%s\t\t%d\t%s\n", records[i].bookname, records[i].author, records[i].genre, records[i].quantity, records[i].isbn);
                    }
                    else
                        continue;
                }
                break;
            case '2' :
                printf("========================\n");
                printf("Book Management System : Search books by author\n");
                printf("========================\n");
                printf("FamilyName> ");
                scanf("%s",&command_name);
                printf("\n");
                printf("ID\t\tName\t\tAuthor\t\tGenre\t\tQuantity\t\tISBN");

                for(i = 0 ; i < *count; i++){
                    if(!strcmp(&command_name, records[i].author)){
                        printf("%s\t\t\t%s\t\t%s\t\t%d\t%s\n", records[i].bookname, records[i].author, records[i].genre, records[i].quantity, records[i].isbn);
                    }
                    else
                        continue;
                }
                break;
            case '3' :
                printf("========================\n");
                printf("Book Management System : Search books by genre\n");
                printf("========================\n");
                printf("Age> ");
                scanf("%s",&command_name);
                printf("\n");
                printf("ID\t\tName\t\tAuthor\t\tGenre\t\tQuantity\t\tISBN");

                for(i = 0 ; i < *count; i++){
                    if(!strcmp(&command_name, records[i].genre)){
                        printf("%s\t\t\t%s\t\t%s\t\t%d\t%s\n", records[i].bookname, records[i].author, records[i].genre, records[i].quantity, records[i].isbn);
                    }
                    else
                        continue;
                }
                break;
            case '4' :
                printf("========================\n");
                printf("Book Management System : Search books by quantity\n");
                printf("========================\n");
                printf("Gender> ");
                scanf("%d",&comm);
                printf("\n");
                printf("ID\t\tName\t\tAuthor\t\tGenre\t\tQuantity\t\tISBN");

                for(i = 0 ; i < *count; i++){
                    if(comm == records[i].quantity){
                        printf("%s\t\t\t%s\t\t%s\t\t%d\t%s\n", records[i].bookname, records[i].author, records[i].genre, records[i].quantity, records[i].isbn);
                    }
                    else
                        continue;
                }
                break;
            case '5' :
                printf("========================\n");
                printf("Book Management System : Search books by isbn\n");
                printf("========================\n");
                printf("Gender> ");
                scanf("%s",&command_name);
                printf("\n");
                printf("ID\t\tName\t\tAuthor\t\tGenre\t\tQuantity\t\tISBN");

                for(i = 0 ; i < *count; i++){
                    if(!strcmp(&command_name, records[i].isbn)){
                        printf("%s\t\t\t%s\t\t%s\t\t%d\t%s\n", records[i].bookname, records[i].author, records[i].genre, records[i].quantity, records[i].isbn);;
                    }
                    else
                        continue;
                }
                break;
            default :
                break;
        }
    }
    return;
}

int delete_book(Record records[], int* count){
  char input[64];
  int i;
  char nullStr[30] = {"\0"};

  printf("=========================\n");
  printf("Book Management System : Delete books\n");
  printf("=========================\n");
  printf("bookname> ");
  scanf("%s", input);

  for(i=0 ; i <= *count; i++){
    if(strcpy(input, records[i].bookname) == 0){
      *count -= 1;
      printf("%s %s is deleted\n", records[i].bookname, records[i].author);
      strcpy(records[i].bookname, nullStr);
      strcpy(records[i].author, nullStr);
      strcpy(records[i].genre, nullStr);
      memset(&records[i].quantity, 0, sizeof(records[i].quantity));
      strcpy(records[i].isbn, nullStr);
    }
  }
  return 0;
}

int update_book(Record records[], int* count){
  char input[64];
  int command = 0;
  char updated_information[64];
  int quantity_updated;
  int cont = 1;
  printf("=========================\n");
  printf("Book Management System : Update books\n");
  printf("=========================\n");
  while(cont == 1){
    printf("Enter bookname>> ");
    scanf("%s", input);

    for(int i=0 ; i < *count ; i++){
      if(strcmp(records[i].bookname, input)==0){
        printf("Please select the part to update\n");
        printf("1.Name of the Book\n");
        printf("2.Name of the author\n");
        printf("3.Genre\n");
        printf("4.Quantity\n");
        printf("5.ISBN\n");
        printf("command>> ");
        scanf("%d", &command);
        if(command == 1){
          printf("Enter Updated information: ");
          scanf("%s", updated_information);
          strcpy(records[i].bookname,updated_information);
        }
        if(command == 2){
          printf("Enter Updated information: ");
          scanf("%s", updated_information);
          strcpy(records[i].author, updated_information);
        }
        if(command == 3){
          printf("Enter Updated information: ");
          scanf("%s", updated_information);
          strcpy(records[i].genre, updated_information);
        }
        if(command == 4){
          printf("Enter Updated information: ");
          scanf("%d", &quantity_updated);
          records[i].quantity = quantity_updated;
        }
        if(command == 5){
          printf("Enter Updated information: ");
          scanf("%s", updated_information);
          strcpy(records[i].isbn, updated_information);
        }
      }
    }
    printf("do you want to update another book?\n");
    printf("y:1/n:0 cont?");
    scanf("%d", &cont);
  }
  return 0;
}

int saveFile(Record records[], int* count){
  if(count > 0){
    int i;
    FILE* fp = fopen("record.txt", "w");

    for (i = 0; i <= *count; i++){
      fprintf(fp, "%s %s %s %d %s", records[i].bookname, records[i].author, records[i].genre, records[i].quantity, records[i].isbn);
      if(i == *count)
        continue;
      else
        fputc('\n', fp);
     }

     fclose(fp);
     return 0;
   }
   else{
     return 0;
   }
}

int openFile(Record records[], int* count){
  FILE* fp = fopen("record.txt", "r");
  int i = 0;
  if(fp == NULL){
    printf("File Open Error!\n");
    return 1;
  }
  else{
    while(1){
      if(feof(fp))
        break;
      else{
        fscanf(fp, "%s %s %s %d %s", records[i].bookname, records[i].author, records[i].genre, &records[i].quantity, records[i].isbn);
        i++;
      }
    }
  }
  fclose(fp);
  return 0;
}
