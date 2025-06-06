PORTNAME=	gcc
PORTVERSION=	11.5.0
CATEGORIES=	lang
MASTER_SITES=	GCC
PKGNAMESUFFIX=	${SUFFIX}

MAINTAINER=	salvadore@FreeBSD.org
COMMENT=	GNU Compiler Collection 11
WWW=		https://gcc.gnu.org

LICENSE=	GPLv3 GPLv3RLE
LICENSE_COMB=	multi

ONLY_FOR_ARCHS=	aarch64 amd64 armv6 armv7 i386 powerpc powerpc64 powerpc64le riscv64
DEPRECATED=	End-of-life upstream since mid 2024, newer versions available
EXPIRATION_DATE=2025-07-19

LIB_DEPENDS=	libgmp.so:math/gmp \
		libmpfr.so:math/mpfr \
		libmpc.so:math/mpc
BUILD_DEPENDS+=	${LOCALBASE}/bin/as:devel/binutils
RUN_DEPENDS+=	${LOCALBASE}/bin/as:devel/binutils
.if defined(MAINTAINER_MODE)
BUILD_DEPENDS+=	runtest:misc/dejagnu
.endif

USES=		compiler:c++11-lang cpe gmake iconv libtool makeinfo perl5 tar:xz
USE_BINUTILS=	yes
USE_PERL5=	build

CONFLICTS=	gcc11-devel

CPE_VENDOR=	gnu

GCC_VERSION=	${PORTVERSION}
SUFFIX=		${PORTVERSION:C/([0-9]+).*/\1/}
CFLAGS:=	${CFLAGS:N-mretpoline}
CXXFLAGS:=	${CXXFLAGS:N-mretpoline}

OPTIONS_DEFINE=		GRAPHITE
GRAPHITE_DESC=		Support for Graphite loop optimizations
OPTIONS_DEFAULT_aarch64=STANDARD_BOOTSTRAP
OPTIONS_DEFAULT_amd64=	STANDARD_BOOTSTRAP
OPTIONS_DEFAULT_i386=	STANDARD_BOOTSTRAP
OPTIONS_DEFAULT_powerpc=LTO_BOOTSTRAP
OPTIONS_DEFAULT_powerpc64=LTO_BOOTSTRAP
OPTIONS_DEFAULT_powerpc64le=LTO_BOOTSTRAP
OPTIONS_RADIO=	BOOTSTRAP
OPTIONS_RADIO_BOOTSTRAP=	LTO_BOOTSTRAP STANDARD_BOOTSTRAP
LTO_BOOTSTRAP_DESC=	Build using a full LTO bootstrap
STANDARD_BOOTSTRAP_DESC=	Build using a full bootstrap without LTO

.if exists(/usr/lib32/libc.so)
OPTIONS_DEFINE_amd64+=		MULTILIB
OPTIONS_DEFAULT_amd64+=	MULTILIB
OPTIONS_DEFINE_powerpc64+=	MULTILIB
#OPTIONS_DEFAULT_powerpc64+=	MULTILIB # https://gcc.gnu.org/bugzilla/show_bug.cgi?id=105010
MULTILIB_DESC=		Build support for 32-bit and 64-bit targets
MULTILIB_CONFIGURE_ENABLE=	multilib
.else
CONFIGURE_ARGS+=	--disable-multilib
.endif

.if defined(CPUTYPE) && ${CPUTYPE:Mg[3-5]}
CFLAGS:=	${CFLAGS:S/mcpu=g/mcpu=G/}
CXXFLAGS:=	${CFLAGS:S/mcpu=g/mcpu=G/}
.endif

.include <bsd.port.pre.mk>

# Extraction fails with poudriere on aarch64 for GCC 11.
# It seems that the bug is specific to lang/gcc11 and lang/gcc12 only.
# No other GCC port is affected.
# See https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=271052
# and https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=246670
.if ${ARCH} == aarch64
EXTRACT_CMD=    ${SETENV} LC_ALL=en_US.UTF-8 /usr/bin/bsdtar
.endif

.if ${ARCH} == amd64
CONFIGURE_TARGET=	x86_64-portbld-${OPSYS:tl}${OSREL}

.elif ${ARCH} == powerpc64
CONFIGURE_ARGS+=	--with-abi=elfv2
.endif

LANGUAGES:=	c,c++,d,objc,fortran,jit
TARGLIB=	${PREFIX}/lib/gcc${SUFFIX}
TARGLIB32=	${PREFIX}/lib32	# The version information is added later
LIBEXEC=	${PREFIX}/libexec/gcc${SUFFIX}
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CONFIGURE_OUTSOURCE=	yes
.if empty(PORT_OPTIONS:M*BOOTSTRAP)
CONFIGURE_ARGS+=--disable-bootstrap
.elif ${PORT_OPTIONS:MLTO_BOOTSTRAP}
CONFIGURE_ARGS+=--with-build-config=bootstrap-lto-noplugin
ALL_TARGET=	bootstrap-lean
PIE_UNSAFE=	yes
.else
CONFIGURE_ARGS+=--with-build-config=bootstrap-debug
ALL_TARGET=	bootstrap-lean
PIE_UNSAFE=	yes
.endif
INSTALL_TARGET=	install-strip
.if ${UID} != 0
BINMODE=	755
.endif
CONFIGURE_ARGS+=--disable-nls \
		--disable-libssp \
		--enable-gnu-indirect-function \
		--enable-host-shared \
		--enable-plugin \
		--libdir=${TARGLIB} \
		--libexecdir=${LIBEXEC} \
		--program-suffix=${SUFFIX} \
		--with-as=${LOCALBASE}/bin/as \
		--with-gmp=${LOCALBASE} \
		--with-gxx-include-dir=${TARGLIB}/include/c++/ \
		--with-gxx-libcxx-include-dir=/usr/include/c++/v1 \
		--with-ld=${LOCALBASE}/bin/ld \
		${ICONV_CONFIGURE_ARG} \
		--with-pkgversion="FreeBSD Ports Collection" \
		--with-system-zlib \
		--without-zstd
MAKE_ARGS+=	MAKEINFOFLAGS="--no-split"
USE_LDCONFIG=	${TARGLIB}
PLIST_SUB+=	GCC_VERSION=${GCC_VERSION} \
		GNU_HOST=${CONFIGURE_TARGET} \
		SUFFIX=${SUFFIX}
INFO=		gcc${SUFFIX}/cpp \
		gcc${SUFFIX}/cppinternals \
		gcc${SUFFIX}/gcc \
		gcc${SUFFIX}/gccinstall \
		gcc${SUFFIX}/gccint \
		gcc${SUFFIX}/gdc \
		gcc${SUFFIX}/gfortran \
		gcc${SUFFIX}/libgccjit \
		gcc${SUFFIX}/libgomp
# Release tarballs (as opposed to snapshots) always carry this.
INFO+=		gcc${SUFFIX}/libquadmath \
		gcc${SUFFIX}/libitm
SUB_FILES=	pkg-message
SUB_LIST+=	TARGLIB=${TARGLIB}

.if ${PORT_OPTIONS:MGRAPHITE}
LIB_DEPENDS+=	libisl.so:devel/isl
CONFIGURE_ARGS+=--with-isl=${LOCALBASE}
.endif

CONFIGURE_ARGS+=--enable-languages=${LANGUAGES}

.if (${ARCH} == amd64 || ${ARCH} == powerpc64) && ${PORT_OPTIONS:MMULTILIB}
USE_LDCONFIG32=	${TARGLIB32}/gcc${SUFFIX}
.endif

pre-everything::
	@${ECHO_MSG} "Making GCC ${PORTVERSION} for ${CONFIGURE_TARGET} [${LANGUAGES}]"

pre-configure:
	cd ${WRKSRC} ; contrib/gcc_update --touch
	@${RM} ${WRKSRC}/gcc/*/*.info*

.if defined(MAINTAINER_MODE)
full-regression-test: build
	cd ${TEST_WRKSRC}; ${MAKE_CMD} -sk check \
	; ${WRKSRC}/contrib/test_summary
.endif

post-stage:
	${RM} ${STAGEDIR}${PREFIX}/share/man/man7/*
	${RM} -r ${STAGEDIR}${TARGLIB}/gcc/*/${GCC_VERSION}/include-fixed/
	# Add target libraries and include files to packaging list.
	${RM} ${WRKDIR}/PLIST.lib

.if (${ARCH} == amd64 || ${ARCH} == powerpc64) && ${PORT_OPTIONS:MMULTILIB}
	${MKDIR} ${STAGEDIR}${TARGLIB32}
	${MV} ${STAGEDIR}${PREFIX}/lib/lib32 ${STAGEDIR}${TARGLIB32}/gcc${SUFFIX}
.endif

.for d in ${TARGLIB:S/^${PREFIX}\///} ${TARGLIB32:S/^${PREFIX}\///} ${LIBEXEC:S/^${PREFIX}\///}
	cd ${STAGEDIR}${PREFIX} ; if [ -d $d ]; then \
	    ${FIND} $d -type f -o -type l >>${WRKDIR}/PLIST.lib ;\
	fi
.endfor
	cd ${WRKDIR} ; ${SED} -i -e "/PLIST.lib/ r PLIST.lib" ${TMPPLIST}

.include <bsd.port.post.mk>
