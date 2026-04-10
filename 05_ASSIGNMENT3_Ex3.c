/******************************************************************************
 * File: print_files.c
 *
 * Description:
 *    Chương trình in nhiều file. Mỗi file bắt đầu ở trang mới,
 *    có tiêu đề và số trang.
 *
 * Author: ChatGPT
 * Date: 2026
 ******************************************************************************/

#include <stdio.h>

#define MAXLINE 1000
#define PAGE_LENGTH 40

/******************************************************************************
 * Function: print_file
 *
 * Description:
 *    In nội dung một file với tiêu đề và số trang.
 *
 * Parameters:
 *    FILE *fp : con trỏ file
 *    char *name : tên file
 *
 * Returns:
 *    none
 ******************************************************************************/
void print_file(FILE *fp, char *name)
{
    char line[MAXLINE];
    int line_count = 0;
    int page = 1;

    printf("\n===== File: %s | Page: %d =====\n", name, page);

    while(fgets(line, MAXLINE, fp) != NULL)
    {
        printf("%s", line);

        line_count++;

        if(line_count == PAGE_LENGTH)
        {
            page++;
            line_count = 0;

            printf("\n===== File: %s | Page: %d =====\n", name, page);
        }
    }
}

/******************************************************************************
 * Function: main
 *
 * Description:
 *    Mở từng file từ command line và gọi hàm in file.
 *
 * Parameters:
 *    int argc
 *    char *argv[]
 *
 * Returns:
 *    0
 ******************************************************************************/
int main(int argc, char *argv[])
{
    FILE *fp;
    int i;

    if(argc < 2)
    {
        printf("Usage: %s file1 file2 ...\n", argv[0]);
        return 1;
    }

    for(i = 1; i < argc; i++)
    {
        fp = fopen(argv[i], "r");

        if(fp == NULL)
        {
            printf("Cannot open %s\n", argv[i]);
            continue;
        }

        print_file(fp, argv[i]);

        fclose(fp);

        printf("\n\n--- NEW FILE ---\n\n");
    }

    return 0;
}