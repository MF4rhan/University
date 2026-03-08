//M. Farhan, 25K-0538
#include <iostream>
#include <string>
using namespace std;

class Invoice
{
	string partno, description;
	int quantity;
	float priceperitem;
public:
	Invoice(string pno="N/A", string desc="Empty", int quant=0, float ppi=0.00)
	: partno(pno), description(desc), quantity(quant), priceperitem(ppi)
	{
		if (quantity<0)	quantity=0;
		if (priceperitem<0) priceperitem=0.00;
	}
	string getPartNumber()
	{
		return partno;
	}
	string getDescription()
	{
		return description;
	}
	int getQuantity()
	{
		return quantity;
	}
	float getPricePerItem()
	{
		return priceperitem;
	}
	float getInvoiceAmount()
	{
		return priceperitem*quantity;
	}
};

int main()
{
	Invoice item1("23KF34","RAM",4, 100), item2("4357KHF","SSD",-2,600);
	//item 1
	cout << "Item#1 Part Number: "<<item1.getPartNumber()<<endl;
	cout << "Description: " << item1.getDescription()<<endl;
	cout << "Quantity: " << item1.getQuantity() << endl;
	cout << "Price Per Item: " << item1.getPricePerItem() << endl;
	cout << "Invoice: " << item1.getInvoiceAmount() << endl << endl;
	//item 2
	cout << "Item#2 Part Number: "<<item2.getPartNumber()<<endl;
	cout << "Description: " << item2.getDescription()<<endl;
	cout << "Quantity: " << item2.getQuantity() << endl;
	cout << "Price Per Item: " << item2.getPricePerItem() << endl;
	cout << "Invoice: " << item2.getInvoiceAmount() << endl;
return 0;
}