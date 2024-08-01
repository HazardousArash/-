#include <iostream>
#include <string>

using namespace std;

int goodness = 0;

string copy(string input, string added, int count) 
{
    size_t start = 0;
    for (int i = 0; i < count; ++i) {
        if (start >= input.length())
            break;
        input.replace(start, added.length(), added);
        start += added.length();
    }
    return input;
}

bool compare(string input, string added) 
{
    return input == added;
}

bool subStr(string input, string key, int count) 
{
    int foundCount = 0;
    size_t found = input.find(key);
    while (found != string::npos) {
        ++foundCount;
        found = input.find(key, found + 1);
    }
    return foundCount == count;
}

bool attach(string input, string key, string str, int count) 
{
    string result = key + str;
    return subStr(input, result, count);
}

bool isLength(string input, int length) 
{
    return input.length() == length;
}

string handler(string option, string input) 
{
    bool result = false;
    string key;
    string str;
    int number = 0;
    if (option == "copy") {
        cin >> key >> number;
        input = copy(input, key, number);
        return input;
    }
    else if (option == "compare") 
    {
        cin >> key;
        result = compare(input, key);
        if (result)
            ++goodness;
        return input;
    }
    else if (option == "substr") 
    {
        cin >> key >> number;
        result = subStr(input, key, number);
        if (result)
            ++goodness;
        return input;
    }
    else if (option == "attach") 
    {
        cin >> key >> number>>str;        
        result = attach(input, key, str, number);
        if (result)
            ++goodness;
        return input;
    }
    else 
    {
        cin >> number;
        result = isLength(input, number);
        if (result)
            ++goodness;
        return input;
    }
}

int main() 
{
    string input;
    cin >> input;
    string option;
    int countOfOptions = 0;
    while (true) 
    {
        cin >> option;
        if (option == "Is")
            break;
        input = handler(option, input);
        ++countOfOptions;
    }
    if ((countOfOptions / 2) <= goodness) 
    {
        cout << "Eyval";
    }
    else 
    {
        cout << "HeifShod";
    }
}
