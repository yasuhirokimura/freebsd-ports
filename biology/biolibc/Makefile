PORTNAME=	biolibc
DISTVERSION=	0.2.7
CATEGORIES=	biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Low-level high-performance bioinformatics library
WWW=		https://github.com/auerlab/biolibc

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libxtend.so:devel/libxtend

USE_GITHUB=	yes
USE_LDCONFIG=	yes

GH_ACCOUNT=	auerlab

MAKE_ARGS+=	MANDIR=${PREFIX}/share/man

INSTALL_TARGET=	install-strip

pre-build:
	(cd ${WRKSRC} && ${MAKE} LOCALBASE=${LOCALBASE} depend)

.include <bsd.port.mk>
