
#include "AvoidRoads.cc"

#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <sys/time.h>
#include <vector>


const static double __EPSILON = 1e-9;
static double __time = 0.0;

static void __timer_start()
{
	struct timeval tv;
	if (gettimeofday(&tv, NULL) == 0)
	{
		__time = double(tv.tv_sec) * 1000.0 + double(tv.tv_usec) * 0.001;
	}
}

static double __timer_stop()
{
	double start = __time;
	__timer_start();
	return __time - start;
}


static void __eat_whitespace(std::istream& in)
{
	while (in.good() && std::isspace(in.peek())) in.get();
}


std::ostream& operator << (std::ostream& out, const std::string& str)
{
	out << '"' << str.c_str() << '"';
	return out;
}

template <class T>
std::ostream& operator << (std::ostream& out, const std::vector<T>& vec)
{
	out << '{';
	if (0 < vec.size())
	{
		out << vec[0];
		for (size_t i = 1; i < vec.size(); ++i) out << ", " << vec[i];
	}
	out << '}';
	return out;
}

std::istream& operator >> (std::istream& in, std::string& str)
{
	__eat_whitespace(in);

	int c;
	if (in.good() && (c = in.get()) == '"')
	{
		std::ostringstream s;
		while (in.good() && (c = in.get()) != '"')
		{
			s.put(char(c));
		}
		str = s.str();
	}

	return in;
}

template <class T>
std::istream& operator >> (std::istream& in, std::vector<T>& vec)
{
	__eat_whitespace(in);

	int c;
	if (in.good() && (c = in.get()) == '{')
	{
		__eat_whitespace(in);
		vec.clear();
		while (in.good() && (c = in.get()) != '}')
		{
			if (c != ',') in.putback(c);

			T t;
			in >> t;
			__eat_whitespace(in);

			vec.push_back(t);
		}
	}

	return in;
}


template <class T>
bool __equals(const T& actual, const T& expected)
{
	return actual == expected;
}

bool __equals(double actual, double expected)
{
	if (std::abs(actual - expected) < __EPSILON)
	{
		return true;
	}
	else
	{
		double minimum = std::min(expected * (1.0 - __EPSILON), expected * (1.0 + __EPSILON));
		double maximum = std::max(expected * (1.0 - __EPSILON), expected * (1.0 + __EPSILON));
		return actual > minimum && actual < maximum;
	}
}

bool __equals(const std::vector<double>& actual, const std::vector<double>& expected)
{
	if (actual.size() != expected.size())
	{
		return false;
	}

	for (size_t i = 0; i < actual.size(); ++i)
	{
		if (!__equals(actual[i], expected[i]))
		{
			return false;
		}
	}

	return true;
}


int main(int argc, char* argv[])
{
	bool	__abort_on_fail = false;
	int	__pass = 0;
	int	__fail = 0;

	if (1 < argc) __abort_on_fail = true;

	std::cout << "TAP version 13" << std::endl;
	std::cout.flush();

	std::ifstream __in("testcases.txt");
	for(;;)
	{
		int __testnum = __pass + __fail + 1;

		long long	__expected;
		int	width;
int	height;
vector <string>	bad;

		__in >> __expected >> width >> height >> bad;
		if (!__in.good()) break;

		std::cout << "# input for test " << __testnum << ": " << width << ", " << height << ", " << bad << std::endl;
		std::cout.flush();

		__timer_start();

		AvoidRoads __object;
		long long __actual = __object.numWays(width, height, bad);

		double __t = __timer_stop();

		std::cout << "# test completed in " << __t << "ms" << std::endl;
		std::cout.flush();

		if (__equals(__actual, __expected))
		{
			std::cout << "ok";
			++__pass;
		}
		else
		{
			std::cout << "not ok";
			++__fail;
		}

		std::cout << " " << __testnum << " - " << __actual << " must equal " << __expected << std::endl;
		std::cout.flush();

		if (__abort_on_fail && 0 < __fail) std::abort();
	}

	std::cout << "1.." << (__pass + __fail) << std::endl
		  << "# passed: " << __pass << std::endl
		  << "# failed: " << __fail << std::endl;

	if (__fail == 0)
	{
		std::cout << std::endl
			  << "# Nice! Don't forget to compile remotely before submitting." << std::endl;
	}

	return __fail;
}

// vim:ft=cpp:noet:ts=8
