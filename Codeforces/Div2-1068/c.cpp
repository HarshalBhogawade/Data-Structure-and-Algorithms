#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        long long k;
        cin >> n >> k;
        
        vector<long long> a(n);
        set<long long> aSet;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            aSet.insert(a[i]);
        }
        
        // Find valid candidates
        vector<long long> candidates;
        
        for (long long x : aSet) {
            // Only check if number of multiples is reasonable
            long long numMultiples = k / x;
            if (numMultiples > 200000) continue; // Too many multiples to check
            
            bool valid = true;
            for (long long mult = x; mult <= k; mult += x) {
                if (aSet.find(mult) == aSet.end()) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                candidates.push_back(x);
            }
        }
        
        // Sort candidates by value (smaller values cover more)
        sort(candidates.begin(), candidates.end());
        
        // Greedy set cover
        set<long long> uncovered(a.begin(), a.end());
        vector<long long> result;
        
        while (!uncovered.empty()) {
            long long best = -1;
            int maxCover = 0;
            
            // Find candidate that covers most uncovered elements
            for (long long b : candidates) {
                int cover = 0;
                for (long long x : uncovered) {
                    if (x % b == 0) {
                        cover++;
                    }
                }
                if (cover > maxCover) {
                    maxCover = cover;
                    best = b;
                }
            }
            
            if (best == -1) {
                cout << -1 << "\n";
                goto next_case;
            }
            
            result.push_back(best);
            
            // Remove covered elements
            auto it = uncovered.begin();
            while (it != uncovered.end()) {
                if (*it % best == 0) {
                    it = uncovered.erase(it);
                } else {
                    ++it;
                }
            }
        }
        
        cout << result.size() << "\n";
        for (int i = 0; i < result.size(); i++) {
            if (i > 0) cout << " ";
            cout << result[i];
        }
        cout << "\n";
        
        next_case:;
    }
    
    return 0;
}