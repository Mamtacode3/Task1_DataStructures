#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;

    Node(int value)
    {
        data = value;
        next = NULL;
    }
};

class LinkedList
{
private:
    Node* head;

public:
    LinkedList()
    {
        head = NULL;
    }

    // Insert: O(1)
    void insert(int value)
    {
        Node* newNode = new Node(value);

        if(head == NULL)
        {
            head = newNode;
            return;
        }

        Node* temp = head;

        while(temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
    }

    // Search: O(n)
    void search(int value)
    {
        Node* temp = head;

        while(temp != NULL)
        {
            if(temp->data == value)
            {
                cout << value << " Found" << endl;
                return;
            }

            temp = temp->next;
        }

        cout << value << " Not Found" << endl;
    }

    // Delete: O(n)
    void deleteNode(int value)
    {
        if(head == NULL)
            return;

        if(head->data == value)
        {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* curr = head;

        while(curr->next != NULL &&
              curr->next->data != value)
        {
            curr = curr->next;
        }

        if(curr->next != NULL)
        {
            Node* temp = curr->next;
            curr->next = curr->next->next;
            delete temp;
        }
    }

    void display()
    {
        Node* temp = head;

        while(temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }
};

int main()
{
    LinkedList list;

    list.insert(10);
    list.insert(20);
    list.insert(30);

    cout << "Linked List: ";
    list.display();

    list.search(20);

    list.deleteNode(10);

    cout << "After Deletion: ";
    list.display();

    return 0;
}