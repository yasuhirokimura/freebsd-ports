--- bundled_deps/hints/HintsToPot.cpp.orig	2024-12-20 11:54:34 UTC
+++ bundled_deps/hints/HintsToPot.cpp
@@ -2,6 +2,7 @@
 #include <vector>
 #include <string>
 #include <boost/filesystem.hpp>
+#include <boost/filesystem/fstream.hpp>
 #include <boost/dll.hpp>
 #include <boost/property_tree/ini_parser.hpp>
 #include <boost/nowide/fstream.hpp>
