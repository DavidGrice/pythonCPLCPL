# Open file
f = open("inputText.txt",'r',encoding = 'utf-8')

# Read file contents
for line in f:
    print(line, end = '')

# Close File
f.close()