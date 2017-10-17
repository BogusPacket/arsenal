#!/usr/bin/python
import steam
import csgo
class Desktop:
	def __init__(self, username='', password=''):
		self.username = username
		self.password = password
		self.client = steam.SteamClient()
		self.csgo = csgo.CSGOClient(client)
		self.client.cli_login(username=username, password=password)
		self.client.run_forever()
	def startCSGO(self):
		self.csgo.launch()
