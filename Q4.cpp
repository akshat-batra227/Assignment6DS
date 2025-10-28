#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* next;
    Node* prev;
};

// Function to insert at end
void insert(Node*& head, Node*& tail, char val) {
    Node* newNode = new Node();
    newNode->data = val;
    newNode->next = nullptr;
    newNode->prev = tail;

    if (head == nullptr)
        head = newNode;
    else
        tail->next = newNode;

    tail = newNode;
}

// Function to check palindrome
bool isPalindrome(Node* head, Node* tail) {
    while (head != nullptr && tail != nullptr && head != tail && tail->next != head) {
        if (head->data != tail->data)
            return false;
        head = head->next;
        tail = tail->prev;
    }
    return true;
}

int main() {
    Node* head = nullptr;
    Node* tail = nullptr;
    int n;
    char ch;

    cout << "\n--- CHECK PALINDROME IN DOUBLY LINKED LIST ---\n";
    cout << "Enter number of characters: ";
    cin >> n;

    cout << "Enter characters one by one:\n";
    for (int i = 0; i < n; i++) {
        cout << "Character " << i + 1 << ": ";
        cin >> ch;
        insert(head, tail, ch);
    }

    if (isPalindrome(head, tail))
        cout << "Output: True (It's a palindrome!)" << endl;
    else
        cout << "Output: False (Not a palindrome)" << endl;

    return 0;
}
