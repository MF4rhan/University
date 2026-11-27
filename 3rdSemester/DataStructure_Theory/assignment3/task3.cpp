#include <iostream>
#include <string>

using namespace std;

class courseRecord
{
public:
    string course_code;
    string* student_names;
    int student_count;

    courseRecord() : course_code(""), student_names(nullptr), student_count(0)
    {
    }

    void setData(string code, string names[], int count)
    {
        course_code = code;
        student_count = count;
        student_names = new string[count];
        for (int i = 0; i < count; i++)
        {
            student_names[i] = names[i];
        }
    }
};

class courseNode
{
public:
    string course_code;
    string* student_names;
    int student_count;
    courseNode* next;

    courseNode(string code, string names[], int count)
    {
        course_code = code;
        student_count = count;
        student_names = new string[count];
        for (int i = 0; i < count; i++)
        {
            student_names[i] = names[i];
        }
        next = nullptr;
    }

    ~courseNode()
    {
        delete[] student_names;
    }
};

class courseHashTable
{
private:
    courseNode** table;
    int table_size;
    int total_courses;

    int computeHashKey(string course_code)
    {
        int key = 0;
        for (int i = 0; i < (int)course_code.length(); i++)
        {
            if (course_code[i] >= '0' && course_code[i] <= '9')
            {
                key += course_code[i] - '0';
            }
        }
        return key;
    }

    int hashFunction(int key)
    {
        return key % table_size;
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

    void insertWithoutResize(string course_code, string student_names[], int student_count)
    {
        int key = computeHashKey(course_code);
        int index = hashFunction(key);

        courseNode* new_node = new courseNode(course_code, student_names, student_count);

        if (table[index] == nullptr)
        {
            table[index] = new_node;
        }
        else
        {
            courseNode* current = table[index];
            while (current->next != nullptr)
            {
                current = current->next;
            }
            current->next = new_node;
        }
        total_courses++;
    }

    void resizeTable()
    {
        int old_size = table_size;
        courseNode** old_table = table;

        table_size = nextPrime(2 * old_size);
        table = new courseNode*[table_size];
        for (int i = 0; i < table_size; i++)
        {
            table[i] = nullptr;
        }
        total_courses = 0;

        for (int i = 0; i < old_size; i++)
        {
            courseNode* current = old_table[i];
            while (current != nullptr)
            {
                insertWithoutResize(current->course_code, current->student_names, current->student_count);
                courseNode* temp = current;
                current = current->next;
                delete temp;
            }
        }

        delete[] old_table;
    }

public:
    courseHashTable(int initial_size)
    {
        table_size = initial_size;
        total_courses = 0;
        table = new courseNode*[table_size];
        for (int i = 0; i < table_size; i++)
        {
            table[i] = nullptr;
        }
    }

    ~courseHashTable()
    {
        for (int i = 0; i < table_size; i++)
        {
            courseNode* current = table[i];
            while (current != nullptr)
            {
                courseNode* temp = current;
                current = current->next;
                delete temp;
            }
        }
        delete[] table;
    }

    void insert(string course_code, string student_names[], int student_count)
    {
        insertWithoutResize(course_code, student_names, student_count);

        double load_factor = (double)total_courses / table_size;
        if (load_factor > 0.7)
        {
            resizeTable();
        }
    }

    void display()
    {
        cout << "Hash Table Contents:" << endl;
        for (int i = 0; i < table_size; i++)
        {
            cout << "Index " << i << ": ";
            courseNode* current = table[i];
            int node_count = 0;

            if (current == nullptr)
            {
                cout << "Empty (Nodes: 0)" << endl;
            }
            else
            {
                while (current != nullptr)
                {
                    cout << current->course_code << " (Students: ";
                    for (int j = 0; j < current->student_count; j++)
                    {
                        cout << current->student_names[j];
                        if (j < current->student_count - 1)
                        {
                            cout << ", ";
                        }
                    }
                    cout << ")";
                    node_count++;

                    if (current->next != nullptr)
                    {
                        cout << " -> ";
                    }
                    current = current->next;
                }
                cout << " | Nodes at index: " << node_count << endl;
            }
        }

        double load_factor = (double)total_courses / table_size;
        cout << "\nCurrent Hash Table Size: " << table_size << endl;
        cout << "Total Number of Courses Stored: " << total_courses << endl;
        cout << "Current Load Factor: " << load_factor << endl;
    }
};

void swapCourses(courseRecord& a, courseRecord& b)
{
    courseRecord temp = a;
    a = b;
    b = temp;
}

int partitionCourses(courseRecord courses[], int low, int high)
{
    int pivot = courses[high].student_count;
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (courses[j].student_count <= pivot)
        {
            i++;
            swapCourses(courses[i], courses[j]);
        }
    }
    swapCourses(courses[i + 1], courses[high]);
    return i + 1;
}

void quickSortCourses(courseRecord courses[], int low, int high)
{
    if (low < high)
    {
        int pivot_index = partitionCourses(courses, low, high);
        quickSortCourses(courses, low, pivot_index - 1);
        quickSortCourses(courses, pivot_index + 1, high);
    }
}

int main()
{
    int total_courses = 6;
    courseRecord courses[6];

    string c1_students[] = {"Ali", "Maria"};
    courses[0].setData("CS1001", c1_students, 2);

    string c2_students[] = {"Hassan"};
    courses[1].setData("CS102", c2_students, 1);

    string c3_students[] = {"Basheer", "Kamran"};
    courses[2].setData("CS103", c3_students, 2);

    string c4_students[] = {"Abdullah", "Ayesha", "Sana"};
    courses[3].setData("CS104", c4_students, 3);

    string c5_students[] = {"Fatima", "Saleem", "Saif", "Aftab"};
    courses[4].setData("CS105", c5_students, 4);

    string c6_students[] = {"Talha", "Khalid"};
    courses[5].setData("CS502", c6_students, 2);

    quickSortCourses(courses, 0, total_courses - 1);

    courseHashTable enrollment_table(7);

    for (int i = 0; i < total_courses; i++)
    {
        enrollment_table.insert(courses[i].course_code, courses[i].student_names, courses[i].student_count);
    }

    enrollment_table.display();

    for (int i = 0; i < total_courses; i++)
    {
        delete[] courses[i].student_names;
    }

    return 0;
}