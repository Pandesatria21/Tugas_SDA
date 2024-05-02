#include <iostream>
using namespace std;

class Node
{
public:
    char id;
    string nama;
    int urutan;
    Node *next;
    
    Node()
    {
        next = NULL;
    }
};

class LinkedList
{
public:
    Node *head;
    Node *tail;
    
    LinkedList()
    {
        head = tail = NULL;
    }
    
    void insertToTail(char data)
    {
        Node *newNode = new Node();
        newNode->id = data;
        
        if(head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }
    
    void insertDataAfter(char data, char after)
    {
        if(head == NULL)
        {
            cout << "ERROR: linkedList kosong" << endl;
        }
        else
        {
            Node *tmp = head;
            while(tmp != NULL && tmp->id != after)
            {
                tmp = tmp->next;
            }
            
            if(tmp == NULL)
            {
                cout << "ERROR: 'after' tidak ditemukan" << endl;
            }
            else
            {
                Node *newNode = new Node();
                newNode->id = data;
                
                newNode->next = tmp->next;
                tmp->next = newNode;
            }
        }
    }
};

int main(int argc, char** argv)
{
    LinkedList *list1 = new LinkedList();
    
    list1->insertToTail('A');
    list1->insertToTail('B');
    
    cout << list1->head->id << endl;
    cout << list1->head->next->id << endl;
 return 0;
}