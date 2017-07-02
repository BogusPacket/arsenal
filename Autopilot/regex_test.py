#!/usr/bin/python
import re
#([A-Za-z0-9.-_~:?#[]@!$&'()*+,;=]+)
re_url = "([A-Za-z0-9._~:/#@!$&'\[\]()*+,;=%]+)"
url = "https://www.google.com"

findings = re.findall(re_url, url)
print findings

