import pandas as pd
import numpy as np
import random
import sys

random.seed(42)

if len(sys.argv) < 3:
    print("Not Enough Arguments")
    sys.exit()

input_file = sys.argv[1]
output_file = sys.argv[2]

print("Loading : ",input_file)
df = pd.read_csv(input_file, header=None,delimiter=' ')

df    = df[[1,2]] -1
df = df.sample(frac=1,random_state=42)

print("Outputing csv : ",output_file)
df.to_csv(output_file,sep=',',index=False,index_label=False,header=False)
