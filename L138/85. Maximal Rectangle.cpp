class Solution
{
  vector<int> nextSmall(vector<int> &heights, int n, stack<int> s)
  {
    vector<int> v(n);
    for (int i = n - 1; i >= 0; i--)
    {
      while (s.top() != -1 && heights[s.top()] >= heights[i])
        s.pop();
      v[i] = s.top();
      s.push(i);
    }
    return v;
  }

  vector<int> prevSmall(vector<int> &heights, int n, stack<int> s)
  {
    vector<int> v(n);
    for (int i = 0; i <= n - 1; i++)
    {
      while (s.top() != -1 && heights[s.top()] >= heights[i])
        s.pop();
      v[i] = s.top();
      s.push(i);
    }
    return v;
  }

  int largestRectangleArea(vector<int> &heights)
  {
    int n = heights.size();
    stack<int> s;
    s.push(-1);
    vector<int> nextSmaller = nextSmall(heights, n, s);
    vector<int> prevSmaller = prevSmall(heights, n, s);

    int area = INT_MIN;
    for (int i = 0; i < n; i++)
    {
      if (nextSmaller[i] == -1)
        nextSmaller[i] = n;
      int l = nextSmaller[i] - prevSmaller[i] - 1;
      int b = heights[i];
      area = max(area, l * b);
    }
    return area;
  }

public:
  int maximalRectangle(vector<vector<char>> &matrix)
  {
    int n = matrix[0].size();
    vector<int> height(n, 0);

    int area = INT_MIN;
    for (int i = 0; i < matrix.size(); i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (matrix[i][j] == '1')
          height[j]++;
        else
          height[j] = 0;
      }
      area = max(area, largestRectangleArea(height));
    }
    return area;
  }
};