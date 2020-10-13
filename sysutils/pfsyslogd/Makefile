PORTNAME=	pfsyslogd
DISTVERSION=	1.0
CATEGORIES=	sysutils

MAINTAINER=	yasu@utahime.org
COMMENT=	Daemon program reading pf log and sending it to syslog

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	yasuhirokimura

USE_RUBY=	yes
RUBY_NO_BUILD_DEPENDS=	yes

ALL_TARGET=	pfsyslogd

PLIST_FILES=	sbin/pfsyslogd

USE_RC_SUBR=	pfsyslogd
SUB_LIST=	RUBY=${RUBY}

# None. portlint compliance
BASEDIR?=
TCPDUMP=		${BASEDIR}/usr/sbin/tcpdump
UNPRIVILEGED_USER=	nobody
PFLOG_INTERFACE=	pflog0

MAKE_ENV=	PFLOG_INTERFACE=${PFLOG_INTERFACE} \
		RUBY=${RUBY} \
		TCPDUMP=${TCPDUMP} \
		UNPRIVILEGED_USER=${UNPRIVILEGED_USER}

PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
