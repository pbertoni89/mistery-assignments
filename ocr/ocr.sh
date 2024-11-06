#!/bin/bash

for f in *; do
	echo ${f}
	tesseract ${f} ${f}
done
