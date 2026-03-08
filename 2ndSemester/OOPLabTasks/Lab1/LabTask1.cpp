#include <iostream>
using namespace std;

int main()
{
    int n, m;
    cout << "enter size of first array:" << endl;
    cin >> n;
    cout << "enter size of second array:" << endl;
    cin >> m;
    
    int* array1 = new int[n];
    int* array2 = new int[m];
    for (int i = 0; i < n; i++)
    {
        cout << "enter "<<i+1<< " element of first array"<<endl;
        cin >> array1[i];
    }
    for (int i = 0; i < m; i++)
    {
        cout << "enter "<<i+1<< " element of second array"<<endl;
        cin >> array2[i];
    }
    int v;
    if (n<m)
    {
        v=m;
    }
    else
    {
        v=n;
    }
    int* final = new int[v];

    int k=0;
    for (int i=0;i<n;i++)
    {
        for (int j=0; j<m; j++)
        {
            if (array1[i]==array2[j])
            {
                final[k]= array1[i];
                k++;
                array2[j]=999;
                break;
            }
            
        }
    }
    int temp;
    for (int i=0;i<k-1;i++)
    {
        for (int j=0;j<k-i-1;j++)
        {
            if (final[j]>final[j+1])
            {
            temp = final[j];
            final[j] = final[j+1];
            final[j+1] = temp;
        	}
        }
    }
    for (int i = 0; i < k; i++)
    {
        cout << final[i] << " ";
    }
    delete array1;
    delete array2;
    delete final;
}



