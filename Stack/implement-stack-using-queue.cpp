#include <bits/stdc++.h>
using namespace std;

// using deque we can perform insertion and deletion at both ends , in stack we need insertiion at one end only
// so we can either use front or back to implement a stack;
//also the operations complexity is O(1)
int main()
{
    deque<int> stack;
    stack.push_back(2);
    stack.push_back(4);
    cout << stack.back() << "Popped from deque" << endl;
    stack.pop_back();
    cout << "Top element is: " << stack.back();
    return 0;
}