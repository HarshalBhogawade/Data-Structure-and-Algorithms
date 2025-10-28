#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int s;
        cin >> s;
        vector<int> arr(s);
        bool hasEven = false, hasOdd = false;
        for(int i = 0; i < s; ++i){
            cin >> arr[i];
            if(arr[i] % 2 == 0) hasEven = true;
            else hasOdd = true;
        }

        if(hasEven && hasOdd){
            sort(arr.begin(), arr.end());
        }
        // else: all same parity -> cannot change order, print as is

        for(int x : arr) cout << x << " ";
        cout << "\n";
    }
    return 0;
}
