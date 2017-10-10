import re, urllib
def getMinPriceOfSkin(skin, wear):
        wear.replace(" ", "%20")
        skin.replace(" ", "%20")
        skin.replace("|", "%7C")
        skin.append(" %28" + wear + "%29")
        url = "http://steamcommunity.com/market/listings/730/" + skin + "/render/?query=&start=0&count=1&country=US&language=english&currency=1"
        txt = urllib.urlopen(url).read()
        price = re.findall("(\$\d+)", re.findall("(market_listing_price market_listing_price_with_fee.{2}\n)(.+)", s)[0])[0]
Skins = {
        "Collections" : {
                "Office" : {
                        "Consumer Grade" : {
                                "FAMAS | Contrast Spray" : {
                                                "Max Float" : 0.80,
                                                "Min Float" : 0.06
                                }
                        },

                        "Industrial Grade" : {
                                "Galil AR | Winter Forest" : {
                                                "Max Float" : 0.80,
                                                "Min Float" : 0.06
                                },
                                "M249 | Blizzard Marbleized" : {
                                                "Max Float" : 0.80,
                                                "Min Float" : 0.06
                                },
                                "G3SG1 | Arctic Camo" : {
                                                "Max Float" : 0.80,
                                                "Min Float" : 0.06
                                }
                        },
                        "Mil-Spec Grade" : {
                                "MP7 | Whiteout" : {
                                                "Max Float" : 0.80,
                                                "Min Float" : 0.06
                                }
                        },
                        "Restricted" : None,
                        "Classified" : None,
                        "Covert" : None
              }
        }
}
