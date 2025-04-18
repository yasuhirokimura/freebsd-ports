PORTNAME=	minetest_game
PORTVERSION=	5.8.0.20241016
CATEGORIES=	games

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	The main game for the Minetest game engine
WWW=		https://www.minetest.net/ \
		https://github.com/minetest/minetest_game

LICENSE=	LGPL21+ CC-BY-SA-3.0
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	luanti>=0:games/luanti

USE_GITHUB=	yes
GH_ACCOUNT=	minetest
GH_TAGNAME=	093cd28

NO_BUILD=	yes
NO_ARCH=	yes
DATADIR=	${PREFIX}/share/luanti/games/${PORTNAME}
PORTDATA=	*
PORTDOCS=	README.md game_api.txt schematic_tables.txt settingtypes.txt
PORTEXAMPLES=	*

OPTIONS_DEFINE=	DOCS EXAMPLES

do-install:
	cd ${WRKSRC} && ${COPYTREE_SHARE} "game.conf menu mods" ${STAGEDIR}${DATADIR}/

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}/
.endfor

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/minetest.conf.example ${STAGEDIR}${EXAMPLESDIR}/

.include <bsd.port.mk>
