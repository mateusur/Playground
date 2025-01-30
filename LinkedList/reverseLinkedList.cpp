class Node{
    public:
    int value;
    Node* next;
    Node(int val, Node* nxt) : value(val), next(nxt) {};
    Node(int val) : Node(val, nullptr) {};
};

Node* reverseLinkedList(Node* head){
    Node* prev = nullptr;
    Node* curent = head;
    Node* next = nullptr; 
    while (curent!=nullptr)
    {
        next = curent->next;
        curent->next = prev;
        prev = curent;
        curent = next;
    }
    return prev;
}
int main(){
    Node a(1);
    Node b(2);
    Node c(3);
    Node d(4);

    a.next = &b;
    b.next = &c;
    c.next = &d;
 
    Node* r = reverseLinkedList(&a);
    return 0;
}