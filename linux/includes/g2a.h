#ifndef G2A_H
#define G2A_H
#define POPULAR_ITEMS "https://www.g2a.com/lucene/search/filter?jsoncallback=jQuery111007667557919303079_1500323788288&skip=&minPrice=0.00&maxPrice=900.00&cc=US&stock=all&event=bestseller&platform=0&search=&genre=0&cat=0&sortOrder=popularity+desc&steam_app_id=&steam_category=&steam_prod_type=&includeOutOfStock=&includeFreeGames=false&isWholesale=false&_=1500323788290&start="
#define G2A_BESTSELLERS 0x01
#include "arsenal.h"
class G2A : protected Arsenal {
public:
	G2A();
	~G2A();
	void updateITEMS(int);
};
#endif
