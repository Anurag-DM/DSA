class Solution
{
public:
  string removeKdigits(string num, int k)
  {
    stack<char> st;
    int c = 0;
    for (char ch : num)
    {
      if (st.empty() || st.top() <= ch || c >= k)
      {
        st.push(ch);
      }
      else
      {
        while (!st.empty() && c < k && st.top() > ch)
        {
          st.pop();
          c++;
        }
        st.push(ch);
      }
    }
    while (c < k)
    {
      st.pop();
      c++;
    }
    string str = "";
    if (st.empty())
      return "0";
    while (!st.empty())
    {
      str.push_back(st.top());
      st.pop();
    }
    reverse(str.begin(), str.end());
    int i;
    for (i = 0; str[i] == '0'; i++)
    {
    }
    str = (i == str.length()) ? "0" : str.substr(i);
    return str;
  }
};