PORTNAME=	dnsflood
PORTVERSION=	1.20
CATEGORIES=	dns
MASTER_SITES=	ZI

MAINTAINER=	zi@FreeBSD.org
COMMENT=	DNS flood detector
WWW=		http://www.adotout.com/

LICENSE=	GPLv2

USES=		tar:tgz

WRKSRC=		${WRKDIR}/dns_flood_detector_1.2

PLIST_FILES=	sbin/dns_flood_detector
USE_RC_SUBR=	dnsflood
PORTDOCS=	README

OPTIONS_DEFINE=	DOCS

pre-patch:
	@${LN} -sf ${WRKSRC}/makefiles/Makefile-FreeBSD ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dns_flood_detector ${STAGEDIR}${PREFIX}/sbin

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in README
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
