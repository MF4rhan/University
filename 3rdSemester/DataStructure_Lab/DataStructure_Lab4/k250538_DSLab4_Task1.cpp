#include <iostream>
using namespace std;

class Node
{
public:
	int data;
	Node* next;

	Node(int dat = 0) : data(dat), next(nullptr)
	{
	}
};

class singleLinkedList
{
private:
	Node* head;
	Node* tail;

public:
	singleLinkedList() : head(nullptr), tail(nullptr)
	{
	}

	~singleLinkedList()
	{
		Node* to_delete = head;
		while (to_delete != nullptr)
		{
			Node* next_node = to_delete->next;
			delete to_delete;
			to_delete = next_node;
		}
		head = nullptr;
		tail = nullptr;
	}

	void insert_at_head(int val)
	{
		Node* node = new Node(val);
		if (head == nullptr)
		{
			head = node;
			tail = node;
		}
		else
		{
			node->next = head;
			head = node;
		}
	}

	void insert_at_tail(int val)
	{
		Node* node = new Node(val);
		if (head == nullptr)
		{
			head = node;
			tail = node;
		}
		else
		{
			tail->next = node;
			tail = node;
		}
	}

	void display_list()
	{
		if (head == nullptr)
		{
			cout << "List is empty.\n";
			return;
		}

		Node* temp = head;
		while (temp != nullptr)
		{
			cout << temp->data << " -> ";
			temp = temp->next;
		}
		cout << "nullptr\n";
	}

	void delete_from_head()
	{
		if (head == nullptr)
		{
			cout << "List is empty.\n";
			return;
		}
		if (head->next == nullptr)
		{
			delete head;
			head = nullptr;
			tail = nullptr;
			return;
		}

		Node* temp = head->next;
		delete head;
		head = temp;
	}

	void delete_from_tail()
	{
		if (head == nullptr)
		{
			cout << "The List is Empty.\n";
			return;
		}
		if (tail == head)
		{
			delete head;
			head = nullptr;
			tail = nullptr;
			return;
		}
		Node* temp = head;
		while (temp->next != tail)
		{
			temp = temp->next;
		}

		delete tail;
		temp->next = nullptr;
		tail = temp;
		return;
	}

	void delete_from_position(int index)
	{
		if (head == nullptr)
		{
			cout << "List is empty.\n";
			return;
		}
		int counter = 1;
		Node* temp = head;

		while (temp != nullptr && counter < index - 1)
		{
			counter++;
			temp = temp->next;
		}
		if (temp == nullptr || temp->next == nullptr)
		{
			cout << "Invalid index.\n";
			return;
		}

		Node* to_delete = temp->next;
		temp->next = to_delete->next;
		delete to_delete;
	}
};


int main()
{
	cout << "How many values do you want to enter: ";
	int num;
	cin >> num;

	singleLinkedList list;

	int choice;
	for (int i = 0; i < num; i++)
	{
		while (true)
		{
			
			cout << "\nDo you want to enter at Head(0) or Tail(1): ";
			cin >> choice;
			if (choice != 0 && choice != 1)
			{
				cout << "Invalid choice.\n";
				continue;
			}
			break;
		}

		cout << "\nEnter the value: ";
		int val;
		cin >> val;

		if (choice == 0)
		{
			list.insert_at_head(val);
		}
		else if (choice == 1)
		{
			list.insert_at_tail(val);
		}
		
	}

	list.display_list();

	while (true)
	{
		cout << "\nDo you want to remove at Head(0) or Tail(1): ";
		cin >> choice;
		if (choice != 1 && choice != 0)
		{
			cout << "Invalid choice.\n";
			continue;
		}
		break;
	}
	if (choice == 1)
	{
		list.delete_from_tail();
	}
	else
	{
		list.delete_from_head();
	}

	list.display_list();

	cout << "\nEnter the position you want to remove at: ";
	cin >> choice;

	list.delete_from_position(choice);

	list.display_list();
	return 0;
}