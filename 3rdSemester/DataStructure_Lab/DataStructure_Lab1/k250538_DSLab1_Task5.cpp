//25K0538, Muhammad Farhan
#include <iostream>
#include <string>
using namespace std;

class Product
{
    private:
    string name;
    int* quantity;

    public:
    Product(string namae, int quant) : name(namae)
    {
        quantity = new int;
        *quantity = quant;
    }

    Product(const Product &other)
    {
        name = other.name;
        quantity = new int;
        *quantity = *other.quantity;
      
    }

    ~Product()
    {
        delete quantity;
    }

    Product& operator=(const Product& other)
    {
        if (this == &other)
        {
            return *this;
        }

        name = other.name;

        delete quantity;
        quantity = new int;
        *quantity = *other.quantity;

        return *this;
    }

    void display()
    {
        cout << "Product Name:\t" << name << endl;
        cout << "Quantity:\t" << *quantity << endl;
    }

};

int main()
{
    Product prod1("soap", 10);
    prod1.display();
    Product prod2 = prod1;
    prod2.display();
    Product prod3("shampoo", 5);
    prod3.display();
    prod3 = prod1;
    prod3.display();

    return 0;
}