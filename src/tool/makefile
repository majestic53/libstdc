# libstdc
# Copyright (C) 2015 David Jolly
# ----------------------
#
# libstdc is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# libstdc is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.

CC=clang
CC_FLAGS_DBG=-m32 -std=c99 -g
CC_FLAGS_REL=-m32 -std=c99 -O3 -Wall
DIR_BIN=./../../bin/
DIR_BUILD=./../../build/
DIR_INC=./include/
DIR_SRC=./src/
DIR_TOP=./
EXE=stdc
LIB_EXT=libext.a
LIB_STD=libstdc.a

all: build

build:
	@echo ""
	@echo "--- BUILDING TOOL --------------------------"
ifndef CC_DBG
	$(CC) $(CC_FLAGS_REL) $(DIR_TOP)main.c $(DIR_BIN)$(LIB_EXT) -o $(DIR_BIN)$(EXE) # release
else
	$(CC) $(CC_FLAGS_DBG) $(DIR_TOP)main.c $(DIR_BIN)$(LIB_EXT) -o $(DIR_BIN)$(EXE) # debug
endif # CC_DBG
	@echo "--- DONE -----------------------------------"
	@echo ""
