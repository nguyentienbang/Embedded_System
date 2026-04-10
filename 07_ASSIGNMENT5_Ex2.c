/******************************************************************************
 * File: hash.c
 *
 * Description:
 *    Cài đặt hash table dùng linked list để đếm số lần xuất hiện từ.
 *
 * Author: Bang
 * Date: 2026
 ******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASHSIZE 101

struct node
{
    char *word;
    int count;
    struct node *next;
};

struct node *hashtab[HASHSIZE];

/******************************************************************************
 * Function: hash
 ******************************************************************************/
unsigned int hash(char *s)
{
    unsigned int hashval = 0;

    while(*s)
    {
        hashval = *s + 31 * hashval;
        s++;
    }

    return hashval % HASHSIZE;
}

/******************************************************************************
 * Function: lookup
 ******************************************************************************/
struct node *lookup(char *s)
{
    struct node *np;
    unsigned int h = hash(s);

    for(np = hashtab[h]; np != NULL; np = np->next)
    {
        if(strcmp(s, np->word) == 0)
        {
            return np;
        }
    }

    /* tạo node mới */
    np = (struct node*)malloc(sizeof(struct node));
    if(np == NULL)
        return NULL;

    np->word = strdup(s);
    np->count = 0;

    np->next = hashtab[h];
    hashtab[h] = np;

    return np;
}

/******************************************************************************
 * Function: addword
 ******************************************************************************/
void addword(char *word)
{
    struct node *np = lookup(word);
    if(np != NULL)
    {
        np->count++;
    }
}

/******************************************************************************
 * Function: cleartable
 ******************************************************************************/
void cleartable(void)
{
    int i;
    struct node *np, *temp;

    for(i = 0; i < HASHSIZE; i++)
    {
        np = hashtab[i];

        while(np != NULL)
        {
            temp = np;
            np = np->next;

            free(temp->word);
            free(temp);
        }

        hashtab[i] = NULL;
    }
}

/******************************************************************************
 * Function: main
 ******************************************************************************/
int main(void)
{
    char *words[] = {"apple", "banana", "apple", "cat", "banana", "apple"};
    int n = 6;
    int i;

    for(i = 0; i < n; i++)
    {
        addword(words[i]);
    }

    /* in bảng */
    printf("Word frequency:\n");
    for(i = 0; i < HASHSIZE; i++)
    {
        struct node *np = hashtab[i];
        while(np != NULL)
        {
            printf("%s: %d\n", np->word, np->count);
            np = np->next;
        }
    }

    cleartable();

    return 0;
}