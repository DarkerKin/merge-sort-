#! /bin/bash

echo "starting process"

pwd

# load python module if needed
module load python


python3 benchmark.py

echo "done"