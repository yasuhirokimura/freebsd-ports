PORTNAME=	PDF-Table
PORTVERSION=	1.007
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Utility class for building table layouts in a PDF::API2 object
WWW=		https://metacpan.org/release/PDF-Table

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-PDF-API2>=0:textproc/p5-PDF-API2

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

OPTIONS_DEFINE=	EXAMPLES

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
