#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "structs.h"
struct books* head = NULL;
struct books* pnew=NULL;
struct books* pcheck=NULL;
void initial_books()
{
    pnew = (struct books *) malloc(sizeof(struct books));
    head = pnew;
    pcheck = head;
    strcpy(pcheck->name,"Hamlet");
    strcpy(pcheck->author,"William Shakespeare");
    pcheck->book_id=1;
    pcheck->price=6;
    pcheck->availability=false;

    pnew = (struct books *) malloc(sizeof(struct books));
    pcheck->next=pnew;
    pcheck=pnew;
    strcpy(pcheck->name,"RichardII");
    strcpy(pcheck->author,"William Shakespeare");
    pcheck->book_id=2;
    pcheck->price=7;
    pcheck->availability=true;

    pnew = (struct books *) malloc(sizeof(struct books));
    pcheck->next=pnew;
    pcheck=pnew;
    strcpy(pcheck->name,"As you like it");
    strcpy(pcheck->author,"William Shakespeare");
    pcheck->book_id=3;
    pcheck->price=4;
    pcheck->availability=false;

    pnew = (struct books *) malloc(sizeof(struct books));
    pcheck->next=pnew;
    pcheck=pnew;
    strcpy(pcheck->name,"King Lear");
    strcpy(pcheck->author,"William Shakespeare");
    pcheck->book_id=4;
    pcheck->price=7;
    pcheck->availability=true;

    pnew = (struct books *) malloc(sizeof(struct books));
    pcheck->next=pnew;
    pcheck=pnew;
    strcpy(pcheck->name,"The tempest");
    strcpy(pcheck->author,"William Shakespeare");
    pcheck->book_id=5;
    pcheck->price=8;
    pcheck->availability=true;

    pnew = (struct books *) malloc(sizeof(struct books));
    pcheck->next=pnew;
    pcheck=pnew;
    strcpy(pcheck->name,"Ulysses");
    strcpy(pcheck->author,"James Joyce");
    pcheck->book_id=6;
    pcheck->price=6;
    pcheck->availability=true;

    pnew = (struct books *) malloc(sizeof(struct books));
    pcheck->next=pnew;
    pcheck=pnew;
    strcpy(pcheck->name,"Finn's Hotel");
    strcpy(pcheck->author,"James Joyce");
    pcheck->book_id=7;
    pcheck->price=8;
    pcheck->availability=true;

    pnew = (struct books *) malloc(sizeof(struct books));
    pcheck->next=pnew;
    pcheck=pnew;
    strcpy(pcheck->name,"Dubliners");
    strcpy(pcheck->author,"James Joyce");
    pcheck->book_id=8;
    pcheck->price=3;
    pcheck->availability=true;

    pnew = (struct books *) malloc(sizeof(struct books));
    pcheck->next=pnew;
    pcheck=pnew;
    strcpy(pcheck->name,"Finnegans Wake");
    strcpy(pcheck->author,"James Joyce");
    pcheck->book_id=9;
    pcheck->price=5;
    pcheck->availability=true;

    pnew = (struct books *) malloc(sizeof(struct books));
    pcheck->next=pnew;
    pcheck=pnew;
    strcpy(pcheck->name,"Chamber Music");
    strcpy(pcheck->author,"James Joyce");
    pcheck->book_id=10;
    pcheck->price=6;
    pcheck->availability=true;

    pnew = (struct books *) malloc(sizeof(struct books));
    pcheck->next=pnew;
    pcheck=pnew;
    strcpy(pcheck->name,"Stephen Hero");
    strcpy(pcheck->author,"James Joyce");
    pcheck->book_id=11;
    pcheck->price=4;
    pcheck->availability=true;

    pnew = (struct books *) malloc(sizeof(struct books));
    pcheck->next=pnew;
    pcheck=pnew;
    strcpy(pcheck->name,"Tomb of Sand");
    strcpy(pcheck->author,"Geetanjali Shree's");
    pcheck->book_id=12;
    pcheck->price=6;
    pcheck->availability=true;

    pnew = (struct books *) malloc(sizeof(struct books));
    pcheck->next=pnew;
    pcheck=pnew;
    strcpy(pcheck->name,"Between two worlds");
    strcpy(pcheck->author,"Geetanjali Shree's");
    pcheck->book_id=13;
    pcheck->price=7;
    pcheck->availability=true;

    pnew = (struct books *) malloc(sizeof(struct books));
    pcheck->next=pnew;
    pcheck=pnew;
    strcpy(pcheck->name,"War and Peace");
    strcpy(pcheck->author,"Leo Tolstoy");
    pcheck->book_id=14;
    pcheck->price=10;
    pcheck->availability=true;

    pnew = (struct books *) malloc(sizeof(struct books));
    pcheck->next=pnew;
    pcheck=pnew;
    strcpy(pcheck->name,"The great Gatsby");
    strcpy(pcheck->author,"F.Scott Fitzgerald");
    pcheck->book_id=15;
    pcheck->price=6;
    pcheck->availability=true;

    pnew = (struct books *) malloc(sizeof(struct books));
    pcheck->next=pnew;
    pcheck=pnew;
    strcpy(pcheck->name,"Don Quixote");
    strcpy(pcheck->author,"Miguel de Cervantes");
    pcheck->book_id=16;
    pcheck->price=8;
    pcheck->availability=true;

    pnew = (struct books *) malloc(sizeof(struct books));
    pcheck->next=pnew;
    pcheck=pnew;
    strcpy(pcheck->name,"Hear Yourself");
    strcpy(pcheck->author,"Prem Rawat");
    pcheck->book_id=17;
    pcheck->price=4;
    pcheck->availability=true;

    pnew = (struct books *) malloc(sizeof(struct books));
    pcheck->next=pnew;
    pcheck=pnew;
    strcpy(pcheck->name,"Lal Salam");
    strcpy(pcheck->author,"Smiriti Irani");
    pcheck->book_id=18;
    pcheck->price=8;
    pcheck->availability=true;

    pnew = (struct books *) malloc(sizeof(struct books));
    pcheck->next=pnew;
    pcheck=pnew;
    strcpy(pcheck->name,"Queen of Fire");
    strcpy(pcheck->author,"Devika Rangachari");
    pcheck->book_id=19;
    pcheck->price=8;
    pcheck->availability=true;

    pnew = (struct books *) malloc(sizeof(struct books));
    pcheck->next=pnew;
    pcheck=pnew;
    strcpy(pcheck->name,"When Breath Becomes Air");
    strcpy(pcheck->author,"Paul Kalanithi");
    pcheck->book_id=20;
    pcheck->price=11;
    pcheck->availability=true;

    pcheck->next=NULL;
}