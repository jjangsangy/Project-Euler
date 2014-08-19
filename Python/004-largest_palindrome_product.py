# -*- coding: utf-8 -*-
"""
A palindromic number reads the same both ways.
The largest palindrome made from the product of two 2-digit numbers is

    9009 = 91 × 99.

Find the largest palindrome made from the product of two 3-digit numbers.
"""

def is_palindrome(string):
    if string[::-1] == string:
        return True
    else:
        return False

def main(digits):
    """ Brute force algorithm"""
    solution = 0
    for i in range(10*(digits-1)+1, 10**digits):
        for j in range(10*(digits-1)+1, 10**digits):
            if (is_palindrome(str(j*i)) and i*j>solution):
                solution=i*j
    return solution

if __name__ == '__main__':
    print(main(3))
