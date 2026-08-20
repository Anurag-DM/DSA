/*
Problem statement
You are given an array/list consisting of 0 and 1 only. Your task is to find the sum of the number of subarrays that contains only 1 and the number of subarrays that contains only 0.

An array 'C' is a subarray of array 'D' if 'C' can be obtained from 'D' by deletion of several elements from the beginning and several elements from the end. Example :

Let 'ARR' = [1,0,0] then the possible subarrays of 'ARR' will be: {1}, {0}, {0}, {1,0}, {0,0}, {1,0,0}.
*/

#include <bits/stdc++.h>
int solve(vector<int> &arr, int ind, int prev, vector<int> &dp)
{
  if (ind == arr.size())
    return 0;

  if (dp[ind] != -1)
    return dp[ind];

  if (prev != -1 && arr[ind] != arr[prev])
    return 0;

  // include
  int inc = 1 + solve(arr, ind + 1, ind, dp);
  return dp[ind] = inc;
}
int numberofSubarrays(vector<int> &arr, int n)
{
  int ans = 0;
  vector<int> dp(n, -1);
  for (int i = 0; i < n; i++)
  {
    ans += solve(arr, i, -1, dp);
  }
  return ans;
}