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

#build a virtual environment
python3 -m venv virtual-environment

#use the virtual environment
source virtual-environment/bin/activate

#install all packages 
pip install -r requirements.txt

#run the program
python3 benchmark.py

#notify when done
echo "done"