# Created by: Sergey Skvortsov <skv@protey.ru>

PORTNAME=	ExtUtils-MakeMaker-Coverage
PORTVERSION=	0.05
PORTREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Add a Makefile target to determine test coverage using Devel::Cover

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Devel-Cover>=0:devel/p5-Devel-Cover \
		p5-Object-Accessor>=0:devel/p5-Object-Accessor

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
