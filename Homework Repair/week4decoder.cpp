#include <iostream>
#include <vector>
using namespace std;

int decoder(int a);

int main()
{
    int test_n, i, j, k, enc_n, a, b;
    vector<int> num;
    cout << "Please enter the number of test cases you wish to decode: ";
    cin >> test_n;
    for(i=0;i<test_n;i++)
    {
        cout << "Please enter the number of encrypted numbers followed by the encrypted numbers: ";
        cin >> enc_n;
        for(k=0;k<enc_n;k++)
        {
            cin >> a;
            b = decoder(a);
            num.push_back(b);
            sort(num.begin(),num.end());
        }
        cout << "Here are the decoded numbers you requested chief! --> ";
        for(j=0;j<enc_n;j++)
            {
                if(num[j]==num[enc_n-1])
                {
                    cout << num[j];
                } else {
                    cout << num[j] << "-";
                }
            }
        num.clear();
        cout << "\n";
    }
}
int decoder(int a)
{
    switch(a)
    {
        case 1:
            a = 1;
            break;
        case 11:
            a = 2;
            break;
        case 111:
            a = 3;
            break;
        case 1111:
            a = 4;
            break;
        case 11111:
            a = 5;
            break;
        case 111111:
            a = 6;
            break;
        case 1111111:
            a = 7;
            break;
        case 11111111:
            a = 8;
            break;
        case 111111111:
            a = 9;
            break;
    }
    return a;
}
