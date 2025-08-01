PORTNAME=	xtide
PORTVERSION=	2.15.6
CATEGORIES=	astro geography
MASTER_SITES=	https://flaterco.com/files/xtide/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${DISTNAME_TCD}${EXTRACT_SUFX} \
		${DISTNAME_HARM}${EXTRACT_SUFX}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Harmonic tide clock and tide predictor
WWW=		https://flaterco.com/xtide/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpng.so:graphics/png

USES=		compiler:c++0x gmake libtool localbase tar:xz
USE_CXXSTD=	c++11
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CONFIGURE_ENV=	ac_cv_header_tcd_h=yes \
		ac_cv_lib_tcd_get_tide_db_header=yes
CFLAGS+=	-Wno-deprecated-declarations
CPPFLAGS+=	-I${WRKSRC_TCD} $$(libpng-config --I_opts)
LDFLAGS+=	-L${WRKSRC_TCD}/.libs $$(libpng-config --L_opts)
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=		WVS X11
OPTIONS_DEFAULT=	X11
OPTIONS_SUB=		yes

WVS_DESC=		Use world vector shoreline data (37MB)
WVS_DISTFILES=		${DISTNAME_WVS}${EXTRACT_SUFX}
X11_USES=		xorg
X11_USE=		xorg=ice,sm,x11,xaw,xext,xmu,xpm,xt
X11_CONFIGURE_WITH=	x
X11_DESKTOP_ENTRIES=	"XTide" "" "xtide" "xtide" "" ""

DISTNAME_TCD=	libtcd-2.2.7-r3
WRKSRC_TCD=	${WRKDIR}/${DISTNAME_TCD:C/-r[0-9]+//}
DISTNAME_HARM=	harmonics-dwf-20241229-free
WRKSRC_HARM=	${WRKDIR}/${DISTNAME_HARM:C/-free//}
DISTNAME_WVS=	wvs

post-patch:
	@${REINPLACE_CMD} -e \
		's|/usr/X11R6|${LOCALBASE}|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		's|"/etc/|"${PREFIX}/etc/| ; \
		 s| /etc/| ${PREFIX}/etc/|' ${WRKSRC}/libxtide/Global.cc

pre-configure:
	@(cd ${WRKSRC_TCD} && ${SETENV} ${CONFIGURE_ENV} \
		CC="${CC}" CFLAGS="${CFLAGS} -fPIC" \
		CXX="${CXX}" CXXFLAGS="${CXXFLAGS} -fPIC" \
		${SH} ./configure ${CONFIGURE_ARGS})

pre-build:
	@(cd ${WRKSRC_TCD} && ${DO_MAKE_BUILD} ${ALL_TARGET})

post-build:
	@${ECHO_CMD} -n > ${WRKDIR}/xtide.conf.sample
	@${ECHO_CMD} "${DATADIR}/harmonics.tcd" >> ${WRKDIR}/xtide.conf.sample
	@${ECHO_CMD} "${DATADIR}/wvs" >> ${WRKDIR}/xtide.conf.sample
	@${LN} -sf ${DISTNAME_HARM}.tcd ${WRKSRC_HARM}/harmonics.tcd
	@${LN} -sf icon_48x48_orig.png ${WRKSRC}/iconsrc/xtide.png

pre-install:
	@(cd ${WRKSRC_TCD} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} \
		 ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${INSTALL_TARGET})
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libtcd.so.[0-9]*

post-install:
	(cd ${WRKDIR} && ${INSTALL_DATA} xtide.conf.sample \
		${STAGEDIR}${PREFIX}/etc)
	@${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC_HARM} && ${INSTALL_DATA} harmonics.tcd \
		${STAGEDIR}${DATADIR})

post-install-WVS-on:
	@${MKDIR} ${STAGEDIR}${DATADIR}/wvs
	(cd ${WRKDIR} && ${INSTALL_DATA} wvs*.dat \
		${STAGEDIR}${DATADIR}/wvs)

post-install-X11-on:
	(cd ${WRKSRC}/iconsrc && ${INSTALL_DATA} xtide.png \
		${STAGEDIR}${PREFIX}/share/pixmaps)

.include <bsd.port.mk>
