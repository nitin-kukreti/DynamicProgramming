/*
* we have give array of integers and we need to find longest increasing subsequence
* example: [10, 22, 9, 33, 21, 50, 41, 60, 80]
* output: 6 as [10, 22, 33, 50, 60, 80] 
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> memo;
int Lis(int index,vector<int>& arr,int prevIndex){
    if(index==arr.size()+1) return 0;
     
    if(memo[index][prevIndex]!=-1) return memo[index][prevIndex];

    // if current element is greater than previous element
    int take=0;
    if(prevIndex==0 || arr[index-1]>arr[prevIndex-1]){
        // we have two options
        // 1. we can include current element in the subsequence
        // 2. we can not include current element in the subsequence
        // we will take the max of the two options
        take=1+Lis(index+1,arr,index);
    }
    int not_take=Lis(index+1,arr,prevIndex);
    return memo[index][prevIndex]=max(take,not_take);
    
}

int iterative_Lcs(vector<int> arr){
    int n=arr.size();
    vector<vector<int>> dp(n+2,vector<int>(n+2,0));
    vector<vector<int>> prev(n+2,vector<int>(n+2,0));
    for(int index=n;index>=1;index--){
        for(int prevIndex=0;prevIndex<=n;prevIndex++){
            // if current element is greater than previous element
            int take=0;
            if(prevIndex==0 || arr[index-1]>arr[prevIndex-1]){
                // we have two options
                // 1. we can include current element in the subsequence
                // 2. we can not include current element in the subsequence
                // we will take the max of the two options
                take=1+dp[index+1][index];
            }
            int not_take=dp[index+1][prevIndex];
            if(take>not_take){
                dp[index][prevIndex]=take;
                prev[index][prevIndex]=index;
            }
            else{
                dp[index][prevIndex]=not_take;
                prev[index][prevIndex]=prevIndex;
            }
        }
    }


    return dp[1][0];
}

int main(){
    vector<int> arr={10, 22, 9, 33, 21, 50, 41, 60, 80};
    int n=arr.size();
    memo.resize(n+2,vector<int>(n+2,-1));
    cout<<iterative_Lcs(arr)<<endl;
    return 0;
}