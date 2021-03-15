#include <iostream>
#include <vector>
#include<bits/stdc++.h> 

using namespace std;

int main()
{
    vector<pair<string,int>> v;
    vector<string> name;
    vector<int> age;
    int i,a;
    string input;
    
    try
    {   cout << "Please Enter Five Names: " << endl;
        while (i<5)
        {
            cin >> input;
            name.push_back(input);
            i++;
        }

        for (i=0;i<=4;i++)
        {
            cout << "please Enter an Age for " << name[i] << ": ";
            cin >> a;
            age.push_back(a);
        }

        for (i=0;i<=4;i++)
        {
            v.push_back( make_pair(name[i],age[i]) );
        }
        
        sort(v.begin(),v.end());

        for (i=0;i<=4;i++)
        {
            cout << v[i].first << ": " << v[i].second << endl;
        }
    }
    catch(...)
    {
        cout << "why don`t we try again>?";
    }

    return 0;
}