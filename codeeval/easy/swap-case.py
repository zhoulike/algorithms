#!/usr/bin/env python
# encoding: utf-8

import sys
test_cases = open(sys.argv[1], 'r')
for test in test_cases:
    print test.swapcase(),

test_cases.close()
