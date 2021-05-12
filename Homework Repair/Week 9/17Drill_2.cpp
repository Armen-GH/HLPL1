#include "std_lib_facilities.h"

void print_array(ostream& os, int* a, int n);
void print_vector(ostream& os, vector<int> v);

int main()
{
    //1
    int a = 7, e;
    int *p1 = &a;
    //2
    cout << "p1 = " << p1 << ", it points to = " << *p1 << endl;
    //3
    int *arr = new int[7];
    int *p2 = arr;
    for(int i=0;i<7;i++)
    {
        arr[i] = (i + 1) * 2;
    }
    //4
    cout << "Value of P2 is " << p2 << endl;
    print_array(cout, arr, 7);
    //5 6 7
    int *p3 = p2;
    p2 = p1;
    p2 = p3;
    //8
    cout << "p1 = " << p1 << ", it points to = " << *p1 << endl;
    cout << "p2 = " << p2 << ", it points to = " << *p2 << "\n" << endl;
    //9
    delete[] arr;
    //10
    int *arr1 = new int[10];
    p1 = arr1;
    for(int i=0;i<10;i++)
    {
        arr1[i] = (i + 1) * 2;
    }
    //11
    int *arr2 = new int[10];
    p2 = arr2;
    for(int i=0;i<10;i++)
    {
        p2[i] = p1[i]; 
    }
    cout << "Array arr1 printed from arr2 is: " << endl;
    print_array(cout, arr2, 10);
    cout << "\n";

    delete[] arr1;
    delete[] arr2;
    //12
    vector<int>v (10);
    for(int i=0;i<10;i++)
    {
        v[i] = (i + 1) * 2;
    }

    vector<int> v1 (10);
    for(int i=0;i<10;i++)
    {
        v1[i] = v[i];
    }
    cout << "Vector v1 printed from v2 is: " << endl;
    print_vector(cout, v1);
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
        os << i << " - " << v[i] << "." << endl;
    }
}
