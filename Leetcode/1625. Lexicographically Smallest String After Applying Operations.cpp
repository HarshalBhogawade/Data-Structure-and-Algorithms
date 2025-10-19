#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        string minStr = s;
        queue<string> q;
        unordered_set<string> visited;
        
        q.push(s);
        visited.insert(s);
        
        while (!q.empty()) {
            string curr = q.front(); q.pop();
            if (curr < minStr) minStr = curr;

            // Operation 1: Add 'a' to odd indices
            string addStr = curr;
            for (int i = 1; i < addStr.size(); i += 2)
                addStr[i] = (addStr[i] - '0' + a) % 10 + '0';
            if (!visited.count(addStr)) {
                visited.insert(addStr);
                q.push(addStr);
            }

            // Operation 2: Rotate right by 'b'
            string rotStr = rotateRight(curr, b);
            if (!visited.count(rotStr)) {
                visited.insert(rotStr);
                q.push(rotStr);
            }
        }
        
        return minStr;
    }

private:
    string rotateRight(const string &s, int b) {
        int n = s.size();
        int k = b % n;
        return s.substr(n - k) + s.substr(0, n - k);
    }
};
