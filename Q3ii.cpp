#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Function to insert node at end in circular linked list
void insert(Node*& head, int val) {
    Node* newNode = new Node();
    newNode->data = val;

    if (head == nullptr) {
        head = newNode;
        head->next = head; // points to itself
        return;
    }

    Node* temp = head;
    while (temp->next != head)
        temp = temp->next;
    temp->next = newNode;
    newNode->next = head; // link last node to head
}

// Function to find size of circular linked list
int findSize(Node* head) {
    if (head == nullptr)
        return 0;

    int count = 0;
    Node* temp = head;
    do {
        count++;
        temp = temp->next;
    } while (temp != head);

    return count;
}

int main() {
    Node* head = nullptr;
    int n, val;

    cout << "\n--- CIRCULAR LINKED LIST SIZE ---\n";
    cout << "Enter number of nodes: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter value for node " << i + 1 << ": ";
        cin >> val;
        insert(head, val);
    }

    cout << "Size of Circular Linked List = " << findSize(head) << endl;
    return 0;
}
