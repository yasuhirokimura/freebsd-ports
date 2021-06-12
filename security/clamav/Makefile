PORTNAME=	clamav
DISTVERSIONPREFIX=	${PORTNAME}-
DISTVERSION=	0.103.0-164
DISTVERSIONSUFFIX=	-g9e0f65e01
PORTEPOCH=	1
CATEGORIES=	security

MAINTAINER=	yasu@utahime.org
COMMENT=	Command line virus scanner written entirely in C

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING.txt

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libjson-c.so:devel/json-c \
		libmspack.so:archivers/libmspack \
		libpcre2-8.so:devel/pcre2

USES=		cmake compiler cpe gnome iconv ncurses pathfix pkgconfig ssl
USE_GITHUB=	yes
GH_ACCOUNT=	Cisco-Talos
USE_GNOME=	libxml2
USE_LDCONFIG=	yes
USE_RC_SUBR=	clamav-clamd clamav-freshclam

CMAKE_ARGS=	-DDATABASE_DIRECTORY:STRING=${_DBDIR}
CMAKE_ON=	ENABLE_EXTERNAL_MSPACK

INSTALL_TARGET=	install/strip

SUB_FILES=	pkg-deinstall
SUB_LIST+=	CHMOD=${CHMOD} \
		CHOWN=${CHOWN} \
		CLAMAV_CLAMD_PIDFILE=${_CLAMAV_CLAMD_PIDFILE} \
		CLAMAV_CLAMD_SOCKET=${_CLAMAV_CLAMD_SOCKET} \
		CLAMAV_MILTER_SOCKET=${_CLAMAV_MILTER_SOCKET} \
		CLAMAVGROUP=${_CLAMAVGROUP} \
		CLAMAVUSER=${_CLAMAVUSER} \
		DBDIR=${_DBDIR} \
		LOGDIR=${_LOGDIR} \
		RUNDIR=${_RUNDIR}

USERS=		clamav
GROUPS=		clamav mail

PLIST_SUB+=	CLAMAVGROUP=${_CLAMAVGROUP} \
		CLAMAVUSER=${_CLAMAVUSER} \
		DBDIR=${_DBDIR} \
		LOGDIR=${_LOGDIR} \
		RUNDIR=${_RUNDIR}

OPTIONS_DEFINE=	ARC ARJ EXPERIMENTAL HTMLDOCS LHA MILTER STDERR TESTS UNRAR \
		UNZOO

OPTIONS_DEFAULT=	ARC ARJ MILTER UNRAR UNZOO
OPTIONS_SUB=		yes

ARC_DESC=		Enable arch archives support
ARJ_DESC=		Enable arj archives support
EXPERIMENTAL_DESC=	Build experimental code
HTMLDOCS_DESC=		Generate doxygen HTML documentation for clamav.h, libfreshclam.h
LHA_DESC=		Enable lha archives support
MILTER_DESC=		Compile the milter interface
STDERR_DESC=		Print logs to stderr instead of stdout
TESTS_DESC=		Run compile-time tests (req. python)
UNZOO_DESC=		Enable zoo archives support

ARC_RUN_DEPENDS=	arc:archivers/arc
ARJ_RUN_DEPENDS=	arj:archivers/arj
EXPERIMENTAL_CMAKE_ON=	-DENABLE_EXPERIMENTAL:BOOL=ON
EXPERIMENTAL_CMAKE_OFF=	-DENABLE_EXPERIMENTAL:BOOL=OFF
HTMLDOCS_BUILD_DEPENDS=	doxygen>0:devel/doxygen
HTMLDOCS_CMAKE_ON=	-DENABLE_DOXYGEN:BOOL=ON
HTMLDOCS_CMAKE_OFF=	-DENABLE_DOXYGEN:BOOL=OFF
HTMLDOCS_ALL_TARGET=	docs/doxygen
LHA_RUN_DEPENDS=	lha:archivers/lha
MILTER_USE=		RC_SUBR=clamav-milter
MILTER_CMAKE_ON=	-DENABLE_MILTER:BOOL=ON
MILTER_CMAKE_OFF=	-DENABLE_MILTER:BOOL=OFF
.if !exists(/usr/lib/libmilter.so)
MILTER_LIB_DEPENDS+=	libmilter.so:mail/libmilter
MILTER_CFLAGS=		-I${LOCALBASE}/include
MILTER_LDFLAGS=		-L${LOCALBASE}/lib
.endif
STDERR_EXTRA_PATCHES=	${FILESDIR}/extra-patch-common_output.c
TESTS_BUILD_DEPENDS=	${LOCALBASE}/include/check.h:devel/check
TESTS_USES=		python:build
TESTS_CMAKE_ON=		-DENABLE_TESTS:BOOL=ON
TESTS_CMAKE_OFF=	-DENABLE_TESTS:BOOL=OFF
UNRAR_CMAKE_ON=		-DENABLE_UNRAR:BOOL=ON
UNRAR_CMAKE_OFF=	-DENABLE_UNRAR:BOOL=OFF
UNZOO_RUN_DEPENDS=	unzoo:archivers/unzoo

_CLAMAVUSER?=	clamav
_CLAMAVGROUP?=	clamav

_CLAMAV_CLAMD_SOCKET?=	${RUNDIR}/clamd.sock
_CLAMAV_CLAMD_PIDFILE?=	${RUNDIR}/clamd.pid
_CLAMAV_MILTER_SOCKET?=	${RUNDIR}/clmilter.sock

_DBDIR=		/var/db/clamav
_LOGDIR=	/var/log/clamav
_RUNDIR=	/var/run/clamav

_SED_CONF=	-E -e 's|^\#?(Example)$$|\#\1|' -e \
		's|^\#?((Update)?LogFile) .*/([a-z]+\.log)$$|\1 ${_LOGDIR}/\3|' \
		-e 's|^\#?(PidFile) .*/([a-z\-]+\.pid)$$|\1 ${_RUNDIR}/\2|' -e \
		's|^\#?(LocalSocket) .*$$|\1 ${_CLAMAV_CLAMD_SOCKET}|' -e \
		's|^\#?(User) .*$$|\1 ${_CLAMAVUSER}|' -e \
		's|^\#?(AllowSupplementaryGroups).*$$|\1 yes|' -e \
		's|^\#?(ScanMail).*$$|\1 yes|' -e \
		's|^\#?(DatabaseDirectory) .*$$|\1 ${_DBDIR}|' -e \
		's|^\#?(DatabaseOwner) .*$$|\1 ${_CLAMAVUSER}|' -e \
		's|^\#?(FixStaleSocket).*$$|\1 yes|' -e \
		's|^\#?(NotifyClamd) .*$$|\1 ${PREFIX}/etc/clamd.conf|' -e \
		's|^\#?(MilterSocket) */tmp.*$$|\1 ${_CLAMAV_MILTER_SOCKET}|' \
		-e 's|^\#?(ClamdSocket).*$$|\1 unix:${_CLAMAV_CLAMD_SOCKET}|'

post-patch:
	@${REINPLACE_CMD} ${_SED_CONF} \
		${WRKSRC}/etc/clamd.conf.sample \
		${WRKSRC}/etc/freshclam.conf.sample \
		${WRKSRC}/etc/clamav-milter.conf.sample

post-build-TESTS-on:
	${MAKE_CMD} -C ${TEST_WRKSRC} check; \

post-install:
	${INSTALL_DATA} ${INSTALL_WRKSRC}/clamav-config.h ${STAGEDIR}${PREFIX}/include
	@${MKDIR} ${STAGEDIR}${_DBDIR} \
		  ${STAGEDIR}${_LOGDIR} \
		  ${STAGEDIR}${_RUNDIR}

post-install-HTMLDOCS-on:
	${MV} ${STAGEDIR}${PREFIX}/share/doc/ClamAV ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
