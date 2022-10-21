#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#ifndef structs_h
#define structs_h
struct admin
{
    char name[20];
    int pass;
    struct admin* next;
};
struct bor_book
{
    char name[30];
    char status[10];
    struct bor_book* next;
};
struct user
{
    char name[20];
    int pass;
    int id;
    int card_id;
    int card_password;
    int card_balance;
    struct bor_book* header;
    struct req_new_books* req;
    struct user* next;
};
struct books
{
    char name[30];
    char author[30];
    int book_id;
    int price;
    bool availability;
    struct books* next;
};
struct req_new_books
{
    char name[30];
    char author[30];
    char approve[10];
};
#endif