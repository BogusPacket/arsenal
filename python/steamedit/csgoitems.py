class Item(SteamClient):
	def __init__(self, marketid='', steamid='', itemid='', assetid=''):
    self.marketid=marketid
    self.assetid=assetid
		self.inspect=inspect
    self.steamid=steamid
	def getFloat(self, *extrasteamclients): #getFloat will alternate between steam clients
		cs.send(ECsgoGCMsg.EMsgGCCStrike15_v2_Client2GCEconPreviewDataBlockRequest, {
                    'param_s': self.steamid,
                    'param_a': self.assetid,
                    'param_d': self.itemid),
                    'param_m': self.marketid,
                 })
		response, = cs.wait_event(ECsgoGCMsg.EMsgGCCStrike15_v2_Client2GCEconPreviewDataBlockResponse)
		return struct.unpack("f", struct.pack("i", response.iteminfo.paintwear))[0]
