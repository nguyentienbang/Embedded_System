/******************************************************************************
 * File: field_sort.c
 *
 * Description:
 *    Sắp xếp chuỗi theo field với option numeric hoặc string.
 *
 * Author: ChatGPT
 * Date: 2026
 ******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

int field = 0;
int numeric = 0;

/******************************************************************************
 * Function: get_field
 ******************************************************************************/
char *get_field(char *line, int f)
{
    static char buf[100];
    int i = 0, j = 0, count = 0;

    while(line[i] != '\0')
    {
        if(line[i] == ' ')
            count++;

        if(count == f)
            buf[j++] = line[i];

        i++;
    }

    buf[j] = '\0';
    return buf;
}

/******************************************************************************
 * Function: compare
 ******************************************************************************/
int compare(const void *a, const void *b)
{
    char *s1 = *(char**)a;
    char *s2 = *(char**)b;

    char *f1 = get_field(s1, field);
    char *f2 = get_field(s2, field);

    if(numeric)
        return atoi(f1) - atoi(f2);
    else
        return strcmp(f1, f2);
}

/******************************************************************************
 * Function: main
 ******************************************************************************/
int main(void)
{
    char *lines[] = {
        "john 25",
        "anna 19",
        "mike 30"
    };

    int n = 3;

    field = 1;     /* sort theo tuổi */
    numeric = 1;   /* so sánh số */

    qsort(lines, n, sizeof(char*), compare);

    for(int i = 0; i < n; i++)
        printf("%s\n", lines[i]);

    return 0;
}