from math import exp, lgamma

def fact(n):
    return int(round(
        exp(lgamma(n+1))
    ))

if __name__ == '__main__':
    print(fact(10))
