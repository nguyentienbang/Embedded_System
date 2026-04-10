/******************************************************************************
 * File: insertion_sort_pointer.c
 *
 * Description:
 *    Cài đặt insertion sort bằng pointer arithmetic.
 *
 * Author: Student
 * Date: 2026
 ******************************************************************************/

#include <stdio.h>

int arr[] = {8, 3, 5, 2, 9, 1};
int len = 6;

/******************************************************************************
 * Function: shift_element
 *
 * Description:
 *    Di chuyển phần tử về đúng vị trí trong phần đã được sắp xếp.
 *
 * Parameters:
 *    int *pElement : con trỏ tới phần tử đang sai vị trí
 *
 * Returns:
 *    none
 ******************************************************************************/
void shift_element(int *pElement)
{
    int value = *pElement;
    int *p = pElement;

    while(p > arr && *(p - 1) > value)
    {
        *p = *(p - 1);
        p--;
    }

    *p = value;
}

/******************************************************************************
 * Function: insertion_sort
 *
 * Description:
 *    Sắp xếp mảng bằng insertion sort sử dụng con trỏ.
 *
 * Parameters:
 *    none
 *
 * Returns:
 *    none
 ******************************************************************************/
void insertion_sort(void)
{
    int *p;

    for(p = arr + 1; p < arr + len; p++)
    {
        if(*p < *(p - 1))
        {
            shift_element(p);
        }
    }
}

/******************************************************************************
 * Function: main
 *
 * Description:
 *    Chạy thử thuật toán.
 ******************************************************************************/
int main(void)
{
    int i;

    insertion_sort();

    for(i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");

    return 0;
}