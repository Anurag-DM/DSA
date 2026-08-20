//time: O(n)   space: O(1)
class Solution
{
public:
  string reverseWords(string &s)
  {
    reverse(s.begin(), s.end());

    int n = s.length();
    int i = 0, write = 0;

    while (i < n)
    {

      // Skip all dots
      while (i < n && s[i] == '.')
        i++;

      if (i >= n)
        break;

      // Add dot before next word (except first word)
      if (write > 0)
        s[write++] = '.';

      int start = write;

      // Copy current word
      while (i < n && s[i] != '.')
        s[write++] = s[i++];

      // Reverse individual word back
      reverse(s.begin() + start, s.begin() + write);
    }

    s.resize(write);

    return s;
  }
};