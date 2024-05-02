#include <iostream>

using namespace std;

class Node {
public:
    char id;
    Node* next;

    Node() {
        next = NULL;
    }
};

class LinkedList {
public:
    Node* head;
    Node* tail;

    LinkedList() {
        head = tail = NULL;
    }

    void insertToHead(char data) {
        Node* node = new Node();
        node->id = data;

        if (head == NULL) {
            head = tail = node;
        } else {
            Node* tmp = head;
            head = node;
            node->next = tmp;
        }
    }

    void insertToTail(char data) {
        Node* node = new Node();
        node->id = data;

        if (head == NULL) {
            head = tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
    }

    void traversal() {
        Node* tmp = head;
        while (tmp != NULL) {
            cout << tmp->id << " ";
            tmp = tmp->next;
        }
        cout << endl;
    }

    void insertDataAfter(char data, char after) {
        if (head == NULL) {
            cout << "ERROR: LinkedList Empty" << endl;
        } else {
            Node* tmp = head;
            while (tmp != NULL && tmp->id != after) {
                tmp = tmp->next;
            }
            if (tmp == NULL) {
                cout << "ERROR: Node with id '" << after << "' not found" << endl;
            } else {
                Node* newNode = new Node();
                newNode->id = data;
                newNode->next = tmp->next;
                tmp->next = newNode;
                if (tmp == tail) {
                    tail = newNode;
                }
            }
        }
    }
};

int main(int argc, char** argv) {

    LinkedList* list1 = new LinkedList();

    list1->insertToHead('A');
    list1->insertToTail('B');

    cout << list1->head->id << endl;
    cout << list1->head->next->id << endl;

    Node* nodeX = new Node();
    nodeX->id = 'X';

    Node* tmp = list1->head->next;
    list1->head->next = nodeX;
    nodeX->next = tmp;

    list1->insertToTail('C');
    list1->insertToTail('D');

    cout << list1->head->id << endl;
    cout << list1->tail->id << endl;

    return 0;
}
