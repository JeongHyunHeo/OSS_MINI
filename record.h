#ifndef _RECORD_H_
#define _RECORD_H_

#define MAX_BOOKNAME 50
#define MAX_AUTHOR 50
#define MAX_GENRE 20
#define MAX_QUANTITY 10
#define MAX_ISBN 20

typedef struct{
  char bookname[MAX_BOOKNAME];
  char author[MAX_AUTHOR];
  char genre[MAX_GENRE];
  int quantity;
  char isbn[MAX_ISBN];
} Record;

#endif
