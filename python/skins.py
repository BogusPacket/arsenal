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
                        class white(object) = {
                                "FAMAS | Contrast Spray" : {
                                                "Max_Float" = 0.80,
                                                "Min_Float = 0.06
                                }
                        },

                        class teal = {
                                "Galil AR | Winter Forest" : {
                                                "Max_Float" = 0.80,
                                                "Min_Float = 0.06
                                },
                                "M249 | Blizzard Marbleized" : {
                                                "Max_Float" = 0.80,
                                                "Min_Float = 0.06
                                },
                                "G3SG1 | Arctic Camo" : {
                                                "Max_Float" = 0.80,
                                                "Min_Float = 0.06
                                }
                        },
                        class blue = {
                                "MP7 | Whiteout" : {
                                                                max_float = 0.80,
                                                                min_float = 0.06
                                }
                        },
                        purple : None,
                        pink : None,
                        red : None
