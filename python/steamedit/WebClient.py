class WebClient:
  def __init__(self, username=None, password=None, emailcode=None, mobilecode=None):
  def buyItem(marketid, price, fee):
    i = price
	  j = fee
	  i = i.replace(".", "")
	  i = j.replace(".", "")
	  i_l = i.split()
	  j_l = j.split()
	  for each in i_l:
		  if each != "0": 
			  price = each
			  break
	  for each in j_l:
		  if each != "0": 
			  fee = each
			  break
	  fee = str(int(total) - int(subtotal))
	global sessionid
	global s
	print total
	print subtotal
	r = s.post(getBuyLinkFromInspectLink(item['link']), headers={"referer" : "http://steamcommunity.com/market/listings/730/M249%20%7C%20Gator%20Mesh%20%28Factory%20New%29",
					"content-type" : "application/x-www-form-urlencoded; charset=UTF-8",
					"origin"  : "http://steamcommunity.com",
					"accept" : "*/*",
					"user-agent" : "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/61.0.3163.100 Safari/537.36",
					"authority" : "steamcommunity.com",
					"accept-encoding" : "gzip, deflate, br" }, data="sessionid=" + sessionid + "&currency=1&subtotal=" + subtotal + "&fee=" + fee + "&total=" + total + "&quantity=1")
	print r.content 
