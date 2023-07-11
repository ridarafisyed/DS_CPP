/* basic queue implimentation with array */

#include <iostream>

using namespace std;

const int MAX_LIMIT = 10;

class Queue
{
private:
    int queue[MAX_LIMIT];
    int front;
    int rear;

    void message(string str)
    {
        cout << str << endl;
    }

public:
    Queue()
    {
        front = rear = -1;
    }; // constructor to initialize the variables.

    void en_queue(int item)
    {
        if (size() <= MAX_LIMIT && rear < MAX_LIMIT)
        {
            if (front == -1)
            {
                front = 0;
            }
            queue[rear] = item;
            rear++;
        }
        else
        {
            message(" Queue is full");
        }
    }

    int de_queue()
    {
        if (is_empty())
        {
            message("Queue is Empty");
            return -1;
        }
        else
        {
            int data = queue[front];
            front++;
            return data;
        }
    }

    bool is_empty()
    {
        return rear == -1;
    }

    int peek()
    {
        return queue[front];
    }
    void display()
    {
        int i;
        if (is_empty())
        {
            message("The Queue is empty");
        }
        else
        {
            cout << "Front -> " << front << endl;
            cout << "Items -> " << endl;
            for (i = front; i != rear; i++)
            {
                cout << queue[i] << endl;
            }
            cout << "Rear -> " << rear << endl;
        }
    }
    int size()
    {
        return rear - front;
    }
};

int main()
{
    Queue q;
    q.en_queue(10);
    q.en_queue(20);
    q.en_queue(30);
    q.display();

    cout << "Size of queue: " << q.size() << endl; // Output: 3

    cout << "Top element: " << q.peek() << endl; // Output: 30

    cout << "Popped element: " << q.de_queue() << endl; // Output: 30

    cout << "Size of stack after popping: " << q.size() << endl; // Output: 2

    return 0;
}