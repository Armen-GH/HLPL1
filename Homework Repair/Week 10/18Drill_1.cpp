#include "std_lib_facilities.h"
//1
int ga[10] = {1,2,4,8,16,32,64,128,256,512};
/*for(int i=0;i<10;i++)
{
    ga[i] = (i+1) * 2;
}
*/

//2
void f(int a[], int n);
int factorial(int a);

int main()
{
    int size = 10;
    f(ga, size); //4.a
    int aa[10];
    for(int i=0;i<size;i++) //4.b
    {
        aa[i] = factorial(i+1);
    }
    f(aa, size); //4.c
}

void f(int a[], int n)
{
    int la[10]; //3.a
    for(int i=0;i<10;i++) //3.b
    {
        la[i] = ga[i];
    }
    for(int i=0;i<10;i++) //3.c
    {
        cout << la[i] << " ";
    }
    int *p = new int[n]; //3.d
    for(int i=0;i<n;i++) //3.e
    {
        p[i] = a[i];
    }
    for(int i=0;i<n;i++)
    {
        cout << p[i];
    }
    delete[] p; //3.g
}

int factorial(int a)
{
    int i=1, f=1;
    for(i; i<=a; i++)
    {
        f = f * i;
    }
    return f;
}
