
#include <iostream>
using namespace std;

class participant
{
    public:
    int id;
    int score;
    int examined_count;
    participant* next;
    participant* prev;
    participant(int i = 0, int sco = 0) : id(i), score(sco), examined_count(0) {}
};

class exam
{
    participant* head;

    public:
    exam() : head(nullptr)  {}

    void insert_at_tail(int id, int score)
    {
        participant* new_participant = new participant(id, score);
        if (head == nullptr)
        {
            head = new_participant;
            head->next = head;
            head->prev = head;
            return;
        }
        participant* tail = head->prev; //getting last node/tail

        tail->next = new_participant;
        new_participant->prev = tail;
        new_participant->next = head;
        head->prev = new_participant;
    }

    void delete_node(participant* node)
    {
        if (node == nullptr)
        {
            cout << "\nCannot delete nullptr.\n";
            return;
        }

        participant* prev_node = node->prev;
        participant* next_node = node->next;
        if (head == node)
        {
            head = next_node;
        }
        prev_node->next = next_node;
        next_node->prev = prev_node;
        delete node;
    }

    void examine()
    {
        if (head == nullptr)
        {
            cout << "\nThe List is empty.\n";
            return;
        }
        participant* checker = head;
        participant* deletion = nullptr;
        bool del = false;

        while (checker->prev != checker && checker->next != checker)
        {
            checker->examined_count++;
            if (checker->examined_count == 3)
            {
                deletion = checker;
                del = true;
            }    

            if (checker->score % 2 == 0)
            {
                checker = checker->next;
                checker = checker->next;
            }
            else if (checker->score % 2 == 1)
            {
                checker = checker->prev;
                checker = checker->prev;
            }

            if (del)
            {
                if (checker == deletion)
                {
                    checker = deletion->next;
                    //if we don't do the above line, then with 2 remaining participants:
                    //checker skips two positions forwards or backwards, and checker then ends up on the same node thats being deleted.
                    //This can cause problems, hence we shift checker so we don't get that problem.
                }  
                delete_node(deletion);
                del = false;
            }
  
        }

    }

    void print()
    {
        if (head == nullptr)
        {
            cout << "\nThe List is empty.\n";
            return;
        }
        int i = 1;
        participant* checker = head;
        do
        {
            cout << "Participant #" << i << ":\tID: " << checker->id << "\t Score: " << checker->score << endl;
            i++;
            checker = checker->next;
        } while (checker != head);
        
    }

};


int main()
{
    exam exammy;
    exammy.insert_at_tail(01, 10);
    exammy.insert_at_tail(02, 12);
    exammy.insert_at_tail(03, 20);
    exammy.insert_at_tail(04, 21);
    exammy.insert_at_tail(05, 15);
    exammy.insert_at_tail(06, 18);
    exammy.insert_at_tail(07, 31);
    exammy.insert_at_tail(10, 33);

    cout << "\nInitial List: \n";
    exammy.print();

    exammy.examine();

    cout << "\n\nFinal Remaining: \n";
    exammy.print();
}