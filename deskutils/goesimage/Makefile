PORTNAME=	goesimage
DISTVERSION=	0.1.4
PORTREVISION=	1
CATEGORIES=	deskutils

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Wallpapers from NOAA Geostationary Operational Environment Satellite
WWW=		https://github.com/pigmonkey/goesimage

LICENSE=	UNLICENSE
LICENSE_FILE=	${WRKSRC}/UNLICENSE

RUN_DEPENDS=	bash:shells/bash \
		curl:ftp/curl \
		nitrogen:sysutils/nitrogen

USES=		magick:6,run shebangfix
SHEBANG_FILES=	goesimage

USE_GITHUB=	yes
GH_ACCOUNT=	pigmonkey

NO_BUILD=	yes
NO_ARCH=	yes

SUB_LIST=	PORTNAME=${PORTNAME}
SUB_FILES=	crontab

RUN_ARGS=	-w -e -o # -w: NOAA GOES West satellite, -e: NOAA GOES East satellite, -o: print output, don't set as a wallpaper (it is set by nitrogen)

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/libexec/
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKDIR}/crontab ${STAGEDIR}${DATADIR}
	@(echo "#!/bin/sh"; \
	  echo ""; \
	  echo "crontab -l | ${GREP} -v '${PREFIX}/bin/${PORTNAME}' | (cat ; cat ${DATADIR}/crontab) | crontab -"; \
	) > ${STAGEDIR}${PREFIX}/bin/${PORTNAME}-enable
	@(echo "#!/bin/sh"; \
	  echo ""; \
	  echo "crontab -l | ${GREP} -v '${PREFIX}/bin/${PORTNAME}' | crontab -"; \
	) > ${STAGEDIR}${PREFIX}/bin/${PORTNAME}-disable
	@(echo "#!/bin/sh"; \
	  echo ""; \
	  echo "${PREFIX}/bin/nitrogen --set-zoom "$$"(${PREFIX}/libexec/${PORTNAME} ${RUN_ARGS})"; \
	) > ${STAGEDIR}${PREFIX}/bin/${PORTNAME}-run-now
	@cd ${STAGEDIR}${PREFIX}/bin && ${CHMOD} +x ${PORTNAME}-enable ${PORTNAME}-disable ${PORTNAME}-run-now

.include <bsd.port.mk>
