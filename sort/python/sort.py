#!/usr/bin/env python
# encoding: utf-8

import sys
import datetime
import random

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

    def bubble_sort(self, cmp_func):
        self.data_sorted = self.data_unsorted[:]
        i = 1
        while i < self.data_size:
            j = i
            while j > 0:
                if cmp_func(self.data_sorted[j - 1], self.data_sorted[j]) > 0:
                    self.data_sorted[j - 1], self.data_sorted[j] = \
                            self.data_sorted[j], self.data_sorted[j - 1]
                j -= 1
            i += 1

    def selection_sort(self, cmp_func):
        self.data_sorted = self.data_unsorted[:]
        i = 0
        while i < self.data_size:
            tmp_i = i
            j = i + 1
            while j < self.data_size:
                if cmp_func(self.data_sorted[tmp_i], self.data_sorted[j]) > 0:
                    tmp_i = j
                j += 1

            if i != tmp_i:
                self.data_sorted[i], self.data_sorted[tmp_i] = \
                        self.data_sorted[tmp_i], self.data_sorted[i]
            i += 1

    def merge_sort(self, cmp_func):
        def _merge(a, start, mid, end):
            tmp = []
            i = start
            j = mid
            
            while i < mid and j < end:
                if cmp_func(a[i], a[j]) < 0:
                    tmp.append(a[i])
                    i += 1
                else:
                    tmp.append(a[j])
                    j +=1

            if i < mid:
                tmp.extend(a[i:mid])
            else:
                tmp.extend(a[j:end])

            a[start:end] = tmp

        def _merge_sort(a, start, end):
            if (end - start) <= 1:
                return

            mid = (start + end) / 2
            _merge_sort(a, start, mid)
            _merge_sort(a, mid, end)
            _merge(a, start, mid, end)

        self.data_sorted = self.data_unsorted[:]
        _merge_sort(self.data_sorted, 0, self.data_size)

    def quick_sort(self, cmp_func):
        def _quick_sort(a, start, end):
            if (end - start) <= 1:
                return 

            left = start + 1
            right = end - 1
            pos = random.randint(start, end - 1)
            a[start], a[pos] = a[pos], a[start]
            pos = start

            while left <= right:
                if cmp(a[left], a[pos]) <= 0:
                    a[left], a[pos] = a[pos], a[left]
                    pos = left
                    left += 1
                else:
                    a[left], a[right] = a[right], a[left]
                    right -= 1

            _quick_sort(a, start, pos)
            _quick_sort(a, pos + 1, end)

        self.data_sorted = self.data_unsorted[:]
        _quick_sort(self.data_sorted, 0, self.data_size)

    def heap_sort(self, cmp_func):
        def left_child(parent):
            return 2 * parent + 1

        def right_child(parent):
            return 2 * parent + 2

        def heapfy(a, i, size):
            largest_i = i
            #left = left_child(i)
            left = 2 * i + 1     #a bit faster than function call.
            if left < size:
                if cmp(a[largest_i], a[left]) < 0:
                    largest_i = left
            #right = right_child(i)
            right = 2 * i + 2
            if right < size:
                if cmp(a[largest_i], a[right]) < 0:
                    largest_i = right

            if largest_i != i:
                a[i], a[largest_i] = a[largest_i], a[i]
                heapfy(a, largest_i, size)

        #initialize
        self.data_sorted = self.data_unsorted[:]
        heap_size = self.data_size

        #build heap
        i = heap_size / 2
        while i >= 0:
            heapfy(self.data_sorted, i, heap_size)
            i -= 1

        #sort
        while heap_size > 1:
            self.data_sorted[0], self.data_sorted[heap_size - 1] = \
                    self.data_sorted[heap_size - 1], self.data_sorted[0]
            heap_size -= 1
            heapfy(self.data_sorted, 0, heap_size)

        
def small2big(a, b):
    return a - b

def main():
    s = sort()
    s.read_data(sys.argv[1])
    dash = sys.argv[2].rindex('.')
    sort_name = []
    sort_time = []

    start = datetime.datetime.now()
    s.insertion_sort(small2big)
    end = datetime.datetime.now()
    delta = end - start
    sort_name.append('insertion')
    sort_time.append(delta.total_seconds())
    output = sys.argv[2][:dash] + '_insertion' +sys.argv[2][dash:]
    s.write_data(output)

    
    start = datetime.datetime.now()
    s.bubble_sort(small2big)
    end = datetime.datetime.now()
    delta = end - start
    sort_name.append('bubble')
    sort_time.append(delta.total_seconds())
    output = sys.argv[2][:dash] + '_bubble' +sys.argv[2][dash:]
    s.write_data(output)

    start = datetime.datetime.now()
    s.selection_sort(small2big)
    end = datetime.datetime.now()
    delta = end - start
    sort_name.append('selection')
    sort_time.append(delta.total_seconds())
    output = sys.argv[2][:dash] + '_selection' +sys.argv[2][dash:]
    s.write_data(output)

    start = datetime.datetime.now()
    s.merge_sort(small2big)
    end = datetime.datetime.now()
    delta = end - start
    sort_name.append('merge')
    sort_time.append(delta.total_seconds())
    output = sys.argv[2][:dash] + '_merge' +sys.argv[2][dash:]
    s.write_data(output)

    start = datetime.datetime.now()
    s.quick_sort(small2big)
    end = datetime.datetime.now()
    delta = end - start
    sort_name.append('quick')
    sort_time.append(delta.total_seconds())
    output = sys.argv[2][:dash] + '_quick' +sys.argv[2][dash:]
    s.write_data(output)

    start = datetime.datetime.now()
    s.heap_sort(small2big)
    end = datetime.datetime.now()
    delta = end - start
    sort_name.append('heap')
    sort_time.append(delta.total_seconds())
    output = sys.argv[2][:dash] + '_heap' +sys.argv[2][dash:]
    s.write_data(output)

    print "%8s" % '',
    for i in sort_name:
        print "%9s" % i,
    print "\n%8s" % sys.argv[1][sys.argv[1].rindex('/') + 1:sys.argv[1].index('_')],
    for i in sort_time:
        print "%9.4f" % i,
    print ''

if __name__ == '__main__':
    main()
