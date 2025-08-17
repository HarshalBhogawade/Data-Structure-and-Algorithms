class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        if (k == 0 || n >= k + maxPts) return 1.0;
        
        vector<double>dp(n+1,0.0);
        dp[0]=1.0;
        double windowSum =1.0;
        double ans = 0.0;
        for(int i=1;i<=n;i++){
            dp[i] = windowSum / maxPts;
            if(i<k){
                windowSum += dp[i];
            }
            else{
                ans += dp[i];
            }
            if(i-maxPts >= 0){
                windowSum -= dp[i-maxPts];
            }
        }
        return ans;        
    }
};


/*Code Explanation
if (k == 0 || n >= k + maxPts) return 1.0;


Case 1: If k == 0, Alice never draws → score = 0 → always ≤ n → probability = 1.

Case 2: If n >= k + maxPts, then Alice’s maximum possible final score (k + maxPts - 1) is still ≤ n → so probability = 1.

vector<double> dp(n + 1, 0.0);
dp[0] = 1.0;


dp[i] = probability that Alice reaches score i.

Alice starts with 0 points, so dp[0] = 1.0.

double windowSum = 1.0;  
double ans = 0.0;


windowSum = sum of the last maxPts values of dp (used for sliding window).

Initially windowSum = dp[0] = 1.0.

ans will store the final probability of ending with ≤ n.

for (int i = 1; i <= n; i++) {
    dp[i] = windowSum / maxPts;


To reach i, Alice must have come from one of the last maxPts states:

dp[i] = (dp[i-1] + dp[i-2] + ... + dp[i-maxPts]) / maxPts


Instead of summing every time, we use windowSum for efficiency.

    if (i < k) {
        windowSum += dp[i];   // Alice can still draw
    } else {
        ans += dp[i];         // Alice stops at >= k
    }


If i < k: Alice hasn’t reached stopping condition yet → add dp[i] into windowSum (it can generate future states).

If i >= k: Alice stops → final score could be i → add to ans.

    if (i - maxPts >= 0) {
        windowSum -= dp[i - maxPts]; // remove oldest value
    }
}


Keeps windowSum size equal to maxPts.

Sliding window ensures efficiency → O(n).

return ans;


After loop, ans holds total probability that final score is between [k, n].

That’s the answer.
*/
