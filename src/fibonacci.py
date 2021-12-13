#!/usr/bin/env python3
# -*- coding: utf-8 -*


def mystery(n):
   span = range(2, n)
   x = [i for i in span]
   for it in span:
       x = [i for i in x if i == it or i % it != 0]
   return x


if __name__ == '__main__':
   print(mystery(2 << 6))
