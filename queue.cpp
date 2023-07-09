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
        front = -1;
        rear = -1;
    }

    void enqueue(int item)
    {
        if (size() <= MAX_LIMIT && rear < MAX_LIMIT)
        {
            queue[rear] = item;
            rear++;
        }
        else
        {
            message(" Queue is full");
        }
    }

    int dequeue()
    {
        if (isEmpty())
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

    bool isEmpty()
    {
        return rear == -1;
    }

    int peek()
    {
        return queue[front];
    }

    int size()
    {
        return rear - front;
    }
};

int main()
{
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Size of queue: " << q.size() << endl; // Output: 3

    cout << "Top element: " << q.peek() << endl; // Output: 30

    cout << "Popped element: " << q.dequeue() << endl; // Output: 30

    cout << "Size of stack after popping: " << q.size() << endl; // Output: 2

    return 0;
}