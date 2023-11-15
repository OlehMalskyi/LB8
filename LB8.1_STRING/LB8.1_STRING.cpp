#include <iostream>
#include <string>

using namespace std;

string findStr(string& str)
{
    size_t pos = str.find("***");

    if (pos != string::npos)
    {
        return str.substr(pos, 3);
    }

    return "";
}

string Change(string& str)
{
    if (str.length() < 3)
    {
        cout << "Enter more characters";
        return str;
    }

    size_t pos;
    while ((pos = str.find("***")) != string::npos)
    {
        str.replace(pos, 3, "!!");
    }
    return str;
}

int main()
{
    string str;
    cout << "Enter string:" << endl;
    getline(cin, str);
    cout << "Modified string (param) : " << str << endl;

    string foundStr = findStr(str);
    if (!foundStr.empty())
    {
        Change(str);
        cout << "'" << foundStr << "' found and will be changed" << endl;
        cout << "Modified string (result): " << str << endl;
    }
    else
    {
        cout << "'***' not found" << endl;
    }

    return 0;
}