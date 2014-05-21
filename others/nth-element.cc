#include <vector>
#include <iostream>
#include <cstdlib>

using namespace std;

template <typename T>
T partition(T first, T last)
{
    // [first, last)
    if (first >= last)
        return first;

    --last;
    swap(*last, *(last - rand() % (last - first)));  //randomize
    
    //pointer to elements less and equal than povit
    T less = first - 1;
    while (first != last) {
        if (*first <= *last)  //*last is pivot
            swap(*(++less), *first);
        ++first;
    }
    swap(*(++less), *last);
    return less;
}

template <typename T>
T randomized_select(T first, T last, int n)
{
    if (first == last - 1)
        return first;

    auto iter = partition(first, last);
    size_t elements = iter - first + 1;
    if (elements == n)
        return iter;
    else if (elements > n)
        return randomized_select(first, iter, n);
    else
        return randomized_select(iter + 1, last, n - elements);
}

template <typename T>
T nth_element(vector<T>& vec, int n)
{
    return *randomized_select(vec.begin(), vec.end(), n);
}

template <typename T>
T median(vector<T>& vec)
{
    if (vec.size() % 2 == 0)
        return nth_element(vec, vec.size() / 2);
    else
        return nth_element(vec, vec.size() / 2 + 1);
}

int main(int argc, char *argv[])
{
    vector<int> ivec = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (auto item: ivec)
        cout << item << " ";
    cout << endl;

    cout << "median: " << median(ivec) << endl;
    for (int i = 1; i <= ivec.size(); ++i)
        cout << i << "th element: " << nth_element(ivec, i) << endl;

    return 0;
}
