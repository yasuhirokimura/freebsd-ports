PORTNAME=	psi
PORTVERSION=	1.5
PORTREVISION=	3
CATEGORIES=	net-im
MASTER_SITES=	SF/${PORTNAME}/Psi/${PORTVERSION}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Qt-based Jabber (XMPP) client
WWW=		https://psi-im.org/

LICENSE=	GPLv2+

LIB_DEPENDS=	libidn.so:dns/libidn \
		libqca-qt5.so:devel/qca@qt5

USES=		cmake compiler:c++11-lang desktop-file-utils minizip pkgconfig \
		qt:5 tar:xz xorg
USE_QT=		concurrent core dbus gui multimedia network svg widgets \
		x11extras xml buildtools:build qmake:build imageformats:run
USE_XORG=	ice sm x11 xcb xext xscrnsaver

CMAKE_ARGS=	-DIDN_LIBRARY:FILEPATH="${LOCALBASE}/lib/libidn.so" \
		-DIDN_INCLUDE_DIR:PATH="${LOCALBASE}/include"

OPTIONS_DEFINE=	WEBENGINE
OPTIONS_RADIO=	SPELLCHECK
OPTIONS_RADIO_SPELLCHECK=	HUNSPELL ENCHANT
SPELLCHECK_DESC=	Spell checker backend
OPTIONS_DEFAULT=	HUNSPELL
OPTIONS_SUB=	yes

WEBENGINE_DESC=		Use QtWebEngine for chatlogs
WEBENGINE_USE=		QT=declarative,location,printsupport,webchannel,webengine
WEBENGINE_CMAKE_BOOL=	ENABLE_WEBKIT

HUNSPELL_LIB_DEPENDS=	libhunspell-1.7.so:textproc/hunspell
HUNSPELL_CMAKE_BOOL=	USE_HUNSPELL

ENCHANT_DESC=		Spell checking support via Enchant
ENCHANT_LIB_DEPENDS=	libenchant.so:textproc/enchant
ENCHANT_CMAKE_BOOL=	USE_ENCHANT

post-patch:
# Replace original Hunspell implementation with better alternative
	@${CP} ${FILESDIR}/hunspellchecker.* \
		${WRKSRC}/src/libpsi/tools/spellchecker
# Avoid conflict with C++20 <version> by adding .txt suffix
	@${MV} ${WRKSRC}/version ${WRKSRC}/version.txt
	@${REINPLACE_CMD} -i .c++20 's,SOURCE_DIR}/version,&.txt,' \
		${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
