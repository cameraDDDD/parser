#include <stdio.h>
#include <string.h>
#include "parser.h"

#define OLD_STR "胡凯闻"
#define NEW_STR "胡凯闻大帅逼"

void replace_name(const char *src, char *dest)
{
    const char *p = src;
    char *q = dest;
    const char *match;
    size_t old_len = strlen(OLD_STR);
    size_t new_len = strlen(NEW_STR);

    /* 找到下一个匹配前的前缀，复制前缀，然后写入替换字符串 */
    while ((match = strstr(p, OLD_STR)) != NULL)
    {
        size_t prefix = (size_t)(match - p);
        if (prefix)
        {
            memcpy(q, p, prefix);
            q += prefix;
        }
        memcpy(q, NEW_STR, new_len);
        q += new_len;
        p = match + old_len;
    }

    /* 复制剩余部分并结束 */
    strcpy(q, p);
}
