#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

// Function to generate binary representations from 1 to N
vector<string> generate(int N)
{
    // Vector to store the binary representations
    vector<string> result;
    
    // Queue to store binary strings
    queue<string> q;
    
    // Start with binary representation of 1
    q.push("1");
    
    // Generate binary representations for numbers 1 to N
    for (int i = 0; i < N; i++)
    {
        // Add current front element to result (binary of current number)
        result.push_back(q.front());
        
        // Generate next two binary numbers by appending '0' and '1'
        // to current binary string
        q.push(q.front() + "0");  // For next even number
        q.push(q.front() + "1");  // For next odd number
        
        // Remove the processed element from queue
        q.pop();
    }
    return result;
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;
    
    // Get binary representations from 1 to n
    vector<string> binaryNumbers = generate(n);
    
    // Display the results
    cout << "Binary representations from 1 to " << n << ":" << endl;
    for (int i = 0; i < binaryNumbers.size(); i++) {
        cout << (i + 1) << " -> " << binaryNumbers[i] << endl;
    }
    
    return 0;
}int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;
    
    vector<string> binaryNumbers = generate(n);
    
    cout << "Binary representations from 1 to " << n << ":" << endl;
    for (int i = 0; i < binaryNumbers.size(); i++) {
        cout << (i + 1) << " -> " << binaryNumbers[i] << endl;
    }
    
    return 0;
}