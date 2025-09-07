#! /bin/bash
#SBATCH --job-name=myjob
#SBATCH --partition=Centaurus
#SBATCH --time=00:30:00
$HOME/myprogram

#starting the process
echo "starting process"

#which directory
pwd

# load python module if needed
module load python

#run the program
python3 benchmark.py

#notify when done
echo "done"