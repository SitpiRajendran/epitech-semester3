#!/usr/bin/env python3
##
## EPITECH PROJECT, 2020
## CNA_groundhog_2019
## File description:
## main
##

import sys
import math

def mess(temp, boucle):
    if (len(temp) <= boucle + 1):
        return ""
    try:
        a =  round((temp[-1] / temp[-1-boucle] - 1) * 100)
        b =  round((temp[-2] / temp[-2-boucle] - 1) * 100)
    except (ValueError, FloatingPointError, ZeroDivisionError, TypeError):
        return ""
    if (abs(a+b) != abs(b)+abs(a)):
        return "\ta switch occurs"
    return ""

def print_h():
    print("SYNOPSIS")
    print("\t./groundhog period")
    print("\nDESCRIPTION")
    print("\tperiod\tthe number of days defining a period")

def calcul_s(temp, boucle):
    if (len(temp) < boucle):
        return "nan"
    moy = sum(temp[-boucle:]) / boucle
    i = 0
    tot = 0
    while i != boucle:
        tot += (temp[len(temp) - boucle + i] - moy)**2
        i += 1
    return format(round(math.sqrt(tot / boucle), 2), '0.2f')

def calcul_r(temp, boucle):
    if (len(temp) <= boucle):
        return "nan"
    a = temp[len(temp) - boucle - 1]
    if a == 0:
        return "man"
    return round(((temp[-1] - a) / a)* 100)

def calcul_g(temp, boucle):
    if (len(temp) <= boucle):
        return "nan"
    g = 0
    top = 0
    count = len(temp) - boucle
    while count != len(temp):
        top = temp[count] - temp[count-1]
        if (top < 0):
            top = 0
        g += top
        count += 1
    return format(round(g/boucle, 2), '0.2f')

def calcul_weird(temp, boucle, s):
    if (len(temp) <= boucle):
        return [temp[-1], 0]
    size = len(temp)
    diff = abs(temp[size-1] - temp[size-2])
    percent = diff / float(s)
    if (percent >= 2):
        percent = 0
    return [temp[-1], round(percent, 2)]

def get_weird(weird):
    weird.sort(key = lambda x : x[1], reverse=True)
    return weird[:5]

def args_handle():
    if (len(sys.argv) != 2):
        print_h()
        exit (84)
    if (sys.argv[1] == "-h"):
        print_h()
        exit (0)
    try:
        int(sys.argv[1])
    except ValueError:
        print("That's not a number !")
        exit (84)
    a = int(sys.argv[1])
    if a <= 0:
        print("That's not a valid number !")
        exit (84)
    return a

def main():
    boucle = args_handle()
    try:
        arg = input()
    except (EOFError, KeyboardInterrupt):
        exit (84)
    temp = []
    weird = []
    r = 0
    switch = 0
    while (arg != "STOP"):
        try:
            float(arg)
        except (ValueError, TypeError):
            print("That's not a number !")
            exit (84)
        temp.append(float(arg))
        if (boucle != 0):
            g = calcul_g(temp, boucle)
            r = calcul_r(temp, boucle)
            message = mess(temp, boucle)
            s = calcul_s(temp, boucle)
            weird.append(calcul_weird(temp, boucle, s))
        else:
            g = "man"
            r = "man"
            s = "man"
        if (message != ""):
            switch += 1
        print("g=" + str(g) + "\tr=" + str(r) + "%\ts="+ str(s) + message)
        try:
            arg = input()
        except (EOFError, KeyboardInterrupt):
            exit (84)
    if (len(temp) <= boucle):
        print("Not enought numbers")
        exit(84)
    print("Global tendency switched " + str(switch) + " times")
    five_weird = get_weird(weird)
    print("5 weirdest values are [", end="")
    i = 0
    while i < 5:
        print(five_weird[i][0], end="")
        if i < 4:
            print(", ", end="")
        i += 1
    print("]")
    return 0

if __name__ == "__main__":
    main()