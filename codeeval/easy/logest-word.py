
import sys
test_cases = open(sys.argv[1], 'r')
for test in test_cases:
    max_len = 0
    longest_word = ""
    for word in test.split():
        if len(word) > max_len:
            longest_word = word
            max_len = len(word)
    print longest_word

test_cases.close()
