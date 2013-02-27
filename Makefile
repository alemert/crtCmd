################################################################################
# makefile for test util
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

LSOWN = libsogen.a

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

include $(MAKE_INCLUDE_PATH)/path.mk
include $(MAKE_INCLUDE_PATH)/compiler.mk

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
# test is to be adjustet
# ------------------------------------------------------------------------------
SRC.O += $(CMDL_OBJ_PATH)/cmdln.o $(REVISION_OBJ_PATH)/ver4bin.o

$(CMDL_SRC_PATH)/cmdln.c : $(CLO)

TEST = t_find_000 t_find_001  t_find_002 \
       t_init_000 t_init_001 t_init_002  \
       t_get_000  t_get_001  t_get_002

include $(MAKE_INCLUDE_PATH)/test.mk

