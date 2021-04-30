#include <iostream>
#include <cmath>
#include <complex>
using namespace std;

int main()
{
    try {   
        double a, b, c, x1, x2, disc, num1, num2;
        cout << "Please enter a, b, c accordingly! ";
        cin >> a >> b >> c;
        disc = pow(b,2) - (4 * a * c);
        if(disc > 0)
        {
            x1 = (-b + sqrt(disc)) / (2*a);
            x2 = (-b - sqrt(disc)) / (2*a);
            cout << "x1 and x2 are real and different from each other!" << endl;
            cout << "x1 and x1 are " << x1 << " " << x2 << endl;
        } else if (disc == 0) {
            x1 = -b / (2 * a);
            cout << "x1 and x2 are real and equal x" << endl;
            cout << "the sole solution is " << x1 << endl;
        } else if (disc < 0){
            num1 = -b/(2*a);
            num2 = sqrt(-disc) / (2*a);
            complex<double> mycomp(num1, num2);
            cout << "x1 and x2 are complex and different!" << endl;
            cout << real(mycomp) << " + " << imag(mycomp) << "i" << endl;
            cout << real(mycomp) << " - " << imag(mycomp) << "i" << endl;
        }
        }
    catch(...)
    {
        cout << "invalid input, please try again!";
    }
}
