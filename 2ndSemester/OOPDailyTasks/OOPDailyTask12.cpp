//25K-0538  Muhammad Farhan
//Non-DMA Version
#include <iostream>
#include <string>
using namespace std;

class Queue
{
    int data[6]; //0 = empty, anything else = full
    int counter;
public:
    Queue():counter(0)
    {
        for(int i=0;i<6;i++)
            data[i]=0;
    }

    void Enqueue()
    {
        cout<<"Insert Item to Enter: ";
        int item;
        cin>>item;
        if(counter<6)
        {
            int j=0;
            for(int i=6-counter;j<counter;i++,j++)
                data[i-1]=data[i];
            data[5]=item;
            counter++;
            cout<<item<<" Added."<<endl;
        }
        else
            cout<<"Overflow."<<endl;

    }

    void Dequeue()
    {
        if(counter>0)
        {
            for(int i=0;i<6;++i)
            {
                if(data[i]!=0)
                {
                    cout<<data[i]<<" Removed."<<endl;
                    data[i]=0;
                    counter--;
                    return;
                }
            }
        }
        else
            cout<<"Underflow."<<endl;
    }

    void display()
    {
        cout<<"[ ";
        for(int i=0;i<6;i++)
            cout<<data[i]<<" ";
        cout<<"]"<<endl<<endl;
    }

    /*
    Because the questions states it, I have made these two checking methods below.
    However, because we are using a counter variable, they are not really needed.
    I COULD use them by using an if(condition) and putting the adding/removing logic on else.
    But whats the point if its not required in the first place.
    */
    bool check_empty()  {counter==0?return true:return false;}
    bool check_full()   {counter==6?return true:return false;}

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
