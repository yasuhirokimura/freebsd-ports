PORTNAME=	jadm
PORTVERSION=	1.0
PORTREVISION=	3
CATEGORIES=	sysutils python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jadm@dachev.info
COMMENT=	FreeBSD jail framework with zfs, vnet and jail.conf support
WWW=		https://github.com/NikolayDachev/jadm

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}paramiko>=1.14.0:security/py-paramiko@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}netifaces>=0.10.3:net/py-netifaces@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tabulate>=0.7.2:devel/py-tabulate@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}paramiko>=1.14.0:security/py-paramiko@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}netifaces>=0.10.3:net/py-netifaces@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tabulate>=0.7.2:devel/py-tabulate@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist
PLIST_FILES=	share/man/man8/jadm.8.gz

pre-install:
	${INSTALL_MAN} ${WRKSRC}/man8/jadm.8 ${STAGEDIR}${PREFIX}/share/man/man8

.include <bsd.port.mk>
