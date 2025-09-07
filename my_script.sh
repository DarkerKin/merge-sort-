#!/bin/bash
#SBATCH --job-name=myjob
#SBATCH --partition=Centaurus
#SBATCH --time=00:30:00
#SBATCH --output=slurm-%j.out   # save job output
#SBATCH --error=slurm-%j.err    # save job errors

echo "starting process"

# move to your project directory
cd /users/vjoshi9/itcs-4145/merge-sort- || exit 1
pwd

# load Anaconda
module load anaconda3/2023.09

# create conda environment if it does not exist
if ! conda env list | grep -q "myenv"; then
    echo "Creating conda environment..."
    conda create -y -n myenv python=3.12
    conda activate myenv
    pip install --upgrade pip
    pip install -r requirements.txt
else
    echo "Using existing conda environment..."
    conda activate myenv
fi

# run the program
echo "Running benchmark.py..."
python benchmark.py

echo "done"