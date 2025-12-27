#include <stdio.h>
#include <string.h>
#include "parser.h"

#define BUF_SIZE 1024

int main(void)
{
    char input[BUF_SIZE];
    char output[BUF_SIZE * 2];  // 替换后字符串会变长，留足空间

    // 按行读取标准输入
    while (fgets(input, sizeof(input), stdin) != NULL) {
        replace_name(input, output);
        fputs(output, stdout);
    }

    return 0;
}
