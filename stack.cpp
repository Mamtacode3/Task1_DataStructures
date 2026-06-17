#include <iostream>
using namespace std;

class Stack
{
private:
    int arr[100];
    int top;

public:
    Stack()
    {
        top = -1;
    }

    // Push: O(1)
    void push(int value)
    {
        arr[++top] = value;
    }

    // Pop: O(1)
    void pop()
    {
        if(top == -1)
        {
            cout << "Stack Underflow" << endl;
            return;
        }

        cout << "Popped Element: "
             << arr[top--] << endl;
    }

    // Search: O(n)
    void search(int value)
    {
        for(int i = 0; i <= top; i++)
        {
            if(arr[i] == value)
            {
                cout << value << " Found" << endl;
                return;
            }
        }

        cout << value << " Not Found" << endl;
    }

    void display()
    {
        for(int i = top; i >= 0; i--)
        {
            cout << arr[i] << " ";
        }

        cout << endl;
    }
};

int main()
{
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Stack: ";
    s.display();

    s.search(20);

    s.pop();

    cout << "After Pop: ";
    s.display();

    return 0;
}