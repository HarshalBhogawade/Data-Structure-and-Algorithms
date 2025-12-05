#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        vector<long long> a(n), b(n);
        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < n; i++) cin >> b[i];

        /*
            We track all possible values of k (score)
            after each turn.

            ✓ k starts at 0 → possible range is [0, 0]
            ✓ After each turn, the range expands or shifts.

            Why a range?
            ----------
            Because choosing red or blue gives TWO possible new scores.
            Over many turns, this becomes a full interval of possible scores.
        */

        long long L = 0, R = 0;   // Current possible range of k

        for(int i = 0; i < n; i++){

            /*
                CURRENT TURN:
                You may choose:

                1. Red card → new score = k - a[i]
                2. Blue card → new score = b[i] - k

                Since k is not a single number but a range [L, R],
                we must transform the whole interval.
            */

            // --- RED CARD transformation ---
            // If k ∈ [L, R], then k - a[i] ∈ [L - a[i], R - a[i]]
            long long redMin = L - a[i];
            long long redMax = R - a[i];

            // --- BLUE CARD transformation ---
            // If k ∈ [L, R], then b[i] - k ∈ [b[i] - R, b[i] - L]
            long long blueMin = b[i] - R;
            long long blueMax = b[i] - L;

            /*
                NEW POSSIBLE RANGE:
                After choosing either red or blue,
                possible scores lie in the UNION of both intervals.

                Since both are simple intervals,
                the final range is:

                newL = min(redMin, blueMin)
                newR = max(redMax, blueMax)
            */

            long long newL = min(redMin, blueMin);
            long long newR = max(redMax, blueMax);

            // Update the range for next iteration
            L = newL;
            R = newR;
        }

        /*
            The problem asks for the MAXIMUM score.
            That is the largest possible value in the final range → R.
        */
        cout << R << "\n";
    }
    return 0;
}
