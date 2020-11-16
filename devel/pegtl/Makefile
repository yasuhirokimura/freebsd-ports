PORTNAME=	pegtl
DISTVERSION=	3.0.0
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Parsing Expression Grammar Template Library

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake
USE_GITHUB=	yes
GH_ACCOUNT=	taocpp
GH_PROJECT=	PEGTL

CMAKE_OFF=	PEGTL_BUILD_TESTS PEGTL_BUILD_EXAMPLES

NO_BUILD=	yes
NO_ARCH=	yes

do-test: # one test case fails: https://github.com/taocpp/PEGTL/issues/189
	@cd ${BUILD_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} -DPEGTL_BUILD_TESTS:BOOL=ON ${CMAKE_SOURCE_PATH} && \
		${DO_MAKE_BUILD} ${ALL_TARGET} && \
		${DO_MAKE_TEST} test

.include <bsd.port.mk>
