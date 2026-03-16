//25K-0538  Muhammad Farhan
//DMA Version
#include <iostream>
#include <string>
using namespace std;

class Queue
{
    int* data; //0 = empty, anything else = full
    int counter;
public:
    Queue():counter(0)
    {
        data = new int [1];
        data[0]=0;
    }
    ~Queue()    {delete[] data;}

    void Enqueue()
    {
        cout<<"Insert Item to Enter: ";
        int item;
        cin>>item;
        int* temp = new int [counter+1];
        for(int i=0;i<counter;i++)
            temp[i]=data[i];
        temp[counter]=item;
        delete[] data;
        data=temp;
        temp = nullptr;
        counter++;
        cout<<item<<" Added."<<endl;
    }

    void Dequeue()
    {
        if(counter==0)
            cout<<"Underflow."<<endl;
        else
        {
            int* temp = new int [counter-1];
            for(int i=1;i<counter;i++)
                temp[i-1]=data[i];
            cout<<data[0]<<" Removed."<<endl;
            delete[] data;
            data=temp;
            temp=nullptr;
            counter--;
        }
    }

    void display()
    {
        cout<<"[ ";
        for(int i=0;i<counter;i++)
            cout<<data[i]<<" ";
        cout<<"]"<<endl<<endl;
    }

};

int main()
{
    Queue Q;
    while(1)
    {
        cout<<"1. Exit"<<endl;
        cout<<"2. Enqueue Item"<<endl;
        cout<<"3. Dequeue Item"<<endl;
        cout<<"4. Display Items"<<endl;
        cout<<"Enter your choice: ";
        int choice;
        cin>>choice;
        if(choice==1)
            break;
        else if (choice==2)
            Q.Enqueue();
        else if (choice==3)
            Q.Dequeue();
        else if (choice==4)
            Q.display();
        else
            cout<<"Invalid Choice, Please try again."<<endl;
        cout<<endl<<endl;
    }
    return 0;
}
