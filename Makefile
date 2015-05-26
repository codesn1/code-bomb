# Copyright (c) 2015 Oliver Katz

# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:

# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.

# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
# THE SOFTWARE.

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
TESTS=testing/Minimal.bin testing/Assertions.bin testing/Death.bin testing/Timers.bin testing/Fuzzing.bin testing/Compilation.bin
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
