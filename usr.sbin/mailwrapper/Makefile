# $FreeBSD: src/usr.sbin/mailwrapper/Makefile,v 1.15.10.2.4.1 2012/03/03 06:15:13 kensmith Exp $

.include <bsd.own.mk>

.if ${MK_MAILWRAPPER} != "no"
PROG=	mailwrapper
MAN=	mailwrapper.8

DPADD=	${LIBUTIL}
LDADD=	-lutil
WARNS?=	6
.endif

.if ${MK_MAILWRAPPER} != "no" || ${MK_SENDMAIL} != "no"
SYMLINKS= 	${BINDIR}/mailwrapper /usr/sbin/sendmail  \
		${BINDIR}/mailwrapper /usr/sbin/hoststat  \
		${BINDIR}/mailwrapper /usr/sbin/purgestat \
		${BINDIR}/mailwrapper /usr/bin/newaliases \
		${BINDIR}/mailwrapper /usr/bin/mailq

.if ${MK_MAILWRAPPER} == "no" && ${MK_SENDMAIL} != "no"
SYMLINKS+=	/usr/libexec/sendmail/sendmail ${BINDIR}/mailwrapper
.endif
.endif

.if ${MK_MAILWRAPPER} != "no" && ${MK_SENDMAIL} == "no"
SYMLINKS+=      ${BINDIR}/mailwrapper /bin/rmail
.endif

.if ${MK_MAILWRAPPER} != "no"
.if !exists(${DESTDIR}/etc/mail/mailer.conf)
FILES=		${.CURDIR}/../../etc/mail/mailer.conf
FILESDIR=	/etc/mail
FILESMODE=	644
.endif
.endif

.include <bsd.prog.mk>
