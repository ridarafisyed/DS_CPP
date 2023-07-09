#include <iostream>

using namespace std;

const int MAX_SIZE = 10;

class Stack // Last In First Out (LIFO)
{
private:
    int stack[MAX_SIZE];
    int topIndex;

public:
    Stack()
    {
        topIndex = -1;
    }
    bool isEmpty()
    {
        return topIndex == -1;
    }
    bool isFull()
    {
        return size() == MAX_SIZE;
    }

    int size()
    {
        return topIndex + 1;
    }

    void push(int item) // adding item in stack
    {
        if (isFull)
        {
            message("Stack is Full");
            return;
        };
        topIndex++;
        stack[topIndex] = item;
        message("Succuessfully added in stack");
        return;
    };
    int pop() // removing item from the stack and returning it
    {
        if (isEmpty())
        {
            message("Stack is empty");
            return -1;
        }
        else
        {
            int currenItem = stack[topIndex];
            --topIndex;

            return currenItem;
        }
    }
    int peek() // peeking the top item in the stack
    {
        if (isEmpty())
        {
            message("Stack is empty");
        }
        else
            return stack[topIndex];
    }

    void message(string str)
    {
        cout << str << endl;
    }
};

int main()
{
    Stack myStack;

    myStack.push(10);
    myStack.push(20);
    myStack.push(30);

    cout << "Size of stack: " << myStack.size() << endl; // Output: 3

    cout << "Top element: " << myStack.peek() << endl; // Output: 30

    cout << "Popped element: " << myStack.pop() << endl; // Output: 30

    cout << "Size of stack after popping: " << myStack.size() << endl; // Output: 2

    return 0;
}