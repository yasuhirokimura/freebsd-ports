PORTNAME=	arrow
PORTVERSION=	18.0.0
PORTREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	APACHE/arrow/arrow-${PORTVERSION}/
PKGNAMESUFFIX=	-glib
DISTNAME=	apache-arrow-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	C API wrapper library for Arrow C++
WWW=		https://arrow.apache.org/ \
		https://github.com/apache/arrow/tree/master/c_glib

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/../LICENSE.txt

BUILD_DEPENDS=	arrow>=${PORTVERSION}:databases/arrow
LIB_DEPENDS=	libarrow.so:databases/arrow

USES=		compiler:c++17-lang gnome meson pkgconfig python:build
USE_GNOME=	introspection

BINARY_ALIAS=	python3=${PYTHON_CMD}
MESON_ARGS=	--default-library=both \
		-Darrow_cpp_build_dir='' \
		-Darrow_cpp_build_type='release' \
		-Ddoc=false \
		-Dgtk_doc=false \
		-Dsource_reference='main' \
		-Dvapi=false
WRKSRC_SUBDIR=	c_glib

PLIST_SUB=	SHLIB_VER=${PORTVERSION:R:R}00

.include <bsd.port.mk>
