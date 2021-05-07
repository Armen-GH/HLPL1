#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <set>
#include <list>
#include <iterator>
using namespace std;

struct Item //1
{
    string name;
    int iid;
    double value;
    friend istream& operator>>(istream& is, Item& item);
    friend ostream& operator<<(ostream& os, const Item& item);
};

istream& operator>>(istream& is, Item& item)
{
    is >> item.name >> item.iid >> item.value;
    return is;
}

ostream& operator<<(ostream& os, const Item& item)
{
    os << item.name << " " << item.iid << " " << item.value << "   ";
    return os;
}

struct Cmp_by_name
{
    bool operator()(const Item &a, const Item &b) const{return a.name < b.name;}
};

struct Cmp_by_iid
{
    bool operator()(const Item &a, const Item &b) const{return a.iid < b.iid;}
};

struct Cmp_by_value
{
    bool operator()(const Item &a, const Item &b) const{return a.value > b.value;}
};

void nameDelete(string Name, vector<Item>& v)
{
    for (int i=0; i!=v.size(); i++)
    {
      if (v[i].name == Name)
      {
          v.erase(v.begin()+i,v.begin()+1+i);
          break;
      }    
    }
}

void idDelete(int n, vector<Item>& v)
{
    for (int i=0; i!=v.size(); i++)
    {
      if (v[i].iid == n)
      {
          v.erase(v.begin()+i,v.begin()+1+i);
          break;
      }    
    }
}

int main()
{
    int i;
    vector<Item> vi; //2 
    ifstream file("input.txt");
    Item intake;
    while(file >> intake)
    {
        vi.push_back(intake);
    }

    cout << "Vector at the beginning:   ";
    for(i=0;i<vi.size();i++)
    {
        cout << vi[i] << " ";
    }
    cout << "\n \n";

    sort(vi.begin(), vi.end(), Cmp_by_name()); //3
    cout << "Sorting by name:   ";
    for(i=0;i<vi.size();i++)
    {
        cout << vi[i] << " ";
    }
    cout << "\n \n";

    sort(vi.begin(), vi.end(), Cmp_by_iid()); //4
    cout << "Sorting by ID:   ";
    for(i=0;i<vi.size();i++)
    {
        cout << vi[i] << " ";
    }
    cout << "\n \n";

    sort(vi.begin(), vi.end(), Cmp_by_value()); //5
    cout << "Sorting by value:   ";
    for(i=0;i<vi.size();i++)
    {
        cout << vi[i] << " ";
    }
    cout << "\n \n";

    Item insert1 = {"horse shoe",99,12.34}; //6
    Item insert2 = {"Canon S400", 9988,499.95};
    vi.push_back(insert1);
    vi.push_back(insert2);
    cout << "After two insertions:   ";
    for(i=0;i<vi.size();i++)
    {
        cout << vi[i] << " ";
    }
    cout << "\n \n";

    nameDelete("car", vi); // 7
    nameDelete("can", vi);
    cout << "After two name-based deletions:   ";
    for(i=0;i<vi.size();i++)
    {
        cout << vi[i] << " ";
    }
    cout << "\n \n";

    idDelete(2, vi); //8
    idDelete(89, vi);
    cout << "After two id-based deletions:   ";
    for(i=0;i<vi.size();i++)
    {
        cout << vi[i] << " ";
    }
    cout << "\n \n";

    //list instead of a vector
    list<Item> li;
    
    cout << "\n \n \n";
    cout << "List at the beginning:   ";
    
}

