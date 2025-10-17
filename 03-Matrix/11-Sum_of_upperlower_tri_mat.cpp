#include<bits/stdc++.h>
using namespace std;
class sumofupperlower{
    public:
    void sum (vector<vector<int>>mat){
        int uppersum = 0;
        int lowersum = 0;
        int n = mat.size();
        int m = mat[0].size();
        for(int i=0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(i<=j){
                    uppersum += mat[i][j];
                }
                if(i>=j){
                    lowersum += mat[i][j];
                }
            }
        }
        cout<<"Upper Matrix Sum: "<<uppersum<<endl;
        cout<<"Lower matrix sum: "<<lowersum<<endl;
    }
};
int main(){
    vector<vector<int>>mat = {{6, 5, 4}, {1, 2, 5}, {7, 9, 7}};
    sumofupperlower obj;
    obj.sum(mat);
}