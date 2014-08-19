# -*- coding: utf-8 -*-
"""
A palindromic number reads the same both ways.
The largest palindrome made from the product of two 2-digit numbers is

    9009 = 91 × 99.

Find the largest palindrome made from the product of two 3-digit numbers.
"""

def is_palindrome(string):
    """ Brute force algorithm """
    i, palindrome = 0, True
    while i<=int(len(string)/2) and palindrome == True:
        if string[i] != string[-(i+1)]:
            palindrome = False
        i+=1
    return palindrome

def main(digits):
    sol = 0
    for i in range(10*(digits-1)+1, 10**digits):
        for j in range(10*(digits-1)+1, 10**digits):
            if (is_palindrome(str(j*i)) and i*j>sol):
                sol=i*j
    return sol

if __name__ == '__main__':
    print(main(3))
