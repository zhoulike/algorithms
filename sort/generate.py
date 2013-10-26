#!/usr/bin/env python
# encoding: utf-8

import random

def main():
    dataset_size = (100, 1000, 10000, 50000, 1000000)
    data_min = -1000000
    data_max = 1000000

    for size in dataset_size:
        file_unsorted = "dataset/" + str(size) + "_unsorted.data"
        f_write = open(file_unsorted, "w")
        
        data = []
        for i in range(size):
            data.append(random.randint(data_min, data_max))

        f_write.write('\n'.join(map(str, data)))
        f_write.close()

        file_sorted = "dataset/" + str(size) + "_sorted.data"
        f_sorted = open(file_sorted, "w")
        data.sort()
        f_sorted.write('\n'.join(map(str, data)))
        f_sorted.close()
        
        

if __name__ == '__main__':
    main()
