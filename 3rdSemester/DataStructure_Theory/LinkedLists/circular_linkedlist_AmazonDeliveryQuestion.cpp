class Node
{
public:
    Node* next;
    int val;
    bool at_home;

    Node(int vala = 0, bool hom = true) : val(vala), next(nullptr), at_home(hom) {}
};

class circularList
{
    Node* head;

    circularList() : head(nullptr) {}

    void deliever()
    {
        //assume first node is the warehouse
        Node* temp = head;
        Node* last_not_home = nullptr;

        while (temp->next != last_not_home)
        {
            if (temp->next == head && last_not_home == nullptr) //this is the new condition added
            {
                break; 
            }
            if (temp->next->at_home)
            {
                Node* addr = temp->next;
                temp->next = addr->next;
                delete addr;
                addr = nullptr;
            }
            else 
            {
                if (last_not_home == nullptr)
                last_not_home = temp->next;
            
                else if (temp->next == head)
                temp->next = last_not_home; 

                temp = temp->next;
            } // end of function
        }
    }
};