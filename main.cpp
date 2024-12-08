#include <iostream>
#include <cstring>
#include <fstream>
#include <map>
#include <list>
using namespace std;

int gen_hash_index(string);

int main() {
    string temp;
    int tempIndex;
    ifstream ifs;
    map<int,list<string>> hash_table;

    ifs.open("lab-37-data.txt");
    if (ifs)
    {
        while (getline(ifs, temp))
        {
            getline(ifs, temp);
            tempIndex = gen_hash_index(temp);
        }
    }
    else 
    {
        cout << "ERROR: Opening File" << endl;
    }
    ifs.close();
    
    return 0;
}

int gen_hash_index(string s)
{
    int sum = 0;
    char arr[s.length() + 1];

    strcpy(arr, s.c_str());
    for (size_t i = 0; i < s.length(); i++)
    {
        sum += (int) arr[i];
    }

    return sum;
}

/*
These targets are present in the dataset and can be used for testing:
536B9DFC93AF
1DA9D64D02A0
666D109AA22E
E1D2665B21EA
*/