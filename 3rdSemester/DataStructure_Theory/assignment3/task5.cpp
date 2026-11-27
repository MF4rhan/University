#include <iostream>
#include <string>

using namespace std;

class courseInfo
{
public:
    int id;
    int credits;
    string type;

    courseInfo() : id(0), credits(0), type("Elective")
    {
    }
};

class degreePlanner
{
private:
    int n;
    int target_credits;
    int max_sem_credits;
    courseInfo courses[15];
    int adj[15][15];

    int memo_sem[4096];
    int next_sem_mask[4096];

    unsigned int rand_seed;

    int getNextRand()
    {
        rand_seed = (rand_seed * 1103515245 + 12345) & 0x7fffffff;
        return (int)(rand_seed >> 16);
    }

    int findMinSemesters(int done_mask, int target_mask)
    {
        if (done_mask == target_mask)
        {
            return 0;
        }

        if (memo_sem[done_mask] != -1)
        {
            return memo_sem[done_mask];
        }

        int available[15];
        int avail_count = 0;

        for (int i = 0; i < n; i++)
        {
            if ((target_mask & (1 << i)) && !(done_mask & (1 << i)))
            {
                bool prereqs_met = true;
                for (int p = 0; p < n; p++)
                {
                    if (adj[p][i] == 1 && !(done_mask & (1 << p)))
                    {
                        prereqs_met = false;
                        break;
                    }
                }
                if (prereqs_met)
                {
                    available[avail_count] = i;
                    avail_count++;
                }
            }
        }

        int best_sem = 1000;
        int best_choice = 0;
        int total_subsets = 1 << avail_count;

        for (int sub = 1; sub < total_subsets; sub++)
        {
            int sem_credits = 0;
            int chosen_mask = 0;

            for (int j = 0; j < avail_count; j++)
            {
                if (sub & (1 << j))
                {
                    int cid = available[j];
                    sem_credits += courses[cid].credits;
                    chosen_mask |= (1 << cid);
                }
            }

            if (sem_credits <= max_sem_credits)
            {
                int rem_sem = findMinSemesters(done_mask | chosen_mask, target_mask);
                if (1 + rem_sem < best_sem)
                {
                    best_sem = 1 + rem_sem;
                    best_choice = chosen_mask;
                }
            }
        }

        memo_sem[done_mask] = best_sem;
        next_sem_mask[done_mask] = best_choice;
        return best_sem;
    }

public:
    degreePlanner(int num_courses, int t_credits, int l_credits)
    {
        n = num_courses;
        target_credits = t_credits;
        max_sem_credits = l_credits;
        int dummy = 0;
        rand_seed = (unsigned int)((long long)&dummy);

        for (int i = 0; i < 15; i++)
        {
            for (int j = 0; j < 15; j++)
            {
                adj[i][j] = 0;
            }
        }
    }

    void setCourse(int id, int credits, string type)
    {
        courses[id].id = id;
        courses[id].credits = credits;
        courses[id].type = type;
    }

    void addPrerequisite(int prereq_id, int course_id)
    {
        if (prereq_id < course_id)
        {
            adj[prereq_id][course_id] = 1;
        }
    }

    void generateRandomGraph()
    {
        for (int i = 0; i < n; i++)
        {
            int credits = (getNextRand() % max_sem_credits) + 1;
            string type = (getNextRand() % 2 == 0) ? "Core" : "Elective";
            setCourse(i, credits, type);
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (getNextRand() % 100 < 30)
                {
                    adj[i][j] = 1;
                }
            }
        }
    }

    int getTotalAvailableCredits()
    {
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += courses[i].credits;
        }
        return sum;
    }

    void displayCourses()
    {
        cout << "Courses:" << endl;
        for (int i = 0; i < n; i++)
        {
            cout << "ID: " << courses[i].id
                 << ", Credits: " << courses[i].credits
                 << ", Type: " << courses[i].type
                 << ", Prerequisites: ";

            bool has_prereq = false;
            for (int p = 0; p < n; p++)
            {
                if (adj[p][i] == 1)
                {
                    if (has_prereq)
                    {
                        cout << ", ";
                    }
                    cout << p;
                    has_prereq = true;
                }
            }
            if (!has_prereq)
            {
                cout << "None";
            }
            cout << endl;
        }
    }

    void generateSemesterPlan()
    {
        int best_mask = -1;
        int best_semesters = 1000;
        int best_excess_credits = 100000;

        int total_masks = 1 << n;

        for (int mask = 1; mask < total_masks; mask++)
        {
            bool valid = true;
            int total_cred = 0;

            for (int i = 0; i < n; i++)
            {
                if (courses[i].type == "Core" && !(mask & (1 << i)))
                {
                    valid = false;
                    break;
                }

                if (mask & (1 << i))
                {
                    total_cred += courses[i].credits;
                    for (int p = 0; p < n; p++)
                    {
                        if (adj[p][i] == 1 && !(mask & (1 << p)))
                        {
                            valid = false;
                            break;
                        }
                    }
                }

                if (!valid)
                {
                    break;
                }
            }

            if (!valid || total_cred < target_credits)
            {
                continue;
            }

            for (int m = 0; m < total_masks; m++)
            {
                memo_sem[m] = -1;
                next_sem_mask[m] = 0;
            }

            int sem_count = findMinSemesters(0, mask);
            int excess = total_cred - target_credits;

            if (sem_count < best_semesters || (sem_count == best_semesters && excess < best_excess_credits))
            {
                best_semesters = sem_count;
                best_excess_credits = excess;
                best_mask = mask;
            }
        }

        if (best_mask == -1)
        {
            cout << "No valid graduation plan found." << endl;
            return;
        }

        for (int m = 0; m < total_masks; m++)
        {
            memo_sem[m] = -1;
            next_sem_mask[m] = 0;
        }
        findMinSemesters(0, best_mask);

        cout << "\nSemester-wise Plan:" << endl;
        int done = 0;
        int sem_num = 1;
        int completed_credits = 0;

        while (done != best_mask)
        {
            int choice = next_sem_mask[done];
            int sem_cred = 0;
            cout << "Semester " << sem_num << ": ";

            bool first = true;
            for (int i = 0; i < n; i++)
            {
                if (choice & (1 << i))
                {
                    if (!first)
                    {
                        cout << ", ";
                    }
                    cout << i;
                    sem_cred += courses[i].credits;
                    first = false;
                }
            }
            cout << " (" << sem_cred << " credits)" << endl;

            completed_credits += sem_cred;
            done |= choice;
            sem_num++;
        }

        cout << "Total credits: " << completed_credits << endl;
        cout << "Credits above T: " << (completed_credits - target_credits) << endl;
    }
};

int main()
{
    cout << "Sample Test Case:" << endl;
    degreePlanner sample_planner(5, 15, 8);
    sample_planner.setCourse(0, 5, "Core");
    sample_planner.setCourse(1, 4, "Core");
    sample_planner.setCourse(2, 4, "Elective");
    sample_planner.setCourse(3, 4, "Core");
    sample_planner.setCourse(4, 2, "Elective");

    sample_planner.addPrerequisite(0, 1);
    sample_planner.addPrerequisite(0, 3);

    sample_planner.displayCourses();
    sample_planner.generateSemesterPlan();

    int n = 0;
    int t = 0;
    int l = 8;

    cout << "\nRandom Graph Test Case:" << endl;
    cout << "Enter number of courses N (N <= 12): ";
    cin >> n;

    if (n < 1 || n > 12)
    {
        cout << "Invalid N. Must be between 1 and 12." << endl;
        return 0;
    }

    degreePlanner random_planner(n, 0, l);
    random_planner.generateRandomGraph();

    int max_possible = random_planner.getTotalAvailableCredits();
    cout << "Enter required credits T (max " << max_possible << "): ";
    cin >> t;

    if (t > max_possible)
    {
        t = max_possible;
    }

    degreePlanner final_planner(n, t, l);
    final_planner = random_planner;

    degreePlanner custom_planner(n, t, l);
    custom_planner.generateRandomGraph();
    while (custom_planner.getTotalAvailableCredits() < t)
    {
        custom_planner.generateRandomGraph();
    }

    custom_planner.displayCourses();
    custom_planner.generateSemesterPlan();

    return 0;
}