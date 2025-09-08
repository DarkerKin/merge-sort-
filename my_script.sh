#!/bin/bash
#SBATCH --job-name=myjob
#SBATCH --partition=Centaurus
#SBATCH --time=168:00:00
#SBATCH --output=slurm-%j.out
#SBATCH --error=slurm-%j.err
#SBATCH --mem=16G

echo "starting process"

#clear response.jsonl
> response.jsonl

# move to your project directory
cd /users/vjoshi9/itcs-4145/merge-sort- || exit 1
pwd

# compile C++ code
make

# run the compiled code 
./merge_sort 10 100000 10000   

# load Anaconda first
module load anaconda3/2023.09

# create or activate conda environment
if ! conda env list | grep -q "myenv"; then
    echo "Creating conda environment..."
    conda create -y -n myenv python=3.12
    source activate myenv   
    pip install --upgrade pip
    pip install -r requirements.txt
else
    echo "Using existing conda environment..."
    source activate myenv
fi

# run Python plotting script
echo "Running benchmark.py..."
python benchmark.py

echo "done benchmarking"
