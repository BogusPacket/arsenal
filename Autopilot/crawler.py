#!/usr/bin/python
import urllib2
import re
import os
win64_GoogleChrome = "Mozilla/5.0 (Windows NT 6.3; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/59.0.3071.115 Safari/537.36";
lynx = "Lynx/2.8.8dev.3 lib222-FM2.14 SSL-MM/1.4.1";
url_regex = "([A-Za-z0-9-._~:?#[]@!$&'()*+,;=]+)"
core_url = "https://www.g2a.com"
def crawl_page(page, f, depth):
	info = dict()
	file = open(f, "a")
	filelen = 0
	list = set([page])
	crawled = []
	headers = {"User-Agent" : win64_GoogleChrome}
	z = 0
	while (z < depth):
		#print "len(list) == " + str(len(list))
		href = list.pop()
		try:
			#os.system("clear")
			#print href
			res = urllib2.Request(href, headers=headers)
			sourceFile = urllib2.urlopen(res)
			sourceText = sourceFile.read()
			filelen += len(sourceText)
			file.write(sourceText)
		except:
			pass
		links = re.findall("(?<=href=\")([A-Za-z0-9._~:/#@!$&'\[\]()*+,;=%]+)", sourceText) #OFFSET
		info[href] = str(len(links))
		if len(links) == 0:
			print "len(links) == 0"
		for l in links:
			if (l != "#"):
				list.add(l)
		z += 1
	return info
def get_test(url):
	list = [url];
	headers = {"User-Agent" : lynx}
	res = urllib2.Request(list.pop(), headers=headers)
	sourceFile = urllib2.urlopen(res)
	sourceText = sourceFile.read()
	return sourceText

if __name__ == "__main__":
	d = crawl_page("https://www.g2a.com/marketplace/product/auctions?id=94&v=0&url=https://www.g2a.com/counter-strike-global-offensive-global.html", "g2a.html", 50);
	for each in d:
		print "Links found in " + each + ":\t" + d[each]
