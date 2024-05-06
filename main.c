#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN 11

typedef struct Node {
    char *str;
    int swaps;
    struct Node *next;
} Node;

Node *createNode(char *str, int swaps) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->str = (char *)malloc(sizeof(char) * (MAX_LEN + 1));
    strcpy(newNode->str, str);
    newNode->swaps = swaps;
    newNode->next = NULL;
    return newNode;
}

void enqueue(Node **head, Node **tail, char *str, int swaps) {
    Node *newNode = createNode(str, swaps);
    if (*head == NULL) {
        *head = *tail = newNode;
    } else {
        (*tail)->next = newNode;
        *tail = newNode;
    }
}

Node *dequeue(Node **head, Node **tail) {
    if (*head == NULL) {
        return NULL;
    }
    Node *temp = *head;
    *head = (*head)->next;
    if (*head == NULL) {
        *tail = NULL;
    }
    return temp;
}

int countDistinct(char *str, int k) {
    Node *head = NULL, *tail = NULL;
    int visited[1000000] = {0};
    int count = 0;

    enqueue(&head, &tail, str, 0);
    visited[atoi(str)] = 1;
    count++;

    while (head != NULL) {
        Node *curr = dequeue(&head, &tail);
        char *currStr = curr->str;
        int currSwaps = curr->swaps;
        free(curr);

        if (currSwaps == k) {
            continue;
        }

        int len = strlen(currStr);
        for (int i = 0; i < len - 1; i++) {
            char temp[MAX_LEN + 1];
            strcpy(temp, currStr);
            char t=temp[i];
            temp[i]=temp[i+1];
            temp[i+1]=t;
            if (temp[0] != '0' && !visited[atoi(temp)]) {
                visited[atoi(temp)] = 1;
                enqueue(&head, &tail, temp, currSwaps + 1);
                count++;
            }
        }
    }

    return count;
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        char n[MAX_LEN + 1];
        int k;
        scanf("%s%d", n, &k);

        printf("%d\n", countDistinct(n, k));
    }

    return 0;
}