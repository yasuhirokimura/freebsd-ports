PORTNAME=	xtl
DISTVERSION=	0.7.2
CATEGORIES=	devel
PKGNAMESUFFIX=	-quant-stack

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Template library that supports other quantstack projects

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	nlohmann-json>0:devel/nlohmann-json
RUN_DEPENDS=	nlohmann-json>0:devel/nlohmann-json
TEST_DEPENDS=	nlohmann-json>0:devel/nlohmann-json \
		googletest>0:devel/googletest

USES=		cmake
USE_GITHUB=	yes
GH_ACCOUNT=	xtensor-stack

NO_BUILD=	yes
NO_ARCH=	yes

do-test:
	@cd ${WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} -Dxtl_DIR:STRING=${STAGEDIR}${PREFIX}/lib/cmake/xtl -DBUILD_TESTS=ON -DDOWNLOAD_GTEST=OFF && \
		${DO_MAKE_BUILD} && \
		${DO_MAKE_TEST} xtest

.include <bsd.port.mk>
