#include <stdio.h>
#include <string.h>
#include <math.h>

long long calculateExpression(char *expression, int *index) {
    long long result = 0;
    long long temp = 0;

    if (expression[*index] >= '0' && expression[*index] <= '9') {
        result = expression[(*index)++] - '0';
    } else if (expression[*index] == '(') {
        (*index)++;
        result = calculateExpression(expression, index);
        (*index)++;
    } else {
        return 0;
    }

    while (*index < strlen(expression)) {
        if (expression[*index] == ')') {
            result = pow(result, 2);
        } else if (expression[*index] == '(') {
            (*index)++;
            temp = calculateExpression(expression, index);
            result = pow(result + temp, 2);
            (*index)++;
        } else {
            break;
        }
    }

    return result;
}

int main() {
    char expression[101];

    while (scanf("%s", expression) != EOF) {
        int index = 0;
        long long result = calculateExpression(expression, &index);
        printf("%lld\n", result);
    }

    return 0;
}