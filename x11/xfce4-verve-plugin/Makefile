PORTNAME=	verve-plugin
PORTVERSION=	2.0.4
CATEGORIES=	x11 xfce
MASTER_SITES=	XFCE/panel-plugins
PKGNAMEPREFIX=	xfce4-
DISTNAME=	${PKGNAMEPREFIX}${PORTNAME}-${DISTVERSIONFULL}
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Command line plugin for the Xfce Desktop
WWW=		https://docs.xfce.org/panel-plugins/xfce4-verve-plugin/start

LICENSE=	GPLv2

LIB_DEPENDS=	libharfbuzz.so:print/harfbuzz \
		libpcre2-8.so:devel/pcre2

USES=		compiler:c11 gettext-tools gmake gnome libtool pkgconfig \
		tar:bzip2 xfce
USE_GNOME=	atk cairo gdkpixbuf glib20 gtk30 pango
USE_XFCE=	libmenu panel

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-dbus
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=		gettext-runtime
NLS_CONFIGURE_ENABLE=	nls

.include <bsd.port.mk>
