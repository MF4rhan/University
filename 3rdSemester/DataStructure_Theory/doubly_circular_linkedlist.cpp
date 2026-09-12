#include <iostream>
using namespace std;

class node
{
    private:
    int value;
    node* next;
    node* previous;

    public:
    node(int val = 0) : value(val), next (nullptr), previous(nullptr)
    {}

    void set_value(int val)
    {
        value = val;
    }

    void set_next(node* ptr)
    {
        next = ptr;
    }

    void set_previous(node* ptr)
    {
        previous = ptr;
    }

    int get_value() const
    {
        return value;
    }

    node* get_next() const
    {
        return next;
    }

    node* get_previous() const
    {
        return previous;
    }

    friend class linked_list;
};

class linked_list
{
    private:
    node* head;

    public:
    linked_list() : head(nullptr)
    {}
    ~linked_list()
    {
        if (head == nullptr)
        {
            return;
        }
        node* to_delete = head->next;
        while (to_delete != head) //checky
        {
            node* next_node = to_delete->next;
            delete to_delete;
            to_delete = next_node;
        }
        delete head;
        head = nullptr;
    }

    /*
    The Methods are in order:
    insertion:
    1. insertnode_attail(int val), does work of insertnode(int val) too. 
    2. insertnode_fromhead (int val) 
    3. insertnode_atindex (int val, int index) 

    deleting:
    1. deletenode_attail(); 
    2. deletenode_fromhead(); 
    3. deletenode_atindex(); 
    4. deletenode_byvalue(); 

    searching:
    1. searchnode_byvalue(int val); 
    2. searchnode_byindex(int index); 

    updating:
    1. updatenode_byvalue(int val);
    2. updatenode_atindex(int val, int index);

    printing:
    1. print_list();
    */

    //Insertion:
    void insert_node_at_tail(int val)
    {
        if (head == nullptr) //if the head is empty, add a node directly.
        {
            head = new node(val);
            head->next = head;
            head->previous = head;
        }
        else
        {
            //if there is only 1 node or more, this will handle it.
            //it checks the next of each node one after another.
            node* temp = head; 
            while (temp->next != head)
            {
                temp = temp->next;
            } 
            temp->next = new node(val);
            temp->next->previous = temp;
            temp->next->next = head;
            head->previous = temp->next;
        }
    }

    void insert_node_at_head(int val)
    {
        node* new_node = new node(val);
        if (head == nullptr)
        {
            head = new_node;
            head->next = head;
            head->previous = head;
            return;
        }
        node* tail = get_tail();
        new_node->next = head;
        head->previous = new_node;
        head = new_node;
        tail->next = head;
        head->previous = tail;

    }

    void insert_node_at_index(int val, int index)
    {
        if (index == 0) //if we enter index 0
        {
            //notice how we don't check if head == nullptr?
            //because even if the head is nullptr, it would immediately break the loop below anyway.
            insert_node_at_head(val);
            return;
        }
        
        int counter = 0;
        node* temp = head;
        
        //first, move to the required position which is index-1 where we will insert our new node.
        while (counter < index - 1) 
        {
            //index - 1, otherwise we would end up at the exact index we want to add (by the line running below), rather than the index before it.
            //and temp!= nullptr, because:
            //1. It acts as a 2nd condition for loop besides counter.
            //2. temp->next != nullptr on above loop and on below safety check would introduce a new bug: you cannot place a new node at the end.
            //even though its a valid index, you can't insert at the end if we do temp->next != nullptr.
            //because it would print invalid, even though its a valid position for us to insert a node.
            temp = temp->next;
            counter++;
            if (temp == head)
            {
                cout << "Invalid Index." << endl;
                return;
            }
        }
        
        if (temp->next == head)
        {
            insert_node_at_tail(val);
            return;
        }
        

        node* new_node = new node(val);
        new_node->next = temp->next;
        temp->next->previous = new_node;
        new_node->previous = temp;
        temp->next = new_node;
    }

    //Deletion:
    void delete_at_tail()
    {
        if (head == nullptr) //if head is empty, do nothing
        {
            return;
        }
        else if (head->next == head) 
        {
            //since we are checking temp->next->next in our loop, that leaves head->next unchecked.
            //hence we handle it separately.
            delete head;
            head = nullptr;
            return;
        }
        
        node* temp = head;
        while (temp->next->next != head)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = head;
        head->previous = temp;
    }

    void delete_at_head()
    {
        if (head == nullptr)
        {
            return;
        }
        if (head->next == head)
        {
            delete head;
            head = nullptr;
            return;
        }

        node* temp = head->next;
        node* tail = get_tail();
        delete head;
        head = temp;
        head->previous = tail;
        tail->next = head;
    }

    void delete_at_value(int val)
    {
        if (head == nullptr)
        {
            return;
        }
        if (head->value == val)
        {
            delete_at_head();
            return;
        }

        node* temp = head;
        while (temp->next != head && temp->next->value != val )
        {
            temp = temp->next;
        }
        if (temp->next == head)
        {
            cout << "Value does not exist in the list." << endl;
            return;
        }

        node* to_delete = temp->next;
        to_delete->next->previous = temp;
        temp->next = to_delete->next;
        delete to_delete;
    }

    void delete_at_index(int index)
    {
        if (index == 0) //notice how we don't check if head == nullptr like by value? 
        //  because even if the head is nullptr, it would immediately break the loop below anyway.
        {
            delete_at_head();
            return;
        }

        int counter = 0;
        node* temp = head; //keep counter and temp synced at same index.
        node* tail = get_tail();
        while (counter < index - 1) 
        {
            counter++;
            temp = temp->next;
            if (temp == head) //checking if we reached the head early or not
            {
                cout << "Invalid Index." << endl;
                return;
            }
        }
 
        node* to_delete = temp->next;
        if (to_delete == head) //checking if the head->next is also a head or not (because the above loop didn't run with just a single node)
        {
            cout << "Invalid index.\n";
            return;
        }
        
        to_delete->next->previous = temp;
        temp->next = to_delete->next;
        delete to_delete;
    }

    //Searching: (will be used for updating section later)
    node* search_node_by_value(int val)
    {
        if (head == nullptr)
        {
            return nullptr;
        }
        if (head->value == val)
        {
            return head;
        }

        node* to_find = head;
        while (to_find->value != val)
        {
            //in searching, we don't need the preceding node.
            //we only need to stop at the preceding node if we are making changes to the structure of the linked list.
            //in searching? we can just read each node one by one and return the node when we find it, simple.
            to_find = to_find->next;
            if (to_find == head)
            {
                cout << "The value does not exist in any node." << endl;
                return nullptr;
            }
        }

        return to_find;
    }

    node* search_node_by_index(int index)
    {
        if (index == 0)
        {
            return head;
        }

        int counter = 0;
        node* to_find = head;

        while (counter < index) //since we don't need the preceding node, we can let it run till full index.
        {
            to_find = to_find->next;
            counter++;
            if (to_find == head)
            {
                cout << "Invalid index." << endl;
                return nullptr;
            }
        }

        return to_find;
    }

    void update_node_by_value(int val)
    {
        node* to_update = search_node_by_value(val);
        if (to_update == nullptr)
        {
            return; //printing invalid statemetn is done by the search function.
        }
        cout << "Enter the new value: ";
        int new_val;
        cin >> new_val;
        to_update->value = new_val;

        cout << "Node value updated." << endl;
    }

    void update_node_by_index(int val, int index)
    {
        node* to_update = search_node_by_index(index);
        if (to_update == nullptr)
        {
            return;
        }

        to_update->value = val;
        cout << "Node value Updated." << endl;
    }

    void print_list()
    {
        if (head == nullptr)
        {
            cout << "List is empty." << endl;
            return;
        }
        cout << head->value << " -> ";
        node* to_print = head->next;
        while (to_print != head)
        {
            cout << to_print->value << " -> ";
            to_print = to_print->next;
        }
        cout << "head" << endl;
    }

    //here the conditions are changed to look for the head instead of nullptr since this is circular.
    node* get_tail()
    {
        if (head == nullptr)
        {
            cout << "The list is empty.\n";
            return nullptr;
        }
        
        node* checker = head;
        while (checker->next != head)
        {
            checker = checker->next;
        }
        return checker;
    }

    node* get_head()
    {
        if (head == nullptr)
        {
            cout << "The list is empty.\n";
            return nullptr;
        }
        return head;
    }
};



int main()
{
    linked_list list1;
 
   list1.insert_node_at_tail(10);
   list1.insert_node_at_head(20);
   list1.insert_node_at_index(100,2);
   list1.insert_node_at_tail(69);

   cout << "List after Insertions: " << endl;
   list1.print_list();

   list1.update_node_by_value(10);
   list1.update_node_by_index(67, 2);

   cout << "List after Updating: " << endl;
   list1.print_list();

   list1.delete_at_head();
   list1.delete_at_value(69);
   list1.delete_at_index(1);
   list1.delete_at_tail();

   cout << "List after Deleting: " << endl;
   list1.print_list();

    return 0;
}

/*
    Value-Based (Blind Searching): 
    You do not know where the target is, so you must constantly look one step ahead to check the value (temp->next->value != val). 
    Because you are checking the data of the next node,
    you are forced to also check if the next node actually exists (temp->next != nullptr) to prevent a segmentation fault.
    Both conditions must look forward together.

    Index-Based (Deterministic Counting):
    You know exactly how many steps to take.
    The counter < index - 1 condition handles 100% of the targeting. 
    Because the counter stops the loop, the pointer condition (temp != nullptr) is 
    stripped of its targeting duties and acts purely as an out-of-bounds safety net.

    The Flexibility Advantage: 
    Because index traversal relies on temp != nullptr, it allows the pointer to legally park on the tail node. 
    This makes inserting at the end of the list a valid operation. 
    If a specific function requires a node to exist after that stopping point (like deletion), 
    you apply the temp->next == nullptr restriction independently outside the loop.


    Common Edge cases to look out for in singly linked list:

    Structural States

    Empty List (head == nullptr): 
        Any attempt to read head->value or head->next results in an instant segmentation fault.
        Must be the first check in every function.

    Single Node List (head->next == nullptr): 
        Deleting the tail in a single-node list requires updating head directly. 
        Standard temp->next->next traversal will crash.

    Target at Head (Index 0 / head->value): 
        Inserting or deleting at the head requires updating the global head pointer itself,
        bypassing standard while loop traversal entirely.

Traversal and Boundaries

    Severe Out-of-Bounds (temp == nullptr): 
        Occurs when requesting an index far beyond the list size. 
        The pointer walks completely off the list. Attempting to read temp->next here causes a crash.

    Mild Out-of-Bounds (temp->next == nullptr): 
        The pointer successfully stops on the exact last node. 
        This is a valid state for appending a node, but an error state for deletion, 
        as there is no subsequent node to destroy.

    Target at Tail: 
        Searching for a value located at the very end of the list. 
        If loop conditions improperly check temp->next != nullptr for searches, 
        the tail node's data is ignored.

    Value Not Found: 
        The pointer reaches the end of the list (nullptr) without triggering a match. 
        Functions must handle returning or exiting safely without executing structure-modifying code.

Memory Management

    Destructor Sequencing: 
        Calling delete to_delete; before saving to_delete->next. 
        This instantly frees the memory, making the next pointer inaccessible 
        and leaving the rest of the list permanently orphaned in the heap.

    Local Variable Assignment: 
        Writing temp = new_node instead of temp->next = new_node. 
        This merely updates a temporary local variable, 
        failing to physically link the node into the heap structure, 
        resulting in an immediate memory leak.
*/
