#include <bits/stdc++.h>
using namespace std;
// srctower //aux_twr //dest_toower
//tc : O(2^N -1)
void toh(int n, char a, char b, char c)
{
    if (n == 0)
    {
        return;
    }
    toh(n - 1, a, c, b);
    cout << "Move disk " << n << " from rod " << a
         << " to rod " << b << endl;
    toh(n - 1, b, a, c);
}
int main()

{
    int N = 3;
    // A, B and C are names of rods
    toh(N, 'A', 'B', 'C');
    return 0;
}