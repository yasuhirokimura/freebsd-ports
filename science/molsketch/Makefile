PORTNAME=	molsketch
DISTVERSION=	0.8.1
DISTVERSIONSUFFIX=	-src
CATEGORIES=	science
MASTER_SITES=	SF/${PORTNAME}/Molsketch/
DISTNAME=	Molsketch-${DISTVERSIONFULL}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	2D molecule editor
WWW=		https://molsketch.sourceforge.net/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libopenbabel.so:science/openbabel

USES=		cmake:noninja compiler:c++17-lang desktop-file-utils localbase:ldflags \
		pkgconfig qt:5 shared-mime-info # build fails with ninja, see https://sourceforge.net/p/molsketch/bugs/41/
USE_QT=		core gui network printsupport svg widgets buildtools:build linguisttools:build qmake:build
USE_LDCONFIG=	${PREFIX}/lib/molsketch

CMAKE_ARGS=	-DMSK_PREFIX:STRING=${PREFIX}

OPTIONS_DEFINE=	DOCS

WRKSRC=		${WRKDIR}/Molsketch-${DISTVERSION}

PORTDOCS=	*

.include <bsd.port.mk>
