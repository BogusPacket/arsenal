#!/usr/bin/python
import sys, os, re, mysql.connector, urllib2

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
def G2A_DATA_update(productid, sellername):
	q = "SELECT * FROM G2A_DATA WHERE productid = " + str(productid) + " AND sellername = \'" + sellername + "\'"
	cursor.execute(q)
	for each in cursor:
		print each

def main():
	p = 94
	sellernames = G2A_DATA_get_all_sellernames(94)
	i = 0
	while i < len(sellernames):
		G2A_DATA_update(p, sellernames[i])
		i += 1
if __name__ == "__main__":
	main()

