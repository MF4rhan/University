#include <iostream>
using namespace std;

class player
{
    public:
    int id;
    int energy;
    char history[1000];
    int historyTop;

    player(int pid = 0) : id(pid), energy(100), historyTop(-1)
    {}

    void push_action(char act)
    {
        historyTop++;
        history[historyTop] = act;
    }

    char pop_action()
    {
        char act = history[historyTop];
        historyTop--;
        return act;
    }

    bool has_action()
    {
        return historyTop >= 0;
    }

    int actions_left()
    {
        return historyTop + 1;
    }
};

class waiting_line
{
    private:
    int arr[105];
    int front;
    int rear;
    int count;
    int capacity;

    public:
    waiting_line(int cap = 100) : front(0), rear(-1), count(0), capacity(cap)
    {}

    bool is_empty()
    {
        return count == 0;
    }

    void enqueue(int val)
    {
        if (count == capacity)
        {
            cout << "\nWaiting Line is Full.\n";
            return;
        }
        rear = (rear + 1) % capacity;
        arr[rear] = val;
        count++;
    }

    int dequeue()
    {
        if (is_empty())
        {
            cout << "\nWaiting Line is empty.\n";
            return -1;
        }
        int val = arr[front];
        front = (front + 1) % capacity;
        count--;
        return val;
    }

    void display(player players[])
    {
        if (is_empty())
        {
            cout << "\nNone.\n";
            return;
        }

        int idx = front;
        for (int i = 0; i < count; i++)
        {
            int p = arr[idx];
            cout << "\nID: " << players[p].id << "  Energy: " << players[p].energy << "  Actions that can be undone: " << players[p].actions_left();
            idx = (idx + 1) % capacity;
        }
        cout << "\n";
    }
};

int main()
{
    cout << "Enter number of players: ";
    int n;
    cin >> n;

    player* players = new player[n];
    for (int i = 0; i < n; i++)
    {
        players[i].id = i + 1;
        players[i].energy = 100;
        players[i].historyTop = -1;
    }

    waiting_line line(n);
    for (int i = 0; i < n; i++)
    {
        line.enqueue(i);
    }

    int* eliminated = new int[n];
    int eliminatedCount = 0;

    cout << "\nEnter number of commands: ";
    int commands;
    cin >> commands;

    cout << "Enter the commands (F, B, T, U):\n";
    for (int i = 0; i < commands; i++)
    {
        if (line.is_empty())
        {
            cout << "\nAll players have been eliminated, remaining commands are ignored.\n";
            break;
        }

        char command;
        cin >> command;

        int current = line.dequeue();

        if (command == 'F')
        {
            players[current].energy -= 10;
            players[current].push_action('F');
        }
        else if (command == 'B')
        {
            players[current].push_action('B');
        }
        else if (command == 'T')
        {
            players[current].energy += 20;
            players[current].push_action('T');
        }
        else if (command == 'U')
        {
            if (players[current].has_action())
            {
                char lastAction = players[current].pop_action();
                if (lastAction == 'F')
                {
                    players[current].energy += 10;
                }
                else if (lastAction == 'T')
                {
                    players[current].energy -= 20;
                }
            }
        }
        else
        {
            cout << "\nInvalid Command.\n";
        }

        if (players[current].energy <= 0)
        {
            eliminated[eliminatedCount++] = players[current].id;
        }
        else
        {
            line.enqueue(current);
        }
    }

    cout << "\nEND OF GAME REPORT\n";

    cout << "Elimination Order: ";
    if (eliminatedCount == 0)
    {
        cout << "None";
    }
    else
    {
        for (int i = 0; i < eliminatedCount; i++)
        {
            cout << eliminated[i];
            if (i < eliminatedCount - 1)
            {
                cout << " -> ";
            }
        }
    }
    cout << "\n";

    cout << "\nRemaining Players in the Waiting Line:";
    line.display(players);

    delete[] players;
    delete[] eliminated;

    return 0;
}