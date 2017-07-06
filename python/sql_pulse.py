#!/usr/bin/python
import sys, os, re, time, datetime, mysql.connector, urllib2

COLOR_RED	=	"\x1b[31m"
COLOR_GREEN	=	"\x1b[32m"
COLOR_YELLOW	=	"\x1b[33m"
COLOR_BLUE	=	"\x1b[34m"
COLOR_MAGENTA	=	"\x1b[35m"
COLOR_CYAN	=	"\x1b[36m"
COLOR_RESET 	=	"\x1b[0m"

cnx = mysql.connector.connect(user='root', password='choppersrus', host='127.0.0.1', database='autopilot')
cursor = cnx.cursor()

def ITEMS_get_all_G2APIDs():
	q = "SELECT g2a_product_id FROM ITEMS"
	cursor.execute(q)
	pid = []
	for each in cursor:
		id = str(each).split("(")[1]
		id = int(id.split(",)")[0])
		pid.append(id)
	return pid

def G2A_DATA_get_all_sellernames(productid):
	l = []
	q = "SELECT sellername FROM G2A_DATA WHERE productid = " + str(productid)
	cursor.execute(q)
	for each in cursor:
		n = str(each)
		n = n.split("(u\'")[1]
		n = n.split("\',)")[0]
		l.append(n)
	return l

#TODO	def G2A_DATA_update(t, productid, orderid, sellername, price):
def G2A_DATA_update(pid, sellername, price):
	print "SELECT * FROM G2A_DATA WHERE productid = " + str(pid) + " AND sellername = \'" + sellername + "\'"
	#cursor.execute(q)
	#for each in cursor:
	#	print each
		
def g2a_get(pid):
	url = "https://www.g2a.com/marketplace/product/auctions/?id="
	headers = {"User-Agent" : "Lynx/2.8.8dev.3 lib222-FM2.14 SSL-MM/1.4.1"}
	t = str(datetime.datetime.now())
	res = urllib2.Request(url + str(pid), headers=headers)
	sourceFile = urllib2.urlopen(res)
	s = sourceFile.read()
	prices = re.findall("(?<=\"f\"\:\"\$).{5}", s);
	users = re.findall("(?<=\"cname\"\:\")[a-zA-Z0-9_@]+", s);
	d = dict()
	i = 0
	while i < len(prices):
		d[users[i]] = float(prices[i])
		i += 1
	return d

def main():
	p = ITEMS_get_all_G2APIDs()
	dict = g2a_get(94)
	for each in dict:
		print each
if __name__ == "__main__":
	main()
