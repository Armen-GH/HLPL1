#include "std_lib_facilities.h"

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

class nameDelete {
    string name;
public:
    nameDelete(const string& nn) : name(nn) { }
    bool operator()(const Item& x) const { return x.name == name; }
};

class idDelete {
    int iid;
public:
    idDelete(int id) : iid(id) { }
    bool operator()(const Item& x) const { return x.iid == iid; }
};

class to_insert {
    double val;
public:
    to_insert(double vv) : val(vv) { }
    bool operator()(const Item& x) const { return x.value < val; }
};

template<typename C> void printout(const C& c, char sep = ' ')
{
    for (const auto& a : c)
        cout << a << sep;
    cout << '\n';
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
    printout(vi);
    cout << "\n \n";

    sort(vi.begin(), vi.end(), Cmp_by_name()); //3
    cout << "Vector Sorted by name:   ";
    printout(vi);
    cout << "\n \n";

    sort(vi.begin(), vi.end(), Cmp_by_iid()); //4
    cout << "Vector Sorted by ID:   ";
    printout(vi);
    cout << "\n \n";

    sort(vi.begin(), vi.end(), Cmp_by_value()); //5
    cout << "Vector Sorted by value:   ";
    printout(vi);
    cout << "\n \n";

    Item insert1 = {"horse shoe",99,12.34}; //6
    Item insert2 = {"Canon S400", 9988,499.95};
    vi.push_back(insert1);
    vi.push_back(insert2);
    cout << "Vector after two insertions:   ";
    printout(vi);
    cout << "\n \n";

    vi.erase(find_if(vi.begin(), vi.end(), nameDelete("bye"))); // 7
    vi.erase(find_if(vi.begin(), vi.end(), nameDelete("grade")));
    cout << "Vector after two name-based deletions:   ";
    printout(vi);
    cout << "\n \n";

    vi.erase(find_if(vi.begin(), vi.end(), idDelete(187))); //8
    vi.erase(find_if(vi.begin(), vi.end(), idDelete(22)));
    cout << "Vector after two id-based deletions:   ";
    printout(vi);
    cout << "\n \n";

    //9 list instead of a vector
    list<Item> li (vi.size());
    copy(vi.begin(), vi.end(), li.begin());
    cout << "List at the beginning:   ";
    printout(li);
    cout << "\n \n";
    
    li.sort(Cmp_by_name());
    cout << "List sorted by name:   ";
    printout(li);
    cout << "\n \n";
    
    li.sort(Cmp_by_iid());
    cout << "List sorted by ID:   ";
    printout(li);
    cout << "\n \n";

    li.sort(Cmp_by_value());
    cout << "List sorted by value:   ";
    printout(li);
    cout << "\n \n";

    Item insert3 = {"Prom",9123,12.344};
    Item insert4 = {"code",812,144.34};
    li.insert(find_if(li.begin(), li.end(), to_insert(insert3.value)), insert3);
    li.insert(find_if(li.begin(), li.end(), to_insert(insert4.value)), insert4);
    cout << "List after two insertions:   ";
    printout(li);
    cout << "\n \n";

    li.erase(find_if(li.begin(), li.end(), nameDelete("hello")));
    li.erase(find_if(li.begin(), li.end(), nameDelete("eye")));
    cout << "List after two name-based deletions: ";
    printout(li);
    cout << "\n \n";

    li.erase(find_if(li.begin(), li.end(), idDelete(6)));
    li.erase(find_if(li.begin(), li.end(), idDelete(10)));
    cout << "List after two id-based deletions: ";
    printout(li);
}
