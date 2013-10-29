#!/usr/bin/env python
# encoding: utf-8
import random


def binary_search(a, size, value):
    low = 0
    high = size - 1

    while low <= high:
        mid = (low + high) / 2
        if a[mid] > value:
            high = mid - 1
        elif a[mid] < value:
            low = mid + 1
        else:
            return mid

    return -1


def test(a, size, value):
    if binary_search(a, size, value) < 0:
        print "cannot find %d" % value
    else:
        print "find %d" % value


def main():
    size = 100000
    data_min = -1000000
    data_max = 1000000
    data = []

    for i in range(size):
        data.append(random.randint(data_min, data_max))
    data.sort()

    test(data, size, -1000000)
    test(data, size, 1000000)
    test(data, size, -10000000)
    test(data, size, 10000000)
    test(data, size, random.randint(data_min, data_max))
    value = random.randint(0, size - 1)
    test(data, size, data[value])
    value = random.randint(0, size - 1)
    test(data, size, data[value])

if __name__ == '__main__':
    main()
