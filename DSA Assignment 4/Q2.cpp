#include <iostream>
#define MAX_SIZE 5
using namespace std;

class Queue {
private:
    int arr[MAX_SIZE];
    int front, rear;
    
public:
    Queue() {
        front = -1;
        rear = -1;
    }
    
    void enqueue(int data) {
        if (isFull()) {
            cout << "Queue is Full!" << endl;
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % MAX_SIZE;
        }
        arr[rear] = data;
        cout << data << " enqueued successfully." << endl;
    }
    
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is Empty!" << endl;
            return;
        }
        cout << arr[front] << " dequeued successfully." << endl;
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % MAX_SIZE;
        }
    }
    
    bool isEmpty() {
        return (front == -1);
    }
    
    bool isFull() {
        return ((front == 0 && rear == MAX_SIZE - 1) || (front == rear + 1));
    }
    
    void display() {
        if (isEmpty()) {
            cout << "Queue is Empty!" << endl;
            return;
        }
        cout << "Queue: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % MAX_SIZE;
        }
        cout << endl;
    }
    
    void peek() {
        if (isEmpty()) {
            cout << "Queue is Empty!" << endl;
            return;
        }
        cout << "Front element: " << arr[front] << endl;
    }
};

int main() {
    Queue q;
    int choice, data;
    
    cout << "Max Size: " << MAX_SIZE << endl;
    
    do {
        cout << "\n1. Enqueue\n2. Dequeue\n3. isEmpty()\n4. isFull()\n5. Display\n6. Peek\n0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "Enter data: ";
                cin >> data;
                q.enqueue(data);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                cout << "Queue is " << (q.isEmpty() ? "Empty" : "Not Empty") << endl;
                break;
            case 4:
                cout << "Queue is " << (q.isFull() ? "Full" : "Not Full") << endl;
                break;
            case 5:
                q.display();
                break;
            case 6:
                q.peek();
                break;
            case 0:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != 0);
    
    return 0;
}
