#ifndef _BASE_H_
#define _BASE_H_

#include "record.h"

void print_book(Record records[], int* count);
void add_book(Record records[], int* count);
void search_book(Record records[], int* count);
int delete_book(Record records[], int* count);
int update_book(Record records[], int* count);
int saveFile(Record records[], int* count);
int openfile(Record records[], int* count);
#endif
