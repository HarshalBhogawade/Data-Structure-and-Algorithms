#include<bits/stdc++.h>
using namespace std;

//brute force : tc->O(n^2)
//sc : O(n+m) knowsme and iknow array
int celebrity(vector<vector<int>> &mat){
    // n*n matrix where n represents no of people

    int n = mat.size();
    vector<int>iknow(n,0); //i knows them
    vector<int>knowsme(n,0);//j knows them
    for(int i=0;i<n;i++){
        for(int j = 0;j<n;j++){
            //check if 1
            if(mat[i][j]==1){
                //j knows i
                knowsme[j]++;
                //i knows j
                iknow[i]++;
            }
        }
    }
    //all remaining n-1 people must know the celebrity;
    //celebrity knows 0 person

    for(int i=0;i<n;i++){
        if(knowsme[i]==n-1 && iknow[i]==0){
            return i;
        }
    }
    return -1;
}

//optimal: tc : O(N) SC : O(1) approach two pointers
//we eliminating the normal peoples
int celebrity1(vector<vector<int>> &mat){
    int n=mat.size();
        int top = 0;
        int bottom = n-1;
        while(top<bottom){
            //if top knows bottom then it cannot be a celebrity
            if(mat[top][bottom]==1){
                top++;
            }
            //if bottom knows top then it cannot be a celebrity
            else if(mat[bottom][top]==1){
                bottom--;
            }else{  //if both dont know each other then both increment and decrement
                top++;
                bottom--;
            }
        }
        //if top is greater then it may not celebrity
        if(top>bottom) return -1;

        //Check if the person pointed 
        //by top is celebrity 
        for(int i=0;i<n;i++){
            if(i==top) continue;
            //check if it not a celebrity
            if(mat[top][i]==1 || mat[i][top]==0){
                return -1;
            }
        }
        return top;
}

int main(){
    vector<vector<int>> mat = {{0, 1, 0}, {0, 0, 0}, {0, 1, 0}};
    // cout << "\nThe id of celebrity is: " << bruteforce(mat);
    cout << "\nThe id of celebrity is: " << celebrity(mat);

    return 0;
}