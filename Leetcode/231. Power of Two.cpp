/*
1)  A number is a power of two if it can be divided by 2 repeatedly until it becomes 1.
2)  If at any step the number becomes odd (and not 1), then it is not a power of two.
3)  Start with the given number n.
4)  Keep dividing n by 2 while n % 2 == 0.
5)  If finally n == 1, return true; else return false
*/

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0) return false;
        while(n%2==0){
            n /=2;
        }
        return n==1;
    }
};
