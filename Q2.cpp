#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Function to insert node at the end of a circular linked list
void insert(Node*& head, int val) {
    Node* newNode = new Node();
    newNode->data = val;

    if (head == nullptr) {
        head = newNode;
        newNode->next = head; // self loop for first node
        return;
    }

    Node* temp = head;
    while (temp->next != head)
        temp = temp->next;

    temp->next = newNode;
    newNode->next = head; // new node points to head
}

// Function to display circular linked list values
void display(Node* head) {
    if (head == nullptr) {
        cout << "List is empty!" << endl;
        return;
    }

    Node* temp = head;
    cout << "Circular Linked List: ";
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);

    // repeat the head value at the end (as shown in question)
    cout << head->data << endl;
}

int main() {
    Node* head = nullptr;
    int n, val;

    cout << "--- DISPLAY CIRCULAR LINKED LIST ---\n";
    cout << "Enter number of nodes: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter value for node " << i + 1 << ": ";
        cin >> val;
        insert(head, val);
    }

    display(head);

    return 0;
}
