PORTNAME=	zix
DISTVERSION=	0.6.2
CATEGORIES=	devel
MASTER_SITES=	http://download.drobilla.net/

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Lightweight C library of portability wrappers and data structures
WWW=		https://drobilla.net/category/zix/

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/glib-2.0.pc:devel/glib20

USES=		meson pkgconfig python:build tar:xz
USE_LDCONFIG=	yes
MESON_ARGS=	-Db_lundef=false \
		-Ddocs=disabled
#-Db_lundef=false: https://github.com/drobilla/zix/issues/9

PLIST_SUB=	VERSION=${DISTVERSION}

.include <bsd.port.mk>
