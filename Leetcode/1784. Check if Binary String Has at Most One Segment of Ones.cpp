#include<bits/stdc++.h>
using namespace std;
bool checkOnesSegment(string s) {
        bool prevState = false;
        int segmentCount = 0;

        for (int i = 0; i < s.size(); i++) {
            char ch = s[i];

            if (ch == '1') {
                if (prevState == false) {
                    segmentCount++;
                    prevState = true;
                }
            } else {
                prevState = false;
            }
        }

        if (segmentCount > 1) {
            return false;
        }
        return true;
    }
int main(){

}