#include <iostream>
#include <vector>

using namespace std;

int maxSubsequence(vector<int> &seq)
{
	vector<int> sum(seq.size() + 1);
	sum[0] = 0;

	for (int i = 1; i < sum.size(); ++i)
		sum[i] = max(seq[i - 1], sum[i - 1] + seq[i - 1]);

	return sum.back();
}

int main(int argc, char *argv[])
{
	int a[] = {5, 15, -30, 10, -5, 40, 10};
	vector<int> v(a, a + 7);
	vector<int> empty;
	vector<int> one;
	one.push_back(-1);

	cout << maxSubsequence(v) << endl
		 << maxSubsequence(empty) << endl
		 << maxSubsequence(one) << endl;
	return 0;
}
