PORTNAME=	peps
PORTVERSION=	2.0
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	http://peps.redprince.net/peps/ \
		ftp://ftp.peps.redprince.net/unix/peps/
PKGNAMEPREFIX=	x

MAINTAINER=	doceng@FreeBSD.org
COMMENT=	Converts EPS images to anti-aliased bitmaps with X11 support
WWW=		http://peps.redprince.net/peps/

LICENSE=	BSD2CLAUSE

DEPRECATED=	Depends on expired graphics/peps
EXPIRATION_DATE=2025-02-28

RUN_DEPENDS=	peps>=2.0_6:graphics/peps

USES=		ghostscript:x11,run
MAKE_ENV=	GSPATH="${LOCALBASE}/bin/gs" GZPATH="/usr/bin/gzip" \
		ETC="${PREFIX}/etc"
ALL_TARGET=	xpeps

PLIST_FILES=	bin/xpeps

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xpeps ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
