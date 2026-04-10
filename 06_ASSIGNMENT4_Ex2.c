/******************************************************************************
 * File: binary_tree.c
 *
 * Description:
 *    Cài đặt cây nhị phân tìm kiếm (BST) với các thao tác:
 *    thêm node, duyệt cây, xóa toàn bộ cây.
 *
 * Author: ChatGPT
 * Date: 2026
 ******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

/* cấu trúc node */
struct node
{
    int data;
    struct node* left;
    struct node* right;
};

/******************************************************************************
 * Function: talloc
 *
 * Description:
 *    Cấp phát bộ nhớ cho một node mới.
 *
 * Parameters:
 *    int data : giá trị node
 *
 * Returns:
 *    con trỏ tới node mới
 ******************************************************************************/
struct node* talloc(int data)
{
    struct node* newnode;

    newnode = (struct node*)malloc(sizeof(struct node));

    if(newnode == NULL)
    {
        printf("Memory allocation failed\n");
        return NULL;
    }

    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;

    return newnode;
}

/******************************************************************************
 * Function: addnode
 *
 * Description:
 *    Thêm node vào cây BST.
 *
 * Parameters:
 *    struct node* root
 *    int data
 *
 * Returns:
 *    root mới
 ******************************************************************************/
struct node* addnode(struct node* root, int data)
{
    if(root == NULL)
    {
        return talloc(data);
    }

    if(data < root->data)
    {
        root->left = addnode(root->left, data);
    }
    else
    {
        root->right = addnode(root->right, data);
    }

    return root;
}

/******************************************************************************
 * Function: preorder
 *
 * Description:
 *    Duyệt cây theo thứ tự preorder.
 *
 * Parameters:
 *    struct node* root
 *
 * Returns:
 *    none
 ******************************************************************************/
void preorder(struct node* root)
{
    if(root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

/******************************************************************************
 * Function: inorder
 *
 * Description:
 *    Duyệt cây theo thứ tự inorder (kết quả sẽ được sắp xếp).
 *
 * Parameters:
 *    struct node* root
 *
 * Returns:
 *    none
 ******************************************************************************/
void inorder(struct node* root)
{
    if(root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

/******************************************************************************
 * Function: deltree
 *
 * Description:
 *    Xóa toàn bộ cây bằng post-order traversal.
 *
 * Parameters:
 *    struct node* root
 *
 * Returns:
 *    số node đã xóa
 ******************************************************************************/
int deltree(struct node* root)
{
    int count = 0;

    if(root != NULL)
    {
        count += deltree(root->left);
        count += deltree(root->right);

        free(root);
        count++;
    }

    return count;
}

/******************************************************************************
 * Function: main
 *
 * Description:
 *    Test các chức năng của cây nhị phân.
 *
 * Returns:
 *    0
 ******************************************************************************/
int main(void)
{
    struct node* root = NULL;
    int values[] = {3, 1, 0, 2, 8, 6, 5, 9};
    int i;
    int n = 8;

    /* thêm node */
    for(i = 0; i < n; i++)
    {
        root = addnode(root, values[i]);
    }

    /* duyệt preorder */
    printf("Preorder: ");
    preorder(root);
    printf("\n");

    /* duyệt inorder */
    printf("Inorder: ");
    inorder(root);
    printf("\n");

    /* xóa cây */
    printf("Deleted nodes: %d\n", deltree(root));

    return 0;
}