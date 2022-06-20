.SUFFIXES: .svg .eps .pdf

SOURCES = $(wildcard */*.svg *.svg) 
TGT_EPS = $(subst .svg,.eps,$(SOURCES))
TGT_PDF = $(subst .svg,.pdf,$(SOURCES))
TARGETS = $(TGT_EPS) $(TGT_PDF)
SUBDIRS = $(dir $(shell echo */Makefile))

.PHONY: all
all: $(TARGETS)
#	for d in $(SUBDIRS) ; \
#	do \
#	  if [ -f $$d/Makefile ] ; then \
#	    (cd $$d; make;) \
#	  fi; \
#	done

%.eps: %.svg Makefile
	inkscape -z -D -E $@ $<
%.pdf: %.svg Makefile
	inkscape -z -D -A $@ $<
