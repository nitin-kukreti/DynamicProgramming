#include<bits/stdc++.h>
using namespace std;

/*
//  Created by Nitin Kukreti on 2022-04-27.
// problem is unbounded knapsack problem
// we can pick any item  multiple times
*/


struct Item{
    int weight;
    int value;
    Item(int w, int v): weight(w), value(v){}
};


// recursive solution time complexity O(2^n) space complexity O(n)
int recursive_kapsack(int item,int capacity,vector<Item> &items){

// if we have 0 items or our capacity is 0 then we can't take any items
    if(item==0 || capacity==0) return 0;

//  when we not take the current item
  int not_taken=recursive_kapsack(item-1,capacity,items);

 // if the weight of the current item is less than the capacity then we can take it
  int taken=0;
  if(items[item-1].weight<=capacity){
      // pick and try to pick same item multiple times
    taken=items[item-1].value+recursive_kapsack(item,capacity-items[item-1].weight,items);
  }   

  return max(taken,not_taken);
}

// recursive memoization time complexity O(n*capacity) space complexity O(n*capacity) + O(n)
int recursive_kapsackMemo(int item,int capacity,vector<Item> &items,vector<vector<int>> &memo){

// if we have 0 items or our capacity is 0 then we can't take any items
    if(item==0 || capacity==0) return 0;
   if(memo[item][capacity]!=-1) return memo[item][capacity];

// when we not take the current item
  int not_taken=recursive_kapsackMemo(item-1,capacity,items,memo);

 // if the weight of the current item is less than the capacity then we can take it
  int taken=0;
  if(items[item-1].weight<=capacity){
      // pick and try to pick same item multiple times
    taken=items[item-1].value+recursive_kapsackMemo(item,capacity-items[item-1].weight,items,memo);
  }   

  return memo[item][capacity]=max(taken,not_taken);
}

// time complexity O(n*capacity) space complexity O(n*capacity)
int tabular_kapsack(int capacity,vector<Item> &items){
    int n=items.size();
    vector<vector<int>> T(n+1,vector<int>(capacity+1,0));
    
    // we have profit of 0 if we have 0 items or our capacity is 0
    for(int i=0;i<=n;i++) T[i][0]=0;
    for(int i=0;i<=capacity;i++) T[0][i]=0;

    for(int item=1;item<=n;item++){
        for(int cap=1;cap<=capacity;cap++){
       
            //    when we not take the item
            int not_taken=T[item-1][cap];

            //    when we take the item if the weight of the item is less than the capacity
            int taken=0;
            if(items[item-1].weight<=cap){
                // pick and try to pick same item multiple times
                taken=items[item-1].value+T[item][cap-items[item-1].weight];
            }

            // we take the item if the profit is greater than the profit of not taking the item
            T[item][cap]=max(taken,not_taken);

        }
    }
    return T[n][capacity];
}


int maxProfit(int bagSize,vector<Item> &item){
   
   return tabular_kapsack(bagSize,item);
}





int main()
{
    vector<Item> items={Item(2,3),Item(1,2),Item(3,4),Item(2,2),Item(3,5),Item(2,1)};
    int capacity=5;
    cout<<maxProfit(capacity,items);
   
  
    return 0;
}