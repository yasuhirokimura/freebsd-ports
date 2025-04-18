PORTNAME=	wmakerconf
PORTVERSION=	2.12
PORTREVISION=	13
CATEGORIES=	x11-wm
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Configuration tool for Window Maker
WWW=		https://sourceforge.net/projects/wmakerconf/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libWINGs.so:x11-wm/windowmaker \
		libharfbuzz.so:print/harfbuzz \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libwraster.so:x11-wm/libwraster

USES=		gettext pkgconfig perl5 gmake gnome localbase shebangfix xorg
USE_GNOME=	cairo gdkpixbuf gtk20
USE_XORG=	x11
SHEBANG_FILES=	scripts/getfile.pl.in scripts/upgrade.pl.in
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
LIBS=		-lintl -lX11 -lWUtil

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

post-extract:
	@${FIND} ${WRKSRC} -name "*.gmo" -delete

post-patch:
	@${REINPLACE_CMD} -e 's|$$(prefix)/share/locale|${STAGEDIR}${PREFIX}/share/locale|g' \
		${WRKSRC}/data/po/Makefile.am ${WRKSRC}/data/po/Makefile.in \
		${WRKSRC}/po/Makefile.in.in
	@${REINPLACE_CMD} -e '/chmod 0/d' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -E '/\/usr\/share/d; \
			      s|/usr/local|${LOCALBASE}|g ; \
			      s|/usr/X11R6|${LOCALBASE}|g; \
			      s|(share/pixmaps.*),|\1|g' \
		${WRKSRC}/data/WMWmakerconf*
.for file in data/po/ja.po po/ja.po
	@${REINPLACE_CMD} -e 's|JISX-0208-1983-0|euc-jp|g' ${WRKSRC}/${file}
.endfor
	@${REINPLACE_CMD} -e '/WMWritePropListToFile/s|,[[:space:]]YES||' \
		${WRKSRC}/src/menu.c ${WRKSRC}/src/rootmenu.c \
		${WRKSRC}/src/wmconfig.c

.include <bsd.port.mk>
