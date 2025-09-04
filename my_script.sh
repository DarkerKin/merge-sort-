#! /bin/bash

pwd

# load python module if needed
module load python


# activate it
source myenv/bin/activate

python3 benchmark.py
