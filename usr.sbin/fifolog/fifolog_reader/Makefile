# $FreeBSD: src/usr.sbin/fifolog/fifolog_reader/Makefile,v 1.3.2.1.8.1 2012/03/03 06:15:13 kensmith Exp $

PROG=	fifolog_reader

CFLAGS+= -I${.CURDIR}/../lib

NO_MAN=	# see ../fifolog_create/fifolog.1

DPADD=	${LIBFIFOLOG} ${LIBUTIL} ${LIBZ}
LDADD=	${LIBFIFOLOG} -lutil -lz

regress:
	./${PROG} /tmp/fifolog.0
	./${PROG} -t /tmp/fifolog.0
	./${PROG} /tmp/fifolog.1
	./${PROG} -B "00:00" /tmp/fifolog.1
	./${PROG} -T "%y%m%d-%H%M%S" /tmp/fifolog.1
	./${PROG} -T "" /tmp/fifolog.1

.include <bsd.prog.mk>
