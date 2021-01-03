PORTNAME=	pyinsane2
DISTVERSION=	2.0.13
PORTREVISION=	3
CATEGORIES=	graphics python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python library to access and use image scanners
WWW=		https://gitlab.gnome.org/World/OpenPaperwork/pyinsane/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}nose>=1.0:devel/py-nose@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pillow>=7.0.0:graphics/py-pillow@${PY_FLAVOR}

USES=		gmake python
USE_PYTHON=	distutils autoplist
NO_ARCH=	yes

.include <bsd.port.mk>
