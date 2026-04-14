/******************************************************************************
 * File: hashtable.h
 *
 * Description:
 *    Khai báo cấu trúc và các hàm cho hash table.
 *    Khai báo kiể dữ liệu, hằng số, nguyên mẫu hàm.
 ******************************************************************************/

#ifndef HASHTABLE_H
#define HASHTABLE_H

#define HASHSIZE 101

struct Node
{
    char name[50];
    char phone[20];
    struct Node *next;
};

/* API */
void init_table(void);
void insert(char *name, char *phone);
struct Node* search(char *name);
void delete(char *name);
void display(void);
void clear_table(void);

#endif