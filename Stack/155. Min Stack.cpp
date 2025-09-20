#include<bits/stdc++.h>
using namespace std;
    stack<pair<int,int>>st;
    void push(int val) {
        if(st.empty()){
            st.push({val,val});
        }else{
            st.push({val,min(val,st.top().second)});
        }
    }
    
    void pop() {
        if(!st.empty()) st.pop();
    }
    
    int top() {
        if(!st.empty())  return st.top().first;
        return -1;
    }
    
    int getMin() {
        if(!st.empty()) return st.top().second;
        return -1;
    }
int main(){
    push(12);
    push(15);
    push(10);
    
    cout << "Top element: " << top() << endl;
    cout << "Minimum element: " << getMin() << endl;
    
    pop();
    cout << "After pop - Top: " << top() << endl;
    cout << "After pop - Min: " << getMin() << endl;
    
    push(5);
    cout << "After push(5) - Top: " << top() << endl;
    cout << "After push(5) - Min: " << getMin() << endl;

    return 0;
}