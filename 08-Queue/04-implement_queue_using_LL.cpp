#include <iostream>
using namespace std;

// Node class
class Node {
public:
    int data;
    Node* next;
    Node(int new_data) {
        data = new_data;
        next = nullptr;
    }
};

// Queue class
class myQueue {
private:
    int currSize;
    Node* front;
    Node* rear;

public:
    myQueue() {
        currSize = 0;
        front = rear= nullptr;
    }

    // Check if empty
    bool isEmpty() {
        return front == nullptr;
    }

    // Enqueue
    void enqueue(int new_data) {
        Node* node = new Node(new_data);
        if (isEmpty()) {
            front = rear = node;
        } else {
            //moving rear ahead
            rear->next = node;
            rear = node;
        }
        //increase size
        currSize++;
    }

    // Dequeue
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow" << endl;
            return -1;
        }
        
        //saving node to delete
        Node* temp = front;
        //getting data to return of deleted node
        int removedData = temp->data;
        //front moving ahead
        front = front->next;
        //if front null means size zero so make both ptr null
        if (front == nullptr) rear = nullptr;
        //removing space
        delete temp;
        //decrease size;
        currSize--;
        return removedData;
    }

    // Get front element
    int getfront() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return front->data;
    }

    // Get size
    int size() {
       return currSize;
    }
};

int main() {
    myQueue q;
    
    q.enqueue(10);
    q.enqueue(20);

    cout << "Dequeue: " << q.dequeue() << "\n";
    
    q.enqueue(30);

    cout << "Front: " << q.getfront() << endl;
    cout << "Size: " << q.size() << endl;

    return 0;
}