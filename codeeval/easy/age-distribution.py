
import sys
test_cases = open(sys.argv[1], 'r')

distribution = []

def built(start, end, description):
    for i in range(start, end + 1):
        distribution.append(description)

built(0, 2, "Home")
built(3, 4, "Preschool")
built(5, 11, "Elementary school")
built(12, 14, "Middle school")
built(15, 18, "High school")
built(19, 22, "College")
built(23, 65, "Work")
built(66, 100, "Retirement")

for test in test_cases:
    age = int(test)
    if age < 0 or age > 100:
        print "This program is for humans"
    else:
        print distribution[age]

test_cases.close()
