import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt
import numpy as np


barWidth = 0.25
fig = plt.subplots(figsize =(12, 8))

counta=[]
countb=[]
countc=[]

lines=open("output.txt","r+").readlines()
for line in lines:
    line.strip("\n")
    line=[float(i) for i in line.split()]
    counta.append(line[0])
    countb.append(line[1])
    countc.append(line[2])



br1 = np.arange(len(counta))
br2 = [x + barWidth for x in br1]
br3 = [x + barWidth for x in br2]
 

plt.bar(br1, counta, color ='r', width = barWidth,edgecolor ='grey', label ='CountA time')
plt.bar(br2, countb, color ='g', width = barWidth,edgecolor ='grey', label ='CountB time')
plt.bar(br3, countc, color ='b', width = barWidth,edgecolor ='grey', label ='CountC time')
 

plt.xlabel('priorities', fontweight ='bold', fontsize = 15)
plt.ylabel('Time (in seconds)', fontweight ='bold', fontsize = 15)
plt.xticks([r + barWidth for r in range(len(counta))],[0,20,40,60,80,100])
plt.ylim((16,17))
plt.legend()
plt.show()