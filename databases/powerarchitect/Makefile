PORTNAME=	powerarchitect
PORTVERSION=	1.0.9
CATEGORIES=	databases java
MASTER_SITES=	http://www.bestofbi.com/downloads/architect/${PORTVERSION}/
DISTNAME=	SQL-Power-Architect-generic-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Data modeling and profiling tool
WWW=		http://www.bestofbi.com/page/architect

LICENSE=	GPLv3

USES=		java
NO_ARCH=	yes
NO_BUILD=	yes
SUB_FILES=	${PORTNAME}

PORTDOCS=	*
DATADIR=	${JAVASHAREDIR}/${PORTNAME}
WRKSRC=		${WRKDIR}/architect-${PORTVERSION}

OPTIONS_DEFINE=	DOCS MYSQL_JDBC PGSQL_JDBC

MYSQL_JDBC_RUN_DEPENDS=	${JAVALIBDIR}/mysql-connector-java.jar:databases/mysql-connector-java
PGSQL_JDBC_RUN_DEPENDS=	${JAVALIBDIR}/postgresql.jar:databases/postgresql-jdbc

do-install:
	@${MKDIR} ${STAGEDIR}/${DATADIR}
	(cd ${WRKSRC}/ && \
		${INSTALL_DATA} architect.jar \
		${STAGEDIR}/${DATADIR}/ && \
		${COPYTREE_SHARE} lib ${STAGEDIR}/${DATADIR})
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} \
		${STAGEDIR}/${PREFIX}/bin/${PORTNAME}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}/${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.generic \
		${STAGEDIR}/${DOCSDIR}

.include <bsd.port.mk>
