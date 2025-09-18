
#include<iostream>
using namespace std;

int size;               // queue size
int front = -1, rear = -1;

bool isempty() {
    return (front == -1 && rear == -1);
}

bool isfull() {
    return (rear == size - 1);
}

void enqueue(int queue[], int value) {
    if (isfull()) {
        cout << "The queue is FULL. Cannot enqueue " << value << endl;
        return;
    }
    if (isempty()) {
        front = 0;
    }
    queue[++rear] = value;
    cout << "Value enqueued: " << value << endl;
}

void dequeue(int queue[]) {
    if (isempty()) {
        cout << "The queue is EMPTY. Cannot dequeue." << endl;
        return;
    }
    cout << queue[front] << " dequeued from queue" << endl;
    if (front == rear) {
        front = rear = -1; 
    } else {
        front++;
    }
}

void display(int queue[]) {
    if (isempty()) {
        cout << "The queue is EMPTY." << endl;
        return;
    }
    for (int i = front; i <= rear; i++) {
        cout << queue[i] << " ";
    }
    cout << endl;
}

void peek(int queue[]) {
    if (isempty()) {
        cout << "The queue is EMPTY." << endl;
    } else {
        cout << "Front element = " << queue[front] << endl;
    }
}

int main() {
    cout << "Enter size of the queue: ";
    cin >> size;
    int queue[size];   

    int choice, value;
    do {
        cout << "\nEnter 1 for isFull\n"
             << "Enter 2 for isEmpty\n"
             << "Enter 3 for enqueue\n"
             << "Enter 4 for dequeue\n"
             << "Enter 5 for display\n"
             << "Enter 6 for peek\n"
             << "Enter 0 to exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                if (isfull()) cout << "Queue is FULL\n";
                else cout << "Queue is NOT full\n";
                break;
            case 2:
                if (isempty()) cout << "Queue is EMPTY\n";
                else cout << "Queue is NOT empty\n";
                break;
            case 3:
                cout << "Enter the value: ";
                cin >> value;
                enqueue(queue, value);
                break;
            case 4:
                dequeue(queue);
                break;
            case 5:
                display(queue);
                break;
            case 6:
                peek(queue);
                break;
            case 0:
                cout << "Exiting";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 0);

    return 0;
}
