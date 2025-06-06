PORTNAME=	lightdm-gtk-greeter-settings
PORTVERSION=	1.2.2
PORTREVISION=	4
CATEGORIES=	x11
MASTER_SITES=	https://launchpad.net/${PORTNAME}/${PORTVERSION:R}/${PORTVERSION}/+download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Settings editor for LightDM GTK Greeter
WWW=		https://launchpad.net/lightdm-gtk-greeter-settings

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	lightdm-gtk-greeter:x11/lightdm-gtk-greeter \
		${PYTHON_PKGNAMEPREFIX}python-distutils-extra>=2.38:devel/py-python-distutils-extra@${PY_FLAVOR}
LIB_DEPENDS=	liblightdm-gobject-1.so:x11/lightdm

USES=		gettext-tools gnome python
USE_GNOME=	intltool pygobject3
USE_PYTHON=	autoplist distutils noflavors

NO_ARCH=	yes
PLIST_FILES=	${PYTHON_SITELIBDIR}/lightdm_gtk_greeter_settings/installation_config.py
PYDISTUTILS_INSTALLARGS+=	--xfce-integration

post-patch:
	@${REINPLACE_CMD} -e "s,%%PREFIX%%,${PREFIX},g" \
		-e "s,%%LOCALBASE%%,${LOCALBASE},g" \
		${WRKSRC}/bin/lightdm-gtk-greeter-settings-pkexec \
		${WRKSRC}/lightdm_gtk_greeter_settings/helpers.py \
		${WRKSRC}/com.ubuntu.pkexec.lightdm-gtk-greeter-settings.policy.in \
		${WRKSRC}/setup.py
	@${RM} -v ${WRKSRC}/bin/lightdm-gtk-greeter-settings-pkexec.bak
	@${RM} -v ${WRKSRC}/bin/lightdm-gtk-greeter-settings-pkexec.orig
	@${RM} -v ${WRKSRC}/lightdm_gtk_greeter_settings/helpers.py.bak
	@${RM} -v ${WRKSRC}/lightdm_gtk_greeter_settings/helpers.py.orig
	@${RM} -v ${WRKSRC}/setup.py.bak
	@${RM} -v ${WRKSRC}/setup.py.orig

.include <bsd.port.pre.mk>

# PYDISTUTILS_INSTALLNOSINGLE is deprecated so...
PYDISTUTILS_INSTALLARGS:=	${PYDISTUTILS_INSTALLARGS:N--single-version-externally-managed}

.include <bsd.port.post.mk>
