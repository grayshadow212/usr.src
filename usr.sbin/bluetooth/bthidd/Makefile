# $Id: Makefile,v 1.6 2006/09/07 21:36:55 max Exp $
# $FreeBSD: src/usr.sbin/bluetooth/bthidd/Makefile,v 1.7.10.1.8.1 2012/03/03 06:15:13 kensmith Exp $

PROG=		bthidd
MAN=		bthidd.8
#		bthidd.conf.5
SRCS=		bthidd.c client.c hid.c kbd.c lexer.l parser.y server.c \
		session.c

CFLAGS+=	-I${.CURDIR}
WARNS?=		6
DEBUG_FLAGS=	-g

DPADD=          ${LIBBLUETOOTH} ${LIBUSBHID}
LDADD=		-lbluetooth -lusbhid

.include <bsd.prog.mk>
