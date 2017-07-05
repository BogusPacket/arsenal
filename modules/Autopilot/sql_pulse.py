#!/usr/bin/python
import sys, os, re, time, datetime, urllib2, mysql.connector

win64_GoogleChrome = "Mozilla/5.0 (Windows NT 6.3; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/59.0.3071.115 Safari/537.36";
lynx = "Lynx/2.8.8dev.3 lib222-FM2.14 SSL-MM/1.4.1";
url_regex = "([A-Za-z0-9-._~:?#[]@!$&'()*+,;=]+)"
csgo = "https://www.g2a.com/marketplace/product/auctions/?id=94"
headers = {"User-Agent" : lynx}
previous = dict()
iter = 0
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

t = "'"
t += str(datetime.datetime.now())
t += "'"


def prev_check(u, p):
	try:
		test = previous[u]
		if previous[u] != p:
			previous[u] = p
			return 1
		else:
			return 0
	except:
		previous[u] = p
		return 1
def urls_create():
	
while 1:
	t = "'"
        t += str(datetime.datetime.now())
        t += "'"
	TIME_B = COLOR_RESET + "[" + COLOR_MAGENTA + t.split("\'")[1] + COLOR_RESET + "]"
	res = urllib2.Request(csgo, headers=headers)
	sourceFile = urllib2.urlopen(res)
	s = sourceFile.read()
	#print s
	prices = re.findall("(?<=\"f\"\:\").{6}", s);
	users = re.findall("(?<=\"cname\"\:\")[a-zA-Z0-9_@]+", s);
	orderids = re.findall("(?<=\"a\"\:\")\d+", s);
	productID = "94"
	cmd = "mysql --host=127.0.0.1 --user=root --password=choppersrus autopilot -e "
	query = ("\"INSERT INTO G2A_DATA (Time, ID, productid, orderid, sellername, price) VALUES ")
	cmd += query
	#print prices
	#print users
	#print orderids
	i = 0
	while (i < len(prices)):
		fprice = float(prices[i].split("$")[1])
		if prev_check(users[i], fprice):
			orderid = orderids[i]
			user = "\'" + users[i] + "\'"
			price = "\'" + prices[i].split("$")[1] + "\'"
			print price
			values = "(" + t + ", " + "1" + ", " + productID + ", " + str(orderid) + ", " + user + ", " + price + ")\""
			float(prices[i].split("$")[1])
			os.system(cmd + values)
			print TIME_B + SUCCESS_B + "Successfully Inserted New Data! Query:\t" + COLOR_CYAN + query + values + COLOR_RESET
		i += 1
	iter += 1
	print previous
	time.sleep(3)

