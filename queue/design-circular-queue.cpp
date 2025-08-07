#include <iostream>
using namespace std;

#define SIZE 5

class CircularQueue {
    int items[SIZE];
    int front, rear;

public:
    CircularQueue() {
        front = -1;
        rear = -1;
    }

    bool isFull() {
        return (front == 0 && rear == SIZE - 1) || (front == rear + 1);
    }

    bool isEmpty() {
        return front == -1;
    }

    void enQueue(int element) {
        if (isFull()) return;
        if (front == -1) front = 0;
        rear = (rear + 1) % SIZE;
        items[rear] = element;
    }

    void deQueue() {
        if (isEmpty()) return;
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % SIZE;
        }
    }

    void display() {
        if (isEmpty()) return;
        int i = front;
        while (true) {
            cout << items[i] << " ";
            if (i == rear) break;
            i = (i + 1) % SIZE;
        }
        cout << endl;
    }
};

int main() {
    CircularQueue q;
    q.enQueue(1);
    q.enQueue(2);
    q.enQueue(3);
    q.enQueue(4);
    q.enQueue(5);
    q.display();
    q.deQueue();
    q.display();
    q.enQueue(6);
    q.display();
    return 0;
}
