################################################################################
# makefile for test util
#  versions inkl 535 are done from temlpalte/pl
################################################################################

MAKE_INCLUDE_PATH=mk.inc

# ------------------------------------------------------------------------------
# Compiler and BIT
# ------------------------------------------------------------------------------
CC=gcc
BIT = 64

# ------------------------------------------------------------------------------
# debugger
# ------------------------------------------------------------------------------
DBGOPT = -g

# ------------------------------------------------------------------------------
# sources
# ------------------------------------------------------------------------------
SOURCES =

LSOWN = 

# ------------------------------------------------------------------------------
# main source
# ------------------------------------------------------------------------------
MAIN = main.c

# ------------------------------------------------------------------------------
# BINARY
# ------------------------------------------------------------------------------
BINARY = tclo

# ------------------------------------------------------------------------------
# rollout includes
# ------------------------------------------------------------------------------
ROLLOUT_INC = 

# ------------------------------------------------------------------------------
# do not change includes
# ------------------------------------------------------------------------------
#include $(MAKE_INCLUDE_PATH)/general.modules.mk

# ------------------------------------------------------------------------------
# path.mk and compile.mk have no rules
# ------------------------------------------------------------------------------
include $(MAKE_INCLUDE_PATH)/path.mk
include $(MAKE_INCLUDE_PATH)/compiler.mk

# ------------------------------------------------------------------------------
# first rule (all:) is in rules.mk
# ------------------------------------------------------------------------------
include $(MAKE_INCLUDE_PATH)/rules.mk

include $(MAKE_INCLUDE_PATH)/depend.mk
include $(MAKE_INCLUDE_PATH)/version.mk
include $(MAKE_INCLUDE_PATH)/cmdln.mk
include $(MAKE_INCLUDE_PATH)/rollout.script.mk
include $(MAKE_INCLUDE_PATH)/clean.mk
include $(MAKE_INCLUDE_PATH)/help.mk
include $(MAKE_INCLUDE_PATH)/vara.mk
include $(MAKE_INCLUDE_PATH)/svn.mk

CLO=$(BIN_BASE)/clo.pl
all : $(CLO)

# ------------------------------------------------------------------------------
# cross plaform
# ------------------------------------------------------------------------------
platform: svn_commit.msg
	$(MAKE) --no-print-directory CC=gcc BIT=64 test
	$(MAKE) --no-print-directory CC=gcc BIT=32 test
ifeq ($(OS_ARCH),SunOS)
	$(MAKE) --no-print-directory CC=cc  BIT=64 test
	$(MAKE) --no-print-directory CC=cc  BIT=32 test
endif
	$(SVN)  ci . $(MAKE_INCLUDE_PATH) -F $<
	$(MV) $< $(subst .msg,.rollout,$<)

# ------------------------------------------------------------------------------
# test is to be adjustet
# ------------------------------------------------------------------------------
SRC.O += $(CMDL_OBJ_PATH)/cmdln.o

TEST = t_find_000 t_find_001 t_init_000 t_init_001 t_get_000

include $(MAKE_INCLUDE_PATH)/test.mk

