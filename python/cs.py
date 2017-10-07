import logging, steam, struct, csgo, crypto, re, urllib
logging.basicConfig(format='[%(asctime)s] %(levelname)s %(name)s: %(message)s', level=logging.DEBUG)
from csgo import CSGOClient
from csgo.enums import ECsgoGCMsg
#from csgo.enums import EGCItemMsg
#from csgo import enums
client = steam.SteamClient()
cs = CSGOClient(client)
url1 = "http://steamcommunity.com/market/listings/730/M249%20%7C%20Gator%20Mesh%20%28Factory%20New%29"
message = steam.core.msg.MsgProto(steam.enums.emsg.EMsg.ClientLogon)
message.header.steamid = steam.steamid.SteamID(type='Individual', universe='Public')
message.body.protocol_version = 65579
message.body.client_package_version = 1771
message.body.client_os_type = steam.enums.EOSType.Windows10
message.body.client_language = "english"
message.body.should_remember_password = True
message.body.supports_rate_limit_response = True
print(message.__str__())
def get_links(start):
    url = "http://steamcommunity.com/market/listings/730/M249%20%7C%20Gator%20Mesh%20%28Factory%20New%29/render/?query=&start=" + str(start) + "&count=100&country=US&language=english&currency=1"
    txt = urllib.urlopen(url).read()
    r = re.split("{\"link\":\"", txt)
    i = 0
    links = []
    while 1:
        try:
            s = r[i].split("\",\"")[0]
            if "listing" not in s:
                if s not in links:
                    links.append(s)
            i += 1
        except: break
    i = 0
    while i < len(links):
        assetid =  txt.split(links[i].split("M")[1].split("A")[0] + "_name\', 730, \'2\', \'")[1].split("\',")[0]
        links[i] = links[i].replace("%assetid%", assetid)
        links[i] = links[i].replace("\\", "")
        i += 1
    return links


def inspect_item(u):
    #u = u.split("steam://rungame/730/")[0]
    print(u)
    try:
        u = u.split("S")[1]
        s = int(u.split("A")[0])
        a = int(u.split("A")[1].split("D")[0])
        d = int(u.split("D")[1])
        m = 0

    except:
       u = u.split("M")[1]
       m = int(u.split("A")[0])
       a = int(u.split("A")[1].split("D")[0])
       d = int(u.split("D")[1])
       s = 0
    cs.send(ECsgoGCMsg.EMsgGCCStrike15_v2_Client2GCEconPreviewDataBlockRequest, {
                    'param_s': s,
                    'param_a': a,
                    'param_d': d,
                    'param_m': m,
                 })
    response, = cs.wait_event(ECsgoGCMsg.EMsgGCCStrike15_v2_Client2GCEconPreviewDataBlockResponse)

    print(struct.unpack("f", struct.pack("i", response.iteminfo.paintwear))[0])
    #crit = cs.socache[csgo.enums.ESOType.CSOItemRecipe][30]
    #print(crit)
    #response, = cs.wait_msg(EGBaseMsg.CSOItemCriteria, {})
    #print(response)
    
@client.on('logged_on')
def start_csgo():
    cs.launch()
    time
#    inspect_item("steam://rungame/730/76561202255233023/+csgo_econ_action_preview%20S76561198197277525A11602151187D3045780037281461530")

@cs.on('ready')
def gc_ready():
    start = 0
    while 1:
        links = get_links(start)
        for each in links:
            print each
            inspect_item(each)
        start += 100
    
   #inspect_item("steam://rungame/730/76561202255233023/+csgo_econ_action_preview%20M1711789915681407128A12199831625D10152853838133115354") 

client.cli_login(username="obama_stole_my_dog", password="Niggers1286")
client.run_forever()

