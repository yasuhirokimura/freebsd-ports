PORTNAME=	ferite
PORTVERSION=	1.0.2
PORTREVISION=	10
CATEGORIES=	lang
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Embeddable scripting language
WWW=		https://sourceforge.net/projects/ferite/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	Abandonware and outdated, last release in 2009 (current version in 2005)
EXPIRATION_DATE=2024-10-31

LIB_DEPENDS=	libpcre.so:devel/pcre \
		libxml2.so:textproc/libxml2

USES=		gmake libtool localbase:ldflags
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
LDFLAGS+=	-lpthread
USE_LDCONFIG=	yes
PLIST_SUB=	MACHINE_ARCH=${MACHINE_ARCH}
INSTALL_TARGET=	install-strip
CFLAGS+=	-D_WANT_SEMUN

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

DOCS_MAKE_ENV_OFF=	NOPORTDOCS=1

post-patch:
	@${REINPLACE_CMD} -e 's|<stdint\.h>|<inttypes.h>|' \
		${WRKSRC}/src/ferite_scanner.c
	@${FIND} ${WRKSRC} -name Makefile.in -print | ${XARGS} \
		${REINPLACE_CMD} -e "s|-lferite|-lferite -L${WRKSRC}/src/.libs|g"

.include <bsd.port.mk>
