#!/bin/sh
#
# Copyright (c) 2003 Poul-Henning Kamp
# All rights reserved.
#
# Please see src/share/examples/etc/bsd-style-copyright.
#
# $FreeBSD: src/usr.sbin/mtree/test/test01.sh,v 1.1.32.1.8.1 2012/03/03 06:15:13 kensmith Exp $
#

set -e

TMP=/tmp/mtree.$$

rm -rf ${TMP}
mkdir -p ${TMP} ${TMP}/mr ${TMP}/mt


ln -s "xx this=is=wrong" ${TMP}/mr/foo
mtree -c -p ${TMP}/mr > ${TMP}/_

if mtree -U -r -p ${TMP}/mt < ${TMP}/_ > /dev/null 2>&1 ; then
	true
else
	echo "ERROR Mtree failed on symlink with space char" 1>&2
	rm -rf ${TMP}
	exit 1
fi

x=x`(cd ${TMP}/mr ; ls -l foo 2>&1) || true`
y=x`(cd ${TMP}/mt ; ls -l foo 2>&1) || true`

if [ "$x" != "$y" ] ; then
	echo "ERROR Recreation of spaced symlink failed" 1>&2
	rm -rf ${TMP}
	exit 1
fi

rm -rf ${TMP}
exit 0
