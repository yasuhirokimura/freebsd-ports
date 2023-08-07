PORTNAME=	xhtml-basic
PORTVERSION=	1.0.${RECDATE}
PORTREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	https://www.w3.org/TR/2000/REC-xhtml-basic-${RECDATE}/
DISTNAME=	xhtml-basic

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	W3C's XHTML Basic DTD
WWW=		https://www.w3.org/TR/xhtml-basic/

LICENSE=	W3C_XHTML_BASIC_DTD
LICENSE_NAME=	License of W3C's XHTML Basic DTD
LICENSE_FILE=	${FILESDIR}/LICENSE
LICENSE_PERMS=	dist-mirror pkg-mirror auto-accept

RUN_DEPENDS=	${LOCALBASE}/share/xml/dtd/xhtml-modularization/catalog.xml:textproc/xhtml-modularization \
		xmlcatmgr:textproc/xmlcatmgr

USES=		tar:tgz

DATADIR=	${PREFIX}/share/xml/dtd/xhtml-basic
NO_ARCH=	yes
NO_BUILD=	yes
NO_MTREE=	yes
SUB_FILES=	catalog.xml

WRKSRC=		${WRKDIR}/REC-xhtml-basic-${RECDATE}

PLIST_FILES=	"@xmlcatmgr ${DATADIR}/catalog.xml"
PORTDATA=	xhtml-basic10-model-1.mod xhtml-basic10.cat xhtml-basic10.dtd \
		xml1.dcl
PORTDOCS=	Overview.html W3C-REC.css logo-REC.png w3c_home.png \
		xhtml-basic.css

OPTIONS_DEFINE=	DOCS

RECDATE=	20001219

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDATA} \
		${STAGEDIR}${DATADIR})
	${INSTALL_DATA} ${WRKDIR}/catalog.xml \
		${STAGEDIR}${DATADIR}/catalog.xml

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} \
		${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
