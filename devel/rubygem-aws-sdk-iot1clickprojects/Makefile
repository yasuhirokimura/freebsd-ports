PORTNAME=	aws-sdk-iot1clickprojects
PORTVERSION=	1.65.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Official AWS Ruby gem for AWS IoT 1-Click Projects Service (AWS IoT 1-Click Projects)
WWW=		https://github.com/aws/aws-sdk-ruby/tree/version-3/gems/aws-sdk-iot1clickprojects

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

DEPRECATED=	Deprecated by upstream
EXPIRATION_DATE=2025-02-28

RUN_DEPENDS=	rubygem-aws-sdk-core>=3.210.0<4:devel/rubygem-aws-sdk-core \
		rubygem-aws-sigv4>=1.5<2:devel/rubygem-aws-sigv4

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
