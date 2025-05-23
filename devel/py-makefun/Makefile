PORTNAME=	makefun
DISTVERSION=	1.15.4
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	meka@tilda.center
COMMENT=	Dynamically create python functions with a proper signature
WWW=		https://github.com/smarie/python-makefun

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	Depends on expired devel/py-pytest-runner
EXPIRATION_DATE=2025-03-31

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pip>=0:devel/py-pip@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-runner>=0:devel/py-pytest-runner@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>=0:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}funcsigs>=0:devel/py-funcsigs@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils pytest

TEST_ENV=	PYTHONPATH=${WRKSRC}/src

NO_ARCH=	yes

.include <bsd.port.mk>
