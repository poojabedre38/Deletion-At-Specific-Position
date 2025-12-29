#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
};

void insertEnd(Node* &head, int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void deleteAtPosition(Node* &head, int position) {
    if (head == NULL) {
        cout << "List is empty" << endl;
        return;
    }
    if (position == 1) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* temp = head;

    for (int i = 1; i < position - 1; i++) {
        if (temp->next == NULL) {
            cout << "Invalid position" << endl;
            return;
        }
        temp = temp->next;
    }

    Node* delNode = temp->next;
    temp->next = delNode->next;
    delete delNode;
}

void display(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Node* head = NULL;

    insertEnd(head, 10);
    insertEnd(head, 20);
    insertEnd(head, 30);
    insertEnd(head, 40);

    cout << "Original List: ";
    display(head);

    deleteAtPosition(head, 3);

    cout << "After Deletion: ";
    display(head);

    return 0;
}
