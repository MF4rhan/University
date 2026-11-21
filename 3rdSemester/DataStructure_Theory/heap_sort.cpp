#include <iostream>
#include <string>

using namespace std;

// Helper function to swap two values without extra libraries
void swapValues(int &first_val, int &second_val)
{
    int temp_val = first_val;
    first_val = second_val;
    second_val = temp_val;
}

// 1. HEAPIFY (Top-Down): Fixes a subtree rooted at index 'i'
// Time Complexity: O(log n)
void heapify(int heap_arr[], int heap_size, int root_idx)
{
    int target_idx = root_idx;          // Tracks largest (for Max-Heap)
    int left_child = 2 * root_idx;
    int right_child = 2 * root_idx + 1;

    // Check if left child exists and is greater than current target
    // [MIN-HEAP CHANGE 1]: Change '>' to '<'
    if (left_child <= heap_size && heap_arr[left_child] > heap_arr[target_idx])
    {
        target_idx = left_child;
    }

    // Check if right child exists and is greater than current target
    // [MIN-HEAP CHANGE 2]: Change '>' to '<'
    if (right_child <= heap_size && heap_arr[right_child] > heap_arr[target_idx])
    {
        target_idx = right_child;
    }

    // If a child was larger, swap and keep pushing down
    if (target_idx != root_idx)
    {
        swapValues(heap_arr[root_idx], heap_arr[target_idx]);
        heapify(heap_arr, heap_size, target_idx);
    }
}

// 2. INSERTION (Bottom-Up): Adds an element at the end and bubbles it up
// Time Complexity: O(log n)
void insertNode(int heap_arr[], int &heap_size, int new_val)
{
    heap_size = heap_size + 1;
    int current_idx = heap_size;
    heap_arr[current_idx] = new_val;

    // Bubble up until reaching root (index 1) or heap property is satisfied
    while (current_idx > 1)
    {
        int parent_idx = current_idx / 2;

        // [MIN-HEAP CHANGE 3]: Change '>' to '<'
        if (heap_arr[current_idx] > heap_arr[parent_idx])
        {
            swapValues(heap_arr[current_idx], heap_arr[parent_idx]);
            current_idx = parent_idx;
        }
        else
        {
            break;
        }
    }
}

// 3. DELETION: Always deletes the root (index 1)
// Time Complexity: O(log n)
void deleteRoot(int heap_arr[], int &heap_size)
{
    if (heap_size == 0)
    {
        cout << "Heap is empty." << endl;
        return;
    }

    // Move the last element to the root and shrink heap size
    heap_arr[1] = heap_arr[heap_size];
    heap_size = heap_size - 1;

    // Push the new root down to its proper position
    heapify(heap_arr, heap_size, 1);
}

// 4. BUILD HEAP: Converts an unsorted array into a heap
// Time Complexity: O(n)
void buildHeap(int heap_arr[], int heap_size)
{
    // Leaf nodes (from heap_size/2 + 1 to heap_size) are already valid heaps.
    // Start from the last non-leaf node and move up to root.
    for (int i = heap_size / 2; i >= 1; i--)
    {
        heapify(heap_arr, heap_size, i);
    }
}

// 5. HEAP SORT: Sorts the array in-place
// Time Complexity: O(n log n)
void heapSort(int heap_arr[], int heap_size)
{
    // Step 1: Turn array into a valid heap
    buildHeap(heap_arr, heap_size);

    // Step 2: Repeatedly swap root (max/min) with the last element and shrink heap
    for (int last_idx = heap_size; last_idx >= 2; last_idx--)
    {
        swapValues(heap_arr[1], heap_arr[last_idx]);
        
        // Heapify reduced heap (size is now last_idx - 1)
        heapify(heap_arr, last_idx - 1, 1);
    }
}

void printArray(int heap_arr[], int heap_size, string label_text)
{
    cout << label_text << ": ";
    for (int i = 1; i <= heap_size; i++)
    {
        cout << heap_arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    // Index 0 is ignored (-1) to keep 1-based indexing
    int heap_arr[100] = {-1};
    int heap_size = 0;

    // --- Test Insertion ---
    insertNode(heap_arr, heap_size, 50);
    insertNode(heap_arr, heap_size, 30);
    insertNode(heap_arr, heap_size, 40);
    insertNode(heap_arr, heap_size, 10);
    insertNode(heap_arr, heap_size, 5);
    insertNode(heap_arr, heap_size, 20);
    insertNode(heap_arr, heap_size, 60);
    printArray(heap_arr, heap_size, "After Insertions (Max-Heap)");

    // --- Test Deletion ---
    deleteRoot(heap_arr, heap_size);
    printArray(heap_arr, heap_size, "After Deleting Root");

    // --- Test Build Heap & Heap Sort on a fresh array ---
    int raw_arr[100] = {-1, 15, 5, 20, 1, 17, 10, 30};
    int raw_size = 7;

    printArray(raw_arr, raw_size, "\nOriginal Unsorted Array");

    buildHeap(raw_arr, raw_size);
    printArray(raw_arr, raw_size, "After Build Heap");

    heapSort(raw_arr, raw_size);
    printArray(raw_arr, raw_size, "After Heap Sort");

    return 0;
}