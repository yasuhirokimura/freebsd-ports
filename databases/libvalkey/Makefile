PORTNAME=	libvalkey
DISTVERSION=	0.1.0
CATEGORIES=	databases

MAINTAINER=	dtxdf@FreeBSD.org
COMMENT=	Valkey client library in C
WWW=		https://github.com/valkey-io/${PORTNAME}

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake
USE_GITHUB=	yes
GH_ACCOUNT=	valkey-io

MAKE_ARGS=	DEBUG_FLAGS= \
		OPTIMIZATION=

ALL_TARGET=	dynamic

OPTIONS_DEFINE=		TLS
OPTIONS_DEFAULT=	TLS

TLS_USES=	ssl
TLS_MAKE_ARGS=	USE_TLS=1

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libvalkey.so.0.1.0

post-install-TLS-on:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libvalkey_tls.so.0.1.0

.include <bsd.port.mk>
