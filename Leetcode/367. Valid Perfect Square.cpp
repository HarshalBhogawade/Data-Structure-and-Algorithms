
/*if have n = 9 
0->1->2->......->9
s1  consider left = 0 and right = 9
s2  calculate mid ;
s3  calculate square of mid
s4  compare that square to the n 
    if equal return true
    if square greater than n (means perfect square is behind the mid)
      do right = mid-1;
    if square is smaller than n (maens perfect square is ahead)
      do left = mid+1;
at the end return false if we not find any perfect square
*/

class Solution {
public:
    bool isPerfectSquare(int num) {
        int left = 0;
        int right = num;
        while(left<=right){
            long long mid = left + (right-left)/2;
            long long square = mid*mid;
            if(square == num) return true;
            if(square>num) right = mid-1;
            else left = mid+1;
        }
        return false;
    }
};
