#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void output(vector<int> &prev, int n) 
{
	if (n == 0)
		return;

	output(prev, prev[n]);
	cout << n << " ";
}

int minPenalty(vector<int> hotel)
{
	hotel.insert(hotel.begin(), 0); //add start point
	vector<int> penalty(hotel.size(), INT_MAX);
	vector<int> prev(hotel.size(), 0);
	penalty[0] = 0;

	for (int i = 1; i < penalty.size(); ++i) {
		for (int j = i - 1; j >= 0 && hotel[i] - hotel[j] <= 200; --j) {
			int tmp = penalty[j] + (200 - hotel[i] + hotel[j]) * (200 - hotel[i] + hotel[j]);	
			if (tmp < penalty[i]) {
				penalty[i] = tmp;
				prev[i] = j;
			}
		}
	}

	output(prev, prev.size() - 1);
	cout << endl;

	return penalty.back();
}

int main(int argc, char *argv[])
{
	int a[] = {50, 150, 300, 450, 500};
	vector<int> v(a, a + 5);
	vector<int> empty;
	vector<int> one;
	one.push_back(50);
	
	cout << minPenalty(v) << endl;
	cout << minPenalty(empty) << endl;
	cout << minPenalty(one) << endl;
	return 0;
}
