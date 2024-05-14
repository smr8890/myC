#include "iostream"
#include "queue"

using namespace std;

priority_queue<int> max_heap;
priority_queue<int, vector<int>, greater<int>> min_heap;

void result(char *command) {
    if (command[1] == 'u') {//push
        int x;
        scanf("%d", &x);

        if (max_heap.empty() || x <= max_heap.top()) {
            max_heap.push(x);
        } else {
            min_heap.push(x);
        }

        if ((int) (max_heap.size() - min_heap.size()) > 1) {
            min_heap.push(max_heap.top());
            max_heap.pop();
        } else if (min_heap.size() > max_heap.size()) {
            max_heap.push(min_heap.top());
            min_heap.pop();
        }

    } else if (command[1] == 'o') {//pop
        printf("%d\n", max_heap.top());
        max_heap.pop();
        if (max_heap.size() < min_heap.size()) {
            max_heap.push(min_heap.top());
            min_heap.pop();
        }
    }
}

int main() {
    char command[5];
    while (scanf("%s", command) != EOF) {
        result(command);
    }
    return 0;
}