#!/bin/bash

gcc 2.c -o 2.out -lm
start=$(date +%s%N)
cat input.txt | ./2.out
end=$(date +%s%N)
time_ns=$((end - start))
time_ms=$(echo "scale=3; $time_ns / 1000000" | bc)
echo "execution time: $time_ns ns"
echo "execution time: $time_ms ms"
