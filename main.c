/******************************************************************************
 * File: main.c
 ******************************************************************************/

#include <stdio.h>
#include "hashtable.h"

int main(void)
{
    struct Node *p;

    init_table();

    insert("An", "111");
    insert("Binh", "222");
    insert("Cuong", "333");

    printf("=== Phone Book ===\n");
    display();

    printf("\n=== Search ===\n");
    p = search("Binh");

    if(p)
        printf("Found: %s -> %s\n", p->name, p->phone);
    else
        printf("Not found\n");

    printf("\n=== Delete ===\n");
    delete("An");

    display();

    clear_table();

    return 0;
}