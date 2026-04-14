/******************************************************************************
 * File: phonebook_hash.c
 *
 * Description:
 *    Cài đặt bảng băm (hash table) dùng chaining để quản lý danh bạ.
 *
 * Author: ChatGPT
 * Date: 2026
 ******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASHSIZE 101

/******************************************************************************
 * Struct: Node
 ******************************************************************************/
struct Node
{
    char name[50];
    char phone[20];
    struct Node *next;
};

struct Node *buckets[HASHSIZE];

/******************************************************************************
 * Function: hash
 *
 * Description:
 *    Hàm băm chuỗi (dùng hệ số 31).
 ******************************************************************************/
unsigned int hash(char *str)
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
    unsigned int h = hash(name);
    struct Node *temp = buckets[h];

    while(temp != NULL)
    {
        if(strcmp(temp->name, name) == 0)
        {
            return temp;
        }
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
            printf("Deleted: %s\n", name);
            return;
        }

        prev = temp;
        temp = temp->next;
    }

    printf("Not found: %s\n", name);
}

/******************************************************************************
 * Function: display
 ******************************************************************************/
void display(void)
{
    int i;
    struct Node *temp;

    printf("\n--- Phone Book ---\n");

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
 * Function: main
 ******************************************************************************/
int main(void)
{
    int i;

    /* init */
    for(i = 0; i < HASHSIZE; i++)
        buckets[i] = NULL;

    /* thêm ít nhất 8 liên hệ */
    insert("An", "111");
    insert("Binh", "222");
    insert("Cuong", "333");
    insert("Dung", "444");
    insert("Hanh", "555");
    insert("Lan", "666");
    insert("Minh", "777");
    insert("Nam", "888");

    display();

    /* tìm kiếm (>= 3 tên, có 1 không tồn tại) */
    printf("\n--- Search ---\n");

    char *names[] = {"An", "Lan", "Tuan"};

    for(i = 0; i < 3; i++)
    {
        struct Node *p = search(names[i]);

        if(p != NULL)
            printf("Found: %s -> %s\n", p->name, p->phone);
        else
            printf("Not found: %s\n", names[i]);
    }

    /* xóa 2 liên hệ */
    printf("\n--- Delete ---\n");

    delete("An");
    delete("Minh");

    display();

    return 0;
}