#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <stdexcept>

using namespace std;

inline void window() { char ch; cin >> ch; }

int main() {
    int sum = 0, num;
    vector<int> nums;
    string word;
    ifstream file("file.txt");

    while (file >> word) {
        try {
            num = stoi(word);
        }
        catch (const std::exception &) {
            continue;
        }
        nums.push_back(num);
    }

    if (file.fail() && !file.eof())
        exit(1);

    for (int x : nums)
        sum += x;

    cout << sum << "\n";
    window();

    return 0;
}
