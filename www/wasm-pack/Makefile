PORTNAME=	wasm-pack
DISTVERSIONPREFIX=	v
DISTVERSION=	0.13.1
PORTREVISION=	7
CATEGORIES=	www

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Workflow tool for Rust-generated WebAssembly
WWW=		https://rustwasm.github.io/wasm-pack/ \
		https://github.com/rustwasm/wasm-pack

LICENSE=	APACHE20 MIT
LICENSE_COMB=	dual
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE-APACHE
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE-MIT

BUILD_DEPENDS=	gmake:devel/gmake \
		zstd>0:archivers/zstd
LIB_DEPENDS=	libcurl.so:ftp/curl

USES=		cargo perl5 pkgconfig
USE_PERL5=	build

USE_GITHUB=	yes
GH_ACCOUNT=	rustwasm

RUSTFLAGS=	${ARCH:S/i386/YES/:C/^[a-z].*//:S/YES/-C target-feature=+sse,+sse2/} # add sse sse2 target-features only on i386

CARGO_CRATES=	addr2line-0.24.2 \
		adler2-2.0.0 \
		aes-0.8.4 \
		aho-corasick-1.1.3 \
		android-tzdata-0.1.1 \
		android_system_properties-0.1.5 \
		anstream-0.6.17 \
		anstyle-1.0.9 \
		anstyle-parse-0.2.6 \
		anstyle-query-1.1.2 \
		anstyle-wincon-3.0.6 \
		anyhow-1.0.91 \
		arbitrary-1.3.2 \
		assert_cmd-2.0.16 \
		autocfg-1.4.0 \
		backtrace-0.3.74 \
		base64-0.22.1 \
		binary-install-0.4.1 \
		bitflags-2.6.0 \
		block-buffer-0.10.4 \
		bstr-1.10.0 \
		bumpalo-3.16.0 \
		byteorder-1.5.0 \
		bzip2-0.4.4 \
		bzip2-sys-0.1.11+1.0.8 \
		camino-1.1.9 \
		cargo-platform-0.1.8 \
		cargo_metadata-0.15.4 \
		cc-1.1.31 \
		cfg-if-1.0.0 \
		chrono-0.4.38 \
		cipher-0.4.4 \
		clap-4.5.20 \
		clap_builder-4.5.20 \
		clap_derive-4.5.18 \
		clap_lex-0.7.2 \
		colorchoice-1.0.3 \
		console-0.15.8 \
		constant_time_eq-0.3.1 \
		core-foundation-sys-0.8.7 \
		cpufeatures-0.2.14 \
		crc-3.2.1 \
		crc-catalog-2.4.0 \
		crc32fast-1.4.2 \
		crossbeam-utils-0.8.20 \
		crypto-common-0.1.6 \
		dashmap-5.5.3 \
		deflate64-0.1.9 \
		deranged-0.3.11 \
		derive_arbitrary-1.3.2 \
		dialoguer-0.10.4 \
		difflib-0.4.0 \
		digest-0.10.7 \
		dirs-next-2.0.0 \
		dirs-sys-next-0.1.2 \
		displaydoc-0.2.5 \
		doc-comment-0.3.3 \
		either-1.13.0 \
		encode_unicode-0.3.6 \
		env_logger-0.10.2 \
		equivalent-1.0.1 \
		errno-0.3.9 \
		fastrand-2.1.1 \
		filetime-0.2.25 \
		flate2-1.0.34 \
		float-cmp-0.9.0 \
		form_urlencoded-1.2.1 \
		fs4-0.6.6 \
		futures-0.3.31 \
		futures-channel-0.3.31 \
		futures-core-0.3.31 \
		futures-executor-0.3.31 \
		futures-io-0.3.31 \
		futures-sink-0.3.31 \
		futures-task-0.3.31 \
		futures-util-0.3.31 \
		generic-array-0.14.7 \
		getrandom-0.2.15 \
		gimli-0.31.1 \
		glob-0.3.1 \
		hashbrown-0.14.5 \
		hashbrown-0.15.0 \
		heck-0.5.0 \
		hex-0.4.3 \
		hmac-0.12.1 \
		home-0.5.9 \
		human-panic-1.2.3 \
		iana-time-zone-0.1.61 \
		iana-time-zone-haiku-0.1.2 \
		idna-0.5.0 \
		indexmap-2.6.0 \
		inout-0.1.3 \
		is_executable-0.1.2 \
		is_terminal_polyfill-1.70.1 \
		itoa-1.0.11 \
		jobserver-0.1.32 \
		js-sys-0.3.72 \
		lazy_static-1.5.0 \
		libc-0.2.161 \
		libredox-0.1.3 \
		linux-raw-sys-0.4.14 \
		lock_api-0.4.12 \
		lockfree-object-pool-0.1.6 \
		log-0.4.22 \
		lzma-rs-0.3.0 \
		memchr-2.7.4 \
		miniz_oxide-0.8.0 \
		normalize-line-endings-0.3.0 \
		num-conv-0.1.0 \
		num-traits-0.2.19 \
		object-0.36.5 \
		once_cell-1.20.2 \
		os_info-3.8.2 \
		parking_lot-0.12.3 \
		parking_lot_core-0.9.10 \
		path-clean-1.0.1 \
		pbkdf2-0.12.2 \
		percent-encoding-2.3.1 \
		pin-project-lite-0.2.15 \
		pin-utils-0.1.0 \
		pkg-config-0.3.31 \
		powerfmt-0.2.0 \
		ppv-lite86-0.2.20 \
		predicates-3.1.2 \
		predicates-core-1.0.8 \
		predicates-tree-1.0.11 \
		proc-macro2-1.0.89 \
		quote-1.0.37 \
		rand-0.8.5 \
		rand_chacha-0.3.1 \
		rand_core-0.6.4 \
		redox_syscall-0.5.7 \
		redox_users-0.4.6 \
		regex-1.11.1 \
		regex-automata-0.4.8 \
		regex-syntax-0.8.5 \
		ring-0.17.8 \
		rustc-demangle-0.1.24 \
		rustix-0.38.38 \
		rustls-0.23.16 \
		rustls-pki-types-1.10.0 \
		rustls-webpki-0.102.8 \
		ryu-1.0.18 \
		same-file-1.0.6 \
		scopeguard-1.2.0 \
		semver-1.0.23 \
		serde-1.0.214 \
		serde_derive-1.0.214 \
		serde_ignored-0.1.10 \
		serde_json-1.0.132 \
		serde_spanned-0.6.8 \
		serial_test-2.0.0 \
		serial_test_derive-2.0.0 \
		sha1-0.10.6 \
		shell-words-1.1.0 \
		shlex-1.3.0 \
		simd-adler32-0.3.7 \
		siphasher-0.3.11 \
		slab-0.4.9 \
		smallvec-1.13.2 \
		socks-0.3.4 \
		spin-0.9.8 \
		strsim-0.10.0 \
		strsim-0.11.1 \
		subtle-2.6.1 \
		syn-2.0.85 \
		tar-0.4.42 \
		tempfile-3.13.0 \
		termtree-0.4.1 \
		thiserror-1.0.65 \
		thiserror-impl-1.0.65 \
		time-0.3.36 \
		time-core-0.1.2 \
		tinyvec-1.8.0 \
		tinyvec_macros-0.1.1 \
		toml-0.7.8 \
		toml-0.8.19 \
		toml_datetime-0.6.8 \
		toml_edit-0.19.15 \
		toml_edit-0.22.22 \
		typenum-1.17.0 \
		unicode-bidi-0.3.17 \
		unicode-ident-1.0.13 \
		unicode-normalization-0.1.24 \
		unicode-width-0.1.14 \
		untrusted-0.9.0 \
		ureq-2.10.1 \
		url-2.5.2 \
		utf8parse-0.2.2 \
		uuid-1.11.0 \
		version_check-0.9.5 \
		wait-timeout-0.2.0 \
		walkdir-2.5.0 \
		wasi-0.11.0+wasi-snapshot-preview1 \
		wasm-bindgen-0.2.95 \
		wasm-bindgen-backend-0.2.95 \
		wasm-bindgen-macro-0.2.95 \
		wasm-bindgen-macro-support-0.2.95 \
		wasm-bindgen-shared-0.2.95 \
		webpki-roots-0.26.6 \
		which-4.4.2 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.9 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		windows-core-0.52.0 \
		windows-sys-0.48.0 \
		windows-sys-0.52.0 \
		windows-sys-0.59.0 \
		windows-targets-0.48.5 \
		windows-targets-0.52.6 \
		windows_aarch64_gnullvm-0.48.5 \
		windows_aarch64_gnullvm-0.52.6 \
		windows_aarch64_msvc-0.48.5 \
		windows_aarch64_msvc-0.52.6 \
		windows_i686_gnu-0.48.5 \
		windows_i686_gnu-0.52.6 \
		windows_i686_gnullvm-0.52.6 \
		windows_i686_msvc-0.48.5 \
		windows_i686_msvc-0.52.6 \
		windows_x86_64_gnu-0.48.5 \
		windows_x86_64_gnu-0.52.6 \
		windows_x86_64_gnullvm-0.48.5 \
		windows_x86_64_gnullvm-0.52.6 \
		windows_x86_64_msvc-0.48.5 \
		windows_x86_64_msvc-0.52.6 \
		winnow-0.5.40 \
		xattr-1.3.1 \
		zerocopy-0.7.35 \
		zerocopy-derive-0.7.35 \
		zeroize-1.8.1 \
		zeroize_derive-1.4.2 \
		zip-2.2.0 \
		zopfli-0.8.1 \
		zstd-0.13.2 \
		zstd-safe-7.2.1 \
		zstd-sys-2.0.13+zstd.1.5.6

OPENSSLINC=	/usr/include
OPENSSLLIB=	/usr/lib

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
