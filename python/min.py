import sys
def min(lst):
        ordered = []
        while len(ordered) < 10:
                min = 99999
                for each in lst:
                        if each < min:
                                if each not in ordered:
                                        min = each
                ordered.append(min)
        return ordered

l = []
f = open(sys.argv[1])
for line in f:
        print line
        try:
                l.append(float(line))
        except: break
o = min(l)
for each in o:
        print each
