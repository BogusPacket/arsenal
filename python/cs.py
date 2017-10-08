import sys, logging, steam, struct, csgo, crypto, re, urllib, time
key = "31216AF1828F766CE0118DD425F82C90"
#logging.basicConfig(format='[%(asctime)s] %(levelname)s %(name)s: %(message)s', level=logging.DEBUG)
from csgo import CSGOClient
from csgo.enums import ECsgoGCMsg
#from csgo.enums import EGCItemMsg
#from csgo import enums
user = steam.webauth.WebAuth("jarsaltaccount", "niggersstink69")
user.login(twofactor_code=sys.argv[4])
#tar = sys.argv[2]
maxminusmin = float(sys.argv[1])
f = open(sys.argv[2])
max = float(sys.argv[3])
skins = []
for line in f:
        skins.append(float(line))
        print line
print "len(skins) = " + str(len(skins))

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
def buy(link):
        global user
        id = link.split("M")[1].split("A")[0]
        print id
        print user.session.get("http://steamcommunity.com/market/buylisting/" + id)
def min(lst):
        m = 0.9999999
        for each in lst:
                if each < m:
                        each = m
        return float(m)
#def buy(link):

def min_list(lst):
        print("Finding Min...")
        global skins
        ordered = []
        while len(ordered) < 10:
                min = 99999
                for each in lst:
                        if each < min:
                                if each not in ordered:
                                        min = each
                ordered.append(min)
        return ordered

def req(start, cnt):
    url = "http://steamcommunity.com/market/listings/730/M249%20%7C%20Gator%20Mesh%20%28Factory%20New%29/render/?query=&start=" + str(start) + "&count=" + str(cnt) + "&country=US&language=english&currency=1"
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
    i = 0
    while i < len(links):
        assetid =  txt.split(links[i].split("M")[1].split("A")[0] + "_name\', 730, \'2\', \'")[1].split("\',")[0]
        links[i] = links[i].replace("%assetid%", assetid)
        links[i] = links[i].replace("\\", "")
        i += 1
    return links

def get_links(start, cnt):
        if cnt < 100:
                return req(start, cnt)
        else:
                links = []
                while cnt:
                        tmp = []
                        if cnt < 100:
                                tmp = req(start, cnt)
                                cnt = 0
                        else:
                                tmp = req(start, 100)
                                cnt -= 100
                                start += 100
                        for each in tmp:
                                links.append(each)


def inspect_item(u):
    #u = u.split("steam://rungame/730/")[0]
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

    ret = struct.unpack("f", struct.pack("i", response.iteminfo.paintwear))[0]
    print ret
    return float(ret)
    #crit = cs.socache[csgo.enums.ESOType.CSOItemRecipe][30]
    #print(crit)
    #response, = cs.wait_msg(EGBaseMsg.CSOItemCriteria, {})
    #print(response)

@client.on('logged_on')
def start_csgo():
    cs.launch()
#    inspect_item("steam://rungame/730/76561202255233023/+csgo_econ_action_preview%20S76561198197277525A11602151187D3045780037281461530")

@cs.on('ready')
def gc_ready():
    print("cs ready!")
    floats = []
    floats_dict = dict()
    links = get_links(0, 10)
    for each in links:
        float = inspect_item(each)
        floats.append(float)
        floats_dict[float] = each
        time.sleep(0.75)
    ordered = min_list(floats)
    avg = int()
    for each in ordered:
        if len(skins) == 10: break
        else:
                skins.append(each)
    print len(skins)
    for each in skins:
        print each
        avg += each
    avg = avg / 10
    print("\n")
    float = (maxminusmin * avg) + 0.004
    print float
    if float < max:
        for each in ordered:
                buy(floats_dict[each])
    #inspect_item("steam://rungame/730/76561202255233023/+csgo_econ_action_preview%20M1711789915681407128A12199831625D10152853838133115354")

client.cli_login(username="obama_stole_my_dog", password="Niggers1286")
client.run_forever()
