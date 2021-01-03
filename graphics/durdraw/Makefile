PORTNAME=	durdraw
DISTVERSION=	0.27.1
CATEGORIES=	graphics python

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	ASCII and ANSI Art text editor for drawing in the terminal
WWW=		https://durdraw.org/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pillow>=7.0.0:graphics/py-pillow@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist

USE_GITHUB=	yes
GH_ACCOUNT=	cmang

NO_ARCH=	yes

.include <bsd.port.mk>
