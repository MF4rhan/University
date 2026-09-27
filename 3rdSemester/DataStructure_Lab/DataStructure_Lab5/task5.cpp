#include <iostream>
using namespace std;

#define MAX 6

class queue
{
    int arr[MAX];
    int front;
    int rear;
    int count;

    public:
    queue() : front(0), rear(-1), count(0) {}

    bool is_empty()
    {
        return count == 0;
    }

    bool is_full()
    {
        return count == MAX;
    }

    void enqueue(int input)
    {
        if (is_full())
        {
            cout << "\nQueue is full.\n";
            return;
        }
        rear = (rear + 1) % MAX;
        arr[rear] = input;
        count++;
    }

    void dequeue()
    {
        if (is_empty())
        {
            cout << "\nQueue is empty.\n";
            return;
        }
        front = (front + 1) % MAX;
        count--;
    }

    int peek()
    {
        if (is_empty())
        {
            cout << "\nQueue is empty.\n";
            return -1;
        }
        return arr[front];
    }

    int get_count()
    {
        return count;
    }

    int get_front()
    {
        return front;
    }

    int get_rear()
    {
        return rear;
    }

    void display_all()
    {
        if (is_empty())
        {
            cout << "\nThe Queue is Empty.\n";
            return;
        }
        for (int i = 0; i < MAX; i++)
        {
            cout << arr[i] << " ";
        }
    }
};

int main()
{
    queue gate;
    gate.enqueue(101);
    gate.enqueue(102);
    gate.enqueue(103);
    gate.enqueue(104);
    gate.enqueue(105);
    gate.enqueue(106);

    gate.dequeue();
    gate.dequeue();
    gate.dequeue();

    gate.enqueue(107);
    gate.enqueue(108);
    gate.enqueue(109);

    gate.dequeue();
    gate.dequeue();

    gate.enqueue(110);

    gate.dequeue();

    gate.enqueue(111);
    gate.enqueue(112);

    gate.display_all();
    cout << "\nFinal Rear: " << gate.get_rear();
    cout << "\nFinal Front: " << gate.get_front();

    return 0;
}