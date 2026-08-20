/*TLE
class Solution
{
  bool solve(string &s, int minj, int maxj, int ind)
  {
    if (ind == s.length() - 1)
      return true;

    bool ans = false;
    for (int i = ind + minj; i <= ind + maxj && i < s.length(); i++)
    {
      if (s[i] == '0')
        ans = ans || solve(s, minj, maxj, i);
    }
    return ans;
  }

public:
  bool canReach(string s, int minJump, int maxJump)
  {

    return solve(s, minJump, maxJump, 0);
  }
};*/

// time complexity is O(n) as each element processed once
class Solution
{
public:
  bool canReach(string s, int minJump, int maxJump)
  {
    queue<int> q;
    q.push(0);

    int n = s.length();
    int farthest = 0;

    while (!q.empty())
    {
      int index = q.front();
      q.pop();

      if (index == n - 1)
        return true;

      int start = max(farthest + 1, index + minJump);
      int end = min(index + maxJump, n - 1);

      for (int i = start; i <= end; i++)
      {
        if (s[i] == '0')
          q.push(i);
      }

      farthest = end; // till end we have processed all elements
    }
    return false;
  }
};