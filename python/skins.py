import re, urllib
def getMinPriceOfSkin(skin, wear):
        skin += (" %28" + wear + "%29")
        url = "http://steamcommunity.com/market/listings/730/" + skin + "/render/?query=&start=0&count=1&$        url = url.replace(" ", "%20")
        url = url.replace("|", "%7C")
        txt = urllib.urlopen(url).read()
        return re.findall("(\$[0-9]+\.[0-9]+)", txt)[0].split("$")[1]
class skins(object):
        class collections(object):
                class office(object):
                        white = {
                                "FAMAS | Contrast Spray" : {
                                                "Max_Float" : 0.80,
                                                "Min_Float" : 0.06
                                }
                        }

                        teal = {
                                "Galil AR | Winter Forest" : {
                                                "Max_Float" : 0.80,
                                                "Min_Float" : 0.06
                                },
                                "M249 | Blizzard Marbleized" : {
                                                "Max_Float" : 0.80,
                                                "Min_Float" : 0.06
                                },
                                "G3SG1 | Arctic Camo" : {
                                                "Max_Float" : 0.80,
                                                "Min_Float" : 0.06
                                }
                        }
                        blue = {
                                "MP7 | Whiteout" : {
                                                "Max Float" : 0.80,
                                                "Min Float" : 0.06
                                }
                        }
print(skins.collections.office.white["FAMAS | Contrast Spray"])
