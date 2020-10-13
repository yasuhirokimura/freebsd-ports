PORTNAME=	pfsyslogd
DISTVERSION=	1.0
CATEGORIES=	sysutils

MAINTAINER=	yasu@utahime.org
COMMENT=	Daemon program reading pf log and sending it to syslog
WWW=		https://github.com/yasuhirokimura/pfsyslogd

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS+=	rubygem-syslog>0:devel/rubygem-syslog

USES=		ruby:run
USE_GITHUB=	yes
GH_ACCOUNT=	yasuhirokimura
USE_RC_SUBR=	pfsyslogd

MAKE_ENV=	PFLOG_INTERFACE=${PFLOG_INTERFACE} \
		RUBY=${RUBY} \
		TCPDUMP=${TCPDUMP} \
		UNPRIVILEGED_USER=${UNPRIVILEGED_USER}
ALL_TARGET=	pfsyslogd

SUB_LIST=	RUBY=${RUBY}

# None. portlint compliance
BASEDIR?=
TCPDUMP=		${BASEDIR}/usr/sbin/tcpdump
UNPRIVILEGED_USER=	nobody
PFLOG_INTERFACE=	pflog0

PLIST_FILES=	sbin/pfsyslogd
PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
