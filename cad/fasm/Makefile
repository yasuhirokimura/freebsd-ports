PORTNAME=	fasm
PORTVERSION=	g20190920
PORTREVISION=	1
CATEGORIES=	cad python
PKGNAMESUFFIX=	-fpga

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	FPGA assembly (FASM) parser and generator
WWW=		https://github.com/SymbiFlow/fasm

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}textX>0:lang/py-textX@${PY_FLAVOR}

USES=		python
USE_GITHUB=	yes
GH_ACCOUNT=	SymbiFlow
GH_TAGNAME=	b8db365
USE_PYTHON=	distutils concurrent noflavors autoplist

NO_ARCH=	yes

CONFLICTS_INSTALL=	fasm SASM

.include <bsd.port.mk>
