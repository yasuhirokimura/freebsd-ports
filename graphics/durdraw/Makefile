PORTNAME=	durdraw
DISTVERSION=	0.28.0
PORTREVISION=	1
CATEGORIES=	graphics python

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	ASCII and ANSI Art text editor for drawing in the terminal
WWW=		https://durdraw.org/ \
		https://github.com/cmang/durdraw

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pillow>=7.0.0:graphics/py-pillow@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils noflavors autoplist

USE_GITHUB=	yes
GH_ACCOUNT=	cmang

NO_ARCH=	yes

.include <bsd.port.mk>
