# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>

PORTNAME=	edid-decode
PORTVERSION=	0.1.20210115
CATEGORIES=	sysutils
MASTER_SITES=	LOCAL/ehaupt

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Decodes binary EDID information from monitors

LICENSE=	MIT

USES=		compiler:c++11-lang gmake tar:xz

LDFLAGS+=	-lm

PLIST_FILES=	bin/edid-decode \
		share/man/man1/edid-decode.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${MANPREFIX}/share/man/man1

.include <bsd.port.mk>
