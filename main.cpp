#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

int sum_ascii(string);

int main() {
    int total = 0;
    string temp;
    ifstream ifs;

    ifs.open("lab-37-data.txt");
    if (ifs)
    {
        while (getline(ifs, temp))
        {
            getline(ifs, temp);
            total += sum_ascii(temp);
        }
    }
    else 
    {
        cout << "ERROR: Opening File" << endl;
    }
    ifs.close();

    cout << "Grand Total: " << total << endl;
    
    return 0;
}

int sum_ascii(string s)
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