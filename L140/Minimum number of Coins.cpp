// ✅ Time Complexity:O(1)
// ✅ Space Complexity:O(1)
class Solution
{
public:
  int findMin(int n)
  {
    // code here
    int coins = 0;
    coins += n / 10;
    int remains = n % 10;

    coins += remains / 5;
    remains = remains % 5;

    coins += remains / 2;
    remains = remains % 2;

    coins += remains / 1;

    return coins;
  }
};