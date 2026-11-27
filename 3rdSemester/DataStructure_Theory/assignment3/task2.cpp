#include <iostream>
#include <string>

using namespace std;

class laptopNode
{
public:
    string model;
    int highest_selling_price;
    int lowest_purchase_price;
    int height;
    laptopNode* left;
    laptopNode* right;

    laptopNode(string m, int sell_price, int buy_price)
        : model(m), highest_selling_price(sell_price), lowest_purchase_price(buy_price), height(1), left(nullptr), right(nullptr)
    {
    }
};

class laptopAvlTree
{
private:
    laptopNode* root;
    int total_records;

    int getHeight(laptopNode* node)
    {
        if (node == nullptr)
        {
            return 0;
        }
        return node->height;
    }

    int getMax(int a, int b)
    {
        return (a > b) ? a : b;
    }

    int getBalanceFactor(laptopNode* node)
    {
        if (node == nullptr)
        {
            return 0;
        }
        return getHeight(node->left) - getHeight(node->right);
    }

    void updateHeight(laptopNode* node)
    {
        if (node != nullptr)
        {
            node->height = 1 + getMax(getHeight(node->left), getHeight(node->right));
        }
    }

    laptopNode* rotateRight(laptopNode* y)
    {
        laptopNode* x = y->left;
        laptopNode* t2 = x->right;

        x->right = y;
        y->left = t2;

        updateHeight(y);
        updateHeight(x);

        return x;
    }

    laptopNode* rotateLeft(laptopNode* x)
    {
        laptopNode* y = x->right;
        laptopNode* t2 = y->left;

        y->left = x;
        x->right = t2;

        updateHeight(x);
        updateHeight(y);

        return y;
    }

    int compareRecords(string m1, int p1, string m2, int p2)
    {
        if (p1 < p2)
        {
            return -1;
        }
        if (p1 > p2)
        {
            return 1;
        }
        if (m1 < m2)
        {
            return -1;
        }
        if (m1 > m2)
        {
            return 1;
        }
        return 0;
    }

    laptopNode* rebalanceNode(laptopNode* node, bool print_rotation)
    {
        updateHeight(node);
        int balance = getBalanceFactor(node);

        if (balance > 1 && getBalanceFactor(node->left) >= 0)
        {
            if (print_rotation)
            {
                cout << "Rotation: LL" << endl;
            }
            return rotateRight(node);
        }

        if (balance > 1 && getBalanceFactor(node->left) < 0)
        {
            if (print_rotation)
            {
                cout << "Rotation: LR" << endl;
            }
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }

        if (balance < -1 && getBalanceFactor(node->right) <= 0)
        {
            if (print_rotation)
            {
                cout << "Rotation: RR" << endl;
            }
            return rotateLeft(node);
        }

        if (balance < -1 && getBalanceFactor(node->right) > 0)
        {
            if (print_rotation)
            {
                cout << "Rotation: RL" << endl;
            }
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }

        return node;
    }

    laptopNode* insertNode(laptopNode* node, string model, int sell_price, int buy_price, bool& inserted)
    {
        if (node == nullptr)
        {
            inserted = true;
            return new laptopNode(model, sell_price, buy_price);
        }

        int cmp = compareRecords(model, sell_price, node->model, node->highest_selling_price);

        if (cmp == 0)
        {
            cout << "Rejected: Duplicate model and selling price for " << model << endl;
            inserted = false;
            return node;
        }
        else if (cmp < 0)
        {
            node->left = insertNode(node->left, model, sell_price, buy_price, inserted);
        }
        else
        {
            node->right = insertNode(node->right, model, sell_price, buy_price, inserted);
        }

        if (!inserted)
        {
            return node;
        }

        return rebalanceNode(node, true);
    }

    laptopNode* getMinValueNode(laptopNode* node)
    {
        laptopNode* current = node;
        while (current->left != nullptr)
        {
            current = current->left;
        }
        return current;
    }

    bool findModelByPrice(laptopNode* node, int target_price, string& found_model)
    {
        if (node == nullptr)
        {
            return false;
        }

        if (target_price == node->highest_selling_price)
        {
            found_model = node->model;
            return true;
        }
        else if (target_price < node->highest_selling_price)
        {
            return findModelByPrice(node->left, target_price, found_model);
        }
        else
        {
            return findModelByPrice(node->right, target_price, found_model);
        }
    }

    laptopNode* deleteNode(laptopNode* node, int target_price, string target_model)
    {
        if (node == nullptr)
        {
            return nullptr;
        }

        int cmp = compareRecords(target_model, target_price, node->model, node->highest_selling_price);

        if (cmp < 0)
        {
            node->left = deleteNode(node->left, target_price, target_model);
        }
        else if (cmp > 0)
        {
            node->right = deleteNode(node->right, target_price, target_model);
        }
        else
        {
            if (node->left == nullptr || node->right == nullptr)
            {
                laptopNode* temp = (node->left != nullptr) ? node->left : node->right;
                delete node;
                return temp;
            }
            else
            {
                laptopNode* successor = getMinValueNode(node->right);
                node->model = successor->model;
                node->highest_selling_price = successor->highest_selling_price;
                node->lowest_purchase_price = successor->lowest_purchase_price;
                node->right = deleteNode(node->right, successor->highest_selling_price, successor->model);
            }
        }

        return rebalanceNode(node, true);
    }

    void rangeSearchHelper(laptopNode* node, int low, int high, bool& found_any)
    {
        if (node == nullptr)
        {
            return;
        }

        if (node->highest_selling_price >= low)
        {
            rangeSearchHelper(node->left, low, high, found_any);
        }

        if (node->highest_selling_price >= low && node->highest_selling_price <= high)
        {
            cout << "Model: " << node->model
                 << ", Selling Price: " << node->highest_selling_price
                 << ", Purchase Price: " << node->lowest_purchase_price << endl;
            found_any = true;
        }

        if (node->highest_selling_price <= high)
        {
            rangeSearchHelper(node->right, low, high, found_any);
        }
    }

    void inOrderDisplay(laptopNode* node)
    {
        if (node == nullptr)
        {
            return;
        }

        inOrderDisplay(node->left);
        cout << "Model: " << node->model
             << ", Selling Price: " << node->highest_selling_price
             << ", Purchase Price: " << node->lowest_purchase_price
             << ", Height: " << node->height
             << ", Balance Factor: " << getBalanceFactor(node) << endl;
        inOrderDisplay(node->right);
    }

public:
    laptopAvlTree() : root(nullptr), total_records(0)
    {
    }

    void insertLaptop(string model, int sell_price, int buy_price)
    {
        if (buy_price > sell_price)
        {
            cout << "Rejected: Purchase price greater than selling price for " << model << endl;
            return;
        }

        bool inserted = false;
        root = insertNode(root, model, sell_price, buy_price, inserted);

        if (inserted)
        {
            total_records++;
            cout << "Inserted: " << model << ", Selling: " << sell_price << ", Purchase: " << buy_price << endl;
        }
    }

    void deleteBySellingPrice(int sell_price)
    {
        int deleted_count = 0;
        string found_model = "";

        while (findModelByPrice(root, sell_price, found_model))
        {
            root = deleteNode(root, sell_price, found_model);
            deleted_count++;
            total_records--;
        }

        if (deleted_count == 0)
        {
            cout << "Deletion for " << sell_price << ": not found" << endl;
        }
        else
        {
            cout << "Deletion for " << sell_price << ": Deleted " << deleted_count << " record(s)" << endl;
        }
    }

    void rangeSearch(int low, int high)
    {
        if (low > high)
        {
            int temp = low;
            low = high;
            high = temp;
        }

        cout << "\nRange Search " << low << " to " << high << ":" << endl;
        bool found_any = false;
        rangeSearchHelper(root, low, high, found_any);

        if (!found_any)
        {
            cout << "No laptops found" << endl;
        }
    }

    void display()
    {
        cout << "\nAVL Tree In-Order Listing:" << endl;
        if (root == nullptr)
        {
            cout << "Tree is empty" << endl;
        }
        else
        {
            inOrderDisplay(root);
        }
        cout << "Total Records: " << total_records << endl;
        cout << "Overall Tree Height: " << getHeight(root) << endl;
    }
};

int main()
{
    laptopAvlTree store;

    store.insertLaptop("Dell XPS", 100000, 80000);
    store.insertLaptop("HP Pavilion", 80000, 65000);
    store.insertLaptop("Lenovo IdeaPad", 60000, 50000);
    store.insertLaptop("Asus TUF", 120000, 95000);
    store.insertLaptop("Acer Nitro", 140000, 110000);
    store.insertLaptop("MSI Katana", 110000, 90000);
    store.insertLaptop("MacBook Air", 70000, 55000);
    store.insertLaptop("HP Victus", 110000, 88000);
    store.insertLaptop("Asus ROG", 110000, 92000);
    store.insertLaptop("Dell Inspiron", 50000, 40000);
    store.insertLaptop("Lenovo ThinkPad", 150000, 125000);
    store.insertLaptop("Acer Predator", 90000, 75000);

    cout << "\nTesting Rejected Insertions:" << endl;
    store.insertLaptop("Dell XPS", 100000, 85000);
    store.insertLaptop("Razer Blade", 130000, 145000);

    store.rangeSearch(115000, 75000);

    cout << "\nBefore Deletion:" << endl;
    store.display();

    cout << "\nPerforming Deletions:" << endl;
    store.deleteBySellingPrice(110000);

    cout << "\nAfter Deleting 110000:" << endl;
    store.display();

    cout << "\nPerforming Non-Existent Deletion:" << endl;
    store.deleteBySellingPrice(999999);

    cout << "\nAfter Non-Existent Deletion:" << endl;
    store.display();

    return 0;
}