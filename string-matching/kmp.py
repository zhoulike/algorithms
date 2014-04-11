#!/usr/bin/env python
# encoding: utf-8


def prefix(pattern):
    """compute the prefix of pattern

    :pattern: a string of pattern
    :returns: list that contains the length of the longest prefix of pattern[i]

    """
    m = len(pattern)
    p = [None for i in range(m)]
    p[0] = 0
    curr = 0  # current index in pattern that needs to compare

    for i in range(1, m):
        while curr > 0 and pattern[curr] != pattern[i]:
            curr = p[curr - 1]   # curr - 1 : previous matched index

        if pattern[curr] == pattern[i]:
            curr += 1
        p[i] = curr

    return p


def kmp(text, pattern):
    """KMP algorithm

    :text: a string of text
    :pattern: a string of pattern
    :returns: position in text

    """
    n = len(text)
    m = len(pattern)

    if m > n:
        yield -1

    p = prefix(pattern)
    curr = 0

    for i in range(0, n):
        while curr > 0 and pattern[curr] != text[i]:
            curr = p[curr - 1]

        if pattern[curr] == text[i]:
            curr += 1

        if curr == m:
            yield i - m + 1
            curr = p[curr - 1]


if __name__ == '__main__':
    for i in kmp("aaaaaaab", "aaab"):
        print i

    print "search 'for' in naive.py:"
    for i in kmp(open("naive.py").read(), "for"):
        print i
