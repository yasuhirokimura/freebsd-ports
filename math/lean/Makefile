PORTNAME=	lean
DISTVERSIONPREFIX=	v
DISTVERSION=	3.31.0
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Theorem prover

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/../LICENSE

LIB_DEPENDS=	libgmp.so:math/gmp

USES=		cmake compiler:c++11-lang
USE_GITHUB=	yes
GH_ACCOUNT=	leanprover-community

WRKSRC_SUBDIR=	src

CMAKE_OFF=	BUILD_TESTING

post-install:
	@${FIND} ${STAGEDIR}${PREFIX} -type d -empty -delete

do-test:
	@cd ${BUILD_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} -DBUILD_TESTING:BOOL=ON ${CMAKE_SOURCE_PATH} && \
		${DO_MAKE_BUILD} ${ALL_TARGET} && \
		${DO_MAKE_TEST} test

.include <bsd.port.mk>
