// time: O(m*n)  space: O(m+n)
class Solution
{
public:
  int maxSquare(vector<vector<int>> &mat)
  {
    int m = mat.size(), n = mat[0].size();
    int maxi = 0;

    for (int i = m - 1; i >= 0; i--)
    {
      for (int j = n - 1; j >= 0; j--)
      {

        if (mat[i][j] == 1)
        {

          if (i == m - 1 || j == n - 1)
          {
            // last row/col
            mat[i][j] = 1;
          }
          else
          {
            mat[i][j] = 1 + min({
                                mat[i][j + 1],    // right
                                mat[i + 1][j],    // down
                                mat[i + 1][j + 1] // diagonal
                            });
          }

          maxi = max(maxi, mat[i][j]);
        }
        else
        {
          mat[i][j] = 0;
        }
      }
    }

    return maxi;
  }
};