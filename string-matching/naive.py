#!/usr/bin/env python
# encoding: utf-8


def naive(text, pattern):
    """naive string search algorithm

    :text: a string of text
    :pattern: a string of pattern
    :returns: position in text

    """
    n = len(text)
    m = len(pattern)

    if m > n:
        yield -1

    for i in range(0, n - m + 1):
        j = 0
        while j < m:
            if text[i + j] != pattern[j]:
                break
            j += 1

        if j == m:
            yield i

if __name__ == '__main__':
    for i in naive("aaaaaaab", "aaab"):
        print i

    print "searching 'for' in naive.py:"
    for i in naive(open("naive.py").read(), "for"):
        print i
