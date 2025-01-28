#include <iostream>
#include <ostream>
class Node{
    public:
    int value;
    Node* next;
    Node(int val, Node* nxt) : value(val), next(nxt) {};
    Node(int val) : Node(val, nullptr) {};
};

class MyLinkedList {
    Node* head;
    int size;
    
public:
    MyLinkedList() {
        head = nullptr;
        size = 0;
    }
    
    int get(int index) {
        if(index>=size || index <0 || head==nullptr){
            return -1;
        }
        Node* cur = head;
        
        for(int i =0; i <= index-1; ++i){
            if(cur == nullptr){
                return -1;
            }
            cur = cur->next;
        }
        return cur->value;
    }
    
    void addAtHead(int val) {
        Node* new_head = new Node(val);
        new_head->next = head;
        head = new_head;
        size++;
    }
    
    void addAtTail(int val) {
        if(size==0){
            addAtHead(val);
            return;
        }
        Node* cur = head;
        while(cur->next!=nullptr){
            cur= cur->next;
        }
        Node* tmp = new Node(val);
        cur->next = tmp;
        if(head==nullptr){
            head = tmp;
        }
        size++;
    }
    
    void addAtIndex(int index, int val) {
        if(index<0 || index>size){
            return;
        }
        if(index == 0){
            addAtHead(val);
            return;
        }
        if(index==size){
            addAtTail(val);
            return;
        }
        Node* tmp = new Node(val);
        Node* cur = head;
        for(int i = 0; i < index-1; ++i){
            cur = cur->next;
        }
        tmp->next = cur->next;
        cur->next = tmp;
        size++;
    }
    
    void deleteAtIndex(int index) {
        if(index<0 || index>=size){
            return;
        }
        if(index==0){
            if(head){
                Node* tmp = head;
                head = head->next;
                delete tmp;
                size--;
            }
            return;
        }
        Node* cur = head;
        
        for(int i = 0; i < index-1; ++i){
            cur=cur->next;
        }
         Node* tmp = cur->next;
        cur->next=cur->next->next;
        if(index==0){
            head = cur;
        }
        delete tmp;
        size--;
        
    }
    ~MyLinkedList(){
        while(size!=0){
            deleteAtIndex(0);
        }
    }
    friend std::ostream& operator<<(std::ostream& os,const MyLinkedList& list);
};
std::ostream& operator<<(std::ostream& os,const MyLinkedList& list){
    Node* tmp = list.head;
    while (tmp!=nullptr)
    {
        os << "value: " << tmp->value << '\n';
        tmp = tmp->next;
    }
    return os;
    
}
/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */

int main(){
MyLinkedList* myLinkedList = new MyLinkedList();
// myLinkedList->addAtHead(1);
// myLinkedList->addAtTail(3);
myLinkedList->addAtIndex(1, 2);    // linked list becomes 1->2->3
// std::cout << *myLinkedList << std::endl;
// std::cout << myLinkedList->get(1)<< std::endl;              // return 2
// myLinkedList->deleteAtIndex(1);    // now the linked list is 1->3
// std::cout << myLinkedList->get(1)<< std::endl;         // return 3





    std::cout << *myLinkedList << std::endl;
    delete myLinkedList;
    return 0;
}