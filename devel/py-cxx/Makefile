PORTNAME=	cxx
PORTVERSION=	7.1.8
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	SF/${PORTNAME}/CXX/PyCXX%20V${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pycxx-${PORTVERSION}

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	Make it easier to extend Python with C++
WWW=		https://cxx.sourceforge.net

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

USES=		python
USE_PYTHON=	autoplist concurrent distutils pythonprefix
PYDISTUTILS_PKGNAME=	CXX

NO_ARCH=	yes

DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/Doc/ && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}

post-patch:
	@${REINPLACE_CMD} \
		-e 's,distutils\.command\.install ,setuptools\.command\.install ,' \
		${WRKSRC}/setup.py

.include <bsd.port.mk>
