#include <iostream>
#include <stack>
using namespace std;

class myQueue {
    stack<int> s1, s2;

public:

    // Enqueue operation (costly)
    void enqueue(int x) {
        
        // Move all elements from s1 to s2
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }

        // Push the new item into s1
        s1.push(x);

        // Push everything back to s1
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }

    // Dequeue operation
    void dequeue() {
        if (s1.empty()) {
            
            // Queue underflow
            return; 
        }
        
        s1.pop();
    }

    // Front operation
    int front() {
        if (s1.empty()) {
            
            // Queue empty
            return -1; 
        }
        return s1.top();
    }

    // Size operation
    int size() {
        return s1.size();
    }
};

// Driver code
int main() {
    myQueue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    cout << "Front: " << q.front() << '\n';  
    cout << "Size: " << q.size() << '\n';    

    q.dequeue();              
    cout << "Front: " << q.front() << '\n';   
    cout << "Size: " << q.size() << '\n';    

    return 0;
}