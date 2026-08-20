// time: O(m*n)   space: O(n)
class Solution
{
public:
  int maximalSquare(vector<vector<char>> &mat)
  {
    int maxi = 0;
    int m = mat.size(), n = mat[0].size();
    vector<int> curr(n + 1, 0), next(n + 1, 0);
    // as dp[i][j] depends on current row(for right) and next row(for diag and down) only.

    for (int i = m - 1; i >= 0; i--)
    {
      for (int j = n - 1; j >= 0; j--)
      {
        int right = curr[j + 1];
        int diag = next[j + 1];
        int down = next[j];

        if (mat[i][j] == '1')
        {
          curr[j] = 1 + min({right, diag, down});
          maxi = max(maxi, curr[j]);
        }
        else
        {
          curr[j] = 0;
        }
      }
      next = curr;
    }

    return maxi * maxi;
  }
};