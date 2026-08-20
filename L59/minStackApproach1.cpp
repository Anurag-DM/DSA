//this approach is O(1)  time and O(s+n) space
class MinStack {
public:
    stack<int> s,mini;
    int cmin;
    MinStack() {
    }
    
    void push(int val) {
        s.push(val);
        if(mini.empty())
            mini.push(val);
        else
            mini.push(min(val,mini.top()));
    }
    
    void pop() {
        s.pop();
        mini.pop();
        
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return mini.top();
    }
};