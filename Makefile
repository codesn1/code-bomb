# Copyright (c) 2015, Oliver Katz
# All rights reserved.
#
# Redistribution and use in source and binary forms, with or without 
# modification, are permitted provided that the following conditions are 
# met:
#
# 1. Redistributions of source code must retain the above copyright notice, 
# this list of conditions and the following disclaimer.
#
# 2. Redistributions in binary form must reproduce the above copyright 
# notice, this list of conditions and the following disclaimer in the 
# documentation and/or other materials provided with the distribution.
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" 
# AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE 
# IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE 
# ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE 
# LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR 
# CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF 
# SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS 
# INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN 
# CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) 
# ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE 
# POSSIBILITY OF SUCH DAMAGE.

CC=gcc
CFLAGS=-g -O0
LDFLAGS=-Isrc

RM=rm
RMFLAGS=-rf

CP=cp
CPFLAGS=-f

MKDIR=mkdir
MKDIRFLAGS=

PREFIX=/usr
TESTS=testing/Minimal.bin
HEADERS=src/Test.h

check : $(TESTS)
	@for i in $(TESTS); do echo ./$$i; ./$$i; done

clean :
	$(RM) $(RMFLAGS) $(shell echo testing/*.bin testing/*.bin.dSYM)

install :
	$(MKDIR) $(MKDIRFLAGS) $(PREFIX)/include/codebomb
	$(CP) $(CPFLAGS) $(shell echo src/*.h) $(PREFIX)/include/codebomb

uninstall :
	$(RM) $(RMFLAGS) $(PREFIX)/include/codebomb

testing/%.bin : testing/%.c $(HEADERS)
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)