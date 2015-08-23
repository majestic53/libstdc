# libz80
# Copyright (C) 2015 David Jolly
# ----------------------
#
# libz80 is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# libz80 is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.

CC=clang
CC_FLAGS=-m32 -std=c99 -O3 -Wall
DIR_BIN=./../../bin/
DIR_BUILD=./../../build/
DIR_INC=./include/
DIR_SRC=./src/
DIR_TOP=./
LIB=libstdc.a

all: build archive

archive:
	@echo ""
	@echo "--- BUILDING LIBRARY -----------------------"
	ar rcs $(DIR_BIN)$(LIB) $(DIR_BUILD)assert.o $(DIR_BUILD)ctype.o $(DIR_BUILD)errno.o $(DIR_BUILD)locale.o $(DIR_BUILD)string.o
	@echo "--- DONE -----------------------------------"
	@echo ""

build: assert.o ctype.o errno.o locale.o string.o

assert.o: $(DIR_SRC)assert.c $(DIR_INC)assert.h
	$(CC) $(CC_FLAGS) -c $(DIR_SRC)assert.c -o $(DIR_BUILD)assert.o

ctype.o: $(DIR_SRC)ctype.c $(DIR_INC)ctype.h
	$(CC) $(CC_FLAGS) -c $(DIR_SRC)ctype.c -o $(DIR_BUILD)ctype.o

errno.o: $(DIR_SRC)errno.c $(DIR_INC)errno.h
	$(CC) $(CC_FLAGS) -c $(DIR_SRC)errno.c -o $(DIR_BUILD)errno.o

locale.o: $(DIR_SRC)locale.c $(DIR_INC)locale.h
	$(CC) $(CC_FLAGS) -c $(DIR_SRC)locale.c -o $(DIR_BUILD)locale.o

string.o: $(DIR_SRC)string.c $(DIR_INC)string.h
	$(CC) $(CC_FLAGS) -c $(DIR_SRC)string.c -o $(DIR_BUILD)string.o
