/* 题目描述:
给你一天的Google搜索日志，你怎么设计算法找出是否有一个搜索词，它出现的频率占所有搜索的一半以上？如果肯定有一个搜索词占大多数，你能怎么提高你的算法找到它？再假定搜索日志就是内存中的一个数组，能否有O(1)空间，O(n)时间的算法？
 */

#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::string;
using std::vector;
using std::endl;

template <typename T>
T boyer_moore_majority(vector<T> &vec)
{
	T candidate;
	int count = 0;

	for (typename vector<T>::iterator iter = vec.begin(); iter != vec.end(); ++iter)
	{
		if (count == 0) {
			candidate = *iter;
			count = 1;
		} else if (candidate == *iter)
			++count;
		else
			--count;	
	}

	return candidate;
}

int main(int argc, char *argv[])
{
	int a[] = {1, 2, 3, 2, 4, 2, 1, 2, 2};
	string s[] = {"hello", "world", "hello", "China", "hello"};
	vector<int> ivec(a, a + sizeof(a) / sizeof(a[0]));
	vector<string> svec(s, s + sizeof(s) / sizeof(s[0]));

	cout << "expected: " << 2 << " computed: " << boyer_moore_majority(ivec) << endl;
	cout << "expected: " << "hello" << " computed: " << boyer_moore_majority(svec) << endl;

	return 0;
}
