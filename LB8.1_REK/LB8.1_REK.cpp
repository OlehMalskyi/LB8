#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

bool findStr(char* str, int i)
{
    if (str[i] == '*' && str[i + 1] == '*' && str[i + 2] == '*')
        return true;
    else if (i < strlen(str) - 2)
        return findStr(str, ++i);
    else
        return false;
}

char* Change(char* dest, const char* str, char* t, int i)
{
    if (str[i] != 0)
    {
        if (str[i] == '*' && str[i + 1] == '*' && str[i + 2] == '*')
        {

            if (strlen(t) + 2 < 150)
            {
                strcat_s(t, 150 - strlen(t), "!!");
                return Change(dest, str, t + 2, i + 3);
            }
            else
            {

                exit(EXIT_FAILURE);
            }
        }
        else
        {
            *t++ = str[i++];
            *t = '\0';
            return Change(dest, str, t, i);
        }
    }
    else
    {
        *t = '\0';
        return dest;
    }
}


int main()
{
    char str[101];
    cout << "Enter string:" << endl;
    cin.getline(str, 100);
    char* dest1 = new char[151];
    dest1[0] = '\0';

    char* dest2;
    dest2 = Change(dest1, str, dest1, 0);

    findStr(str, 0) ? cout << "'***' found and will be changed" << endl : cout << "'***' not found" << endl;

    cout << "Modified string (param) : " << str << endl;
    cout << "Modified string (result): " << dest2 << endl;

    delete[] dest1;
    return 0;
}
