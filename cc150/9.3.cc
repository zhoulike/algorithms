#include <iostream>
#include <vector>

using namespace std;

int findMagic1(vector<int> &vec)
{
    for (int i = 0; i < vec.size(); ++i)
        if (vec[i] == i)
            return i;
    return -1;
}

//find something in sorted array indicates binary search
int findMagic2(vector<int> &vec)
{
    int low = 0, high = vec.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (vec[mid] == mid)
            return mid;
        else if (vec[mid] < mid)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

//we need to search both left and right side, but we can skip some elements
int findMagic3(vector<int> &vec, int low, int high)
{
    if (low < 0 || high >= vec.size() || high < low)
        return -1;

    int mid = low + (high - low) / 2;
    if (vec[mid] == mid)
        return mid;

    //min(vec[mid], mid -1) may skip some elements
    int result = findMagic3(vec, low, min(vec[mid], mid - 1));
    if (result >= 0)
        return result;

    result = findMagic3(vec, max(vec[mid], mid + 1), high);
    if (result >= 0)
        return result;
}

int findMagic3(vector<int> &vec)
{
    return findMagic3(vec, 0, vec.size() - 1);
}

int main(int argc, char *argv[])
{
    vector<int> v = {-1, -2, 0, 1, 4};
    cout << findMagic1(v) << endl
         << findMagic2(v) << endl;
    vector<int> vDup = {-10, -5, 2, 2, 2, 3, 5, 4, 7, 9, 12, 13};
    cout << findMagic3(v) << endl
         << findMagic3(vDup) << endl;
    return 0;
}
