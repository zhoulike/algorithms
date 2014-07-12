
import sys
test_cases = open(sys.argv[1], 'r')
for test in test_cases:
    info, mine = test.split(';')
    row, column = map(int, info.split(','))
    for val in range(row * column):
        if mine[val] == '*':
            sys.stdout.write('*')
        else:
            i = val / column
            j = val % column
            count = 0
            
            #prev row
            if i - 1 >= 0:
                if j - 1 >= 0 and mine[(i - 1) * column + j - 1] == '*':
                    count += 1
                if mine[(i - 1) * column + j] == '*':
                    count += 1
                if j + 1 < column and mine[(i - 1) * column + j + 1] == '*':
                    count += 1
                    
            #current row
            if j - 1 >= 0 and mine[val - 1] == '*':
                count += 1
            if j + 1 < column and mine[val + 1] == '*':
                count += 1
            
            #next row
            if i + 1 < row:
                if j - 1 >= 0 and mine[(i + 1) * column + j - 1] == '*':
                    count += 1
                if mine[(i + 1) * column + j] == '*':
                    count += 1
                if j + 1 < column and mine[(i + 1) * column + j + 1] == '*':
                    count += 1
                    
            sys.stdout.write(str(count))
    sys.stdout.write('\n')

test_cases.close()
