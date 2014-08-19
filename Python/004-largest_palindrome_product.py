# -*- coding: utf-8 -*-
"""
A palindromic number reads the same both ways.
The largest palindrome made from the product of two 2-digit numbers is

    9009 = 91 × 99.

Find the largest palindrome made from the product of two 3-digit numbers.
"""

def is_palindrome(string):
    decide, i = 1, 0
    while (i<=int(len(string)/2) and decide==1):
        if string[i] != string[-(i+1)]:
            decide=0
        i+=1
    return decide

if __name__ == '__main__':
    aux=0
    for k in range(101,1000):
        for j in range(101,1000):
            if (is_palindrome(str(j*k)) and j*k>aux):
                aux=j*k
    print(aux)
