/******************************************************************************
 * File: compare_files.c
 *
 * Description:
 *    Chương trình so sánh hai file văn bản và in ra dòng đầu tiên
 *    mà chúng khác nhau.
 *
 * Author: ChatGPT
 * Date: 2026
 ******************************************************************************/

#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

/******************************************************************************
 * Function: main
 *
 * Description:
 *    Mở hai file được truyền từ command line, đọc từng dòng và so sánh.
 *    Khi gặp dòng khác nhau đầu tiên thì in ra và kết thúc.
 *
 * Parameters:
 *    int argc : số tham số dòng lệnh
 *    char *argv[] : danh sách tham số dòng lệnh
 *
 * Returns:
 *    0
 ******************************************************************************/
int main(int argc, char *argv[])
{
    FILE *fp1;
    FILE *fp2;

    char line1[MAXLINE];
    char line2[MAXLINE];

    int line = 1;

    /* kiểm tra số tham số */
    if(argc != 3)
    {
        printf("Usage: %s file1 file2\n", argv[0]);
        return 1;
    }

    /* mở file */
    fp1 = fopen(argv[1], "r");
    fp2 = fopen(argv[2], "r");

    if(fp1 == NULL || fp2 == NULL)
    {
        printf("Error opening files\n");
        return 1;
    }

    /* đọc và so sánh từng dòng */
    while(fgets(line1, MAXLINE, fp1) != NULL &&
          fgets(line2, MAXLINE, fp2) != NULL)
    {
        if(strcmp(line1, line2) != 0)
        {
            printf("Files differ at line %d\n", line);
            printf("File1: %s", line1);
            printf("File2: %s", line2);
            return 0;
        }

        line++;
    }

    /* kiểm tra nếu 1 file dài hơn */
    if(fgets(line1, MAXLINE, fp1) != NULL ||
       fgets(line2, MAXLINE, fp2) != NULL)
    {
        printf("Files differ in length at line %d\n", line);
    }
    else
    {
        printf("Files are identical\n");
    }

    fclose(fp1);
    fclose(fp2);

    return 0;
}