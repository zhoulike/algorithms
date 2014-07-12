#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main(int argc, char *argv[])
{
    int test_cases;
    cin >> test_cases;

    for (int case_num = 1; case_num <= test_cases; ++case_num) {
        cout << "Case #" << case_num << ": ";

        int num;
        cin >> num;
        vector<int> books, alex, bob;
        while (num--) {
            int worth;
            cin >> worth;
            books.push_back(worth);
        }

        for (int worth: books) {
            if (worth % 2 == 0)
                bob.push_back(worth);
            else
                alex.push_back(worth);
        }
        sort(alex.begin(), alex.end());
        sort(bob.begin(), bob.end(), greater<int>());

        int i = 0, j = 0;
        for (int worth: books) {
            if (worth % 2 == 0)
                cout << bob[i++] << " ";
            else
                cout << alex[j++] << " ";
        }
        cout << endl;
    }
    return 0;
}
