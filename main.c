#include <stdio.h>
#include "structs.h"
void initial_books();
void Owner_mode();
void admin_mode();
void user_mode();
void initial_admins();
void initial_users();
extern struct user* user_head;
int main()
{
    initial_users();
    initial_books();
    initial_admins();
    while(1) {
        int x,y;
        printf("              *****Welcome*****\n");
        printf("1-Owner mode\n");
        printf("2-Admin mode\n3-User mode\nYour choice : ");
        scanf("%d", &x);
        switch (x)
        {
            case 1:
            {
                Owner_mode();
                break;
            }
            case 2:
            {
                admin_mode();
                break;
            }
            case 3:
            {
                user_mode();
                break;
            }
        }
        printf("\nRun again ?\n1-Yes\n2-No");
        scanf("%d",&y);
        if(y==2)
            break;
    }
     return 0;
}