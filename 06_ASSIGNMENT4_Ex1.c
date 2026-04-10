/******************************************************************************
 * File: linked_list.c
 *
 * Description:
 *    Cài đặt danh sách liên kết đơn với các thao tác:
 *    thêm, tìm, xóa, in và giải phóng bộ nhớ.
 *
 * Author: Bang
 * Date: 2026
 ******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

/* cấu trúc node */
struct node
{
    int data;
    struct node* next;
};

/******************************************************************************
 * Function: display
 *
 * Description:
 *    In toàn bộ phần tử trong danh sách.
 *
 * Parameters:
 *    struct node* head : con trỏ đầu danh sách
 *
 * Returns:
 *    none
 ******************************************************************************/
void display(struct node* head)
{
    struct node* temp = head;

    while(temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

/******************************************************************************
 * Function: addback
 *
 * Description:
 *    Thêm phần tử vào cuối danh sách.
 *
 * Parameters:
 *    struct node* head : đầu danh sách
 *    int data : giá trị cần thêm
 *
 * Returns:
 *    struct node* : head mới
 ******************************************************************************/
struct node* addback(struct node* head, int data)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    struct node* temp;

    newnode->data = data;
    newnode->next = NULL;

    if(head == NULL)
    {
        return newnode;
    }

    temp = head;

    while(temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newnode;

    return head;
}

/******************************************************************************
 * Function: find
 *
 * Description:
 *    Tìm phần tử có giá trị data trong danh sách.
 *
 * Parameters:
 *    struct node* head
 *    int data
 *
 * Returns:
 *    con trỏ tới node tìm thấy hoặc NULL
 ******************************************************************************/
struct node* find(struct node* head, int data)
{
    while(head != NULL)
    {
        if(head->data == data)
        {
            return head;
        }
        head = head->next;
    }

    return NULL;
}

/******************************************************************************
 * Function: delnode
 *
 * Description:
 *    Xóa node pElement khỏi danh sách.
 *
 * Parameters:
 *    struct node* head
 *    struct node* pElement
 *
 * Returns:
 *    head mới
 ******************************************************************************/
struct node* delnode(struct node* head, struct node* pElement)
{
    struct node* temp;

    if(head == NULL || pElement == NULL)
    {
        return head;
    }

    /* xóa head */
    if(head == pElement)
    {
        temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    temp = head;

    while(temp->next != NULL && temp->next != pElement)
    {
        temp = temp->next;
    }

    if(temp->next == pElement)
    {
        temp->next = pElement->next;
        free(pElement);
    }

    return head;
}

/******************************************************************************
 * Function: freelist
 *
 * Description:
 *    Giải phóng toàn bộ danh sách.
 *
 * Parameters:
 *    struct node* head
 *
 * Returns:
 *    none
 ******************************************************************************/
void freelist(struct node* head)
{
    struct node* temp;

    while(head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}

/******************************************************************************
 * Function: main
 *
 * Description:
 *    Test các chức năng của danh sách liên kết.
 *
 * Returns:
 *    0
 ******************************************************************************/
int main(void)
{
    struct node* head = NULL;
    struct node* p;

    /* thêm phần tử */
    head = addback(head, 10);
    head = addback(head, 20);
    head = addback(head, 30);
    head = addback(head, 40);

    printf("List: ");
    display(head);

    /* tìm */
    p = find(head, 30);
    if(p != NULL)
    {
        printf("Found: %d\n", p->data);
    }

    /* xóa */
    head = delnode(head, p);

    printf("After delete: ");
    display(head);

    /* giải phóng */
    freelist(head);

    return 0;
}