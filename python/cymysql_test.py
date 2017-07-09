#!/usr/bin/python
import cymysql

c = cymysql.connect(host='localhost', port=3306, user='root', passwd='choppersrus', db='autopilot')
cursor = c.cursor()
cursor.execute("SELECT name FROM ITEMS WHERE g2a_product_id = 94")
for each in cursor:
	print(str(each))
