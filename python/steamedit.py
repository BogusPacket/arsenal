#!/usr/bin/python
import steam, csgo, urllib, re
class DesktopClient:
	def __init__(self, username='', password=''):
		self.username = username
		self.password = password
		self.client = steam.SteamClient()
		self.csgo = csgo.CSGOClient(self.client)
		self.client.cli_login(username=username, password=password)
	def startCSGO(self):
		self.csgo.launch()
		
class Skin:
	def __init__(self, client=None, name=None, steamid=None, itemid=None, assetid=None, price=None, fee=None, float=None, marketid=None):
		self.name=name
    		self.marketid=marketid
    		self.assetid=assetid
    		self.steamid=steamid
		self.float=float
		self.fee=fee
		self.price=price
		
	def getFloat(self, client): #getFloat will alternate between steam clients
		client.send(ECsgoGCMsg.EMsgGCCStrike15_v2_Client2GCEconPreviewDataBlockRequest, {
                    'param_s': self.steamid,
                    'param_a': self.assetid,
                    'param_d': self.itemid,
                    'param_m': self.marketid,})
		response, = client.wait_event(ECsgoGCMsg.EMsgGCCStrike15_v2_Client2GCEconPreviewDataBlockResponse)
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
