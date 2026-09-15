#include <iostream>
#include <string>
using namespace std;

class product
{
    public:
    int id;
    string name;
    string category;
    int price;
    product* next;

    product(int pid = 0, string namae = "N/A", string cat = "N/A", int pri = 0)
    : id(pid), name(namae), category(cat), price(pri), next(nullptr) {}
};

class company
{
    private:
    product* head;

    public:
    company() : head(nullptr) {};

    void insert_sorted(int pid, string namae, string cat, int pri)
    {
        product* new_product = new product(pid, namae, cat, pri);
        if (head == nullptr)
        {
            head = new_product;
            return;
        }
        if (head->id > pid)
        {
            new_product->next = head;
            head = new_product;
            return;
        }

        product* checker = head;
        while (checker->next != nullptr && checker->next->id < pid)
        {
            checker = checker->next;
        }
        new_product->next = checker->next;
        checker->next = new_product;  
    }

    company* merge(company& prod1, company& prod2)
{
    if (prod1.head == nullptr)
    {
        company* master_list = new company;
        master_list->head = prod2.head;
        prod2.head = nullptr;
        return master_list;
    }
    if (prod2.head == nullptr)
    {
        company* master_list = new company;
        master_list->head = prod1.head;
        prod1.head = nullptr;
        return master_list;
    }

    company* master_list = new company;

    product dummy;
    product* tail = &dummy;
    product* list1 = prod1.head;
    product* list2 = prod2.head;

    while (list1 != nullptr && list2 != nullptr)
    {
        if (list1->id < list2->id)
        {
            tail->next = list1;
            tail = tail->next;
            list1 = list1->next;
        }
        else if (list2->id < list1->id)
        {
            tail->next = list2;
            tail = tail->next;
            list2 = list2->next;
        }
        else if (list1->price <= list2->price)
        {
            tail->next = list1;
            tail = tail->next;
            list1 = list1->next;

            product* to_delete = list2;
            list2 = list2->next;
            delete to_delete;
        }
        else
        {
            tail->next = list2;
            tail = tail->next;
            list2 = list2->next;

            product* to_delete = list1;
            list1 = list1->next;
            delete to_delete;
        }
    }

    if (list1 != nullptr)
    {
        tail->next = list1;
    }
    else if (list2 != nullptr)
    {
        tail->next = list2;
    }

    master_list->head = dummy.next;

    prod1.head = nullptr;
    prod2.head = nullptr;
    return master_list;
}

    void display_masterlist_count_value()
    {
        if (head == nullptr)
        {
            cout << "\nThe list is empty.\n";
            return;
        }
        
        product* prod = head;
        int counter = 0;
        int totalprice = 0;

        while (prod != nullptr)
        {
            counter++;
            cout << "\nItem #" << counter << ": " << "    ID: " << prod->id << "  Name: " << prod->name << "  Price: " << prod->price;
            totalprice += prod->price;
            prod = prod->next;
        }
        
        cout << "\nTotal Number of Products in the Inventory: " << counter;
        cout << "\nTotal Valuatoin of all products: " << totalprice << "\n"; 
    }

};


int main()
{
    company glowcare;
    company beautyhub;

    //GlowCare
    glowcare.insert_sorted(103, "Face Wash", "Cleanser", 500);
    glowcare.insert_sorted(101, "Moisturizer", "Cream", 800);
    glowcare.insert_sorted(105, "Sunscreen", "Cream", 650);   // duplicate ID with beautyHub, different price

    //BeautyHub
    beautyhub.insert_sorted(102, "Lip Balm", "Lips", 200);
    beautyhub.insert_sorted(105, "Sunscreen", "Cream", 700);  // duplicate ID, higher price than glowCare
    beautyhub.insert_sorted(104, "Toner", "Skin", 450);

    cout << "GlowCare Branch List: ";
    glowcare.display_masterlist_count_value();

    cout << "\nBeautyHub Branch List: ";
    beautyhub.display_masterlist_count_value();

    company* master_list = glowcare.merge(glowcare, beautyhub);

    cout << "\nMerged Master List: ";
    master_list->display_masterlist_count_value();

    delete master_list;

    return 0;
}