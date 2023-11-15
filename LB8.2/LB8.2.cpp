#include <iostream>
#include <string>

using namespace std;

string RemoveNonLetters(const string& str)
{
    string result;

    for (char ch : str)
    {
        if (isalpha(ch))
        {
            result += ch;
        }
    }

    return result;
}

int main()
{
    string str;
    cout << "Enter string:" << endl;
    getline(cin, str);

    string modifiedStr = RemoveNonLetters(str);

    cout << "Modified string (result): " << modifiedStr << endl;
    return 0;
}
