PORTNAME=	postgresql
# Keep the ?=, it is used by the other pltcl ports.
PORTREVISION?=	0
CATEGORIES=	databases tcl
PKGNAMESUFFIX?=	${WANT_PGSQL_VER}${COMPONENT}

MAINTAINER=	pgsql@FreeBSD.org
COMMENT=	Module for using Tcl to write SQL functions

MASTERDIR=	${.CURDIR}/../../databases/postgresql${WANT_PGSQL_VER}-server

WANT_PGSQL_VER?=18

USES+=		tcl pgsql:${WANT_PGSQL_VER}
WANT_PGSQL=	server

CONFIGURE_ARGS=	--with-tcl --without-tk \
		--with-tclconfig="${TCL_LIBDIR}" \
		--with-includes="${TCL_INCLUDEDIR}"

CONFIGURE_ENV+=	TCLSH="${TCLSH}"
MAKE_ENV+=	TCL_INCDIR="${TCL_INCLUDEDIR}"

BUILD_DIRS=	src/backend src/pl/tcl
INSTALL_DIRS=	src/pl/tcl
SLAVE_ONLY=	yes
COMPONENT=	-pltcl

# this port fails to build in parallel
MAKE_JOBS_UNSAFE=	yes

.include "${MASTERDIR}/Makefile"
