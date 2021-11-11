#!/bin/sh

set -e
if [ $1 = "-i" ]; then
    original_extension="$2"
    shift
    shift
else
    original_extension="$(echo $1 | sed -n 's/^-i\(.*\)/\1/p')"
    if [ -z "${original_extension}" ]; then
	echo Invalid first argument: "$1" 1>&2
	exit 1
    fi
    shift
fi
if [ -z "${original_extension}" ]; then
    extension=.sed_checked
else
    extension="${original_extension}"
fi
sed -i"${extension}" "$@"
for x in "${@}" ; do
    if [ -f "${x}" ]; then
	if cmp -s "${x}" "${x}${extension}" ; then
	    if [ ! -z "${REWARNFILE}" ]; then
		echo - - REINPLACE_CMD ran, but did not modify file contents: ${x#${WRKSRC}/} >> ${REWARNFILE}
	    fi
	fi
	if [ -z "${original_extension}" ]; then
	    rm -f "${x}${extension}"
	fi
    fi
done
