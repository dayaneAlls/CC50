import sys
import csv

if len(sys.argv) != 3:
    print("Usage: python dna.py data.csv sequence.txt")
    sys.exit(1)
counts, data = [], {}

with open(sys.argv[2], "r") as txtfile:
    strs = txtfile.read()

with open(sys.argv[1], "r") as csvfile:
    dnas = csvfile.readline()
    dnas = dnas[5:-1].split(",")
    reader = csv.reader(csvfile)
    data = {rows[0]:rows[1:4] for rows in reader}

for i in range(len(dnas)):
    counts.append(str(strs.count(dnas[i])))

for key, value in data.items():
    if value == counts:
        print(key)
    else:
        print("No match")
        break

sys.exit(0)
