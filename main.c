#include <stdio.h>
#include <string.h>
#include "parser.h"

#define BUF_SIZE 1024

int main(void)
{
    char input[BUF_SIZE];
    char output[BUF_SIZE * 2]; // 替换后字符串会变长，留足空间
    size_t line_count = 0;

    // 按行读取标准输入并统计行数
    while (fgets(input, sizeof(input), stdin) != NULL)
    {
        replace_name(input, output);
        fputs(output, stdout);
        line_count++;
    }

    // 程序结束时打印行统计到 stderr（不影响 stdout 的数据流）
    fprintf(stderr, "Lines: %zu\n", line_count);

    return 0;
}
