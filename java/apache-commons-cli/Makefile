PORTNAME=	commons-cli
PORTVERSION=	1.4
CATEGORIES=	java devel
MASTER_SITES=	APACHE_COMMONS_BINARIES
PKGNAMEPREFIX=	apache-
DISTNAME=	${PORTNAME}-${PORTVERSION}-bin

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Java library for command line arguments and options
WWW=		https://commons.apache.org/proper/commons-cli/

LICENSE=	APACHE20

USES=		java

NO_BUILD=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

JARFILE=	${PORTNAME}-${PORTVERSION}.jar
DESTJARFILE=	${PORTNAME}.jar
PLIST_FILES=	%%JAVAJARDIR%%/${DESTJARFILE}
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_DATA} ${WRKSRC}/${JARFILE} \
		${STAGEDIR}${JAVAJARDIR}/${DESTJARFILE}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} apidocs ${STAGEDIR}${DOCSDIR})
	(cd ${WRKSRC} && ${INSTALL_DATA} LICENSE.txt NOTICE.txt \
		RELEASE-NOTES.txt ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
