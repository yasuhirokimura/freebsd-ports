--- dkimpy_milter/config.py.orig	2023-02-27 01:05:26 UTC
+++ dkimpy_milter/config.py
@@ -89,10 +89,10 @@ class HostsDataset(object):
                 self.item = item[1:]
                 self.negative = True
             try:
-                try:
-                    self.item = ipaddress.ip_address(str(self.item, "utf-8"))
-                except TypeError:
+                if isinstance(self.item, str):
                     self.item = ipaddress.ip_address(self.item)
+                else:
+                    self.item = ipaddress.ip_address(str(self.item, "utf-8"))
                 if isinstance(self.item, ipaddress.IPv4Address):
                     self.isipv4 = True
                 elif isinstance(self.item, ipaddress.IPv6Address):
