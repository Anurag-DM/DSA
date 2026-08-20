class Solution
{
public:
  int minimumDays(int S, int N, int M)
  {
    if ((N < M) || (S > 6 && 6 * N < 7 * M))
      return -1;

    int sundays = S / 7;
    int buyingDays = S - sundays;
    int totalFoodReq = S * M;

    int ans = 0;
    if (totalFoodReq % N == 0)
      ans = totalFoodReq / N;
    else
      ans = totalFoodReq / N + 1;

    if (ans <= buyingDays)
      return ans;
    else
      return -1;
  }
};