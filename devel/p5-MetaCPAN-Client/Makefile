PORTNAME=	MetaCPAN-Client
PORTVERSION=	2.033000
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:MICKEY
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Comprehensive, DWIM-featured client to the MetaCPAN API
WWW=		https://metacpan.org/release/MetaCPAN-Client

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-IO-Socket-SSL>=1.42:security/p5-IO-Socket-SSL \
		p5-JSON-MaybeXS>=0:converters/p5-JSON-MaybeXS \
		p5-Moo>=0:devel/p5-Moo \
		p5-Net-SSLeay>=1.49:security/p5-Net-SSLeay \
		p5-Ref-Util>=0:devel/p5-Ref-Util \
		p5-Safe-Isa>=0:devel/p5-Safe-Isa \
		p5-Type-Tiny>=0:devel/p5-Type-Tiny \
		p5-URI>=0:net/p5-URI
TEST_DEPENDS=	p5-LWP-Protocol-https>=0:www/p5-LWP-Protocol-https \
		p5-Test-Fatal>=0:devel/p5-Test-Fatal \
		p5-Test-Needs>=0.002005:devel/p5-Test-Needs

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
