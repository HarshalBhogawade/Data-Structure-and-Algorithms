#include <bits/stdc++.h>
using namespace std;


//problem : 
//key identification from distance and time is speed 
//returned the racer with the most speed as a winner
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int d,tm;
	    int index = -1;
	    int maxspeed = -1;
	    for(int i=1;i<=n;i++){
	        cin>>d>>tm;
	        int speed = d/tm;
	        if(speed > maxspeed){
	            maxspeed  = speed;
	            index = i;
	        }
	    }
	    cout<<index<<endl;
	    
	    
	}
}
