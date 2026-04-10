/******************************************************************************
 * File: callback.c
 *
 * Description:
 *    Sử dụng qsort và function pointer để xử lý danh sách record.
 *
 * Author: Bang
 * Date: 2026
 ******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* cấu trúc record */
struct student
{
    char firstname[20];
    char lastname[20];
    int age;
};

/******************************************************************************
 * Function: cmp_firstname
 ******************************************************************************/
int cmp_firstname(const void *a, const void *b)
{
    return strcmp(((struct student*)a)->firstname,
                  ((struct student*)b)->firstname);
}

/******************************************************************************
 * Function: cmp_lastname
 ******************************************************************************/
int cmp_lastname(const void *a, const void *b)
{
    return strcmp(((struct student*)a)->lastname,
                  ((struct student*)b)->lastname);
}

/******************************************************************************
 * Function: print_if_gt20
 ******************************************************************************/
void print_if_gt20(struct student s)
{
    if(s.age > 20)
    {
        printf("%s %s %d\n", s.firstname, s.lastname, s.age);
    }
}

/******************************************************************************
 * Function: apply
 ******************************************************************************/
void apply(struct student arr[], int n, void (*fp)(struct student))
{
    int i;
    for(i = 0; i < n; i++)
    {
        fp(arr[i]);
    }
}

/******************************************************************************
 * Function: main
 ******************************************************************************/
int main(void)
{
    struct student arr[] = {
        {"An", "Nguyen", 19},
        {"Binh", "Tran", 22},
        {"Cuong", "Le", 25},
        {"Dung", "Pham", 18}
    };

    int n = 4;

    /* sort theo firstname */
    qsort(arr, n, sizeof(struct student), cmp_firstname);

    printf("Sort by firstname:\n");
    apply(arr, n, print_if_gt20);

    /* sort theo lastname */
    qsort(arr, n, sizeof(struct student), cmp_lastname);

    printf("\nSort by lastname:\n");
    apply(arr, n, print_if_gt20);

    return 0;
}