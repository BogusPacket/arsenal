#!/usr/bin/python
import os, sys, time, urllib2, re

url = "https://www.g2a.com/lucene/search/filter"
url += "?jsoncallback=jQuery1110038484328661451217_1499201833508&skip=28837%2C28838%2C28847%2C28849%2C28852%2C28856%2C28857%2C28858%2C28859%2C28860%2C28861%2C28862%2C28863%2C28867%2C28868%2C29472%2C29473%2C29474%2C33104"
url += "&minPrice=0.00&maxPrice=1200.00&cn=&stock=all&event=bestseller&platform=0&search="
url += "&genre=0&cat=0&sortOrder=popularity+desc&steam_app_id=&steam_category=&steam_prod_type=&includeOutOfStock=&includeFreeGames=false&_=1499201833510"
lynx = "Lynx/2.8.8dev.3 lib222-FM2.14 SSL-MM/1.4.1";
cmd = "mysql --host=127.0.0.1 --user=root --password=choppersrus autopilot -e "
query = ("\"INSERT INTO ITEMS (id, name, g2a_product_id, type, preorder) VALUES ")
cmd += query
itemcount = 0
def main():
	s = ""
	headers = {"User-Agent" : lynx}
	i = 0
	while i < 5:
		if i == 4:
			get = url + "&start=" + str(i * 24) + "&rows=4"
		else:
			get = url + "&start=" + str(i * 24) + "&rows=24"
		res = urllib2.Request(get, headers=headers)
		sourceFile = urllib2.urlopen(res)
		s += sourceFile.read()
		i += 1
	ids = re.findall("(?<=\"id\"\:)(\d+)", s)
	names = re.findall("(?<=\"name\":\")([?!']+)", s)
	preorder = re.findall("(?<=\"preOrder\":)([A-Za-z0-9$:#@]+)", s)
	print ids
	print names
	print preorder
	i = 0
	while i < len(ids):
		values = "(" + str(i + 1) + ", \'" + names[i] + "\', " + ids[i] + ", \'Product Key\', " + preorder[i] + ")\""
		print cmd + values
		#os.system(cmd + values)
		i += 1
if __name__ == "__main__":
	main()
