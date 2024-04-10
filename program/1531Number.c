#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int num[100000];

int cmp_int(const void* _a , const void* _b)//参数格式固定
{
    int* a = (int*)_a; //强制类型转换
    int* b = (int*)_b;
    return *a - *b;
}
int cmp_char(const void *_a, const void *_b)//参数格式固定
{
    char *a = (char *) _a;//强制类型转换
    char *b = (char *) _b;
    return *a - *b;
}

int sameDigits(int a, int b) {
    char astr[7], bstr[7];
    sprintf(astr, "%d", a);
    sprintf(bstr, "%d", b);
    qsort(astr, strlen(astr), sizeof(char),cmp_char);
    qsort(bstr, strlen(bstr), sizeof(char),cmp_char);
    if(strcmp(astr,bstr)==0)
        return 1;
    return 0;
}

int main() {
    int len = 0, i, j, k;
    int x, y, n, temp;
    for (y = 10; y < 100001; y++) {
        for (x = 1; x < 10; x++) {
            n = x * y;
            if (sameDigits(n,10*y+x)) {
                num[len] = n;
                len++;
            }
        }
    }

//    for (i = 0; i < len - 1; i++) {
//        for (j = 0; j < len - i - 1; j++) {
//            if (num[i] > num[i + 1]) {
//                temp = num[i];
//                num[i] = num[i + 1];
//                num[i + 1] = temp;
//            }
//        }
//    }
    qsort(num, len,sizeof (int ),cmp_int);

    for (k = 0; k < len; k++) {
        printf("%d\n", num[k]);
    }
}