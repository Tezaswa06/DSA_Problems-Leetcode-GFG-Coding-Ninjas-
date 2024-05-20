class FrontMiddleBackQueue {
public:
    deque<int>leftdq;
    deque<int>rightdq;

    void balance(){
        while (leftdq.size() > rightdq.size() + 1) {
            rightdq.push_front(leftdq.back());
            leftdq.pop_back();
        }
        while (rightdq.size() > leftdq.size()) {
            leftdq.push_back(rightdq.front());
            rightdq.pop_front();
        }
    }
    void pushFront(int val) {
        leftdq.push_front(val);
        balance();
    }
    
    void pushMiddle(int val) {
        if(leftdq.size() > rightdq.size()){
            int val1 = leftdq.back();
            rightdq.push_front(val1);
            leftdq.pop_back();
        }
        leftdq.push_back(val);
        balance();
    }
    
    void pushBack(int val) {
        rightdq.push_back(val);
        balance();
    }
    
    int popFront() {
        if(leftdq.size() + rightdq.size() == 0){
            return -1;
        }
        int val1 = leftdq.front();
        leftdq.pop_front();
        balance();
        return val1;
    }
    
    int popMiddle() {
        if(leftdq.size() + rightdq.size() == 0){
            return -1;
        }
        int val1 = leftdq.back();
        leftdq.pop_back();
        balance();
        return val1;
    }
    
    int popBack() {
        if(leftdq.size() + rightdq.size() == 0){
            return -1;
        }
        if(rightdq.size() == 0){
            int val1 = leftdq.back();
            leftdq.pop_back();
            balance();
            return val1;
        }
        else{
            int val1 = rightdq.back();
            rightdq.pop_back();
            balance();
            return val1;
        }
    }
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */