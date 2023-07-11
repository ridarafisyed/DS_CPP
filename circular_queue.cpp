#include <iostream>

using namespace std;

#define MAX_LIMIT 5

class CircularQueue
{
private:
    int queue[MAX_LIMIT];
    int front, rear;
    void message(string str, int item)
    {
        cout << endl
             << str << " " << item << endl;
    }
    void message(string str)
    {
        cout << endl
             << str << " " << endl;
    }

public:
    CircularQueue() // constructor to initialize the variables.
    {
        front = rear = -1;
    };
    bool is_full()
    {
        if (front == 0 && rear == MAX_LIMIT - 1)
        {
            return true;
        }
        if (front == rear + 1)
        {
            return true;
        }
        return false;
    }
    // Check if the queue is empty
    bool is_empty()
    {
        if (front == -1)
            return true;
        else
            return false;
    }
    void en_queue(int item)
    {
        // check if its first element then set the front at 0 start
        if (is_full())
        {
            cout << "Queue is full";
        }
        else
        {
            if (front == -1)
            {
                front = 0;
            }
            rear = (rear + 1) % MAX_LIMIT;
            queue[rear] = item;
            message("The New Item is Added Successfully", item);
        }
    }
    int de_queue()
    {
        int item;
        if (is_empty())
        {
            message("The Queue is Empty.");
            return -1;
        }
        else
        {
            item = queue[rear];
            if (rear == front) //
            {
                front = rear = -1;
                return -1;
            }
            else
            {
                front = (front + 1) % MAX_LIMIT;
                return item;
            }
        }
    }

    int size()
    {
        return (rear - front) + 1;
    }
    //
    void display()
    {
        int i;
        if (is_empty())
        {
            message("The Queue is empty");
        }
        else
        {
            cout << endl
                 << "List of Items in a Queue :" << endl;
            cout << endl
                 << "Front -> " << front << endl;
            cout << endl
                 << "Items -> " << endl;
            for (i = front; i != rear; i = (i + 1) % MAX_LIMIT)
            {
                cout << i << " Item : " << queue[i] << endl;
            }
            cout << "Rear -> " << rear << endl;
        }
    }

    // display the first element of the queue
    int peek()
    {
        if (is_empty())
        {
            message("The Queue is Empty");
            return (-1);
        }
        else
        {
            return queue[front];
        }
    }
};

void greetings()
{
    cout << endl;
    cout << endl;
    cout << "Welcome to the Circular Queue Program" << endl;
    cout << endl;
}

int main()
{
    CircularQueue q;
    greetings();
    q.de_queue();
    q.display();

    q.en_queue(1);
    q.en_queue(2);
    q.en_queue(3);
    q.en_queue(4);
    q.en_queue(5);

    // Fails to en_queue because front == 0 && rear == MAX_LIMIT - 1
    q.en_queue(6);

    q.display();
    cout << "Top element: " << q.peek() << endl;
    int elem = q.de_queue();

    if (elem != -1)
        cout << endl
             << "Deleted Element is " << elem;

    q.display();

    q.en_queue(7);

    q.display();

    // Fails to en_queue because front == rear + 1
    q.en_queue(8);
    q.display();

    return 0;
}