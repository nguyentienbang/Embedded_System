/******************************************************************************
 * File: priority_queue_heap.c
 *
 * Description:
 *    Cài đặt hàng đợi ưu tiên bằng Max-Heap.
 *
 * Author: ChatGPT
 * Date: 2026
 ******************************************************************************/

#include <stdio.h>
#include <string.h>

#define MAX 100

/******************************************************************************
 * Struct: Patient
 ******************************************************************************/
struct Patient
{
    char name[50];
    int priority;
};

/* heap */
struct Patient heap[MAX];
int size = 0;

/******************************************************************************
 * Function: swap
 ******************************************************************************/
void swap(struct Patient *a, struct Patient *b)
{
    struct Patient temp = *a;
    *a = *b;
    *b = temp;
}

/******************************************************************************
 * Function: heapify_up
 ******************************************************************************/
void heapify_up(int i)
{
    int parent;

    while(i > 0)
    {
        parent = (i - 1) / 2;

        if(heap[parent].priority < heap[i].priority)
        {
            swap(&heap[parent], &heap[i]);
            i = parent;
        }
        else
            break;
    }
}

/******************************************************************************
 * Function: heapify_down
 ******************************************************************************/
void heapify_down(int i)
{
    int left, right, largest;

    while(1)
    {
        left = 2 * i + 1;
        right = 2 * i + 2;
        largest = i;

        if(left < size && heap[left].priority > heap[largest].priority)
            largest = left;

        if(right < size && heap[right].priority > heap[largest].priority)
            largest = right;

        if(largest != i)
        {
            swap(&heap[i], &heap[largest]);
            i = largest;
        }
        else
            break;
    }
}

/******************************************************************************
 * Function: push
 ******************************************************************************/
void push(char *name, int priority)
{
    strcpy(heap[size].name, name);
    heap[size].priority = priority;

    heapify_up(size);
    size++;
}

/******************************************************************************
 * Function: pop
 ******************************************************************************/
struct Patient pop(void)
{
    struct Patient top = heap[0];

    heap[0] = heap[size - 1];
    size--;

    heapify_down(0);

    return top;
}

/******************************************************************************
 * Function: peek
 ******************************************************************************/
struct Patient peek(void)
{
    return heap[0];
}

/******************************************************************************
 * Function: display
 ******************************************************************************/
void display(void)
{
    int i;

    printf("\n--- Heap ---\n");
    for(i = 0; i < size; i++)
    {
        printf("%s (%d)\n", heap[i].name, heap[i].priority);
    }
}

/******************************************************************************
 * Function: main
 ******************************************************************************/
int main(void)
{
    struct Patient p;

    /* nhập 5 bệnh nhân */
    push("An", 2);
    push("Binh", 5);
    push("Cuong", 3);
    push("Dung", 8);
    push("Hanh", 6);

    display();

    /* peek */
    p = peek();
    printf("\nHighest priority: %s (%d)\n", p.name, p.priority);

    /* pop toàn bộ */
    printf("\n--- Serving order ---\n");

    while(size > 0)
    {
        p = pop();
        printf("%s (%d)\n", p.name, p.priority);
    }

    return 0;
}