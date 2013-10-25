#!/usr/bin/env python
# encoding: utf-8

import sys

class sort():
    """A sort class with many different sorting algorithms"""

    def __init__(self):
        self.data_unsorted = []
        self.data_sorted = []
        self.data_size = 0

    def read_data(self, name):
        """read unsorted data from file"""
        fread = open(name)
        self.data_unsorted = map(int, fread.read().split())
        self.data_size = len(self.data_unsorted)
        fread.close()

    def write_data(self, name):
        """write sorted data to file"""
        fwrite = open(name, 'w')
        fwrite.write('\n'.join(map(str, self.data_sorted)))
        fwrite.close()

    def insertion_sort(self, cmp_func):
        self.data_sorted = self.data_unsorted[:]
        i = 1
        while i < self.data_size:
            tmp = self.data_sorted[i]
            j = i
            while j > 0 and cmp_func(self.data_sorted[j - 1], tmp) > 0:
                self.data_sorted[j] = self.data_sorted[j - 1]
                j -= 1
            self.data_sorted[j] = tmp
            i += 1
        
def small2big(a, b):
    return a - b

def main():
    s = sort()
    s.read_data(sys.argv[1])
    s.insertion_sort(small2big)
    #print s.data_sorted
    s.write_data(sys.argv[2] + '_insertion')
    

if __name__ == '__main__':
    main()
