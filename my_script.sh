#! /bin/bash


# load python module if needed
module load python

# make a new venv (only once)
python3 -m venv myenv

# activate it
source myenv/bin/activate

pip install -r requirements.txt

python3 benchmark.py
