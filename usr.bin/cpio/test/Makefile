# $FreeBSD: src/usr.bin/cpio/test/Makefile,v 1.4.2.3.2.1 2012/03/03 06:15:13 kensmith Exp $

LIBARCHIVEDIR=	${.CURDIR}/../../../contrib/libarchive

.PATH:	${LIBARCHIVEDIR}/cpio
CPIO_SRCS= cmdline.c

.PATH:	${LIBARCHIVEDIR}/libarchive_fe
CPIO_SRCS+= err.c pathmatch.c

.PATH:	${LIBARCHIVEDIR}/cpio/test
TESTS=	\
	test_0.c				\
	test_basic.c				\
	test_format_newc.c			\
	test_gcpio_compat.c			\
	test_option_B_upper.c			\
	test_option_C_upper.c			\
	test_option_J_upper.c			\
	test_option_L_upper.c			\
	test_option_Z_upper.c			\
	test_option_a.c				\
	test_option_c.c				\
	test_option_d.c				\
	test_option_f.c				\
	test_option_help.c			\
	test_option_l.c				\
	test_option_lzma.c			\
	test_option_m.c				\
	test_option_t.c				\
	test_option_u.c				\
	test_option_version.c			\
	test_option_y.c				\
	test_option_z.c				\
	test_owner_parse.c			\
	test_passthrough_dotdot.c		\
	test_passthrough_reverse.c		\
	test_pathmatch.c

# Build the test program
SRCS= list.h					\
	${CPIO_SRCS}				\
	${TESTS}				\
	main.c

CLEANFILES+= list.h bsdcpio_test

NO_MAN=yes

PROG=bsdcpio_test
DPADD=${LIBARCHIVE} ${LIBBZ2} ${LIBZ}
CFLAGS+=	-DPLATFORM_CONFIG_H=\"${.CURDIR}/../config_freebsd.h\"
CFLAGS+=	-I${.CURDIR}/..
LDADD= -larchive -lz -lbz2
#CFLAGS+= -static -g -O2 -Wall
CFLAGS+= -g -O2 -Wall
CFLAGS+= -I${.OBJDIR}
CFLAGS+= -I${LIBARCHIVEDIR}/cpio -I${LIBARCHIVEDIR}/libarchive_fe

# Uncomment to link against dmalloc
#LDADD+= -L/usr/local/lib -ldmalloc
#CFLAGS+= -I/usr/local/include -DUSE_DMALLOC
WARNS=6

check test:	bsdcpio_test
	${.OBJDIR}/bsdcpio_test -p ${.OBJDIR}/../bsdcpio \
	-r ${LIBARCHIVEDIR}/cpio/test

${.OBJDIR}/list.h list.h: ${TESTS} Makefile
	(cd ${LIBARCHIVEDIR}/cpio/test; cat ${TESTS}) | \
	grep DEFINE_TEST > ${.OBJDIR}/list.h

clean:
	rm -f ${CLEANFILES}
	rm -f *~
	-chmod -R +w /tmp/bsdcpio_test.*
	rm -rf /tmp/bsdcpio_test

.include <bsd.prog.mk>
