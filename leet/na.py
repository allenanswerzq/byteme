
import string
c = r'\"hello\n\\\"too'
c = c.replace('\\', '^')
print(c)
i = 0
s = ''
while i < len(c):
    if c[i] == '^':
        t = c[i:i+2]
        if t == '^n' or t == '^r' or t == '^t':
            s += t
            i += 3
        else:
            s += c[i+1]
            i += 2
    elif c[i]!='^' and c[i] in string.printable:
        s += c[i]
        i += 1
s = s.replace('^', '\\')
print(s)

