import logging, steam, struct, csgo, crypto
logging.basicConfig(format='[%(asctime)s] %(levelname)s %(name)s: %(message)s', level=logging.DEBUG)
from csgo import CSGOClient
from csgo.enums import ECsgoGCMsg
#from csgo.enums import EGCItemMsg
#from csgo import enums
client = steam.SteamClient()
cs = CSGOClient(client)

message = steam.core.msg.MsgProto(steam.enums.emsg.EMsg.ClientLogon)
message.header.steamid = steam.steamid.SteamID(type='Individual', universe='Public')
message.body.protocol_version = 65579
message.body.client_package_version = 1771
message.body.client_os_type = steam.enums.EOSType.Windows10
message.body.client_language = "english"
message.body.should_remember_password = True
message.body.supports_rate_limit_response = True
print(message.__str__())
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
       a = int(u.split("A")[1]).split("D")[0]
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

@cs.on('ready')
def gc_ready():
    #inspect_item("steam://rungame/730/76561202255233023/+csgo_econ_action_preview%20S76561198197277525A11917086098D4948412171191378526")
    #time.sleep(1)
    #inspect_item("steam://rungame/730/76561202255233023/+csgo_econ_action_preview%20S76561198218077912A3162370634D14909734931962909189")
    #time.sleep(2)
    #Factory New
    inspect_item("steam://rungame/730/76561202255233023/+csgo_econ_action_preview%20S76561198197277525A11602151187D3045780037281461530")

client.cli_login(username="obama_stole_my_dog", password="Niggers1286")
client.run_forever()
cs.launch()