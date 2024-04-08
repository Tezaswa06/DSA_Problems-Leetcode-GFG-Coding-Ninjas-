class Node {
    
    public :
    int val;
    Node *next;
    Node(int data)
    {
        this->val = data;
        this->next = NULL;
    }
};

class MyLinkedList {
    Node *head, *tail;
public:
    MyLinkedList() {
        head = NULL;
        tail = NULL;
    }
    
    int get(int index) {
        Node *ptr = head;
        
        while(ptr != NULL && index != 0)
        {
            ptr = ptr->next;
            index--;
        }

        if(ptr == NULL)
            return -1;
        
        return ptr->val;
    }
    
    void addAtHead(int val) {
        Node *node = new Node(val);

        if(head == NULL)
        {
            head = node;
            tail = node;
        }else
        {
            node->next = head;
            head = node;
        }
    }
    
    void addAtTail(int val) {
        Node *node = new Node(val);

        if(head == NULL)
        {
            head = node;
            tail = node;
        }else
        {
            tail->next = node;
            tail = node;
        }


    }
    
    void addAtIndex(int index, int val) {
        Node *ptr = head;

        Node *temp = new Node(val);
        if(index == 0)
        {
            temp -> next = head;
            head = temp;
            return;
        }
        while(ptr != NULL && index - 1 > 0)
        {
            ptr = ptr->next;
            index--;
        }

        if(ptr == NULL)
            return;
        temp -> next = ptr->next;
        if(ptr->next == NULL)
            tail = temp;
        ptr->next = temp;
        
    }
    
    void deleteAtIndex(int index) {
        
        Node *ptr = head;
        Node *temp = NULL;
        if(index == 0)
        {
            temp = head;
            head = temp->next;
            delete temp;
            if(head==NULL)
                tail = NULL;
            return;
        }
        
        while(ptr != NULL && index - 1 > 0)
        {
            ptr = ptr->next;
            index--;
        }
        if(ptr == NULL || ptr-> next == NULL)
            return;
        
        temp = ptr -> next;
        ptr->next = temp->next;
        if(temp->next == NULL)
            tail = ptr;
        delete temp;
        
    }
};


/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */