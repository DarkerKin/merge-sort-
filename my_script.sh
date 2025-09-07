#!/bin/bash
#SBATCH --job-name=myjob
#SBATCH --partition=Centaurus
#SBATCH --time=168:00:00
#SBATCH --output=slurm-%j.out
#SBATCH --error=slurm-%j.err
#SBATCH --mem=16G

echo "starting process"

# move to your project directory
cd /users/vjoshi9/itcs-4145/merge-sort- || exit 1
pwd

# compile C++ code
make

# run the compiled code (adjust range so it fits runtime & memory!)
./merge_sort 10 1000000000 10000   # safer upper bound than 1e9

# load Anaconda first
module load anaconda3/2023.09

# create or activate conda environment
if ! conda env list | grep -q "myenv"; then
    echo "Creating conda environment..."
    conda create -y -n myenv python=3.12
    source activate myenv   # safer inside SLURM than "conda activate"
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
