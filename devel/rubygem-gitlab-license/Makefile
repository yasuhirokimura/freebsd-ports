PORTNAME=	gitlab-license
PORTVERSION=	2.6.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Generate, verify and enforce software licenses
WWW=		https://gitlab.com/gitlab-org/gitlab-chronic-duration

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	bash>0:shells/bash

USES=		gem shebangfix
SHEBANG_FILES=	bin/setup

NO_ARCH=	yes

.include <bsd.port.mk>
