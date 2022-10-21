#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"
void list_books();
void search_book();
int entered_user_pass;
struct user* user_head=NULL;
extern struct books* head;
struct user *current = NULL;
char entered_user_name[10];
extern struct user* user_pnew;
extern struct user* user_pcheck;
int choice,k;
void initial_users()
{
    user_pnew=(struct user *) malloc(sizeof(struct user));
    user_head=user_pnew;
    user_pcheck=user_head;
    strcpy(user_pcheck->name,"omar");
    user_pcheck->pass=1234;
    user_pcheck->id=1;
    user_pcheck->card_id=1010;
    user_pcheck->card_password=2002;
    user_pcheck->card_balance=100;
    user_pcheck->req=NULL;
    user_pcheck->header=NULL;

    user_pnew = (struct user *) malloc(sizeof(struct user));
    user_pcheck->next=user_pnew;
    user_pcheck = user_pnew;
    strcpy(user_pcheck->name,"ahmed");
    user_pcheck->pass=2020;
    user_pcheck->id=2;
    user_pcheck->card_id=2020;
    user_pcheck->card_password=2202;
    user_pcheck->card_balance=150;
    user_pcheck->req=NULL;
    user_pcheck->header=NULL;
    user_pcheck->next=NULL;
}
void show_user() {
    current = user_head;
    while (current) {
        if (!strcmp(entered_user_name, current->name)) {
            printf("Username : %s\n", current->name);
            printf("User ID : %d\n", current->id);
            printf("Password %d\n",current->pass);
            struct bor_book* ch=current->header;
            while(ch) {
                printf("borrowed books : ");
                printf("%s\n", ch->name);
                ch=ch->next;
            }
            if(current->card_id==0)
                printf("No library card available");
            else
            printf("Library card ID : %d",current->card_id);
            break;
        }
        else
            current = current->next;
    }
}
struct bor_book* checker=NULL;
struct bor_book* cc=NULL;
void req_to_borrow() {
    char count = 0;
    list_books();
    struct bor_book *new = NULL;
    checker = current->header;
    while (checker != NULL) {
        count++;
        checker = checker->next;
    }
    if (count == 2)
        printf("You can't borrow more than 2 books");
    else {
         if (current->header == NULL) {
             new = (struct bor_book *) malloc(sizeof(struct bor_book));
             current->header = new;
             current->header->next=NULL;
         }
         else {
            cc = current->header;
            while (cc != NULL)
                cc = cc->next;
            new = (struct bor_book *) malloc(sizeof(struct bor_book));
            current->header->next=new;
        }
            printf("Enter the name of the book you want");
            getchar();
            gets(new->name);
            strcpy(new->status, "waiting");
            printf("Please wait for the admin to accept");
            new->next = NULL;
    }
}
void req_new_book()
{
    struct req_new_books *newr=NULL;
    newr=(struct req_new_books*)malloc(sizeof (struct req_new_books));
    current->req=newr;
    printf("enter the name of  the book");
    scanf("%s", newr->name);
    printf("Enter the name of the author");
    scanf("%s", newr->author);
}
void show_requests() {
    struct bor_book *bb = current->header;
    while (bb) {
        printf("%s---->", bb->name);
        printf("status : %s\n", bb->status);
        bb = bb->next;
    }
}
void buy_book()
{
    int ent_id,ent_card_id,ent_card_pass,total=0,v,m;
    list_books();
    struct books *curent = head;
     //current = user_head;
    while(1) {
        printf("Enter the book id You want");
        scanf("%d", &ent_id);
        while(curent) {
            if (curent->book_id == ent_id) {
                total += curent->price;
                break;
            } else
                curent = curent->next;
        }
        printf("if you want to buy another book enter 0 , else enter any number");
        scanf("%d",&v);
        if(v)
            break;
    }
    printf("Total cost is %d\n",total);
    printf("You can pay cash or with your library card\n");
    printf("Enter any number to pay with library card or 0 to pay cash");
    scanf("%d",&m);
    if(m)
    {
        while (1) {
            printf("Enter your library card id");
            scanf("%d", &ent_card_id);
            printf("Enter your library card password");
            scanf("%d", &ent_card_pass);
            if (ent_card_id != current->card_id || ent_card_pass != current->card_password)
                printf("Wrong id or password pls enter again");
            else
                break;
        }
        if(current->card_balance>=total)
            printf("Paid successfully");
        else
            printf("Not enough balance in your library card\nyou can pay cash");
    }
    else
        printf("Pay cash to recieve your books");
}
void user_mode() {
    current = user_head;
    if (user_head == NULL)
        printf("ask the admin to add you first ");
    else {
        while(1) {
            printf("Enter the username\n");
            scanf("%s",&entered_user_name);
            printf("Enter the password");
            scanf("%d",&entered_user_pass);
            while (current)
            {
                if (!strcmp(entered_user_name, current->name) && (entered_user_pass == current->pass)) {
                    printf("Hi %s \n",current->name);
                    break;
                }
                else
                    current = current->next;
            }
            if (current == NULL) {
                printf("Wrong username or password pls enter again\n");
                current = user_head;
            }
            else
                break;
        }
                while (1) {
                    printf("Enter the number before what you want\n1-View your data\n2-Change password");
                    printf("\n3-View all books\n4-Search for a book\n5-Borrow a book\n6-Buy a book\n");
                    printf("7-Request a new book to be provided in the future\n8-Show borrow requests\n9-Logout");
                    scanf("%d", &choice);
                    switch (choice) {
                        case 1: {
                            show_user();
                            break;
                        }
                        case 2: {
                            printf("Enter the new password");
                            scanf("%d", &current->pass);
                            break;
                        }
                        case 3: {
                            list_books();
                            break;
                        }
                        case 4: {
                            search_book();
                            break;
                        }
                        case 5: {
                            req_to_borrow();
                            break;
                        }
                        case 6: {
                            buy_book();
                            break;
                        }
                        case 7: {
                           req_new_book();
                            break;
                        }
                        case 8: {
                           show_requests();
                            break;
                        }
                        case 9: {
                            break;
                        }
                    }
                    printf("\nIf you want to do something else enter any number-else enter 0");
                    scanf("%d", &k);
                    if (!k)
                        break;
                }
            }
}