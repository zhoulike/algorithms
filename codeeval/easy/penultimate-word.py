#!/usr/bin/env python
# encoding: utf-8

import sys

test_cases = open(sys.argv[1], 'r')
for test in test_cases:
    words = test.split()
    if len(words) >= 2:
        print words[-2]

test_cases.close()
