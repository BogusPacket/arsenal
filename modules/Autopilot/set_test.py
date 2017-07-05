#!/usr/bin/python
import os, sys, mysql.connector, re

def getPID_list():
	result = []
	cnx = mysql.connector.connect(user='root', password='choppersrus', host='127.0.0.1', database='autopilot')
	cursor = cnx.cursor()
	query = "SELECT g2a_product_id FROM ITEMS"
	cursor.execute(query)
	for each in cursor:
		result.append(each)
		print result[len(result) - 1]
getPID_list()
exit(1)
