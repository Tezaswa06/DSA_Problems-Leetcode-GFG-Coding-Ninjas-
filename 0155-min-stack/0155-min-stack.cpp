// Approach 1 most optimised approach in terms of time

// class MinStack {
// public:
//     stack<int> stk;
//     stack<int> minstk;

//     MinStack() {
//         minstk.push(INT_MAX);
//     }
    
//     void push(int val) {
//         stk.push(val);
//         int newmin = min(minstk.top(),val);
//         minstk.push(newmin);
//     }
    
//     void pop() {
//         stk.pop();
//         minstk.pop();
//     }
    
//     int top() {
//         return stk.top();
//     }
    
//     int getMin() {
//         return minstk.top();
//     } 
// };

// Approach 2 

class MinStack {
public:
    stack<long> stk;
    long min = INT_MAX;
    
    void push(int val) {
        if(val >= min){
            stk.push(1l * val);
        }
        else{
            stk.push(2l * val - min);
            min = val;
        }
    }
    
    void pop() {
        long top1 = stk.top();
        stk.pop();
        if(top1 >= min){
            return;
        }
        min = 2l * min - top1;
    }
    
    int top() {
        long top1 = stk.top();
        if(top1 < min){
            return (int)min;
        }
        return (int)top1;
    }
    
    int getMin() {
        return (int)min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */