PORTNAME=	keras-preprocessing
DISTVERSION=	1.1.2
PORTREVISION=	2
CATEGORIES=	math python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	rm@FreeBSD.org
COMMENT=	Easy data preprocessing and data augmentation for DL models
WWW=		https://github.com/keras-team/keras-preprocessing

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}six>=0:devel/py-six@${PY_FLAVOR}

USES=		python
USE_GITHUB=	yes
GH_ACCOUNT=	keras-team
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.mk>
