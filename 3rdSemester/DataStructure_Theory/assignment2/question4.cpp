#include <iostream>
#include <string>

using namespace std;

class MinHeap
{
private:
    int* heap_array;
    int capacity;
    int heap_size;

    // helper functions to get indices
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

    // helper to swap two elements in the array
    void swap_nodes(int index_one, int index_two)
    {
        int temp = heap_array[index_one];
        heap_array[index_one] = heap_array[index_two];
        heap_array[index_two] = temp;
    }

    // restores heap property upward and prints array after every swap
    void sift_up(int index, int& swap_count)
    {
        while (index > 0 && heap_array[parent(index)] > heap_array[index])
        {
            swap_nodes(index, parent(index));
            swap_count++;
            index = parent(index);
            cout << "swap " << swap_count << ": ";
            print_heap();
        }
    }

    // restores heap property downward and prints array after every swap
    void sift_down(int index)
    {
        int smallest = index;
        int left = left_child(index);
        int right = right_child(index);

        if (left < heap_size && heap_array[left] < heap_array[smallest])
        {
            smallest = left;
        }

        if (right < heap_size && heap_array[right] < heap_array[smallest])
        {
            smallest = right;
        }

        if (smallest != index)
        {
            swap_nodes(index, smallest);
            cout << "after swap: ";
            print_heap();
            sift_down(smallest);
        }
    }

public:
    MinHeap(int max_capacity) : heap_array(new int[max_capacity]), capacity(max_capacity), heap_size(0)
    {
    }

    ~MinHeap()
    {
        delete[] heap_array;
    }

    // loads the given initial array h
    void load_array(int source_array[], int size)
    {
        heap_size = size;
        for (int i = 0; i < size; i++)
        {
            heap_array[i] = source_array[i];
        }
    }

    // inserts a new job deadline into the min heap
    void insert(int key, int& swap_count)
    {
        if (heap_size == capacity)
        {
            cout << "Heap is full\n";
            return;
        }

        heap_array[heap_size] = key;
        heap_size++;
        sift_up(heap_size - 1, swap_count);
    }

    // removes and returns the minimum deadline
    int extract_min()
    {
        if (heap_size <= 0)
        {
            cout << "Heap is empty\n";
            return -1;
        }

        if (heap_size == 1)
        {
            heap_size--;
            return heap_array[0];
        }

        int min_value = heap_array[0];
        heap_array[0] = heap_array[heap_size - 1];
        heap_size--;

        cout << "last element moved to root: ";
        print_heap();

        sift_down(0);

        return min_value;
    }

    // decreases the deadline of a job at a given index
    void decrease_key(int index, int new_value)
    {
        if (index < 0 || index >= heap_size)
        {
            cout << "Invalid index\n";
            return;
        }

        if (new_value > heap_array[index])
        {
            cout << "New value is greater than current value\n";
            return;
        }

        heap_array[index] = new_value;
        int dummy_swaps = 0;
        sift_up(index, dummy_swaps);
    }

    // prints the current array representation
    void print_heap()
    {
        for (int i = 0; i < heap_size; i++)
        {
            cout << heap_array[i] << " ";
        }
        cout << "\n";
    }
};

int main()
{
    MinHeap scheduler(30);

    // initial array h from given data
    int initial_h[] = {5, 11, 8, 14, 17, 9, 12, 20, 16, 19};
    scheduler.load_array(initial_h, 10);

    cout << "initial array h:\n";
    scheduler.print_heap();

    // part b
    cout << "\npart b:\n";
    int total_swaps = 0;
    cout << "inserting 6:\n";
    scheduler.insert(6, total_swaps);
    cout << "inserting 4:\n";
    scheduler.insert(4, total_swaps);
    cout << "total swaps in part b: " << total_swaps << "\n";

    // part c
    cout << "\npart c:\n";
    cout << "first extract min:\n";
    scheduler.extract_min();
    cout << "second extract min:\n";
    scheduler.extract_min();

    // part d
    cout << "\npart d:\n";
    cout << "decreasing key at index 7 from 20 to 3:\n";
    scheduler.decrease_key(7, 3);

    return 0;
}