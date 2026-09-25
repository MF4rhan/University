#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

combatant* select_combatant(team& t);
void hero_turn(team& heroes, team& enemies);
void enemy_turn(team& heroes, team& enemies);

class combatant
{
    public:
    string name;
    int health;
    int attack;
    combatant* prev;
    combatant* next;

    combatant(string namae = "N/A", int hp = 0, int atk = 0)
    : name(namae), health(hp), attack(atk), prev(nullptr), next(nullptr)
    {}
};

class team
{
    private:
    combatant* head;
    combatant* tail;

    public:
    team() : head(nullptr), tail(nullptr)
    {}

    ~team()
    {
        combatant* checker = head;
        while (checker != nullptr)
        {
            combatant* holder = checker->next;
            delete checker;
            checker = holder;
        }
    }

    bool is_empty()
    {
        return head == nullptr;
    }

    void insert_at_tail(string namae, int hp, int atk)
    {
        combatant* new_combatant = new combatant(namae, hp, atk);
        if (head == nullptr)
        {
            head = new_combatant;
            tail = new_combatant;
            return;
        }

        tail->next = new_combatant;
        new_combatant->prev = tail;
        tail = new_combatant;
    }

    combatant* find_by_name(string namae)
    {
        combatant* checker = head;
        while (checker != nullptr)
        {
            if (checker->name == namae)
            {
                return checker;
            }
            checker = checker->next;
        }
        return nullptr;
    }

    combatant* find_by_position(int index)
    {
        if (index < 0)
        {
            return nullptr;
        }

        combatant* checker = head;
        int counter = 0;
        while (checker != nullptr && counter < index)
        {
            checker = checker->next;
            counter++;
        }
        return checker;
    }

    void remove_combatant(combatant* target)
    {
        if (target == nullptr)
        {
            return;
        }

        if (target->prev != nullptr)
        {
            target->prev->next = target->next;
        }
        else
        {
            head = target->next;
        }

        if (target->next != nullptr)
        {
            target->next->prev = target->prev;
        }
        else
        {
            tail = target->prev;
        }

        delete target;
    }

    int count_members()
    {
        int counter = 0;
        combatant* checker = head;
        while (checker != nullptr)
        {
            counter++;
            checker = checker->next;
        }
        return counter;
    }

    int total_health()
    {
        int sum = 0;
        combatant* checker = head;
        while (checker != nullptr)
        {
            sum += checker->health;
            checker = checker->next;
        }
        return sum;
    }

    void display_names()
    {
        if (head == nullptr)
        {
            cout << "None";
        }

        combatant* checker = head;
        while (checker != nullptr)
        {
            cout << checker->name;
            if (checker->next != nullptr)
            {
                cout << ", ";
            }
            checker = checker->next;
        }
        cout << "\n";
    }

    void display_full()
    {
        if (head == nullptr)
        {
            cout << "\nNone.\n";
            return;
        }

        combatant* checker = head;
        while (checker != nullptr)
        {
            cout << "\nName: " << checker->name << "  Health: " << checker->health << "  Attack Power: " << checker->attack;
            checker = checker->next;
        }
        cout << "\n";
    }
};



int main()
{
    srand(time(0));

    team heroes;
    team enemies;

    cout << "Setting up the Hero's Team (5 Heroes):\n";
    for (int i = 0; i < 5; i++)
    {
        string namae;
        int hp, atk;

        cout << "\nEnter Hero " << i + 1 << " Name: ";
        cin >> namae;
        cout << "Enter Health (1-70): ";
        cin >> hp;
        cout << "Enter Attack Power (1-5): ";
        cin >> atk;

        heroes.insert_at_tail(namae, hp, atk);
    }

    cout << "\nSetting up the Enemy Team (5 Enemies):\n";
    for (int i = 0; i < 5; i++)
    {
        string namae;
        int hp, atk;

        cout << "\nEnter Enemy " << i + 1 << " Name: ";
        cin >> namae;
        cout << "Enter Health (1-70): ";
        cin >> hp;
        cout << "Enter Attack Power (1-5): ";
        cin >> atk;

        enemies.insert_at_tail(namae, hp, atk);
    }

    int ROUND_LIMIT = 10;
    int round = 1;
    bool battleOver = false;

    while (round <= ROUND_LIMIT && !battleOver)
    {
        cout << "\n----- Round " << round << " -----\n";

        cout << "\nHero's Turn:\n";
        hero_turn(heroes, enemies);

        if (enemies.is_empty())
        {
            cout << "\nThe Enemy Team has been eliminated, Heroes win!\n";
            battleOver = true;
            break;
        }

        cout << "\nEnemy Counterattack:\n";
        enemy_turn(heroes, enemies);

        if (heroes.is_empty())
        {
            cout << "\nThe Hero Team has been eliminated, Enemies win!\n";
            battleOver = true;
            break;
        }

        round++;
    }

    if (!battleOver)
    {
        int heroHealth = heroes.total_health();
        int enemyHealth = enemies.total_health();

        cout << "\n----- Battle Complete after " << ROUND_LIMIT << " rounds -----\n";

        if (heroHealth > enemyHealth)
        {
            cout << "\nThe Heroes win with more total health remaining!\n";
            cout << "\nSurviving Heroes:";
            heroes.display_full();
        }
        else if (enemyHealth > heroHealth)
        {
            cout << "\nThe Enemies win with more total health remaining!\n";
            cout << "\nSurviving Enemies:";
            enemies.display_full();
        }
        else
        {
            cout << "\nThe battle ends in a Draw!\n";
            cout << "\nRemaining Heroes:";
            heroes.display_full();
            cout << "\nRemaining Enemies:";
            enemies.display_full();
        }
    }
    else
    {
        if (heroes.is_empty())
        {
            cout << "\nSurviving Enemies:";
            enemies.display_full();
        }
        else
        {
            cout << "\nSurviving Heroes:";
            heroes.display_full();
        }
    }

    return 0;
}

combatant* select_combatant(team& t)
{
    int mode;
    do
    {
        cout << "\nSelect by Name or Position (1 for Name, 2 for Position): ";
        cin >> mode;

        if (mode != 1 && mode != 2)
        {
            cout << "\nInvalid Choice, Please try again.\n";
        }

    } while (mode != 1 && mode != 2);

    combatant* selected = nullptr;
    if (mode == 1)
    {
        string namae;
        cout << "Enter Name: ";
        cin >> namae;
        selected = t.find_by_name(namae);
    }
    else
    {
        int index;
        cout << "Enter Position (starting from 0): ";
        cin >> index;
        selected = t.find_by_position(index);
    }

    if (selected == nullptr)
    {
        cout << "\nThat combatant does not exist in the team.\n";
    }

    return selected;
}

void hero_turn(team& heroes, team& enemies)
{
    cout << "\nChoose your attacker:";
    combatant* attacker = nullptr;
    while (attacker == nullptr)
    {
        attacker = select_combatant(heroes);
    }

    cout << "\nChoose the target to attack:";
    combatant* target = nullptr;
    while (target == nullptr)
    {
        target = select_combatant(enemies);
    }

    int damage = attacker->attack * (rand() % 3 + 1);
    target->health -= damage;
    cout << "\n" << attacker->name << " attacked " << target->name << " for " << damage << " damage.\n";

    if (target->health <= 0)
    {
        cout << "\n" << target->name << " has been defeated.\n";
        enemies.remove_combatant(target);
    }

    cout << "\nRemaining Heroes: ";
    heroes.display_names();
    cout << "Remaining Enemies: ";
    enemies.display_names();
}

void enemy_turn(team& heroes, team& enemies)
{
    int enemyCount = enemies.count_members();
    int enemyIndex = rand() % enemyCount;
    combatant* attacker = enemies.find_by_position(enemyIndex);

    int heroCount = heroes.count_members();
    int heroIndex = rand() % heroCount;
    combatant* target = heroes.find_by_position(heroIndex);

    int damage = attacker->attack * (rand() % 3 + 1);
    target->health -= damage;
    cout << "\n" << attacker->name << " counterattacked " << target->name << " for " << damage << " damage.\n";

    if (target->health <= 0)
    {
        cout << "\n" << target->name << " has been defeated.\n";
        heroes.remove_combatant(target);
    }

    cout << "\nRemaining Heroes: ";
    heroes.display_names();
    cout << "Remaining Enemies: ";
    enemies.display_names();
}