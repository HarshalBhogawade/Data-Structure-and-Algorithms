#include <bits/stdc++.h>
using namespace std;

string isequal(string a, string b) {

    vector<int> freq(256, 0);

    for(char ch : a) freq[ch]++;
    for(char ch : b) freq[ch]--;

    
    for(int x : freq) {
        if(x != 0) return "NO";
    }
    return "YES";
}

int main(){
    int n;
    cin >> n;
    while(n--){
        int len;
        cin >> len;
        string a, b;
        cin >> a >> b;
        cout << isequal(a,b) << endl;
    }
}
