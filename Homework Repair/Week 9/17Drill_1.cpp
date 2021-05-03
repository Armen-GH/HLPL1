#include "std_lib_facilities.h"

//4
void print_array10(ostream& os, int* a);
//7
void print_array(ostream& os, int* a, int n);
void print_vector(ostream& os, vector<int> v);

int main()
{
    int e;
    //1
    int *arr = new int[10];
    //2
    for (int i=0;i<10;i++) 
    {
        arr[i] = i + 1;
    }
    //3
    delete[] arr; //9

    //5
    int *arr1 = new int[10];
    for(int i=0;i<10;i++)
    {
        arr1[i] = i + 100;
    }
    for(int i=0;i<10;i++)
    {
        cout << arr1[i] << " - ";
    }
    delete[] arr1; //9

    //6
    int *arr2 = new int[11];
    for(int i=0;i<11;i++)
    {
        arr2[i] = i + 100;
    }
    for(int i=0;i<11;i++)
    {
        cout << arr2[i] << " - ";
    }
    delete[] arr2; //9

    //8
    int *arr3 = new int[20];
    for(int i=0;i<20;i++)
    {
        arr3[i] = i + 100;
    }
    print_array(cout, arr3, 20);
    delete[] arr3; //9

    //10
    vector<int> vec;
    for(int i=0;i<10;i++)
    {
        e = i + 100;
        vec.push_back(e);
    }
    print_vector(cout, vec);

    vector<int> vec1;
    for(int i=0;i<11;i++)
    {
        e = i + 100;
        vec.push_back(e);
    }
    print_vector(cout, vec);

    vector<int> vec;
    for(int i=0;i<20;i++)
    {
        e = i + 100;
        vec.push_back(e);
    }
    print_vector(cout, vec);
}

void print_array10(ostream& os, int* a)
{
    for(int i=0;i<10;i++) 
    {
        os << i << " = " << a[i] << "." << endl;
    }
    cout << endl;
}

void print_array(ostream& os, int* a, int n)
{
    for(int i=0;i<n;i++) 
    {
        os << i << " = " << a[i] << "." << endl;
    }
    cout << endl;
}

void print_vector(ostream& os, vector<int> v)
{
    for(int i=0;i<v.size();i++)
    {
        os << i << " - ";
    }
    cout << endl;
}
