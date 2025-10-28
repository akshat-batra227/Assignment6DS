#include <iostream>
using namespace std;

struct DNode {
    int data;
    DNode* prev;
    DNode* next;
};

DNode* head2 = nullptr;

// Insert at end
void insertDNode(int value) {
    DNode* newNode = new DNode();
    newNode->data = value;
    newNode->next = nullptr;

    if (head2 == nullptr) {
        newNode->prev = nullptr;
        head2 = newNode;
        cout << "Inserted " << value << " as first node.\n";
        return;
    }

    DNode* temp = head2;
    while (temp->next != nullptr)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
    cout << "Inserted " << value << " at end.\n";
}

// Delete node
void deleteDNode(int key) {
    if (head2 == nullptr) {
        cout << "List is empty.\n";
        return;
    }

    DNode* temp = head2;
    while (temp != nullptr && temp->data != key)
        temp = temp->next;

    if (temp == nullptr) {
        cout << "Node not found.\n";
        return;
    }

    if (temp->prev != nullptr)
        temp->prev->next = temp->next;
    else
        head2 = temp->next; // deleting head

    if (temp->next != nullptr)
        temp->next->prev = temp->prev;

    delete temp;
    cout << "Deleted node " << key << ".\n";
}

// Search node
void searchDNode(int key) {
    DNode* temp = head2;
    int pos = 1;

    while (temp != nullptr) {
        if (temp->data == key) {
            cout << "Node " << key << " found at position " << pos << ".\n";
            return;
        }
        temp = temp->next;
        pos++;
    }

    cout << "Node not found.\n";
}

// Display
void displayDList() {
    if (head2 == nullptr) {
        cout << "List is empty.\n";
        return;
    }

    DNode* temp = head2;
    cout << "Doubly Linked List: ";
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    int choice, value;

    while (true) {
        cout << "\n---- Doubly Linked List Menu ----\n";
        cout << "1. Insert Node\n2. Delete Node\n3. Search Node\n4. Display\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                insertDNode(value);
                break;

            case 2:
                cout << "Enter value to delete: ";
                cin >> value;
                deleteDNode(value);
                break;

            case 3:
                cout << "Enter value to search: ";
                cin >> value;
                searchDNode(value);
                break;

            case 4:
                displayDList();
                break;

            case 5:
                cout << "Exiting...\n";
                return 0;

            default:
                cout << "Invalid choice! Try again.\n";
        }
    }
}
