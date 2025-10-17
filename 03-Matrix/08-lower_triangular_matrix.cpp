#include<bits/stdc++.h>
using namespace std;
class lowermat{
    public:
    vector<vector<int>> lower(int n , int m){
        //when i < j those elements will be zero 
        //when i >= j those elements will be non zero
        vector<vector<int>>mat(n,vector<int>(m,0));
        for(int i =0;i<n;i++){
            for(int j=0;j<m;j++){
                if(j<=i){
                    mat[i][j] = 1;
                }else{
                    mat[i][j] = 0;
                }
            }
        }
        return mat;
    }

    void print(vector<vector<int>>mat){
        for(auto & row : mat){
            for(auto & num : row){
                cout<<num<<" ";

            }
            cout<<endl;
        }
    }
};
int main(){
    lowermat obj;
    vector<vector<int>>ans = obj.lower(5,5);
    obj.print(ans);
    cout<<endl;
    cout<<"Number of non zeros  "<<5*(5+1)/2<<endl;
    cout<<"Numver of zeros: "<<5*5 - 5*(5+1)/2;
}