#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

bool findStr(char* str) {
    int pos = 0;
    char* t;
    while (t = strchr(str + pos, '*')) {
        pos = t - str + 1;
        if (str[pos] == '*' && str[pos + 1] == '*')
            return true;
    }
    return false;
}

char* Change(char* s) {
    size_t newSize = strlen(s) + 1;
    char* t = new char[newSize];
    char* p;
    int pos1 = 0, pos2 = 0;
    *t = 0;

    while (p = strstr(s + pos1, "***")) {
        pos2 = p - s;
        strncat_s(t, newSize, s + pos1, static_cast<rsize_t>(pos2) - pos1);
        strcat_s(t, newSize, "!!");
        pos1 = pos2 + 3;
    }

    strcat_s(t, newSize, s + pos1);
    return t;
}



int main() {
    char str[101];
    cout << "Enter string:" << endl;
    cin.getline(str, 100);

    if (findStr(str)) {
        char* dest = Change(str);
        cout << "'***' found and will be changed" << endl;
        cout << "Modified string (param) : " << str << endl;
        cout << "Modified string (result): " << dest << endl;
        delete[] dest;
    }
    else {
        cout << "'***' not found" << endl;
    }

    return 0;
}