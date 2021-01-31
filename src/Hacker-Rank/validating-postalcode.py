s = input()
print(s.isdigit() and 100000 <= int(s) <= 999999 and 
      sum([s[i] == s[i+2] for i in range(0, 4)]) < 2)

'''
import re

print(bool(re.match(
    r'^'
    r'(?!.*(.).\1.*(.).\2)'
    r'(?!.*(.)(.)\3\4)'
    r'[1-9]\d{5}'
    r'$', input()
))) '''