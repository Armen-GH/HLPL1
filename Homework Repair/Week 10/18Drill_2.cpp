#include "std_lib_facilities.h"

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
        vv.push_back(factorial(i+1));
    }
    f(vv); //4.c
}

void f(vector<int> v)
{
    vector<int> lv; //3.a
    lv.reserve(v.size());
    for(int i=0;i<10;i++) //3.b
    {
        lv.push_back(gv[i]);
    }
    for(int i=0;i<10;i++) //3.c
    {
        cout << lv[i] << " ";
    }
    cout << "\n" << endl;
    vector<int> lv2 = v; //3.d
    for(int i=0;i<lv2.size();i++) //3.e
    {
        cout << lv2[i] << " ";
    }
    cout << "\n" << endl;
}

int factorial(int a)
{
    int i, f=1;
    for(i=1; i<=a; i++)
    {
        f = f * i;
    }
    return f;
}
