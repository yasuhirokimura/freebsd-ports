PORTNAME=	pyobfuscate
PORTVERSION=	0.3.20131129
PORTREVISION=	2
CATEGORIES=	devel

MAINTAINER=	cs@FreeBSD.org
COMMENT=	Python source code obfuscator
WWW=		https://github.com/astrand/pyobfuscate

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	astrand
GH_TAGNAME=	47cc6e49bf65649c9fc53fbf4ae7d6e23b565550

USES=		python shebangfix
USE_PYTHON=	distutils autoplist concurrent optsuffix
NO_ARCH=	yes
SHEBANG_FILES=	*.py pyobfuscate pyobfuscate-install

post-patch:
	@${REINPLACE_CMD} -e "s,'/usr/bin','${PREFIX}/bin'," ${WRKSRC}/setup.py

.include <bsd.port.mk>
