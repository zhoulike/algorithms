#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <sstream>

using namespace std;

const char* number[10] = {"zero", "one", "two", "three", "four", "five",
                          "six", "seven", "eight", "nine"};
const char* dups[11] = {"", "", "double", "triple", "quadruple", "quintuple",
                        "sextuple", "septuple", "octuple", "nonuple", "decuple"};


queue<int> read_int(string &method)
{
    for (char &ch:  method)
        if (ch == '-')
            ch = ' ';
    istringstream iss(method);
    queue<int> imethod;
    int tmp;
    while (iss >> tmp)
        imethod.push(tmp);
    return imethod;
}

void print(int count, char num)
{
    if (count >= 2 && count <= 10)
        cout << dups[count] << " " << number[num - '0'] << " ";
    else {
        while (count--)
            cout << number[num - '0'] << " ";
    }
}

int main(int argc, char *argv[])
{
    int test_cases;
    cin >> test_cases;
    for (int case_num = 1; case_num <= test_cases; ++case_num) {
        cout << "Case #" << case_num << ": ";

        string phone_number, method;
        cin >> phone_number >> method;
        queue<int> imethod = read_int(method);

        int i = 0;
        while (!imethod.empty()) {
            int remains = imethod.front();
            imethod.pop();

            char prev = ' ';
            int count = 1;
            for (; i < phone_number.size() && remains > 0; ++i, --remains) {
                if (prev == ' ')
                    prev = phone_number[i];
                else if (phone_number[i] == prev)
                    ++count;
                else {
                    print(count, prev);
                    prev = phone_number[i];
                    count = 1;
                }
            }
            print(count, prev);
        }
        cout << endl;
    }
    return 0;
}
