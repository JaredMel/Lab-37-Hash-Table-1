#include <iostream>
#include <cstring>
#include <fstream>
#include <map>
#include <list>
using namespace std;

int gen_hash_index(string);
void printFirst100(map<int,list<string>>);
void searchKey(map<int,list<string>>);
void addKey(map<int,list<string>>&);
void removeKey(map<int,list<string>>&);
void modifyKey(map<int,list<string>>&);

int main() {
    string temp;
    int tempIndex;
    ifstream ifs;
    int choice;
    map<int,list<string>> hash_table;

    ifs.open("lab-37-data.txt");
    if (ifs)
    {
        while (getline(ifs, temp))
        {
            getline(ifs, temp);
            tempIndex = gen_hash_index(temp);
            list<string> tempList = {temp};
            hash_table.insert({tempIndex, tempList});
        }
    }
    else 
    {
        cout << "ERROR: Opening File" << endl;
    }
    ifs.close();

    while (choice != 0)
    {
        do
        {
            cout << "Hash Table Menu:" << endl;
            cout << "[1] Print first 100 entries" << endl;
            cout << "[2] Search for a key" << endl;
            cout << "[3] Add a key" << endl;
            cout << "[4] Remove a key" << endl;
            cout << "[5] Modify a key" << endl;
            cout << "[0] Exit" << endl;
            cout << "Enter your choice:" << endl;
            cin >> choice;
        } while (choice < 0 || choice > 5);
        
        switch (choice)
        {
        case 1:
            printFirst100(hash_table);
            break;
        case 2:
            searchKey(hash_table);
            break;
        case 3:
            addKey(hash_table);
            break;
        case 4:
            removeKey(hash_table);
            break;
        case 5:
            modifyKey(hash_table);
            break;
        default:
            break;
        }
    }
    
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

void printFirst100(map<int,list<string>> hash_table)
{
    cout << "First 100 map entries:" << endl;
    map<int,list<string>>::iterator it = hash_table.begin();
    it++;
    for (size_t i = 0; i < 100; i++)
    {
        cout << "[Key]: " << it->first << " [Value]: ";
        for (string value : it->second)
        {
            cout << value << ", ";
        }
        cout << endl;
        it++;
    }
}

void searchKey(map<int,list<string>> hash_table)
{
    string key;
    int index;
    map<int,list<string>>::iterator it;

    cout << "Enter the Key you are searching for:" << endl;
    getline(cin, key);

    index = gen_hash_index(key);

    it = hash_table.find(key);
    if (it != hash_table.end())
    {
        hash_table.erase (it);
        cout << "Key is not in hash table" << endl;
    }
    else
    {
        cout << "[Key]: " << key << " [Value]: ";
        for (string value : it->second)
        {
            cout << value << ", ";
        }
    }
    cout << endl;
}

void addKey(map<int,list<string>> &hash_table)
{
    string key;
    int index;

    cout << "Enter key you wish to add: " << endl;
    getline(cin, key);

    index = gen_hash_index(key);
    list<string> keyList = {key};
    hash_table.insert({index, keyList});
    cout << "Sucessfully inserted " << key << endl;
}

void removeKey(map<int,list<string>> &hash_table)
{
    string key;
    int index;
    map<int,list<string>>::iterator it;

    cout << "Enter key you wish to remove: " << endl;
    getline(cin, key);

    index = gen_hash_index(key);

    it = hash_table.find(key);
    if (it != hash_table.end())
    {
        hash_table.erase(it);
        cout << "Key is not in hash table" << endl;
    }
    else
    {
        hash_table.erase(it);
        cout << "Key successfully erased" << endl;
    }
}

void modifyKey(map<int,list<string>> &hash_table)
{
    string key;
    string newKey;
    int index;
    int newIndex;
    map<int,list<string>>::iterator it;

    cout << "Enter key you wish to modify: " << endl;
    getline(cin, key);

    index = gen_hash_index(key);

    it = hash_table.find(key);
    if (it != hash_table.end())
    {
        hash_table.erase(it);
        cout << "Key is not in hash table" << endl;
    }
    else
    {
        cout << "What do you want to change the key to: " << endl;
        getline(cin, newKey);
        newIndex = gen_hash_index(newKey);
        list<string> keyList = {newKey};
        hash_table.erase(it);
        hash_table.insert({newIndex, keyList});
    }
}

/*
These targets are present in the dataset and can be used for testing:
536B9DFC93AF
1DA9D64D02A0
666D109AA22E
E1D2665B21EA
*/