#include <iostream>
#include <string>

using namespace std;

struct Student
{
    string student_id;
    string name;
    string department;
    double cgpa;
    string award;

    Student() : student_id(""), name(""), department(""), cgpa(0.0), award("None")
    {
    }

    Student(string id, string student_name, string dept, double student_cgpa) : student_id(id), name(student_name), department(dept), cgpa(student_cgpa), award("None")
    {
    }
};

//merges two sorted subarrays into one in descending order
void merge(Student* students, int left, int mid, int right)
{
    int left_size = mid - left + 1;
    int right_size = right - mid;

    //allocate temporary arrays for left and right halves
    Student* left_arr = new Student[left_size];
    Student* right_arr = new Student[right_size];

    for (int i = 0; i < left_size; i++)
    {
        left_arr[i] = students[left + i];
    }
    for (int j = 0; j < right_size; j++)
    {
        right_arr[j] = students[mid + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = left;

    //using >= ensures stability by picking the left element first on tie
    while (i < left_size && j < right_size)
    {
        if (left_arr[i].cgpa >= right_arr[j].cgpa)
        {
            students[k] = left_arr[i];
            i++;
        }
        else
        {
            students[k] = right_arr[j];
            j++;
        }
        k++;
    }

    //copy any remaining elements from left half
    while (i < left_size)
    {
        students[k] = left_arr[i];
        i++;
        k++;
    }

    //copy any remaining elements from right half
    while (j < right_size)
    {
        students[k] = right_arr[j];
        j++;
        k++;
    }

    delete[] left_arr;
    delete[] right_arr;
}

//divide and conquer merge sort
void merge_sort(Student* students, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        merge_sort(students, left, mid);
        merge_sort(students, mid + 1, right);
        merge(students, left, mid, right);
    }
}

//assigns rector's list and dean's list based on university criteria
void assign_awards(Student* students, int total_students)
{
    for (int i = 0; i < total_students; i++)
    {
        if (students[i].cgpa >= 3.75)
        {
            students[i].award = "Rector's List";
        }
        else if (students[i].cgpa >= 3.50)
        {
            students[i].award = "Dean's List";
        }
        else
        {
            students[i].award = "None";
        }
    }
}

//displays final ranked merit list handling ties in rank
void display_merit_list(Student* students, int total_students)
{
    int current_rank = 1;

    for (int i = 0; i < total_students; i++)
    {
        //update rank only when cgpa drops
        if (i > 0 && students[i].cgpa < students[i - 1].cgpa)
        {
            current_rank = i + 1;
        }

        cout << "Rank " << current_rank << ": "<< students[i].student_id << " | "<< students[i].name << " | "
             << students[i].department << " | "<< "CGPA: " << students[i].cgpa << " | "<< students[i].award << "\n";
    }
}

int main()
{
    //ill be honest, i used ai to generate the students list, i am not writing down all 30 by hand.
    const int total_students = 30;
    Student students[total_students] = {
        Student("23K-0101", "Ali Khan", "CS", 3.82),
        Student("23K-0102", "Bilal Ahmed", "SE", 3.45),
        Student("23K-0103", "Hamza Tariq", "CS", 3.75),
        Student("23K-0104", "Ayesha Siddiqui", "AI", 4.00),
        Student("23K-0105", "Zainab Fatima", "DS", 3.65),
        Student("23K-0106", "Usman Ghani", "CS", 3.20),
        Student("23K-0107", "Saad Rehman", "SE", 3.90),
        Student("23K-0108", "Hassan Raza", "AI", 3.50),
        Student("23K-0109", "Fatima Noor", "CS", 3.75),
        Student("23K-0110", "Mustafa Ali", "DS", 3.10),
        Student("23K-0111", "Sara Khan", "SE", 3.65),
        Student("23K-0112", "Omar Farooq", "CS", 3.95),
        Student("23K-0113", "Mariam Tariq", "AI", 3.35),
        Student("23K-0114", "Ahmed Raza", "DS", 4.00),
        Student("23K-0115", "Danish Iqbal", "CS", 3.55),
        Student("23K-0116", "Hiba Malik", "SE", 3.88),
        Student("23K-0117", "Zubair Shah", "AI", 2.95),
        Student("23K-0118", "Khadija Bibi", "CS", 3.70),
        Student("23K-0119", "Taha Siddiqui", "DS", 3.50),
        Student("23K-0120", "Anas Javed", "SE", 3.40),
        Student("23K-0121", "Noman Bashir", "CS", 3.60),
        Student("23K-0122", "Yusra Nadeem", "AI", 3.82),
        Student("23K-0123", "Fahad Mustafa", "DS", 3.15),
        Student("23K-0124", "Sana Sheikh", "SE", 3.78),
        Student("23K-0125", "Haris Mehmood", "CS", 3.65),
        Student("23K-0126", "Laiba Arshad", "AI", 3.25),
        Student("23K-0127", "Asad Ullah", "DS", 3.52),
        Student("23K-0128", "Maham Zahra", "CS", 3.91),
        Student("23K-0129", "Waqas Akram", "SE", 2.85),
        Student("23K-0130", "Zeeshan Qureshi", "AI", 3.70)
    };

    merge_sort(students, 0, total_students - 1);
    assign_awards(students, total_students);
    display_merit_list(students, total_students);

    return 0;
}