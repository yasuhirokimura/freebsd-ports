PORTNAME=	jruby-jars
PORTVERSION=	9.2.21.0
CATEGORIES=	devel rubygems java
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	JAR files from the JRuby distribution
WWW=		https://github.com/jruby/jruby/tree/master/maven/jruby-jars

LICENSE=	EPL GPLv2 LGPL21
LICENSE_COMB=	dual

BUILD_DEPENDS=	jgem:lang/jruby
RUN_DEPENDS=	jruby:lang/jruby

USES=		gem java

RUBYGEMBIN=	${LOCALBASE}/bin/jgem

NO_ARCH=	yes

.include <bsd.port.mk>
