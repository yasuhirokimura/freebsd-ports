# Created by: Robert Gogolok <gogo@cs.uni-sb.de>

PORTNAME=	bundler
PORTVERSION=	2.2.23
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	sysutils rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Tool that manages gem dependencies for Ruby applications

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

PLIST_FILES=	bin/bundle bin/bundler
GEM_MANUALS_SEC1=	${GEM_LIB_DIR}/lib/bundler/man/bundle-add.1	\
			${GEM_LIB_DIR}/lib/bundler/man/bundle-binstubs.1 \
			${GEM_LIB_DIR}/lib/bundler/man/bundle-cache.1 \
			${GEM_LIB_DIR}/lib/bundler/man/bundle-check.1 \
			${GEM_LIB_DIR}/lib/bundler/man/bundle-clean.1 \
			${GEM_LIB_DIR}/lib/bundler/man/bundle-config.1 \
			${GEM_LIB_DIR}/lib/bundler/man/bundle-doctor.1 \
			${GEM_LIB_DIR}/lib/bundler/man/bundle-exec.1 \
			${GEM_LIB_DIR}/lib/bundler/man/bundle-gem.1 \
			${GEM_LIB_DIR}/lib/bundler/man/bundle-info.1 \
			${GEM_LIB_DIR}/lib/bundler/man/bundle-init.1 \
			${GEM_LIB_DIR}/lib/bundler/man/bundle-inject.1 \
			${GEM_LIB_DIR}/lib/bundler/man/bundle-install.1 \
			${GEM_LIB_DIR}/lib/bundler/man/bundle-list.1 \
			${GEM_LIB_DIR}/lib/bundler/man/bundle-lock.1 \
			${GEM_LIB_DIR}/lib/bundler/man/bundle-open.1 \
			${GEM_LIB_DIR}/lib/bundler/man/bundle-outdated.1 \
			${GEM_LIB_DIR}/lib/bundler/man/bundle-platform.1 \
			${GEM_LIB_DIR}/lib/bundler/man/bundle-pristine.1 \
			${GEM_LIB_DIR}/lib/bundler/man/bundle-remove.1 \
			${GEM_LIB_DIR}/lib/bundler/man/bundle-show.1 \
			${GEM_LIB_DIR}/lib/bundler/man/bundle-update.1 \
			${GEM_LIB_DIR}/lib/bundler/man/bundle-viz.1 \
			${GEM_LIB_DIR}/lib/bundler/man/bundle.1
GEM_MANUALS_SEC5=	${GEM_LIB_DIR}/lib/bundler/man/gemfile.5

.include <bsd.port.mk>
