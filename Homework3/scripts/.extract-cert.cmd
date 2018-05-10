cmd_scripts/extract-cert := gcc -Wp,-MD,scripts/.extract-cert.d -Wall -Wmissing-prototypes -Wstrict-prototypes -O2 -fomit-frame-pointer -std=gnu89   -I./tools/include  -o scripts/extract-cert scripts/extract-cert.c  -lcrypto

source_scripts/extract-cert := scripts/extract-cert.c

deps_scripts/extract-cert := \
  /usr/include/stdc-predef.h \
  /usr/include/stdio.h \
  /usr/include/features.h \
  /usr/include/sys/cdefs.h \
  /usr/include/bits/wordsize.h \
  /usr/include/gnu/stubs.h \
  /usr/include/gnu/stubs-64.h \
  /usr/lib/gcc/x86_64-redhat-linux/4.8.5/include/stddef.h \
  /usr/include/bits/types.h \
  /usr/include/bits/typesizes.h \
  /usr/include/libio.h \
  /usr/include/_G_config.h \
  /usr/include/wchar.h \
  /usr/lib/gcc/x86_64-redhat-linux/4.8.5/include/stdarg.h \
  /usr/include/bits/stdio_lim.h \
  /usr/include/bits/sys_errlist.h \
  /usr/include/bits/stdio.h \
  /usr/include/stdlib.h \
  /usr/include/bits/waitflags.h \
  /usr/include/bits/waitstatus.h \
  /usr/include/endian.h \
  /usr/include/bits/endian.h \
  /usr/include/bits/byteswap.h \
  /usr/include/bits/byteswap-16.h \
  /usr/include/xlocale.h \
  /usr/include/sys/types.h \
  /usr/include/time.h \
  /usr/include/sys/select.h \
  /usr/include/bits/select.h \
  /usr/include/bits/sigset.h \
  /usr/include/bits/time.h \
  /usr/include/sys/sysmacros.h \
  /usr/include/bits/pthreadtypes.h \
  /usr/include/alloca.h \
  /usr/include/bits/stdlib-float.h \
  /usr/lib/gcc/x86_64-redhat-linux/4.8.5/include/stdint.h \
  /usr/include/stdint.h \
  /usr/include/bits/wchar.h \
  /usr/lib/gcc/x86_64-redhat-linux/4.8.5/include/stdbool.h \
  /usr/include/string.h \
  /usr/include/bits/string.h \
  /usr/include/bits/string2.h \
  /usr/include/err.h \
  /usr/include/openssl/bio.h \
  /usr/include/openssl/e_os2.h \
  /usr/include/openssl/opensslconf.h \
  /usr/include/openssl/opensslconf-x86_64.h \
    $(wildcard include/config/header/bn/h.h) \
    $(wildcard include/config/header/rc4/locl/h.h) \
    $(wildcard include/config/header/bf/locl/h.h) \
    $(wildcard include/config/header/des/locl/h.h) \
  /usr/include/openssl/crypto.h \
  /usr/include/openssl/stack.h \
  /usr/include/openssl/safestack.h \
  /usr/include/openssl/opensslv.h \
  /usr/include/openssl/ossl_typ.h \
  /usr/include/openssl/symhacks.h \
  /usr/include/openssl/pem.h \
  /usr/include/openssl/evp.h \
  /usr/include/openssl/objects.h \
  /usr/include/openssl/obj_mac.h \
  /usr/include/openssl/asn1.h \
  /usr/include/bits/timex.h \
  /usr/include/openssl/bn.h \
  /usr/lib/gcc/x86_64-redhat-linux/4.8.5/include/limits.h \
  /usr/lib/gcc/x86_64-redhat-linux/4.8.5/include/syslimits.h \
  /usr/include/limits.h \
  /usr/include/bits/posix1_lim.h \
  /usr/include/bits/local_lim.h \
  /usr/include/linux/limits.h \
  /usr/include/bits/posix2_lim.h \
  /usr/include/bits/xopen_lim.h \
  /usr/include/openssl/fips.h \
  /usr/include/openssl/x509.h \
  /usr/include/openssl/buffer.h \
  /usr/include/openssl/ec.h \
  /usr/include/openssl/ecdsa.h \
  /usr/include/openssl/ecdh.h \
  /usr/include/openssl/rsa.h \
  /usr/include/openssl/dsa.h \
  /usr/include/openssl/dh.h \
  /usr/include/openssl/sha.h \
  /usr/include/openssl/x509_vfy.h \
  /usr/include/openssl/lhash.h \
  /usr/include/openssl/pkcs7.h \
  /usr/include/openssl/pem2.h \
  /usr/include/openssl/err.h \
  /usr/include/errno.h \
  /usr/include/bits/errno.h \
  /usr/include/linux/errno.h \
  /usr/include/asm/errno.h \
  /usr/include/asm-generic/errno.h \
  /usr/include/asm-generic/errno-base.h \
  /usr/include/openssl/engine.h \
  /usr/include/openssl/rand.h \
  /usr/include/openssl/ui.h \

scripts/extract-cert: $(deps_scripts/extract-cert)

$(deps_scripts/extract-cert):
