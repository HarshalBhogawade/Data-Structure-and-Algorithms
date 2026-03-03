#include<bits/stdc++.h>
using namespace std;
/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        long long i=0;
        long long j=n;
        if(n==1 ) return 1;

        while(i<=j){
            long long mid = i+(j-i)/2;
            long long num = guess(mid);
            if(num == 0){
                return (int)mid;
            }else if(num == -1){
                j = mid-1;
            }else{
                i = mid+1;
            }
        }
        return -1;
    }
};
int main(){

}