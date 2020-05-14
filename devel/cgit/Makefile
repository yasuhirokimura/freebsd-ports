PORTNAME=	cgit
DISTVERSION=	1.2.3-70
PORTREVISION=	2
CATEGORIES=	devel www
MASTER_SITES=	http://git.zx2c4.com/cgit/snapshot/:cgit \
		KERNEL_ORG/software/scm/git:git
DISTNAME=	cgit-${CGIT_HASH}
DISTFILES=	cgit-${CGIT_HASH}${EXTRACT_SUFX}:cgit \
		git-${GIT_VERSION}${EXTRACT_SUFX}:git

MAINTAINER=	mt@markoturk.info
COMMENT=	Fast, lightweight web frontend for Git repositories
WWW=		https://git.zx2c4.com/cgit/about/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

TEST_DEPENDS=	msgfmt:devel/gettext-tools

CGIT_HASH=	09d24d7
GIT_VERSION=	2.52.0
USES=		compiler:c++11-lang cpe gmake iconv perl5 python:env shebangfix \
		ssl tar:xz
CPE_VENDOR=	lars_hjemli
USE_PERL5=	test
SHEBANG_FILES=	filters/email-gravatar.py filters/html-converters/md2html \
		filters/html-converters/rst2html filters/syntax-highlighting.py

MAKE_ARGS+=	CGIT_CONFIG=${PREFIX}/etc/cgitrc \
		CGIT_SCRIPT_PATH=${WWWDIR} \
		NO_GETTEXT=1 \
		NO_LUA=1 \
		NO_R_TO_GCC_LINKER=1 \
		prefix=${PREFIX} \
		V=1

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib ${ICONV_LIB}
SUB_FILES=	pkg-message

PORTDOCS=	${PORTNAME}rc.5.txt

OPTIONS_DEFINE=		ASCIIDOC DOCS
OPTIONS_DEFAULT=	ASCIIDOC
OPTIONS_SUB=		yes

ASCIIDOC_DESC=		Use asciidoc to preprocess man page
ASCIIDOC_BUILD_DEPENDS=	a2x:textproc/asciidoc

post-extract:
	@${RMDIR} ${WRKSRC}/git
	@${MV} ${WRKDIR}/git-${GIT_VERSION} ${WRKSRC}/git

post-patch:
	@${REINPLACE_CMD} -e 's/^\(GIT_VER =\).*$$/\1 ${GIT_VERSION}/' \
		${WRKSRC}/Makefile

	@${REINPLACE_CMD} -e 's/-liconv/${ICONV_LIB}/' \
		-e "s|\(ALL_CFLAGS =\)|\1 -I${OPENSSLINC}|g" \
		-e "s|\(ALL_LDFLAGS =\)|\1 -L${OPENSSLLIB}|g" \
		${WRKSRC}/git/Makefile

post-install:
	${STRIP_CMD} ${STAGEDIR}${WWWDIR}/cgit.cgi

post-install-ASCIIDOC-on:
	a2x --doctype manpage --format manpage ${WRKSRC}/cgitrc.5.txt
	${INSTALL_MAN} ${WRKSRC}/cgitrc.5 ${STAGEDIR}${PREFIX}/share/man/man5

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
