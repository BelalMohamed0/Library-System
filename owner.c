#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"
char entered_name[10];
int entered_pass;
extern struct admin* admin_head;
extern struct admin* admin_pnew;
extern struct admin* admin_pcheck;
void add_admin()
{
    if(admin_head==NULL) {
        admin_pnew = (struct admin *) malloc(sizeof(struct admin));
        admin_head = admin_pnew;
    }
    else {
        admin_pcheck = admin_head;
        while(admin_pcheck->next!=NULL)
            admin_pcheck=admin_pcheck->next;
        admin_pnew = (struct admin*) malloc(sizeof(struct admin));
        admin_pcheck->next=admin_pnew;
    }
    printf("Enter the new admin name : ");
    scanf("%s",&admin_pnew->name);
        printf("Enter the new admin password : ");
        scanf("%d",&admin_pnew->pass);
    admin_pnew->next=NULL;
}
void remove_admin()
{
    struct admin* current=admin_head;
    if(current==NULL)
        printf("There are no Admins already");
    else {
        printf("enter the admin name you want to delete");
        scanf("%s",&entered_name);
        if (admin_head) {
            if (!strcmp(current->name ,entered_name))
            {
                    struct admin* selected=admin_head;
                    struct admin* previous=NULL;
                    while(selected) {
                        if (!strcmp(selected->name, entered_name))
                        {
                            if(previous)
                                previous->next=selected->next;
                            else
                                admin_head=selected->next;

                            free(current);
                        }
                        previous=selected;
                        selected=selected->next;
                    }
                }
        }
    }
    printf("admin deleted successfully");
}
void initial_admins();
int remove_perm=1;
void Owner_mode() {
    int c,x=1;
    initial_admins();
    while(1) {
        printf("Enter the username");
        scanf("%s", &entered_name);
        printf("Enter the password");
        scanf("%d", &entered_pass);
        if (strcmp(entered_name, "Owner") || (entered_pass != 1234))
            printf("Wrong username or password pls enter again\n");
        else
            break;
    }
    while(x)
    {
        printf("If you want to add new admin enter 1\nIf you want to remove an admin enter 2\nIf you want to remove permissions from admins enter 3\nIf you want to return permissions enter 4");
        scanf("%d", &c);
        switch (c) {
            case 1: {
                add_admin();
                break;
            }
            case 2: {
                remove_admin();
                break;
            }
            case 3: {
                remove_perm = 0;
            }
            case 4:
            {
                remove_perm=1;
            }
        }
        printf("\nIf you want to do something enter 1 else enter 0");
        scanf("%d",&x);
    }
}