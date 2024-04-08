
// signle linked List 
// class Node {
    
//     public :
//     int val;
//     Node *next;
//     Node(int data)
//     {
//         this->val = data;
//         this->next = NULL;
//     }
// };

// class MyLinkedList {
//     Node *head, *tail;
// public:
//     MyLinkedList() {
//         head = NULL;
//         tail = NULL;
//     }
    
//     int get(int index) {
//         Node *ptr = head;
        
//         while(ptr != NULL && index != 0)
//         {
//             ptr = ptr->next;
//             index--;
//         }

//         if(ptr == NULL)
//             return -1;
        
//         return ptr->val;
//     }
    
//     void addAtHead(int val) {
//         Node *node = new Node(val);

//         if(head == NULL)
//         {
//             head = node;
//             tail = node;
//         }else
//         {
//             node->next = head;
//             head = node;
//         }
//     }
    
//     void addAtTail(int val) {
//         Node *node = new Node(val);

//         if(head == NULL)
//         {
//             head = node;
//             tail = node;
//         }else
//         {
//             tail->next = node;
//             tail = node;
//         }


//     }
    
//     void addAtIndex(int index, int val) {
//         Node *ptr = head;

//         Node *temp = new Node(val);
//         if(index == 0)
//         {
//             temp -> next = head;
//             head = temp;
//             return;
//         }
//         while(ptr != NULL && index - 1 > 0)
//         {
//             ptr = ptr->next;
//             index--;
//         }

//         if(ptr == NULL)
//             return;
//         temp -> next = ptr->next;
//         if(ptr->next == NULL)
//             tail = temp;
//         ptr->next = temp;
        
//     }
    
//     void deleteAtIndex(int index) {
        
//         Node *ptr = head;
//         Node *temp = NULL;
//         if(index == 0)
//         {
//             temp = head;
//             head = temp->next;
//             delete temp;
//             if(head==NULL)
//                 tail = NULL;
//             return;
//         }
        
//         while(ptr != NULL && index - 1 > 0)
//         {
//             ptr = ptr->next;
//             index--;
//         }
//         if(ptr == NULL || ptr-> next == NULL)
//             return;
        
//         temp = ptr -> next;
//         ptr->next = temp->next;
//         if(temp->next == NULL)
//             tail = ptr;
//         delete temp;
        
//     }
// };

// Double Linked List 
class Node {
public:
    int val;        // Value stored in the node
    Node *next;     // Pointer to the next node
    Node *prev;     // Pointer to the previous node

    // Constructor to initialize a node with given data
    Node(int data) {
        this->val = data;   // Assigning data to the node
        this->next = nullptr;  // Initializing next pointer to nullptr
        this->prev = nullptr;  // Initializing prev pointer to nullptr
    }
};

class MyLinkedList {
    Node *head, *tail;      // Pointers to the head and tail nodes
public:
    MyLinkedList() {
        head = nullptr;     // Initializing head pointer to nullptr (empty list)
        tail = nullptr;     // Initializing tail pointer to nullptr (empty list)
    }
    
    // Method to get the value of the node at the given index
    int get(int index) {
        Node *ptr = head;   // Pointer to traverse the list
        
        // Traverse the list until reaching the desired index or end of list
        while(ptr != nullptr && index != 0) {
            ptr = ptr->next;    // Move to the next node
            index--;            // Decrement index counter
        }

        // If ptr is nullptr, index is out of bounds
        if(ptr == nullptr)
            return -1;   // Return -1 to indicate index out of range
        
        // Return the value of the node at the specified index
        return ptr->val;
    }
    
    // Method to add a new node with given value at the head of the list
    void addAtHead(int val) {
        Node *temp = new Node(val);    // Create a new node with given value

        // If list is empty, set both head and tail to the new node
        if(head == nullptr) {
            head = temp;
            tail = temp;
        } else {
            // Otherwise, add the new node at the head of the list
            temp->next = head;  // Set next of new node to current head
            head->prev = temp;  // Set prev of current head to new node
            head = temp;        // Update head to point to new node
        }
    }
    
    // Method to add a new node with given value at the tail of the list
    void addAtTail(int val) {
        Node *temp = new Node(val);    // Create a new node with given value

        // If list is empty, set both head and tail to the new node
        if(head == nullptr) {
            head = temp;
            tail = temp;
        } else {
            // Otherwise, add the new node at the tail of the list
            tail->next = temp;  // Set next of current tail to the new node
            temp->prev = tail;  // Set prev of new node to current tail
            tail = temp;        // Update tail to point to new node
        }
    }
    
    // Method to add a new node with given value at the specified index
    void addAtIndex(int index, int val) {
        // If index is negative, add the new node at the head
        if(index <= 0) {
            addAtHead(val);
            return;
        }

        Node *ptr = head;           // Pointer to traverse the list
        Node *temp = new Node(val); // Create a new node with given value
        
        // Traverse the list to find the node at index-1
        while(ptr != nullptr && index - 1 > 0) {
            ptr = ptr->next;    // Move to the next node
            index--;            // Decrement index counter
        }

        // If ptr is nullptr, index is out of bounds
        if(ptr == nullptr)
            return;

        // Insert the new node after the node at index-1
        temp->next = ptr->next; // Set next of new node to next of ptr
        temp->prev = ptr;       // Set prev of new node to ptr
        if(ptr->next != nullptr)
            ptr->next->prev = temp; // Update prev of next node to new node
        ptr->next = temp;       // Set next of ptr to the new node

        // Update tail if new node is added at the end of the list
        if(temp->next == nullptr)
            tail = temp;
    }
    
    // Method to delete the node at the specified index
    void deleteAtIndex(int index) {
        // If index is negative or list is empty, do nothing
        if(index < 0 || head == nullptr)
            return;

        Node *ptr = head;   // Pointer to traverse the list
        
        // If index is 0, delete the first node (head)
        if(index == 0) {
            head = head->next;  // Update head to point to the next node
            if(head != nullptr)
                head->prev = nullptr; // Update prev of new head to nullptr
            delete ptr;         // Delete the original head node
            // If head is nullptr, list is empty, update tail to nullptr
            if(head == nullptr)
                tail = nullptr;
            return;
        }

        // Traverse the list to find the node at index-1
        while(ptr != nullptr && index - 1 > 0) {
            ptr = ptr->next;    // Move to the next node
            index--;            // Decrement index counter
        }

        // If ptr is nullptr or next node is nullptr, index is out of bounds
        if(ptr == nullptr || ptr->next == nullptr)
            return;

        Node *temp = ptr->next;     // Pointer to the node to be deleted
        ptr->next = temp->next;     // Update next of ptr to skip the node to be deleted
        if(temp->next != nullptr)
            temp->next->prev = ptr; // Update prev of next node to ptr
        // If the node to be deleted is the tail, update tail to ptr
        if(temp == tail)
            tail = ptr;
        delete temp;                // Delete the node
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