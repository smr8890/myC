#include "iostream"
#include "queue"

using namespace std;

int main() {
    priority_queue<int> max;
    priority_queue<int, vector<int>, greater<int>> min;
    printf("%d\n",max.size());
    max.push(1);
    printf("%d\n",max.top());
    printf("%d\n",max.size());
    max.pop();
    printf("%d\n",max.size());
    max.push(2);
    max.push(1);
    printf("%d",max.top());
    return 0;
}