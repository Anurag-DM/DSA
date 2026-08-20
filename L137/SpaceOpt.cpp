class Solution
{
public:
  int minDistance(string word1, string word2)
  {
    int n1 = word1.length(), n2 = word2.length();

    vector<int> curr(n2 + 1, 0);
    vector<int> next(n2 + 1, 0);

    for (int i = n2 - 1; i >= 0; i--)
    {
      next[i] = n2 - i;
    }

    for (int ind1 = n1 - 1; ind1 >= 0; ind1--)
    {
      curr[n2] = n1 - ind1;
      for (int ind2 = n2 - 1; ind2 >= 0; ind2--)
      {
        if (word1[ind1] == word2[ind2])
          curr[ind2] = next[ind2 + 1];
        else
        {
          int replace = 1 + next[ind2 + 1];
          int add = 1 + curr[ind2 + 1];
          int del = 1 + next[ind2];
          curr[ind2] = min({replace, add, del});
        }
      }
      next = curr;
    }
    return next[0]; // here writing curr[0] gives error. this is the edge case where for eg word1 = "" and word2 = "a". dry run to understand
  }
};