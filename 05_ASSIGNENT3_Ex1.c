/******************************************************************************
 * File: case_convert.c
 *
 * Description:
 *    Chương trình chuyển đổi chữ hoa sang chữ thường hoặc ngược lại
 *    tùy theo tên chương trình khi chạy.
 *
 * Author: ChatGPT
 * Date: 2026
 ******************************************************************************/

#include <stdio.h>
#include <ctype.h>
#include <string.h>

/******************************************************************************
 * Function: main
 *
 * Description:
 *    Hàm chính của chương trình. Đọc ký tự từ stdin và chuyển đổi
 *    chữ hoa hoặc chữ thường tùy theo tên chương trình.
 *
 * Parameters:
 *    int argc : số lượng tham số dòng lệnh
 *    char *argv[] : danh sách tham số dòng lệnh
 *
 * Returns:
 *    0
 ******************************************************************************/
int main(int argc, char *argv[])
{
    int c;

    /* kiểm tra tên chương trình */
    if (strstr(argv[0], "tolower") != NULL)
    {
        while ((c = getchar()) != EOF)
        {
            putchar(tolower(c));
        }
    }
    else if (strstr(argv[0], "toupper") != NULL)
    {
        while ((c = getchar()) != EOF)
        {
            putchar(toupper(c));
        }
    }
    else
    {
        printf("Program name must contain 'tolower' or 'toupper'\n");
    }

    return 0;
}