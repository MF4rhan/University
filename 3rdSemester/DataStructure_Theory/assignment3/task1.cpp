#include <iostream>
#include <string>

using namespace std;

class hashSlot
{
public:
    string word;
    int probes;
    bool is_occupied;

    hashSlot() : word(""), probes(0), is_occupied(false)
    {
    }
};

class vocabHashTable
{
private:
    hashSlot* table;
    int table_size;
    int word_count;
    int roll_sum;

    int computeKey(string word)
    {
        int ascii_sum = 0;
        for (int i = 0; i < (int)word.length(); i++)
        {
            ascii_sum += (int)word[i];
        }
        return ascii_sum + roll_sum;
    }

    int primaryHash(int key)
    {
        return key % table_size;
    }

    int secondaryHash(int key)
    {
        return 7 - (key % 7);
    }

    bool isPrime(int num)
    {
        if (num <= 1)
        {
            return false;
        }
        for (int i = 2; i * i <= num; i++)
        {
            if (num % i == 0)
            {
                return false;
            }
        }
        return true;
    }

    int nextPrime(int num)
    {
        int candidate = num + 1;
        while (!isPrime(candidate))
        {
            candidate++;
        }
        return candidate;
    }

    void resizeTable()
    {
        int old_size = table_size;
        hashSlot* old_table = table;

        table_size = nextPrime(2 * old_size);
        table = new hashSlot[table_size];
        word_count = 0;

        for (int i = 0; i < old_size; i++)
        {
            if (old_table[i].is_occupied)
            {
                insert(old_table[i].word);
            }
        }

        delete[] old_table;
    }

public:
    vocabHashTable(int initial_size, int s_value)
    {
        table_size = initial_size;
        roll_sum = s_value;
        word_count = 0;
        table = new hashSlot[table_size];
    }

    ~vocabHashTable()
    {
        delete[] table;
    }

    void insert(string word)
    {
        int key = computeKey(word);
        int h1 = primaryHash(key);
        int h2 = secondaryHash(key);

        for (int i = 0; i < table_size; i++)
        {
            int index = (h1 + i * h2) % table_size;

            if (table[index].is_occupied && table[index].word == word)
            {
                return;
            }

            if (!table[index].is_occupied)
            {
                table[index].word = word;
                table[index].probes = i + 1;
                table[index].is_occupied = true;
                word_count++;

                double load_factor = (double)word_count / table_size;
                if (load_factor > 0.7)
                {
                    resizeTable();
                }
                return;
            }
        }
    }

    void search(string word)
    {
        int key = computeKey(word);
        int h1 = primaryHash(key);
        int h2 = secondaryHash(key);

        for (int i = 0; i < table_size; i++)
        {
            int index = (h1 + i * h2) % table_size;

            if (!table[index].is_occupied)
            {
                cout << word << ": not memorized" << endl;
                return;
            }

            if (table[index].word == word)
            {
                cout << word << ": found at index " << index << " with " << (i + 1) << " probe(s)" << endl;
                return;
            }
        }

        cout << word << ": not memorized" << endl;
    }

    void display()
    {
        cout << "Hash Table Contents:" << endl;
        for (int i = 0; i < table_size; i++)
        {
            if (table[i].is_occupied)
            {
                cout << "Index " << i << ": Word: " << table[i].word
                     << ", Length: " << table[i].word.length()
                     << ", Probes: " << table[i].probes << endl;
            }
        }

        double load_factor = (double)word_count / table_size;
        cout << "\nTable Size: " << table_size << endl;
        cout << "Total Words: " << word_count << endl;
        cout << "Current Load Factor: " << load_factor << endl;
    }
};

void countingSortByLength(string words[], int n, int exp)
{
    string* output = new string[n];
    int count[10] = {0};

    for (int i = 0; i < n; i++)
    {
        int digit = ((int)words[i].length() / exp) % 10;
        count[digit]++;
    }

    for (int i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--)
    {
        int digit = ((int)words[i].length() / exp) % 10;
        output[count[digit] - 1] = words[i];
        count[digit]--;
    }

    for (int i = 0; i < n; i++)
    {
        words[i] = output[i];
    }

    delete[] output;
}

void radixSortByLength(string words[], int n)
{
    int max_len = 0;
    for (int i = 0; i < n; i++)
    {
        if ((int)words[i].length() > max_len)
        {
            max_len = (int)words[i].length();
        }
    }

    for (int exp = 1; max_len / exp > 0; exp *= 10)
    {
        countingSortByLength(words, n, exp);
    }
}

int getRollDigitSum(string roll_no)
{
    int sum = 0;
    for (int i = 0; i < (int)roll_no.length(); i++)
    {
        if (roll_no[i] >= '0' && roll_no[i] <= '9')
        {
            sum += roll_no[i] - '0';
        }
    }
    return sum;
}

int main()
{
    string roll_no = "25K-0538";
    int roll_sum = getRollDigitSum(roll_no);

    int total_words = 10;
    string words[10] = {
        "Kindness", "Politeness", "Understandable", "Empathy", "Knowledge",
        "Gratitude", "Patience", "Righteous", "Appreciate", "Easy"
    };

    radixSortByLength(words, total_words);

    vocabHashTable dictionary(20, roll_sum);

    for (int i = 0; i < total_words; i++)
    {
        dictionary.insert(words[i]);
    }

    dictionary.display();

    cout << "\nSearch Results:" << endl;
    dictionary.search("Empathy");
    dictionary.search("Courage");

    return 0;
}