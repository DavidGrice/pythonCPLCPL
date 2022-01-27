import re
import pandas as pd

myDict = {"Severity":["High","High","Medium","Low"],"Level":[500, 400, 300, 100], "Animal":["Dog","Cow","Otter","Pig"]}

data = pd.DataFrame(myDict)

# Open file
f = open("inputText.txt",'r',encoding = 'utf-8')

# Read file contents
for line in f:
    first = re.findall(r"[a-zA-Z].+[|]",line)
    second = re.findall(r"[|].*",line)

    first_part = str(first).replace("|","")
    first_part = first_part.replace("[","")
    first_part = first_part.replace("]","")
    first_part = first_part.replace("'","")

    second_part = str(second).replace("|","")
    second_part = second_part.replace("[","")
    second_part = second_part.replace("]","")
    second_part = second_part.replace("'","")
    
    for x in data.values:
        if first_part == str(x[2]):
            print(str(x[0])+" | " + str(x[1]) + " | " + str(x[2]) + " | " + second_part)

# Close File
f.close()