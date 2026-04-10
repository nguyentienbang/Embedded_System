/******************************************************************************
 * File: strend.c
 *
 * Description:
 *    Kiểm tra chuỗi t có xuất hiện ở cuối chuỗi s hay không.
 *
 * Author: ChatGPT
 * Date: 2026
 ******************************************************************************/

#include <stdio.h>
#include <string.h>

/******************************************************************************
 * Function: strend
 *
 * Description:
 *    Trả về 1 nếu t nằm ở cuối s, ngược lại trả về 0.
 *
 * Parameters:
 *    char *s
 *    char *t
 *
 * Returns:
 *    int
 ******************************************************************************/
int strend(char *s, char *t)
{
    int len_s = strlen(s);
    int len_t = strlen(t);

    if(len_t > len_s)
        return 0;

    return strcmp(s + len_s - len_t, t) == 0;
}

/******************************************************************************
 * Function: main
 ******************************************************************************/
int main(void)
{
    char s[] = "hello world";
    char t[] = "world";

    printf("Result: %d\n", strend(s, t));

    return 0;
}