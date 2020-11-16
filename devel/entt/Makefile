PORTNAME=	entt
DISTVERSIONPREFIX=	v
DISTVERSION=	3.7.1
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Fast and reliable entity-component system (ECS) and much more

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake
USE_GITHUB=	yes
GH_ACCOUNT=	skypjack

CMAKE_OFF=	BUILD_TESTING

NO_ARCH=	yes

do-test:
	@cd ${BUILD_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} -DENTT_BUILD_TESTING:BOOL=ON ${CMAKE_SOURCE_PATH} && \
		${DO_MAKE_BUILD} ${ALL_TARGET} && \
		${DO_MAKE_TEST} test

.include <bsd.port.mk>
