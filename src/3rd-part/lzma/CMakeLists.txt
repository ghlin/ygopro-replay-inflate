SET(LZMA_SRC
  LzmaLib.c
  Alloc.c
  LzmaDec.c
  LzFind.c
  LzmaEnc.c)

ADD_LIBRARY(lzma STATIC ${LZMA_SRC})

