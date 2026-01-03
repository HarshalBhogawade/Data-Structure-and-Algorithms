    int numOfWays(int n) {
        const int MOD = 1000000007;

        long long a = 6; // ABA patterns
        long long b = 6; // ABC patterns

        for (int i = 2; i <= n; ++i) {
            long long na = (a * 3 + b * 2) % MOD;
            long long nb = (a * 2 + b * 2) % MOD;
            a = na;
            b = nb;
        }

        return (a + b) % MOD;
    }
