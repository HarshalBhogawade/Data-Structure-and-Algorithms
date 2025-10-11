#include<iostream>
#include<stack>
#include<queue>

void reversequeue(std::queue<int>&q){
    std::stack<int>st;
        int n = q.size();
        for (int i = 0; i < n; i++) {
            st.push(q.front());
            q.pop();
        }
        
        while(!st.empty()){
            q.push(st.top());
            st.pop();
        }
}
int main(){
    std::queue<int>q;
    // Populate the queue with some values
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    // Reverse the queue
    reversequeue(q);

    // Print the reversed queue
    while(!q.empty()){
        std::cout << q.front() << " ";
        q.pop();
    }
    std::cout << std::endl;
    return 0;
}