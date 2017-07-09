#!/usr/bin/python
import sys, os, re, time, datetime,  cymysql, urllib2, threading, Queue

COLOR_RED	=	"\x1b[31m"
COLOR_GREEN	=	"\x1b[32m"
COLOR_YELLOW	=	"\x1b[33m"
COLOR_BLUE	=	"\x1b[34m"
COLOR_MAGENTA	=	"\x1b[35m"
COLOR_CYAN	=	"\x1b[36m"
COLOR_RESET 	=	"\x1b[0m"
SUCCESS_B = COLOR_RESET + "[" + COLOR_GREEN + "+" + COLOR_RESET + "]"
INFO_B = COLOR_RESET + "[" + COLOR_BLUE + "+" + COLOR_RESET + "]"
ERROR_B = COLOR_RESET + "[" + COLOR_RED + "+" + COLOR_RESET + "]"

cnx = cymysql.connect(user='root', passwd='choppersrus', host='127.0.0.1', db='autopilot')
cursor = cnx.cursor()

def refineStr(s):
	s = s.split("(\'")[1]
	s = s.split("\',)")[0]
	return s

def ITEMS_get_name(pid):
	q = "SELECT DISTINCT name FROM ITEMS WHERE g2a_product_id = " + str(pid)
	cursor.execute(q)
	r = refineStr(str(cursor.fetchall()[0]))
	return r

def G2A_DATA_MAX_ROW():
	q = "SELECT MAX(row) FROM G2A_DATA"
	cursor.execute(q)
	r = str(cursor.fetchall()[0])
	r = r.split("(")[1]
	r = int(r.split("L,)")[0])
	r += 1
	return str(r)
def ITEMS_get_all_G2APIDs():
	q = "SELECT g2a_product_id FROM ITEMS"
	cursor.execute(q)
	pid = []
	for each in cursor:
		id = str(each).split("(")[1]
		id = int(id.split("L,)")[0])
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

#TODO	def G2A_DATA_update(str(), int(), int(), str(), float()):
def G2A_DATA_update(d):
	while 1:
		update = d.get()
		cursor.execute("SELECT MAX(row) FROM G2A_DATA WHERE productid = "	+	update["Product ID"])
		l = cursor.fetchall()
		r = str(l[0])
		r = r.split("(")[1]
		r = r.split(",)")[0]
		if r != "None":
			cursor.execute("SELECT lowest_price FROM G2A_DATA WHERE row = "		+	r)
			prev_price = str(cursor.fetchall()[0])
			prev_price = prev_price.split("(")[1]
			prev_price = prev_price.split(",)")[0]
			if prev_price != update['Price']:
				row = G2A_DATA_MAX_ROW()
				query = ("INSERT INTO G2A_DATA (row, time, productid, name, orderid, lowest_price, seller_name) VALUES ")
				query += "(" + row + ", "
				query += "'" + update["Time"] + "\', "
				query += update['Product ID'] + ", "
				query += "'" + update["Name"] + "\', "
				query += update['Order ID'] + ", "
				query += update['Price'] + ", "
				query += "'" + update["Seller"] + "\')"
				print(SUCCESS_B + query)
				print(cursor.execute(query))
		else:
			query = ("INSERT INTO G2A_DATA (row, time, productid, name, orderid, lowest_price, seller_name) VALUES ")
			row
			query += "(" + G2A_DATA_MAX_ROW() + ", "
			query += "'" + update["Time"] + "\', "
			query += update['Product ID'] + ", "
			query += "'" + update["Name"] + "\', "
			query += update['Order ID'] + ", "
			query += update['Price']  + ", "
			query += "\'" + update["Seller"] + "\')"
			print(cursor.execute(query))
	cnx.commit()
	print("Committed!")
'''
	for r in rows:
		cursor.execute("SELECT sellername, price FROM G2A_DATA WHERE row = " + r)
		l = cursor.fetchall()
		name = str(l[0])
		name = name.split(", ")[0]
		name = name.split("u\'")[1]
		name = name.split("'")[0]
		price = str(l[0])
		price = price.split(", ")[1]
		price = float(price.split(")")[0])
		if (d[name] == price):
			print("Voiding Unchanged Price: {" + name + " : " + price + "}")
			return
'''

def g2a_get(pid_q, dict_q):
	result = []
	pids = []
	while not pid_q.empty():
		pid = pid_q.get()
		url = "https://www.g2a.com/marketplace/product/auctions/?id="
		headers = {"User-Agent" : "Lynx/2.8.8dev.3 lib222-FM2.14 SSL-MM/1.4.1"}
		t = str(datetime.datetime.now())
		try:
			sourceFile = urllib2.urlopen(url + str(pid), timeout=1)
		except:
			
			continue
		s = sourceFile.read()
		sourceFile.close()
		prices = re.search(r"(?<=\"lowest_price\"\:\")([0-9]+\.[0-9]+)", s, re.M | re.I)
		users = re.search(r"(?<=\"cname\"\:\")[a-zA-Z0-9_@]+", s, re.M | re.I)
		orderids = re.search(r"(?<=\"a\"\:\")\d+", s, re.M | re.I)

		print(INFO_B + prices.group())
		print(INFO_B + users.group())
		print(INFO_B + orderids.group())

		d = dict()
		d["Time"] = t
		d["Product ID"] = str(pid)
		d["Name"] = ITEMS_get_name(pid)
		d["Order ID"] = orderids.group()
		d["Seller"] = users.group()
		d["Price"] = prices.group()
		dict_q.put(d)
def main():
	ITEMS_get_name(94)
	p = ITEMS_get_all_G2APIDs()
	dicts = []
	print(COLOR_MAGENTA + "Sending Requests..." + COLOR_RESET)
	pid_q = Queue.Queue()
	dict_q = Queue.Queue()
	for each in p:
		pid_q.put(each)
	processes = []
	i = 0
	while i < 20:
		process = threading.Thread(target=g2a_get, args=[pid_q, dict_q])
		process.setDaemon(True)
		process.start()
		i += 1
	G2A_DATA_update(dict_q)
if __name__ == "__main__":
	main()
