#	@(#)Makefile	8.1 (Berkeley) 6/6/93
# $FreeBSD: src/usr.sbin/rmt/Makefile,v 1.10.34.1.8.1 2012/03/03 06:15:13 kensmith Exp $

PROG=	rmt
MAN=	rmt.8

WARNS?=	4

# called from /usr/src/etc/Makefile
etc-rmt:
	rm -f ${DESTDIR}/etc/rmt
	ln -s ${BINDIR}/rmt ${DESTDIR}/etc/rmt

.include <bsd.prog.mk>
