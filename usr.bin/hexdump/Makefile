#	@(#)Makefile	8.1 (Berkeley) 6/6/93
# $FreeBSD: src/usr.bin/hexdump/Makefile,v 1.9.30.1.8.1 2012/03/03 06:15:13 kensmith Exp $

PROG=	hexdump
SRCS=	conv.c display.c hexdump.c hexsyntax.c odsyntax.c parse.c
MAN=	hexdump.1 od.1
MLINKS=	hexdump.1 hd.1
LINKS=	${BINDIR}/hexdump ${BINDIR}/od
LINKS+=	${BINDIR}/hexdump ${BINDIR}/hd
WARNS?=	6

.include <bsd.prog.mk>
