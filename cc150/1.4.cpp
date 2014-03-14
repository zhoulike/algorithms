#include <iostream>
#include <cstring>

using namespace std;

int replaceSpace(char s[], int n)
{
    int len = strlen(s);
    if (len == 0)
        return 0;

    int spaces = 0, i = 0;
    while(s[i] != '\0')
        if (s[i++] == ' ')
            ++spaces;

    if (len + spaces * 2 + 1 > n) //assure enough space, includes '\0'
        return -1;

    //p includes '\0', 1 space->3 characters
    char *p = s + len, *q = s + len + spaces * 2; 
    while (p >= s) {
        if (*p == ' ') {
            *q-- = '0';
            *q-- = '2';
            *q-- = '%';
            --p;
        } else
            *q-- = *p--;
    }

    return len;
}

int main(int argc, char *argv[])
{
    char a[100];
    strcpy(a, "Mr John Smith");
    cout << replaceSpace(a, 100) << " real characters" << endl;
    cout << a << endl;
    return 0;
}
