From 61539201e71c448b8a9513174f1b8bbb04e8093e Mon Sep 17 00:00:00 2001
From: Yasuhiro Kimura <yasu@utahime.org>
Date: Sun, 18 Jul 2021 05:15:06 +0900
Subject: [PATCH] jail: Add '-s' options to MAKE_CMD by default

Add '-s' option to MAKE_CMD unless '-v' option of 'poudriere' is
specified. This means less messages are displayed while
building/installing/updating jail from source tree.
---
 src/share/poudriere/jail.sh | 3 +++
 1 file changed, 3 insertions(+)

diff --git src/share/poudriere/jail.sh src/share/poudriere/jail.sh
index cdbf60fe..b80753a5 100755
--- src/share/poudriere/jail.sh
+++ src/share/poudriere/jail.sh
@@ -418,6 +418,9 @@ setup_build_env() {
 			err 1 "You need fmake installed on the host: devel/fmake"
 		MAKE_CMD=${FMAKE}
 	fi
+	if ! [ ${VERBOSE} -gt 0 ]; then
+		MAKE_CMD="${MAKE_CMD} -s"
+	fi
 
 	: ${CCACHE_BIN:="/usr/local/libexec/ccache"}
 	if [ -n "${CCACHE_DIR}" -a -d ${CCACHE_BIN}/world ]; then
-- 
2.32.0

