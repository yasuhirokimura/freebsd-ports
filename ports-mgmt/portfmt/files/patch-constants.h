--- constants.h.orig	2025-04-04 10:59:34 UTC
+++ constants.h
@@ -23,7 +23,9 @@ extern size_t static_shebang_langs_len;
 extern size_t static_shebang_langs_len;
 #define VAR_BROKEN_RUBY(block, flags, uses) \
 	{ block, "BROKEN_RUBY32", flags, uses }, \
-	{ block, "BROKEN_RUBY33", flags, uses }
+	{ block, "BROKEN_RUBY33", flags, uses }, \
+	{ block, "BROKEN_RUBY34", flags, uses }, \
+	{ block, "BROKEN_RUBY35", flags, uses }
 #define VAR_FOR_EACH_ARCH(block, var, flags, uses) \
 	{ block, var "aarch64", flags, uses }, \
 	{ block, var "amd64", flags, uses }, \
