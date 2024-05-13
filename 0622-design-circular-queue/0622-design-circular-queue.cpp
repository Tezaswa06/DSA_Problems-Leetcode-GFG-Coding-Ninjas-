class MyCircularQueue {
public:

    vector<int>arr;
    int front = 0;
    int rear = 0;
    int size = 0;


    MyCircularQueue(int k) {
        arr.resize(k);
    }
    
    bool enQueue(int value) {
        if(isFull()){ // queue overflow
            return false;
        }

        arr[rear] = value;
        size++;
        rear = (rear + 1) % arr.size();
        return true;
    }
    
    bool deQueue() { 
        if(isEmpty()){ // queue underflow
            return false;
        }

        front = (front + 1) % arr.size();
        size--;
        return true;
    }
    
    int Front() {
        if(isEmpty()){
            return -1;
        }
        return arr[front];
    }
    
    int Rear() {
        if(isEmpty()){
            return -1;
        }
        return arr[(rear - 1 + arr.size()) % arr.size()];
    }
    
    bool isEmpty() {
        return (size == 0);
    }
    
    bool isFull() {
        return (size == arr.size());
    }
};

/**
 * Your MyCircularQueue o
 bject will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */