class Node{
    public:
    int value;
    Node* next;
    Node(int val, Node* nxt) : value(val), next(nxt) {};
    Node(int val) : Node(val, nullptr) {};
};

bool findCycle(Node* head){
    Node* slow = head;
    Node* fast = head;
    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            return true;
        }
    }
    return false;
}
int main(){
    Node a(1);
    Node b(2);
    Node c(3);
    Node d(4);

    a.next = &b;
    b.next = &a;
    c.next = &d;
    d.next = &b;
 
    bool cycle = findCycle(&a);
    return 0;
}