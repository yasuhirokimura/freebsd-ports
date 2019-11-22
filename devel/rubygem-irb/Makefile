PORTNAME=	irb
PORTVERSION=	1.3.6
PORTREVISION=	2
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

PLIST_FILES=	bin/irb

.include <bsd.port.mk>
