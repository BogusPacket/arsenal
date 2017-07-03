#!/usr/bin/python
import os, re

f = open("g2a.html", "r")
print os.system("stat g2a.html")
s = f.read(14172)
prices = re.findall("(?<=\"f\"\:\").{6}", s);
users = re.findall("(?<=\"cname\"\:\")[a-zA-Z0-9_@]+", s);
orderid = re.findall("(?<=\"a\"\:\")\d+", s);

print prices
print users
print orderid
