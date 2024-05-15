// Approach 1 pop heavy

// class MyQueue {
// public:
//     stack<int> actualstk;
//     stack<int> extrastk;

//     void push(int x) {
//         actualstk.push(x);    
//     }
    
//     int pop() {
//         while(actualstk.size() > 0){
//            extrastk.push(actualstk.top()); 
//            actualstk.pop();
//         }
//         int ans = extrastk.top();
//         extrastk.pop();

//         while(extrastk.size() > 0){
//             actualstk.push(extrastk.top());
//             extrastk.pop();
//         }
//         return ans;
//     }
    
//     int peek() {
//         while(actualstk.size() > 0){
//            extrastk.push(actualstk.top()); 
//            actualstk.pop();
//         }
//         int ans = extrastk.top();

//         while(extrastk.size() > 0){
//             actualstk.push(extrastk.top());
//             extrastk.pop();
//         }
//         return ans;
//     }
    
//     bool empty() {
//         return actualstk.empty();
//     }
// };

// Approach 2 push heavy

class MyQueue {
public:
    stack<int> actualstk;
    stack<int> extrastk;

    void push(int x) {
        while(actualstk.size() > 0){
            extrastk.push(actualstk.top());
            actualstk.pop();
        }
        actualstk.push(x);
        while(extrastk.size() > 0){
            actualstk.push(extrastk.top());
            extrastk.pop();
        }
    }
    
    int pop() {
        int ans = actualstk.top();
        actualstk.pop();
        return ans;
    }
    
    int peek() {
        int ans = actualstk.top();
        return ans;
    }
    
    bool empty() {
        return actualstk.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */