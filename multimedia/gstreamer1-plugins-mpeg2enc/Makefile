PORTREVISION=	0
CATEGORIES=	multimedia

COMMENT=	GStreamer mpeg encoder plugin

BROKEN_armv6=	fails to compile: 'format_codes.h' file not found
BROKEN_armv7=	fails to compile: 'format_codes.h' file not found

LIB_DEPENDS=	libmjpegutils.so:multimedia/mjpegtools

MESON_ARGS+=	-Dgpl=enabled

MASTERDIR=	${.CURDIR:H:H}/multimedia/gstreamer1-plugins

PLIST=		${.CURDIR}/pkg-plist

DIST=		bad
GST_PLUGIN=	mpeg2enc

.include "${MASTERDIR}/Makefile"
