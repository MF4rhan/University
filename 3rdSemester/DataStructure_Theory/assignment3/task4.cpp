#include <iostream>
#include <string>

using namespace std;

class priorityNode
{
public:
    int priority_id;
    int height;
    priorityNode* left;
    priorityNode* right;

    priorityNode(int id) : priority_id(id), height(1), left(nullptr), right(nullptr)
    {
    }
};

class dispatchAvlTree
{
private:
    priorityNode* root;

    int getHeight(priorityNode* node)
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

    int getBalanceFactor(priorityNode* node)
    {
        if (node == nullptr)
        {
            return 0;
        }
        return getHeight(node->left) - getHeight(node->right);
    }

    void updateHeight(priorityNode* node)
    {
        if (node != nullptr)
        {
            node->height = 1 + getMax(getHeight(node->left), getHeight(node->right));
        }
    }

    priorityNode* rotateRight(priorityNode* y)
    {
        priorityNode* x = y->left;
        priorityNode* t2 = x->right;

        x->right = y;
        y->left = t2;

        updateHeight(y);
        updateHeight(x);

        return x;
    }

    priorityNode* rotateLeft(priorityNode* x)
    {
        priorityNode* y = x->right;
        priorityNode* t2 = y->left;

        y->left = x;
        x->right = t2;

        updateHeight(x);
        updateHeight(y);

        return y;
    }

    priorityNode* rebalanceNode(priorityNode* node)
    {
        updateHeight(node);
        int balance = getBalanceFactor(node);

        if (balance > 1 && getBalanceFactor(node->left) >= 0)
        {
            return rotateRight(node);
        }

        if (balance > 1 && getBalanceFactor(node->left) < 0)
        {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }

        if (balance < -1 && getBalanceFactor(node->right) <= 0)
        {
            return rotateLeft(node);
        }

        if (balance < -1 && getBalanceFactor(node->right) > 0)
        {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }

        return node;
    }

    priorityNode* insertNode(priorityNode* node, int id)
    {
        if (node == nullptr)
        {
            return new priorityNode(id);
        }

        if (id < node->priority_id)
        {
            node->left = insertNode(node->left, id);
        }
        else if (id > node->priority_id)
        {
            node->right = insertNode(node->right, id);
        }
        else
        {
            return node;
        }

        return rebalanceNode(node);
    }

    priorityNode* getMinValueNode(priorityNode* node)
    {
        priorityNode* current = node;
        while (current->left != nullptr)
        {
            current = current->left;
        }
        return current;
    }

    priorityNode* deleteNode(priorityNode* node, int id)
    {
        if (node == nullptr)
        {
            return nullptr;
        }

        if (id < node->priority_id)
        {
            node->left = deleteNode(node->left, id);
        }
        else if (id > node->priority_id)
        {
            node->right = deleteNode(node->right, id);
        }
        else
        {
            if (node->left == nullptr || node->right == nullptr)
            {
                priorityNode* temp = (node->left != nullptr) ? node->left : node->right;
                delete node;
                return temp;
            }
            else
            {
                priorityNode* successor = getMinValueNode(node->right);
                node->priority_id = successor->priority_id;
                node->right = deleteNode(node->right, successor->priority_id);
            }
        }

        return rebalanceNode(node);
    }

    void inorderHelper(priorityNode* node)
    {
        if (node == nullptr)
        {
            return;
        }
        inorderHelper(node->left);
        cout << node->priority_id << " ";
        inorderHelper(node->right);
    }

    void preorderHelper(priorityNode* node)
    {
        if (node == nullptr)
        {
            return;
        }
        cout << node->priority_id << " ";
        preorderHelper(node->left);
        preorderHelper(node->right);
    }

    void postorderHelper(priorityNode* node)
    {
        if (node == nullptr)
        {
            return;
        }
        postorderHelper(node->left);
        postorderHelper(node->right);
        cout << node->priority_id << " ";
    }

    void printCurrentLevel(priorityNode* node, int level)
    {
        if (node == nullptr)
        {
            return;
        }
        if (level == 1)
        {
            cout << node->priority_id << " ";
        }
        else if (level > 1)
        {
            printCurrentLevel(node->left, level - 1);
            printCurrentLevel(node->right, level - 1);
        }
    }

public:
    dispatchAvlTree() : root(nullptr)
    {
    }

    void insert(int id)
    {
        root = insertNode(root, id);
    }

    void remove(int id)
    {
        root = deleteNode(root, id);
    }

    void inorder()
    {
        cout << "Inorder Traversal: ";
        inorderHelper(root);
        cout << endl;
    }

    void preorder()
    {
        cout << "Preorder Traversal: ";
        preorderHelper(root);
        cout << endl;
    }

    void postorder()
    {
        cout << "Postorder Traversal: ";
        postorderHelper(root);
        cout << endl;
    }

    void levelorder()
    {
        cout << "Levelorder Traversal: ";
        int h = getHeight(root);
        for (int i = 1; i <= h; i++)
        {
            printCurrentLevel(root, i);
        }
        cout << endl;
    }
};

int main()
{
    dispatchAvlTree dispatch_system;

    int initial_ids[19] = {45, 25, 65, 15, 35, 55, 75, 10, 20, 30, 40, 50, 60, 80, 5, 8, 7, 27, 26};

    for (int i = 0; i < 19; i++)
    {
        dispatch_system.insert(initial_ids[i]);
    }

    dispatch_system.insert(6);

    int delete_ids[6] = {80, 75, 65, 55, 45, 35};

    for (int i = 0; i < 6; i++)
    {
        dispatch_system.remove(delete_ids[i]);
    }

    dispatch_system.inorder();
    dispatch_system.postorder();
    dispatch_system.preorder();
    dispatch_system.levelorder();

    return 0;
}