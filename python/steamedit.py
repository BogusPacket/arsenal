#!/usr/bin/python
import steam, csgo, urllib, re, threading, struct
from csgo.enums import ECsgoGCMsg
class WebClient:
	sessionid=str()
	def __init__(self, username='', password=''):
		client = steam.webauth.WebAuth(username, password)
		self.session = client.login()
		self.session.get("https://store.steampowered.com/account/history")
		self.session.get("http://steamcommunity.com/market/listings/730/M249%20%7C%20Gator%20Mesh%20%28Factory%20New%29")
		for each in self.session.cookies:
			if each.name == "sessionid":
				self.sessionid=each.value
				break
	def buy(self, item):
		p = str(item.price)
		f = str(item.fee)
		p = p.replace(".", "")
		f = f.replace(".", "")
		p_l = p.split()
		f_l = f.split()
		for each in p_l:
			if each != "0": 
				total = each
				break
		for each in f_l:
			if each != "0":
				fee = each
				break
		subtotal = str(int(total) - int(fee))
		r = self.session.post(getBuyLinkFromInspectLink(item['link']), headers={"referer" : "http://steamcommunity.com/market/listings/730/M249%20%7C%20Gator%20Mesh%20%28Factory%20New%29",
					"content-type" : "application/x-www-form-urlencoded; charset=UTF-8",
					"origin"  : "http://steamcommunity.com",
					"accept" : "*/*",
					"user-agent" : "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/61.0.3163.100 Safari/537.36",
					"authority" : "steamcommunity.com",
					"accept-encoding" : "gzip, deflate, br" }, data="sessionid=" + sessionid + "&currency=1&subtotal=" + subtotal + "&fee=" + fee + "&total=" + total + "&quantity=1")
		print r.content 
class DesktopClient(threading.Thread):
	logged_on=0
	csgo_ready=0
	client=steam.SteamClient()
	csgo=csgo.CSGOClient(client)
	def __init__(self, username='', password=''):
		threading.Thread.__init__(self)
		self.username=username
		self.password=password
		self.client.cli_login(username=self.username, password=self.password)
	def run(self):
		self.client.run_forever()
		
@DesktopClient.client.on('logged_on')
def logged_on():
	print "Logged On!"
	DesktopClient.logged_on=1
	DesktopClient.csgo.launch()
	
@DesktopClient.csgo.on('ready')
def ready():
	print "CSGO Ready!"
	DesktopClient.csgo_ready=1
		
class Skin:
	def __init__(self, name=None, steamid=0, itemid=0, assetid=0, price=None, fee=None, float=None, marketid=0):
		self.name=name
    		self.marketid=marketid
    		self.assetid=assetid
		self.itemid=itemid
    		self.steamid=steamid
		self.float=float
		self.fee=fee
		self.price=price
		
	def getFloat(self, client): #getFloat will alternate between steam clients
		client.csgo.send(ECsgoGCMsg.EMsgGCCStrike15_v2_Client2GCEconPreviewDataBlockRequest, {
                    'param_s': int(self.steamid),
                    'param_a': int(self.assetid),
                    'param_d': int(self.itemid),
                    'param_m': int(self.marketid),})
		response, = client.csgo.wait_event(ECsgoGCMsg.EMsgGCCStrike15_v2_Client2GCEconPreviewDataBlockResponse)
		self.float=struct.unpack("f", struct.pack("i", response.iteminfo.paintwear))[0]
		return response
		
def getSkinListings(skin, start, cnt):
	global url
	url = "http://steamcommunity.com/market/listings/730/" + skin + "/render/?query=&start=" + str(start) + "&count=" + str(cnt) + "&country=US&language=english&currency=1"
	url = url.replace(" ", "%20")
	url = url.replace("|", "%7C")
	url = url.replace("(", "%28")
	url = url.replace(")", "%29")
	print url
	txt = urllib.urlopen(url).read()
	r = re.split("{\"link\":\"", txt)
	i = 0
	links = []
	while 1:
		try:
			s = r[i].split("\",\"")[0]
			if "listing" not in s:
				if s not in links:
					if "csgo_econ" in s:
						links.append(s)
			i += 1
		except: break
	
	marketids=[]
	itemids=[]
	assetids=[]
	prices=[]
	fees=[]
	for each in links:
		marketid = each.split("M")[1].split("A")[0]
		itemids.append(each.split("D")[1])
		assetids.append(txt.split(marketid + "_name\', 730, \'2\', \'")[1].split("\',")[0])
		marketids.append(marketid)
	prices = re.findall("market_listing_price market_listing_price_with_fee.{20}([0-9]+\.[0-9]+)", txt)
	i = 0
	for each in re.findall("market_listing_price market_listing_price_without_fee.{20}([0-9]+\.[0-9]+)", txt):
		fees.append(str(float(prices[i]) - float(each)))
		i += 1
	items = []
	i = 0
	for each in links:
		items.append(Skin(marketid=marketids[i], itemid=itemids[i], price=prices[i], fee=fees[i], assetid=assetids[i]))
		i += 1
	return items
