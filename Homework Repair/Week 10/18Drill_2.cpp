#include "std_lib_facilities.h"
//1
vector<int> gv = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512};
//2
void f(vector<int> v);
int factorial(int a);

int main()
{
    f(gv); //4.a
    vector<int> vv;
    for(int i=0;i<10;i++) //4.b
    {
        vv[i] = factorial(i+1);
    }
    f(vv); //4.c
}

void f(vector<int> v)
{
    vector<int> lv; //3.a
    for(int i=0;i<10;i++) //3.b
    {
        lv[i] = gv[i];
    }
    for(int i=0;i<10;i++) //3.c
    {
        cout << lv[i] << " ";
    }
    vector<int> lv2 = v; //3.d
    for(int i=0;i<lv2.size();i++) //3.e
    {
        cout << lv2[i] << " ";
    }
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
