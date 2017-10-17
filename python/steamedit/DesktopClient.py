class DesktopClient:
	def __init__(self, username='', password=''):
		self.username = username
		self.password = password
		self.client = steam.SteamClient()
		self.csgo = CSGOClient(client)
		self.client.cli_login(username=username, password=password)
		self.client.run_forever()
	def startCSGO(self):
		self.csgo.launch()
