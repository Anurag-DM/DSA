// using monotonic stack
// time O(n) space: O(n)
class Solution
{
public:
  int mctFromLeafValues(vector<int> &arr)
  {
    stack<int> s;
    s.push(INT_MAX);
    int res = 0;
    for (int i : arr)
    {
      if (i <= s.top())
        s.push(i);
      else
      {
        while (s.top() < i)
        {
          int leaf1 = s.top();
          s.pop();
          if (i > s.top())
          {
            res += leaf1 * s.top();
          }
          else
          {
            res += leaf1 * i;
          }
        }
        s.push(i);
      }
    }

    while (s.top() != INT_MAX)
    {
      int leaf1 = s.top();
      s.pop();
      int leaf2 = s.top();
      if (leaf2 == INT_MAX)
        break;
      res += leaf1 * leaf2;
    }
    return res;
  }
};