#include <iostream>
using namespace std;

#define MAX 100

class Queue {
    int arr[MAX];
    int front, rear;  

public:
    Queue() 
    {
        front = -1;
        rear = -1;
    }

    bool is_empty() 
    {
        return front == -1;
    }

    bool is_full() 
    {
        return rear == MAX - 1;
    }

    void enqueue(int x) 
    {
        if (is_full()) 
        {
            cout << "Queue Overflow\n";
            return;
        }
        if (is_empty())
            front = 0;  
        arr[++rear] = x;
    }

    void dequeue() 
    {
        if (is_empty()) 
        {
            cout << "Queue Underflow\n";
            return;
        }
        if (front == rear) 
        {
           
            front = -1;
            rear = -1;
        } else 
        {
            front++;  
        }
    }

    int peek() 
    {
        if (is_empty()) 
        {
            cout << "Queue is empty\n";
            return -1;
        }
        return arr[front];
    }

    int get_size()
    {
        if (is_empty())
        {
            return 0;
        }
        return rear - front + 1;
    }

};

class Stack 
{
    int arr[MAX]; 
    int top;       

public:
    Stack() {
        top = -1;   
    }

    bool is_empty() {
        return top == -1;
    }

    bool is_full() {
        return top == MAX - 1;
    }

    void push(int x) {
        if (is_full()) {
            cout << "Stack Overflow\n";
            return;
        }
        arr[++top] = x;   
    }

    void pop() {
        if (is_empty()) {
            cout << "Stack Underflow\n";
            return;
        }
        top--;   
    }

    int peek() {
        if (is_empty()) {
            cout << "Stack is empty\n";
            return -1;
        }
        return arr[top];
    }
};

void reverse_first_k(Queue& q, int k)
{
    if (q.is_empty() || k <= 0 || k > q.get_size())
    {
        return;
    }
    
    Stack stacky;

    for (int i = 0; i < k; i++)
    {
        stacky.push(q.peek());
        q.dequeue();
    }

    int remaining = q.get_size();

    while (!stacky.is_empty())
    {
        q.enqueue(stacky.peek());
        stacky.pop();
    }

    for (int i = 0; i < remaining; i++)
    {
        int temp = q.peek();
        q.dequeue();
        q.enqueue(temp);
    }
}

int main()
{
    Queue q;
    
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6);
    q.enqueue(7);

    int k;
    cout << "Enter the first K elements you'd like to reverse in the queue: ";
    cin >> k;

    reverse_first_k(q, k);

    cout << "Queue after reversing first " << k << " elements:\n";
    while (!q.is_empty())
    {
        cout << q.peek() << " ";
        q.dequeue();
    }
    cout << "\n";

    return 0;
}