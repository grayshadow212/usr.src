#	@(#)Makefile	8.1 (Berkeley) 6/6/93
# $FreeBSD: src/usr.bin/kdump/Makefile,v 1.14.2.2.2.1 2012/03/03 06:15:13 kensmith Exp $

.if (${MACHINE_ARCH} == "amd64")
SFX=		32
.endif

.PATH: ${.CURDIR}/../ktrace

PROG=		kdump
SRCS=		kdump.c ioctl.c kdump_subr.c subr.c
CFLAGS+=	-I${.CURDIR}/../ktrace -I${.CURDIR} -I${.CURDIR}/../..

.if ${MACHINE_ARCH} == "amd64" || ${MACHINE_ARCH} == "i386"
SRCS+=		linux_syscalls.c
.endif

CLEANFILES=	ioctl.c kdump_subr.c linux_syscalls.c

ioctl.c: mkioctls
	sh ${.CURDIR}/mkioctls ${DESTDIR}/usr/include > ${.TARGET}

kdump_subr.c: mksubr
	sh ${.CURDIR}/mksubr ${DESTDIR}/usr/include > ${.TARGET}

linux_syscalls.c:
	/bin/sh ${.CURDIR}/../../sys/kern/makesyscalls.sh \
	    ${.CURDIR}/../../sys/${MACHINE_ARCH}/linux${SFX}/syscalls.master ${.CURDIR}/linux_syscalls.conf
	echo "int nlinux_syscalls = sizeof(linux_syscallnames) / sizeof(linux_syscallnames[0]);" \
	    >> linux_syscalls.c

.include <bsd.prog.mk>
