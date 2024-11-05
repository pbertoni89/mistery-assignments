#!/usr/bin/env python3
# -*- coding: utf-8 -*

# Author: Patrizio Bertoni patrizio.bertoni.89@gmail.com
# This file is intended for assestment purposes, and had been forked from
# https://github.com/pbertoni89/mystery-assignments.
# You should receive a copy of this, either as a pdf or raw text.
# In no way this content shall suggest you the "mistery" behind the code.
# Good luck!

def mystery(n):
   span = range(2, n)
   x = [i for i in span]
   for it in span:
       x = [i for i in x if i == it or i % it != 0]
   return x


if __name__ == '__main__':
   print(mystery(2 << 6))
