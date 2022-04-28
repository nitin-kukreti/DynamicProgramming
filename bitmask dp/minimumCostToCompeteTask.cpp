#include<bits/stdc++.h>
using namespace std;
 
 vector<vector<int>> memo;

int solve(vector<vector<int>> jobs,int person,int n,int &used){
    if(person==n){
        return 0;
    }
    if(memo[person][used]!=-1){
        return memo[person][used];
    }
    int ans=INT_MAX;
    for(int i=0;i<n;i++){
       int mask=1<<i;
       if(used&mask){
           continue;
       }
         used|=mask;
            int temp=jobs[person][i]+solve(jobs,person+1,n,used);
            ans=min(ans,temp);
            used^=mask;
    }
    return memo[person][used]=ans;
}


int main(){
    int n=4;
    vector<vector<int>> dp(n,vector<int>(1<<n,-1));
    memo=dp;
    vector<vector<int>> jobs={{9,2,7,8},{6,4,3,7},{5,8,1,8},{7,6,9,4}};
    int used=0;
    cout<<solve(jobs,0,n,used)<<endl;
    return 0;
}