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

GEM_MANUALS_SEC1=	${GEM_LIB_DIR}/man/irb.1

.include <bsd.port.pre.mk>
.if ${RUBY_VER} >= 2.7
PLIST_FILES=	bin/irb
.elif ${RUBY_VER} == 2.6
# WIP: irb wrapper script is installed by ruby port so far, see bug 241554, 237833
post-install:
	${RM} ${STAGEDIR}${PREFIX}/bin/irb
.else
IGNORE=		${PORTNAME} is included in lang/${RUBY_NAME}
.endif

.include <bsd.port.post.mk>
