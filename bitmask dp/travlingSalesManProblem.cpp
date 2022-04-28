#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> memo;
// time complexity: O(n^2 * 2^n)
int solve(int city, int &visited,vector<vector<int>> cityDistances,int totalCities,int startCity){
   if(visited==(1<<totalCities)-1){
      return cityDistances[city][startCity];
   }
    if(memo[city][visited]!=-1) return memo[city][visited];
    int minDistance=INT_MAX;
    for(int i=0;i<totalCities;i++){
        int mask=(1<<i);
        if(visited&mask) continue;
        visited|=mask;
        int distance=cityDistances[city][i]+solve(i,visited,cityDistances,totalCities,startCity);
        visited^=mask;
        minDistance=min(minDistance,distance);
    }
    return memo[city][visited]=minDistance;
}

int main()
{
   int totalCities=4;
   int startCity=0;
   vector<vector<int>> cityDistances={{0,10,15,20},{5,0,9,10},{6,8,0,12},{8,8,9,0}};
    int visited=0;
    memo.resize(totalCities,vector<int>(1<<totalCities,-1));
    int distance=solve(startCity,visited,cityDistances,totalCities,startCity);
    cout<<distance;
    return 0;
}

