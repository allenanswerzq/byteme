#/usr/bin/env python
def letterCombinations(digits):
    if '' == digits: return []
    maps = {
        '2': 'abc',
        '3': 'def',
        '4': 'ghi',
        '5': 'jkl',
        '6': 'mno',
        '7': 'pqrs',
        '8': 'tuv',
        '9': 'wxyz'
    }
    # NOTE: reduce function initial value be placed before the sequences
    # i.e.: "23" turns into `['']23`
    return reduce(lambda acc, digit: [x + y for x in acc for y in maps[digit]], digits, [''])

if __name__ == "__main__":
    print letterCombinations("23")
