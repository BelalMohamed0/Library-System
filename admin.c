#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"
extern struct user* user_head;
struct admin* admin_head=NULL;
struct admin* admin_pnew=NULL;
struct admin* admin_pcheck=NULL;
struct user* user_pnew=NULL;
struct user* user_pcheck=NULL;
void initial_admins()
{
    admin_pnew = (struct admin *) malloc(sizeof(struct admin));
    admin_head = admin_pnew;
    admin_pcheck = admin_head;
    strcpy(admin_pcheck->name,"admin1");
    admin_pcheck->pass=1010;

    admin_pnew = (struct admin *) malloc(sizeof(struct admin));
    admin_pcheck->next=admin_pnew;
    admin_pcheck = admin_pnew;
    strcpy(admin_pcheck->name,"admin2");
    admin_pcheck->pass=2020;

    admin_pnew = (struct admin *) malloc(sizeof(struct admin));
    admin_pcheck->next=admin_pnew;
    admin_pcheck = admin_pnew;
    strcpy(admin_pcheck->name,"admin3");
    admin_pcheck->pass=3030;

    admin_pcheck->next=NULL;

}
void add_user()
{
    if(user_head==NULL) {
        user_pnew = (struct user*) malloc(sizeof(struct user));
        user_head = user_pnew;
    }
    else {
        user_pcheck = user_head;
        while(user_pcheck->next!=NULL)
            user_pcheck=user_pcheck->next;
        user_pnew = (struct user*) malloc(sizeof(struct user));
        user_pcheck->next=user_pnew;
    }
    printf("Enter the new user name : ");
    getchar();
    gets(user_pnew->name);
    printf("Enter the new user id : ");
    scanf("%d", &user_pnew->id);
    user_pnew->req=NULL;
    user_pnew->next=NULL;
}
void remove_user()
{
    char entered_name[20];
    struct user* current=user_head;
    if(current==NULL)
        printf("There are no users already");
    else {
        printf("enter the user name you want to delete");
        scanf("%s",&entered_name);
        if (user_head) {

                struct user* selected=user_head;
                struct user* previous=NULL;
                while(selected) {
                    if (!strcmp(selected->name, entered_name))
                    {
                        if(previous)
                            previous->next=selected->next;
                        else
                            user_head=selected->next;

                        free(selected);
                        printf("deleted successfully");
                    }
                    previous=selected;
                    selected=selected->next;
                }
        }
        else
            printf("No users already");
    }
}
void list_users()
{
    struct user* current=user_head;
    if(current==NULL)
        printf("There are no users");
    else
    {
        while(current)
        {
            printf("Username : %s\n", current->name);
            printf("User ID : %d\n", current->id);
            if(current->req!=NULL)
            printf("Requested book name: %s, Author name :%s\n",current->req->name,current->req->author);
            current=current->next;
        }
    }
}
extern struct books* head ;
extern struct books* pnew;
extern struct books* pcheck;
void list_books()
{
    struct books* current=head;
    if(current==NULL)
        printf("There are no books now");
    else
    {
        while(current)
        {
            printf("Name : %s\n", current->name);
            printf("Author : %s\n", current->author);
            printf("Book id : %d\n", current->book_id);
            printf("Status : %s\n", current->availability?"Available":"Not available");
            current=current->next;
        }
    }
}
void add_book()
{
    if(head==NULL) {
        pnew = (struct books*) malloc(sizeof(struct books));
        head = pnew;
        head->book_id=1;
    }
    else {
        pcheck = head;
        while(pcheck->next!=NULL)
            pcheck=pcheck->next;
        pnew = (struct books*) malloc(sizeof(struct books));
        pnew->book_id=(pcheck->book_id)+1;
        pcheck->next=pnew;
    }
    pnew->availability=true;
    printf("Enter the new book name : ");
    getchar();
    gets(pnew->name);
    printf("Enter the new book author : ");
    gets(pnew->author);
    pnew->next=NULL;
}
void remove_book()
{
    char entered_name[20];
    struct books* current=head;
    if(current==NULL)
        printf("There are no books already");
    else {
        printf("enter the book name you want to delete");
        getchar();
        gets(entered_name);
        if (head) {
            struct books* selected=head;
            struct books* previous=NULL;
                while(selected) {
                    if (!strcmp(selected->name, entered_name))
                    {
                        if(previous) {
                            previous->next = selected->next;
                        }
                        else {
                            head = selected->next;
                        }
                        free(selected);
                        printf("deleted successfully");
                    }
                    previous=selected;
                    selected=selected->next;
                }
        }
    }
}
void edit_user_id()
{
    char entered_name[20];
    struct user* current = user_head;
    if (current == NULL)
        printf("There are no users yet");
    else {
        printf("enter the user name you want to edit");
        scanf("%s", &entered_name);
        while (current) {
            if (!strcmp(current->name, entered_name)) {
                printf("enter the new id");
                scanf("%d",&current->id);
                printf("ID edited successfully");
                break;
            }
            else
                current = current->next;
        }
    }
}
void search_book()
{
    int a;
    printf("Enter 1 to search by name\n2 to search by author\n3 to search by id");
    scanf("%d",&a);
    struct books* search =head;
    switch (a)
    {
        case 1:
        {
            char entered_name[20];
            printf("enter the book name you want to find");
            getchar();
            gets(entered_name);
            while (search) {
                if (!strcmp(search->name, entered_name))
                {
                    printf("name : %s\n",search->name);
                    printf("Author : %s\n",search->author);
                    printf("ID : %d\n",search->book_id);
                    printf("%s\n", search->availability?"Available":"Not available");
                    break;
                }
                search=search->next;
            }
            if(search==NULL)
                printf("book name not found");
            break;
        }
        case 2:
        {
            char entered_author_name[30];
            printf("enter the Author name you want to find");
            getchar();
            gets(entered_author_name);
            while (search) {
                if (!strcmp(search->author, entered_author_name))
                {
                    printf("name : %s\n",search->name);
                    printf("Author : %s\n",search->author);
                    printf("ID : %d\n",search->book_id);
                    printf("%s\n", search->availability?"Available":"Not available");
                    break;
                }
                search=search->next;
            }
            if(search==NULL)
                printf("author not found");
            break;
        }
        case 3:
        {
            int ent_book_id;
            printf("enter book id you want to find");
            scanf("%d", &ent_book_id);
            while (search) {
                if (search->book_id== ent_book_id)
                {
                    printf("name : %s\n",search->name);
                    printf("Author : %s\n",search->author);
                    printf("ID : %d\n",search->book_id);
                    printf("%s\n", search->availability?"Available":"Not available");
                    break;
                }
                search=search->next;
            }
            if(search==NULL)
                printf("ID not found");
            break;
        }
    }
}
void reserve_book()
{
    struct user *current =NULL;
    struct bor_book* check=NULL;
    int y,k;
    list_users();
    while(1) {
        current = user_head;
        int ent_id;
        printf("\nEnter the id of the user that you want to check");
        scanf("%d", &ent_id);
        while (current) {
            if (ent_id == current->id)
            {
                check=current->header;
                if(check==NULL) {
                    printf("There are no books requested from this user\n");
                    break;
                }
                else {
                    while(check) {
                        printf("%s\n", check->name);
                        printf("If you want to reserve this book enter 1,else enter 0");
                        scanf("%d",&k);
                        if(k)
                        strcpy(check->status,"approved");
                        check=check->next;
                    }
                    break;
                }
            } else
                current = current->next;
        }
        printf("If you want to check another user enter 0 ,else enter any number");
        scanf("%d",&y);
        if(y)
            break;
    }
}
void make_book_available()
{
    char ent_book[20];
    printf("Enter the name of the book you want to make available again");
    getchar();
    gets(ent_book);
    struct books* current=head;
    while(strcmp(current->name,ent_book))
        current=current->next;
current->availability=true;
    printf("Book availability updated successfully\n");
}
char entered_admin_name[10];
int entered_admin_pass;
extern int remove_perm;
void admin_mode()
{
    struct admin* find_admin=admin_head;
    while(1) {
        printf("Enter the username");
        scanf("%s", entered_admin_name);
        printf("Enter the password");
        scanf("%d", &entered_admin_pass);
        while (find_admin)
        {
            if (!strcmp(entered_admin_name, find_admin->name) && (entered_admin_pass == find_admin->pass))
                break;
            else
                find_admin = find_admin->next;
        }
        if (find_admin == NULL) {
            printf("Wrong username or password pls enter again\n");
            find_admin = admin_head;
        }
        else
            break;
    }
    int x,y;
    while(1) {
        printf("Enter 1 to view all users data\n2 to view all books\n3 to add a book\n4 to remove a book\n");
        printf("5 to add user\n6 to remove user\n7 to edit a user id\n8 to search for a book\n");
        printf("9 to make a reservation of books\n10 to make a book available in stock again\n11 to logout");
        scanf("%d", &x);
        switch (x) {
            case 1: {
                list_users();
                break;
            }
            case 2: {
                list_books();
                break;
            }
            case 3: {
                if (remove_perm)
                    add_book();
                else
                    printf("You don't have the permission to do that");
                break;
            }
            case 4: {
                if (remove_perm)
                    remove_book();
                else
                    printf("You don't have the permission to do that");
                break;
            }
            case 5: {
                if (remove_perm)
                    add_user();
                else
                    printf("You don't have the permission to do that");
                break;
            }
            case 6: {
                if (remove_perm==1)
                    remove_user();
                else
                    printf("You don't have the permission to do that");
                break;
            }
            case 7: {
                edit_user_id();
                break;
            }
            case 8: {
                search_book();
                break;
            }
            case 9: {
                reserve_book();
                break;
            }
            case 10: {
                make_book_available();
                break;
            }
            case 11:
            {
                break;
            }
        }
        printf("\nIf you want to do something else enter any number else enter 0");
        scanf("%d",&y);
        if(!y)
            break;
    }
}