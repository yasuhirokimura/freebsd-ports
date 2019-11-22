PORTNAME=	irb
PORTVERSION=	1.3.6
PORTREVISION=	1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	meta@FreeBSD.org
COMMENT=	Interactive Ruby

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-reline>=0.2.5:devel/rubygem-reline

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.pre.mk>

PLIST_FILES=	bin/irb \
		share/man/man1/irb.1.gz

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/man/man1
	${INSTALL_DATA} ${WRKSRC}/man/irb.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.post.mk>
