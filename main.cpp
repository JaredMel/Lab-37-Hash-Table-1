#include <iostream>
#include <cstring>
using namespace std;

int sum_ascii(string);

int main() {
    char a = 'A';
    cout << a << endl;
    cout << (int) a << endl;
    int b = 66;
    cout << b << endl;
    cout << (char) b << endl;

    string teststr = "AB";
    int test = sum_ascii(teststr);
    cout << test << endl;

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