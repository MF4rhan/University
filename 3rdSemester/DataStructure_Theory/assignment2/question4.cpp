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

    // restores heap property upward after insertion or key decrease
    void sift_up(int index)
    {
        while (index > 0 && heap_array[parent(index)] > heap_array[index])
        {
            swap_nodes(index, parent(index));
            index = parent(index);
        }
    }

    // restores heap property downward after extract_min
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

    // inserts a new job deadline into the min heap
    void insert(int key)
    {
        if (heap_size == capacity)
        {
            cout << "Heap is full\n";
            return;
        }

        heap_array[heap_size] = key;
        heap_size++;
        sift_up(heap_size - 1);
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
        sift_up(index);
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