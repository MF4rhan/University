#include <iostream>
#include <string>
using namespace std;

class song
{
    public:
    string title;
    string genre;
    int duration;
    bool isExplicit;
    song* next;

    song(string titl = "N/A", string genr = "N/A", int dur = 0, bool expl = false)
    : title(titl), genre(genr), duration(dur), isExplicit(expl), next(nullptr)
    {}
};

class playlist
{
    private:
    song* head;
    int operationCounter;

    void operationCheck()
    {
        operationCounter++;
        if (operationCounter % 3 == 0)
        {
            validate_rules();
        }
    }

    void validate_rules()
    {
        cout << "\nChecking playlist rules after 3 operations...\n";
        bool genreBroken = false;
        bool durationBroken = false;

        song* checker = head;
        while (checker != nullptr && checker->next != nullptr)
        {
            if (checker->genre == checker->next->genre)
            {
                genreBroken = true;
            }
            checker = checker->next;
        }

        checker = head;
        while (checker != nullptr && checker->next != nullptr && checker->next->next != nullptr)
        {
            if (checker->duration + checker->next->duration + checker->next->next->duration > 600)
            {
                durationBroken = true;
            }
            checker = checker->next;
        }

        if (!genreBroken && !durationBroken)
        {
            cout << "All rules are satisfied.\n";
        }
        else
        {
            if (genreBroken)
            {
                cout << "Warning: Two songs of the same genre ended up adjacent.\n";
            }
            if (durationBroken)
            {
                cout << "Warning: Some 3 consecutive songs exceed 600 seconds.\n";
            }
        }
    }

    public:
    playlist(): head(nullptr), operationCounter(0)
    {}

    ~playlist()
    {
        while (head != nullptr)
        {
            song* to_delete = head;
            head = head->next;
            delete to_delete;
        }
    }

    int count_songs()
    {
        int counter = 0;
        song* checker = head;
        while (checker != nullptr)
        {
            counter++;
            checker = checker->next;
        }
        return counter;
    }

    song* get_node_at(int index)
    {
        if (index < 0)
        {
            return nullptr;
        }

        song* checker = head;
        int counter = 0;
        while (checker != nullptr && counter < index)
        {
            checker = checker->next;
            counter++;
        }
        return checker;
    }

    void insert_song(string titl, string genr, int dur, bool expl, int index)
    {
        int size = count_songs();
        if (index < 0 || index > size)
        {
            cout << "\nInvalid Position.\n";
            return;
        }

        int pos = index;
        while (pos <= size)
        {
            song* before = nullptr;
            song* after = head;
            int counter = 0;
            while (counter < pos)
            {
                before = after;
                after = after->next;
                counter++;
            }

            bool genreOk = true;
            if (before != nullptr && before->genre == genr)
            {
                genreOk = false;
            }
            if (after != nullptr && after->genre == genr)
            {
                genreOk = false;
            }

            bool durationOk = true;
            song* two_before = get_node_at(pos - 2);
            if (two_before != nullptr && before != nullptr)
            {
                if (two_before->duration + before->duration + dur > 600)
                {
                    durationOk = false;
                }
            }
            if (before != nullptr && after != nullptr)
            {
                if (before->duration + dur + after->duration > 600)
                {
                    durationOk = false;
                }
            }
            if (after != nullptr && after->next != nullptr)
            {
                if (dur + after->duration + after->next->duration > 600)
                {
                    durationOk = false;
                }
            }

            if (genreOk && durationOk)
            {
                song* new_song = new song(titl, genr, dur, expl);
                new_song->next = after;
                if (before == nullptr)
                {
                    head = new_song;
                }
                else
                {
                    before->next = new_song;
                }

                if (pos == index)
                {
                    cout << "\nSong inserted at position " << pos << ".\n";
                }
                else
                {
                    cout << "\nPosition " << index << " would have broken the rules, song inserted at position " << pos << " instead.\n";
                }
                operationCheck();
                return;
            }

            pos++;
        }

        cout << "\nCould not find a valid position without breaking the rules, song not added.\n";
    }

    void delete_song(int index)
    {
        song* target = get_node_at(index);
        if (target == nullptr)
        {
            cout << "\nInvalid Position.\n";
            return;
        }

        if (target->isExplicit)
        {
            cout << "\nThis song is marked explicit, it cannot be deleted directly. Remove the explicit flag first.\n";
            return;
        }

        song* before = nullptr;
        if (index > 0)
        {
            before = get_node_at(index - 1);
        }

        if (before == nullptr)
        {
            head = target->next;
        }
        else
        {
            before->next = target->next;
        }

        delete target;
        cout << "\nSong deleted from position " << index << ".\n";
        operationCheck();
    }

    void remove_explicit_flag(int index)
    {
        song* target = get_node_at(index);
        if (target == nullptr)
        {
            cout << "\nInvalid Position.\n";
            return;
        }

        target->isExplicit = false;
        cout << "\nExplicit flag removed from position " << index << ", it can now be deleted.\n";
    }

    void search_song(string titl)
    {
        song* checker = head;
        int pos = 0;
        while (checker != nullptr)
        {
            if (checker->title == titl)
            {
                cout << "\nSong found at Position " << pos << ": " << checker->title << "  Genre: " << checker->genre << "  Duration: " << checker->duration << "  Explicit: " << (checker->isExplicit ? "Yes" : "No") << "\n";
                operationCheck();
                return;
            }
            checker = checker->next;
            pos++;
        }

        cout << "\nSong not found.\n";
        operationCheck();
    }

    void display_playlist()
    {
        if (head == nullptr)
        {
            cout << "\nThe playlist is empty.\n";
            return;
        }

        song* checker = head;
        int pos = 0;
        while (checker != nullptr)
        {
            cout << "\nPosition " << pos++ << ": " << checker->title << "  Genre: " << checker->genre << "  Duration: " << checker->duration << "  Explicit: " << (checker->isExplicit ? "Yes" : "No");
            checker = checker->next;
        }
        cout << "\n";
    }
};

int main()
{
    playlist my_playlist;

    int choice;
    do
    {
        cout << "\n1. Insert Song";
        cout << "\n2. Delete Song";
        cout << "\n3. Remove Explicit Flag from a Song";
        cout << "\n4. Search Song";
        cout << "\n5. Display Playlist";
        cout << "\n6. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            string titl, genr;
            int dur, index, explChoice;

            cout << "\nEnter Song Title: ";
            cin >> titl;
            cout << "\nEnter Genre (pop, rock, jazz, classical, electronic): ";
            cin >> genr;
            cout << "\nEnter Duration in seconds: ";
            cin >> dur;
            cout << "\nIs it Explicit? (1 for Yes, 0 for No): ";
            cin >> explChoice;
            cout << "\nEnter Position to insert at: ";
            cin >> index;

            my_playlist.insert_song(titl, genr, dur, explChoice == 1, index);
        }
        else if (choice == 2)
        {
            int index;
            cout << "\nEnter Position to delete: ";
            cin >> index;

            my_playlist.delete_song(index);
        }
        else if (choice == 3)
        {
            int index;
            cout << "\nEnter Position to remove explicit flag from: ";
            cin >> index;

            my_playlist.remove_explicit_flag(index);
        }
        else if (choice == 4)
        {
            string titl;
            cout << "\nEnter Title to search: ";
            cin >> titl;

            my_playlist.search_song(titl);
        }
        else if (choice == 5)
        {
            my_playlist.display_playlist();
        }
        else if (choice != 6)
        {
            cout << "\nInvalid Choice, Please try again.\n";
        }

    } while (choice != 6);

    return 0;
}