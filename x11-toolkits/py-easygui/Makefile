PORTNAME=	easygui
PORTVERSION=	0.98.1
PORTREVISION=	1
CATEGORIES=	x11-toolkits python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Easy GUI programming in python

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}tkinter>0:x11-toolkits/py-tkinter@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pillow>=7.0.0:graphics/py-pillow@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	distutils autoplist

NO_ARCH=	yes

.include <bsd.port.mk>
