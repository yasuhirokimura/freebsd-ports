PORTNAME=	urwid-readline
DISTVERSION=	0.13
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/}-${DISTVERSION}

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Textbox edit widget for Urwid that supports readline shortcuts
WWW=		https://github.com/rr-/urwid_readline

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}urwid>0:devel/py-urwid@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

do-test:
	(cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} -m pytest)

.include <bsd.port.mk>
