#include <bits/stdc++.h> 
int findMinimumCost(string str) {
  if(str.length() % 2 == 1)
    return -1;

  int cost = 0;
  stack<char> s;

  for(char c:str){
    if(c == '{')
      s.push(c);
    else{
      if(s.empty()){
        cost++;
        s.push('{');
      }
      else
        s.pop();
    }
  }

  cost += s.size()/2;

  return cost;
}