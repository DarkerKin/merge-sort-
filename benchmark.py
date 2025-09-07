import pandas as pd
import matplotlib.pyplot as plt
import json

# Read results from file
results = []
with open("results.jsonl", "r") as f:
    for line in f:
        try:
            results.append(json.loads(line))
        except json.JSONDecodeError:
            continue  # skip bad lines if any

# Convert to DataFrame
df = pd.DataFrame(results)

# Plot
ax = df.plot(
    kind="line",
    x="size",
    y="Elapsed time",
    xlabel="Size of the array",
    ylabel="Time taken to sort the array (nanoseconds)",
    title="Merge Sort Benchmark",
    legend=False
)

plt.tight_layout()
plt.savefig("benchmark_plot.png")
plt.show()