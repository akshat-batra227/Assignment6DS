#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Function to insert a new node at the end
void insert(Node*& head, int val) {
    Node* newNode = new Node();
    newNode->data = val;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr)
        temp = temp->next;

    temp->next = newNode;
}

// Function to check if the list is circular
bool isCircular(Node* head) {
    if (head == nullptr)
        return false;

    Node* temp = head->next;

    while (temp != nullptr && temp != head)
        temp = temp->next;

    // if we reach head again → circular
    return (temp == head);
}

int main() {
    Node* head = nullptr;
    int n, val;

    cout << "--- CHECK IF LINKED LIST IS CIRCULAR ---\n";
    cout << "Enter number of nodes: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter value for node " << i + 1 << ": ";
        cin >> val;
        insert(head, val);
    }

    
    // head->next->next->next = head;  // manually link last node to head

    if (isCircular(head))
        cout << "The linked list is circular." << endl;
    else
        cout << "The linked list is NOT circular." << endl;

    return 0;
}
