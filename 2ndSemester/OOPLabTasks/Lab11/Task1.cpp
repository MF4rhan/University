#include <iostream>
#include <string>
using namespace std;

template <typename T, typename U>
class Pair
{
private:
    T variable_one;
    U variable_two;

public:
    Pair(T var1, U var2) : variable_one(var1), variable_two(var2)
    {}

    void display()
    {
      cout << "Pair: (" << variable_one << "," << variable_two << ")\n";
    }
};

int main()
{
    Pair<int, string> pair_one(5, "Hello");
    Pair<double, int> pair_two(3.14, 42);

    pair_one.display();
    pair_two.display();

    return 0;
};
