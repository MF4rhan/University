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
    
    int k=0;
    for (int i=0;i<m;i++)
    {
        for (int j=0; j<n; j++)
        {
            if (array2[i]==array1[j])
            {
                k++;
                break;
            }
        }
    }
    if (k==m)
    {
    	cout <<"True"<<endl;
	}
	else
	{
		cout << "False" << endl;
	}
	delete array1;
    delete array2;
}
