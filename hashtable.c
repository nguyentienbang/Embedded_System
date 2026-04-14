/******************************************************************************
 * File: hashtable.c
 *
 * Description:
 *    Cài đặt hàm băm và các thao tác trên bảng băm.
 ******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashtable.h"

static struct Node *buckets[HASHSIZE];

/******************************************************************************
 * Function: hash
 ******************************************************************************/
static unsigned int hash(char *str)
{
    unsigned int hashval = 0;

    while(*str)
    {
        hashval = *str + 31 * hashval;
        str++;
    }

    return hashval % HASHSIZE;
}

/******************************************************************************
 * Function: init_table
 ******************************************************************************/
void init_table(void)
{
    int i;
    for(i = 0; i < HASHSIZE; i++)
        buckets[i] = NULL;
}

/******************************************************************************
 * Function: insert
 ******************************************************************************/
void insert(char *name, char *phone)
{
    unsigned int h = hash(name);
    struct Node *newnode;

    newnode = (struct Node*)malloc(sizeof(struct Node));

    strcpy(newnode->name, name);
    strcpy(newnode->phone, phone);

    newnode->next = buckets[h];
    buckets[h] = newnode;
}

/******************************************************************************
 * Function: search
 ******************************************************************************/
struct Node* search(char *name)
{
    struct Node *temp = buckets[hash(name)];

    while(temp != NULL)
    {
        if(strcmp(temp->name, name) == 0)
            return temp;

        temp = temp->next;
    }

    return NULL;
}

/******************************************************************************
 * Function: delete
 ******************************************************************************/
void delete(char *name)
{
    unsigned int h = hash(name);
    struct Node *temp = buckets[h];
    struct Node *prev = NULL;

    while(temp != NULL)
    {
        if(strcmp(temp->name, name) == 0)
        {
            if(prev == NULL)
                buckets[h] = temp->next;
            else
                prev->next = temp->next;

            free(temp);
            return;
        }

        prev = temp;
        temp = temp->next;
    }
}

/******************************************************************************
 * Function: display
 ******************************************************************************/
void display(void)
{
    int i;
    struct Node *temp;

    for(i = 0; i < HASHSIZE; i++)
    {
        temp = buckets[i];

        while(temp != NULL)
        {
            printf("%s : %s\n", temp->name, temp->phone);
            temp = temp->next;
        }
    }
}

/******************************************************************************
 * Function: clear_table
 ******************************************************************************/
void clear_table(void)
{
    int i;
    struct Node *temp, *next;

    for(i = 0; i < HASHSIZE; i++)
    {
        temp = buckets[i];

        while(temp != NULL)
        {
            next = temp->next;
            free(temp);
            temp = next;
        }

        buckets[i] = NULL;
    }
}