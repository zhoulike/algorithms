
import sys

coins = [1, 3, 5]
minimum = [0]

test_cases = open(sys.argv[1], 'r')
for test in test_cases:
    coin = int(test)
    if coin < 0:
        continue
    while coin >= len(minimum):
        minimum.append(sys.maxint)
        curr = len(minimum) - 1
        for i in coins:
            if curr - i >= 0:
                minimum[curr] = min(minimum[curr], minimum[curr - i] + 1)
    print minimum[coin]

test_cases.close()
