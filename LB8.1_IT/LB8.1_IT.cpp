#include <iostream>
#include <cstring>

using namespace std;

bool findStr(char* str)
{
    for (int i = 0; i < strlen(str) - 2; i++)
        if (str[i] == '*' && str[i + 1] == '*' && str[i + 2] == '*')
            return true;
    return false;
}

char* Change(char* str)
{
    if (strlen(str) < 3)
        return str;
    char* tmp = new char[101];
    char* t = tmp;

    tmp[0] = '\0';
    int i = 0;

    while (str[i] != 0)
    {
        if (str[i] == '*' && str[i + 1] == '*' && str[i + 2] == '*')
        {
            strcat_s(t, 101, "!!");
            t += 2;
            i += 3;
        }
        else
        {
            *t++ = str[i++];
            *t = '\0';
        }
    }
    *t = '\0';

    return tmp;
}

int main()
{
    char str[101];
    cout << "Enter string:" << endl;
    cin.getline(str, 100);

    char* dest = Change(str);

    findStr(str) ? cout << "'***' found and will be changed" << endl : cout << "'***' not found" << endl;

    cout << "Modified string (param): " << str << endl;
    cout << "Modified string (result): " << dest << endl;

    return 0;
}
