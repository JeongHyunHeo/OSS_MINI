#include <stdio.h>
#include <string.h>
#include <extras.h>

void swap(Record* curr, Record next){
  Record temp;
  temp = curr;
  curr = next;
  next = temp;
}

int defragmentation(Record records[], int* count){
  printf("Defragmentation progressing......\n");
  for(int i=0; i<count ; i++){
    if(ctrcmp(records[i].bookname, " ") == 0){
      swap(&records[i], &records[i+1]);
    }
  }
  return 0;
}

void sort(Record records[], int* count){
  Record temp;
  for(int i=0; i < count-1 ; i++){
    for(int j=1; j<count; j++){
      if(strcmp(records[i].bookname, records[j])>0){
        strcpy(&temp, &records[i]);
        strcpy(&records[i], &records[j]);
        strcpy(&records[j], &temp);
      }
    }
  }
}
