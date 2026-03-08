#include <iostream>
#include <string>
using namespace std;

class Cars
{
	const string Model;
	string Brand;
	int price;
	
	public:
		Cars(string mod, string bran, int monei): Model(mod), Brand(bran), price(monei) {}
		
		void getDetails()
		{
			cout << "Model No: " <<  Model<< endl;
			cout << "Brand: " << Brand << endl;
			cout << endl;
		}
		void getPrice()
		{
			cout << "Price: " << price << endl;
			cout << endl;
		}
		//void setReg(string reg) {Model = reg;}
		//This function shows a compile time error because we cannot assign a value to a const variable
};

int main()
{
	Cars obj1("Corolla", "Toyota", 30000);
	Cars obj2("Jimny", "Suzuki",25000);
	
	obj1.getDetails();
	obj1.getPrice();
	obj2.getDetails();
	obj2.getPrice();
	
return 0;
}
