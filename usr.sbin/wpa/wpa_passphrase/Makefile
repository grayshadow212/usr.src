# $FreeBSD: src/usr.sbin/wpa/wpa_passphrase/Makefile,v 1.3.2.1.8.1 2012/03/03 06:15:13 kensmith Exp $

.include "${.CURDIR}/../Makefile.inc"

.PATH.c:${WPA_SUPPLICANT_DISTDIR}

PROG=	wpa_passphrase
SRCS=	wpa_passphrase.c sha1.c md5.c

CFLAGS+= -DINTERNAL_SHA1
CFLAGS+= -DINTERNAL_MD5

MAN=	wpa_passphrase.8

.include <bsd.prog.mk>
