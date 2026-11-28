#include <iostream>
#include <string>
using namespace std;

class Node
{
    public:
    string key; //or int for numeric
    string data;
    Node* next;

    Node(string kei, string datay) : key(kei), data(datay), next(nullptr)
    {}
};

class HashTableNode
{
    private:
    Node** table;
    int table_size; //ideally prime
    int count_nodes;

    int hashFunction(string key) //string version
    {
        int hash = 0;
        for (int i = 0; i < key.length(); i++)
        {
            hash = (hash * 31 + key[i]) % table_size;
        }
        return hash;
    }

    int hashFunction(int key) //int version
    {
        if (key < 0)
        {
            key = -key;
        }
        return key % table_size;
    }

    public:
    HashTableNode(int size): table_size(size), count_nodes(0)
    {
        table = new Node*[table_size];
        for (int i = 0; i < table_size; i++)
        {
            table[i] = nullptr;
        }
    }

    void insert(string key, string value)
    {
        int index = hashFunction(key);
        Node* checker = table[index];

        while (checker != nullptr)
        {
            if (checker->key == key)
            {
                checker->data = value;
                return;
            }
            checker = checker->next;
        }

        Node* new_node = new Node(key, value);
        new_node->next = table[index];
        table[index] = new_node;
        count_nodes++;
    }

    string search(string key)
    {
        int index = hashFunction(key);
        Node* checker = table[index];

        while (checker != nullptr)
        {
            if (checker->key == key)
            {
                return checker->data;
            }
            checker = checker->next;
        }

        return "Not Found";
    }

    bool deleter(string key)
    {
        int index = hashFunction(key);
        Node* checker = table[index];
        if (checker == nullptr)
        {
            return false;
        }
        
        if (checker->key == key)
        {
            table[index] = checker->next;
            delete checker;
            count_nodes--;
            return true;
        }
        while (checker->next != nullptr)
        {
            if (checker->next->key == key)
            {
                Node* deleting = checker->next;
                checker->next = deleting->next;
                delete deleting;
                count_nodes--;
                return true;
            }
            checker = checker->next;
        } 
        return false;
    }

    void display()
    {
        for (int i = 0; i < table_size; i++)
        {
            cout << "Index " << i << ":\t";
            Node* checker = table[i];
            while (checker != nullptr)
            {
                cout << "[" << checker->key << ": " << checker->data << "] ->";
                checker = checker->next; 
            }
            cout << "NULL PTR" << endl;
            
        }
    }
};

class Slot
{
    public:

    string key;
    string data;
    int status; //0 = empty, 1 = occupied, 2 = deleted

    Slot(string kei = "", string datay = "") : key(kei), data(datay), status(0)
    {}

};

class HashTableSlot
{
    private:
    Slot* table;
    int table_size;
    int prime_R;
    int count_slots;

    int hashFunction(string key)
    {
        int hash = 0;
        for (int i = 0; i < key.length(); i++)
        {
            hash = (hash * 31 + key[i]) % table_size;
        }
        return hash;
        
    }

    int hashFunction(int key)
    {
        if (key < 0)
        {
            key = -key;
        }
        return key % table_size;
    }

    int secondHashFunction(string key)
    {
        int hash = 0;
        for (int i = 0; i < key.length(); i++)
        {
            hash = (hash * 31 + key[i]) % prime_R;
        }
        return prime_R - hash; //basically, in above loop, the hash is always gonna be prime_R - 1 or less. so this prevents us from getting 0 in return.  
    }

    int secondHashFunction(int key)
    {
        if (key < 0)
        {
            key = -key;
        }
        return prime_R - (key % prime_R);  
    }

    int probe(string key, int i)
    {
        int h1 = hashFunction(key);

        // Pick one formula:
        // Linear:    return (h1 + i) % table_size;
        // Quadratic: return (h1 + i * i) % table_size;
        // Double:    return (h1 + i * secondHash(key)) % table_size;
        return (h1 + i * secondHashFunction(key)) % table_size;
    }

    public:
    HashTableSlot(int size, int prim = 11) : table_size(size), prime_R(prim), count_slots(0)
    {
        if (prime_R >= table_size)
        {
            prime_R = table_size - 1;
        }
        table = new Slot[size];
    }

   void insert(string key, string value)
    {
        int first_deleted = -1;

        for (int i = 0; i < table_size; i++)
        {
            int index = probe(key, i);

            if (table[index].status == 1 && table[index].key == key)
            {
                table[index].data = value;
                return;
            }
            else if (table[index].status == 2 && first_deleted == -1)
            {
                first_deleted = index;
            }
            else if (table[index].status == 0)
            {
                int target = (first_deleted != -1) ? first_deleted : index;
                table[target].key = key;
                table[target].data = value;
                table[target].status = 1;
                count_slots++;
                return;
            }
        }

        if (first_deleted != -1)
        {
            table[first_deleted].key = key;
            table[first_deleted].data = value;
            table[first_deleted].status = 1;
            count_slots++;
            return;
        }

        cout << "Hash table is full!" << endl;
    }

    string search(string key)
    {
        for (int i = 0; i < table_size; i++)
        {
            int index = probe(key, i);

            if (table[index].status == 0)
            {
                return "Not found.";
            }
            else if (table[index].status == 1 && table[index].key == key)
            {
                return table[index].data;
            }

        }
        return "Not found.";
    }

    bool deleter(string key)
    {
        for (int i = 0; i < table_size; i++)
        {
            int index = probe(key, i);
            if (table[index].status == 0)
            {
                return false;
            }
            else if (table[index].status == 1 && table[index].key == key)
            {
                table[index].data = "";
                table[index].key = "";
                table[index].status = 2;
                count_slots--;
                return true;
            }
        }
        return false;
    }

    void display()
    {
        for (int i = 0; i < table_size; i++)
        {
            cout << "Index " << i << ":\t";
            if (table[i].status == 0)
            {
                cout << "[Empty]" << endl;
            }
            else if (table[i].status == 1)
            {
                cout << "[" << table[i].key << " : " << table[i].data << "]" << endl;
            }
            else if (table[i].status == 2)
            {
                cout << "[Deleted]" << endl;
            }

        }
    }
};

