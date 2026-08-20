#include <queue>
using namespace std;

class MyStack {
private:
    queue<int> q;
public:
    MyStack() {}

    void push(int x) {
        q.push(x);
        int sz = q.size();
        // rotate previous elements behind the newly added element
        for (int i = 0; i < sz - 1; ++i) {
            q.push(q.front());
            q.pop();
        }
    }

    int pop() {
        int val = q.front();
        q.pop();
        return val;
    }

    int top() {
        return q.front();
    }

    bool empty() {
        return q.empty();
    }
};
/*class MyStack {
    void reverse(queue<int> &q){
        if(q.empty())
            return;
        int temp=q.front();
        q.pop();
        reverse(q);
        q.push(temp);
    }
public:
    queue<int> q;
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
    }
    
    int pop() {
        if(q.empty())
            return -1;
        reverse(q);
        int t=q.front();
        q.pop();
        reverse(q);
        return t;
    }
    
    int top() {
        reverse(q);
        int t=q.front();
        reverse(q);
        return t;
    }
    
    bool empty() {
        return q.empty();
    }
};*/

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */