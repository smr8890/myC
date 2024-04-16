#include "stdio.h"
#include "string.h"

int main() {
    char str[505];
    while (scanf("%s", str) != EOF) {
        char outputStr[505];
        int len_output = 0, cursor = 0;
        for (int i = 0; i < strlen(str); ++i) {
            //插入字母
            if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')) {
                for (int j = len_output; j >= cursor + 1; --j) {
                    outputStr[j] = outputStr[j - 1];
                }
                outputStr[cursor] = str[i];
                cursor++;
                len_output++;
            }
            //首尾跳转
            if (str[i] == '[') {
                cursor = 0;
            }
            if (str[i] == ']') {
                cursor = len_output;
            }
            //光标移动
            if (str[i] == '<' && cursor != 0) {
                cursor--;
            }
            if (str[i] == '>' && cursor != len_output) {
                cursor++;
            }
            //删除
            if (str[i] == '-' && cursor != 0) {
                for (int j = cursor - 1; j < len_output - 1; ++j) {
                    outputStr[j] = outputStr[j + 1];
                }
                len_output--;
                cursor--;
            }
            if (str[i] == '+' && cursor != len_output) {
                for (int j = cursor; j < len_output - 1; ++j) {
                    outputStr[j] = outputStr[j + 1];
                }
                len_output--;
            }
        }
        for (int i = 0; i < len_output; ++i) {
            printf("%c", outputStr[i]);
        }
        printf("\n");
    }
    return 0;
}