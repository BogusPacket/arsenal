#!/usr/bin/python
import steam, csgo, urllib, re, threading
from csgo.enums import ECsgoGCMsg
class DesktopClient(threading.Thread):
	def __init__(self, username='', password=''):
		threading.Thread.__init__(self)
		self.username = username
		self.password = password
		self.client = steam.SteamClient()
		self.csgo = csgo.CSGOClient(self.client)
	
	def startCSGO(self):
		self.csgo.launch()
	def run(self): 
		self.client.cli_login(username=self.username, password=self.password)
		self.client.run_forever()
		
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
		print self.steamid
		print self.assetid
		print self.itemid
		print self.marketid
		client.csgo.send(ECsgoGCMsg.EMsgGCCStrike15_v2_Client2GCEconPreviewDataBlockRequest, {
                    'param_s': int(self.steamid),
                    'param_a': int(self.assetid),
                    'param_d': int(self.itemid),
                    'param_m': int(self.marketid),})
		response, = client.csgo.wait_event(ECsgoGCMsg.EMsgGCCStrike15_v2_Client2GCEconPreviewDataBlockResponse)
		self.float=struct.unpack("f", struct.pack("i", response.iteminfo.paintwear))[0]
		
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
		items.append(Skin(marketid=marketids[i], itemid=itemids[i], price=prices[i], fee=fees[i]))
		i += 1
	return items
