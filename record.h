#ifndef _RECORD_H_
#define _RECORD_H_

#define MAX 64

typedef struct{
  char bookname[MAX];
  char author[MAX];
  char genre[MAX];
  int quantity;
  char isbn[MAX];
} Record;

#endif
