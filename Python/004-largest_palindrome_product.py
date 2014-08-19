# -*- coding: utf-8 -*-
"""
A palindromic number reads the same both ways.
The largest palindrome made from the product of two 2-digit numbers is

    9009 = 91 × 99.

Find the largest palindrome made from the product of two 3-digit numbers.
"""

def is_palindrome(string):
    """ Brute force algorithm """
    decide, i = 1, 0
    while (i<=int(len(string)/2) and decide==1):
        if string[i] != string[-(i+1)]:
            decide=0
        i+=1
    return decide

def main(digits):
    aux=0
    for i in range(10^(digits-1)+1, 10**digits):
        for j in range(10^(digits-1)+1, 10**digits):
            if (is_palindrome(str(j*i)) and i*j>aux):
                aux=i*j
    return aux

if __name__ == '__main__':
    print(main(3))
