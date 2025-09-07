import subprocess
import json
import pandas as pd
import matplotlib.pyplot as plt



subprocess.run(["make"])
time_taken_in_respect_to_array_size = {"size":[],"time elapsed":[]}


for i in range(10,10**9):
    result = subprocess.run(["./merge_sort",str(i)], capture_output=True, text=True)
    time_taken_in_respect_to_array_size["size" ].append(json.loads(result.stdout)["size"])
    time_taken_in_respect_to_array_size["time elapsed"].append(json.loads(result.stdout)["Elapsed time"])

df = pd.DataFrame(data=time_taken_in_respect_to_array_size)
df.plot(kind="line",y="time elapsed",x="size",xlabel='size of the array',ylabel='time taken to sort the array (nanoseconds)')
plt.savefig('benchmark.png')
