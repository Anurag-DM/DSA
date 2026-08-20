//approach 1 using extra queue Time Complexity	O(n) Space Complexity	O(n)
class Solution {
  public:
    void rearrangeQueue(queue<int> &q) {
        int n=q.size();
        queue<int> q2;
        for(int i=0;i<n/2;i++){
            q2.push(q.front());
            q.pop();
        }
        for(int i=0;i<n/2;i++){
            q.push(q2.front());
            q2.pop();
            q.push(q.front());
            q.pop();
        }
    }
};
//approach 3 using extra stack 
//Time Complexity: O(n²) (due to recursive stack reversal)
//Space Complexity: O(n) (stack + recursion stack frames)
/*class Solution {
    void insertAtBottom(stack<int> &s,int num){
        if(s.empty()){
            s.push(num);
            return;
        }
        int no=s.top();
        s.pop();
        insertAtBottom(s,num);
        s.push(no);
    }
    void reverse(stack<int> &s){
        if(s.empty())
            return;
        int num=s.top();
        s.pop();
        reverse(s);
        insertAtBottom(s,num);
    }
  public:
    void rearrangeQueue(queue<int> &q) {
        stack<int> s;
        int n=q.size();
        for(int i=0;i<n/2;i++){
            s.push(q.front());
            q.pop();
        }
        reverse(s);
        for(int i=0;i<n/2;i++){
            q.push(s.top());
            s.pop();
            q.push(q.front());
            q.pop();
        }
    }
};*/
/*
//approach 2 using extra stack Time Complexity	O(n) Space Complexity	O(n)
class Solution {
  public:
    void rearrangeQueue(queue<int> &q) {
        stack<int> s;
        int n=q.size();
        for(int i=0;i<n/2;i++){
            s.push(q.front());
            q.pop();
        }
        while(!s.empty()){
            q.push(s.top());
            s.pop();
        }
        for(int i=0;i<n/2;i++){
            q.push(q.front());
            q.pop();
        }
        for(int i=0;i<n/2;i++){
            s.push(q.front());
            q.pop();
        }
        for(int i=0;i<n/2;i++){
            q.push(s.top());
            s.pop();
            q.push(q.front());
            q.pop();
        }
    }
};
*/