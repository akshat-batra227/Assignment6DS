#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = nullptr;

// Function to insert a node
void insertNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;

    if (head == nullptr) {
        head = newNode;
        newNode->next = head; // circular link
        cout << "Inserted " << value << " as the first node.\n";
        return;
    }

    Node* temp = head;
    while (temp->next != head)
        temp = temp->next;

    temp->next = newNode;
    newNode->next = head;
    cout << "Inserted " << value << " at the end.\n";
}

// Function to delete a specific node
void deleteNode(int key) {
    if (head == nullptr) {
        cout << "List is empty.\n";
        return;
    }

    Node *curr = head, *prev = nullptr;

    // If head needs to be deleted
    if (curr->data == key) {
        if (curr->next == head) {
            delete curr;
            head = nullptr;
            cout << "Deleted the only node.\n";
            return;
        }

        // Move to last node
        Node* last = head;
        while (last->next != head)
            last = last->next;

        last->next = head->next;
        head = head->next;
        delete curr;
        cout << "Deleted head node " << key << ".\n";
        return;
    }

    // Otherwise, find the node
    do {
        prev = curr;
        curr = curr->next;
        if (curr->data == key) {
            prev->next = curr->next;
            delete curr;
            cout << "Deleted node " << key << ".\n";
            return;
        }
    } while (curr != head);

    cout << "Node not found.\n";
}

// Function to search for a node
void searchNode(int key) {
    if (head == nullptr) {
        cout << "List is empty.\n";
        return;
    }

    Node* temp = head;
    int pos = 1;
    do {
        if (temp->data == key) {
            cout << "Node " << key << " found at position " << pos << ".\n";
            return;
        }
        temp = temp->next;
        pos++;
    } while (temp != head);

    cout << "Node not found.\n";
}

// Function to display list
void displayList() {
    if (head == nullptr) {
        cout << "List is empty.\n";
        return;
    }

    Node* temp = head;
    cout << "Circular Linked List: ";
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

int main() {
    int choice, value;

    while (true) {
        cout << "\n---- Circular Linked List Menu ----\n";
        cout << "1. Insert Node\n2. Delete Node\n3. Search Node\n4. Display\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                insertNode(value);
                break;

            case 2:
                cout << "Enter value to delete: ";
                cin >> value;
                deleteNode(value);
                break;

            case 3:
                cout << "Enter value to search: ";
                cin >> value;
                searchNode(value);
                break;

            case 4:
                displayList();
                break;

            case 5:
                cout << "Exiting...\n";
                return 0;

            default:
                cout << "Invalid choice! Try again.\n";
        }
    }
}
