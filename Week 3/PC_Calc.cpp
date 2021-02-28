#include <iostream>
#include <cmath>

using namespace std;

int factorial(int a)
{
    int i=1, f=1;
    for(i; i<=a; i++)
    {
        f = f * i;
    }
    return f;
}

int permutation(int a, int b)
{
    return factorial(a) / factorial(a-b);
}

int combination(int a, int b)
{
    return permutation(a, b) / factorial(b);
}

int main()
{
    int a, b;
    char c;
    cout << "Enter a positive number (a): ";
    cin >> a;
    cout << "Enter another positive number (b): ";
    cin >> b;
    cout << "Enter (P) for permutation, (C) for combination, (B) for Both: ";
    cin >> c;
    c = tolower(c); //to avoid user`s upper / lower input confusion!
    
    try
    {
        if(c=='p')
        {
        cout << "Permutation for " << a << " and " << b << " is: "  << permutation(a, b);

        } 
        else if(c=='c')
        {
        cout << "Combination for " << a << " and " << b << " is: "  << combination(a, b);
        } 
        else
        {
        cout << "Permutation for " << a << " and " << b << " is: "  << permutation(a, b) << endl;
        cout << "Combination for " << a << " and " << b << " is: "  << combination(a, b);
        }
    }
    catch(...)
    {
        cout << "try again!";
    }
    return 0;
}
