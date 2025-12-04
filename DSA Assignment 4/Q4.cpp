#include <iostream>
#include <queue>
using namespace std;

class StackTwoQueues {
    queue<int> q1, q2;

public:
    void push(int x) {
        // Push x to empty q2
        q2.push(x);

        // Pour all elements from q1 to q2
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }

        // Swap names of q1 and q2
        swap(q1, q2);
    }

    void pop() {
        if (q1.empty()) {
            cout << "Stack is empty\n";
            return;
        }
        else{
            cout << "Popped: " << q1.front() << endl;
            q1.pop();
        }
    }

    int top() {
        if (q1.empty()) {
            cout << "Stack is empty\n";
            return -1;
        }
        return q1.front();
    }

    bool empty() {
        return q1.empty();
    }
};

class StackOneQueue {
    queue<int> q;

public:
    void push(int x) {
        int size = q.size();
        q.push(x);

        // Rotate the queue to move newest element to front
        for (int i = 0; i < size; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    void pop() {
        if (q.empty()) {
            cout << "Stack is empty\n";
            return;
        }
        cout << "Popped: " << q.front() << endl;
        q.pop();
    }

    int top() {
        if (q.empty()) {
            cout << "Stack is empty\n";
            return -1;
        }
        return q.front();
    }

    bool empty() {
        return q.empty();
    }
};

int main() {
    StackTwoQueues s;
    s.push(10);
    s.push(20);
    cout << "Top: " << s.top() << endl; // 20
    s.pop();                            // Pops 20
    cout << "Top: " << s.top() << endl; // 10
    s.pop();                            // Pops 10
    s.pop();                            // Empty stack

    StackOneQueue s1;
    s1.push(30);
    s1.push(45);
    cout << "Top: " << s1.top() << endl; // 30
    s1.pop();                            // Pops 30
    cout << "Top: " << s1.top() << endl; // 45
    s1.pop();                            // Pops 45
    s1.pop();                            // Empty stack
    
    return 0;
}
