#include <iostream>
#include<algorithm>
#include<string>
#include <vector>

using namespace std;

bool compareString(string& str1, string& str2) {
    return str1.size() == str2.size() ? str1 < str2 : str1.size() < str2.size();
}

int main()
{
    vector<string> names;

    for (int i = 0; i < 5; i++)
    {
        cout << "Enter Name: ";
        string input;
        getline(cin, input);
        names.push_back(input);
    }

    sort(names.begin(), names.end(), compareString);

    for (int i = 0; i < 5; i++)
    {
        cout << names[i] << endl;
    }

    return 0;
}
