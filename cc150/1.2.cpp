#include <iostream>
#include <cstring>

using namespace std;

/*time: O(n), space: O(n)*/
char* reverse(const char *str)
{
    if (str == NULL)
        return NULL;

    int len = strlen(str);
    char *ret = new char[len + 1];
    ret[len] = '\0';

    char *p = ret + len - 1;
    while (p >= ret)
        *p-- = *str++;

    return ret;
}

/*time: O(n), space: O(1)*/
void reverse2(char *str) 
{
    if (str == NULL)
        return;

    int len = strlen(str);
    char *p = str, *q = str + len - 1;
    
    while (p < q) {
        swap(*p, *q);
        ++p;
        --q;
    }
}

int main(int argc, char *argv[])
{
    cout << "NULL string -> " << (reverse(NULL) == NULL? "NULL": "non-NULL") << endl;
    cout << "a -> " << reverse("a") << endl;
    cout << "ab -> " << reverse("ab") << endl;
    cout << "abc -> " << reverse("abc") << endl;
    cout << "abcd -> " << reverse("abcd") << endl;
    cout << "abcdefg -> " << reverse("abcdefg") << endl;

    char *null = NULL;
    char a[] = "a",
         ab[] = "ab",
         abc[] = "abc",
         abcd[] = "abcd",
         abcdefg[] = "abcdefg";

    reverse2(null);
    reverse2(a);
    reverse2(ab);
    reverse2(abc);
    reverse2(abcd);
    reverse2(abcdefg);
    //reverse2("segment fault!"); // cannot call reverse2 like this

    cout << a << endl
         << ab << endl
         << abc << endl
         << abcd << endl
         << abcdefg << endl;

    return 0;
}
