queue<int> rev(queue<int> q)
{
    stack<int> s;
    
    while(!q.empty()) {
        int element = q.front();
        q.pop();
        s.push(element);
    }

    while(!s.empty()) {
        int element = s.top();
        s.pop();
        q.push(element);
    }
    return q;
}
/*2nd approach using recursion time and space both are O(n)
class Solution {
    void solve(queue<int> &q){
        if(q.empty())
            return;
        int num=q.front();
        q.pop();
        solve(q);
        q.push(num);
    }
  public:
    void reverseQueue(queue<int> &q) {
        // code here
        solve(q);
        
    }
};
*/