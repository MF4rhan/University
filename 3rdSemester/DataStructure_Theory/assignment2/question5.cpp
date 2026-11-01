#include <iostream>
#include <string>

using namespace std;

struct Job
{
    string name;
    int priority;
    int arrival_order;

    Job() : name(""), priority(0), arrival_order(0)
    {
    }

    Job(string job_name, int job_priority, int job_order) : name(job_name), priority(job_priority), arrival_order(job_order)
    {
    }
};

class PriorityQueue
{
private:
    Job* heap_array;
    int capacity;
    int heap_size;
    int arrival_counter;

    //helper functions to get tree indices
    int parent(int index)
    {
        return (index - 1) / 2;
    }

    int left_child(int index)
    {
        return (2 * index) + 1;
    }

    int right_child(int index)
    {
        return (2 * index) + 2;
    }

    //return true if job at first index has higher priority than job at second index
    bool has_higher_priority(int first_index, int second_index)
    {
        if (heap_array[first_index].priority < heap_array[second_index].priority)
        {
            return true;
        }
        if (heap_array[first_index].priority == heap_array[second_index].priority)
        {
            return heap_array[first_index].arrival_order < heap_array[second_index].arrival_order;
        }
        return false;
    }

    //swap two jobs in the array
    void swap_jobs(int first_index, int second_index)
    {
        Job temp = heap_array[first_index];
        heap_array[first_index] = heap_array[second_index];
        heap_array[second_index] = temp;
    }

    //moves a job up to restore heap order
    void sift_up(int index)
    {
        while (index > 0 && has_higher_priority(index, parent(index)))
        {
            swap_jobs(index, parent(index));
            index = parent(index);
        }
    }

    //moves a job down to restore heap order
    void sift_down(int index)
    {
        int highest = index;
        int left = left_child(index);
        int right = right_child(index);

        if (left < heap_size && has_higher_priority(left, highest))
        {
            highest = left;
        }

        if (right < heap_size && has_higher_priority(right, highest))
        {
            highest = right;
        }

        if (highest != index)
        {
            swap_jobs(index, highest);
            sift_down(highest);
        }
    }

public:
    PriorityQueue(int max_capacity) : heap_array(new Job[max_capacity]), capacity(max_capacity), heap_size(0), arrival_counter(0)
    {
    }

    ~PriorityQueue()
    {
        delete[] heap_array;
    }

    //pushes a new job into the priority queue
    void push(string job_name, int priority)
    {
        if (heap_size == capacity)
        {
            cout << "queue is full\n";
            return;
        }

        arrival_counter++;
        heap_array[heap_size] = Job(job_name, priority, arrival_counter);
        heap_size++;
        sift_up(heap_size - 1);
    }

    //removes and returns the highest priority job
    string pop()
    {
        if (heap_size <= 0)
        {
            cout << "queue is empty\n";
            return "";
        }

        string top_job = heap_array[0].name;
        heap_array[0] = heap_array[heap_size - 1];
        heap_size--;
        sift_down(0);

        return top_job;
    }

    //returns the highest priority job without removing it
    string peek()
    {
        if (heap_size <= 0)
        {
            cout << "queue is empty\n";
            return "";
        }

        return heap_array[0].name;
    }
};

int main()
{
    PriorityQueue print_server(20);

    //priorities from the given data: j1(3), j2(1), j3(2), j4(1), j5(3), j6(2)
    int p_j1 = 3;
    int p_j2 = 1;
    int p_j3 = 2;
    int p_j4 = 1;
    int p_j5 = 3;
    int p_j6 = 2;

    //step 1 to 3
    print_server.push("J1", p_j1);
    print_server.push("J2", p_j2);
    print_server.push("J3", p_j3);

    //step 4
    cout << "step 4 pop: " << print_server.pop() << "\n";

    //step 5 to 6
    print_server.push("J4", p_j4);
    print_server.push("J5", p_j5);

    //step 7 to 8
    cout << "step 7 pop: " << print_server.pop() << "\n";
    cout << "step 8 pop: " << print_server.pop() << "\n";

    //step 9
    print_server.push("J6", p_j6);

    //step 10 to 12
    cout << "step 10 pop: " << print_server.pop() << "\n";
    cout << "step 11 pop: " << print_server.pop() << "\n";
    cout << "step 12 pop: " << print_server.pop() << "\n";

    return 0;
}