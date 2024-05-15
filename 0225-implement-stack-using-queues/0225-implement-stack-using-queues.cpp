// Approach 1 pop heavy
// class MyStack {
// public:
//     queue<int> q;
    
//     void push(int x) {
//         q.push(x);
//     }
    
//     int pop() {
//         int size = q.size();
//         for(int i = 1 ; i < size ; i++){
//             q.push(q.front());
//             q.pop();
//         }
//         int ans = q.front();
//         q.pop();
//         return ans;
//     }
    
//     int top() {
//         int size = q.size();
//         for(int i = 1 ; i < size ; i++){
//             q.push(q.front());
//             q.pop();
//         }
//         int ans = q.front();
//         q.push(ans);
//         q.pop();
//         return ans;
//     }
    
//     bool empty() {
//         return q.empty();
//     }
// };

// Approach 2 push heavy
class MyStack {
public:
    queue<int> q;
    
    void push(int x) {
        q.push(x);
        for(int i = 1 ; i < q.size() ; i++){
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int ans = q.front();
        q.pop();
        return ans;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */