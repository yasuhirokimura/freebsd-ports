PORTNAME=	CAD-Drawing
PORTVERSION=	0.26
PORTREVISION=	12
CATEGORIES=	graphics perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Methods to create, load, and save vector graphics
WWW=		https://metacpan.org/release/CAD-Drawing

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-CAD-Calc>=0:math/p5-CAD-Calc \
		p5-Math-Geometry-Planar>=0:math/p5-Math-Geometry-Planar \
		p5-Math-MatrixReal>=0:math/p5-Math-MatrixReal \
		p5-Math-Vec>=0:math/p5-Math-Vec \
		p5-Stream>=0:devel/p5-Stream

USES=		magick:6,run perl5
USE_PERL5=	modbuild

.include <bsd.port.mk>
