/******************************************************************************
 * Copyright (c) 2015 Oliver Katz                                             *
 *                                                                            *
 * Permission is hereby granted, free of charge, to any person obtaining a    *
 * copy of this software and associated documentation files (the "Software"), *
 * to deal in the Software without restriction, including without limitation  *
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,   *
 * and/or sell copies of the Software, and to permit persons to whom the      *
 * Software is furnished to do so, subject to the following conditions:       *
 *                                                                            *
 * The above copyright notice and this permission notice shall be included in *
 * all copies or substantial portions of the Software.                        *
 *                                                                            *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR *
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,   *
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL    *
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER *
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING    *
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER        *
 * DEALINGS IN THE SOFTWARE.                                                  *
 ******************************************************************************/

#ifndef __CODEBOMB_CompilationTest_H
#define __CODEBOMB_CompilationTest_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#include "Test.h"

#define CB_COMPILATION_TEST_C(name, cmd, code) void cb_##name( \
	int *cb_result) \
{ \
	*cb_result = cb_compile_c(cmd, code); \
}

#define CB_COMPILATION_TEST_CXX(name, cmd, code) void cb_##name( \
	int *cb_result) \
{ \
	*cb_result = cb_compile_cxx(cmd, code); \
}

int cb_compile_c(const char *cmd, const char *code)
{
	char srcpath[1024];
	sprintf(srcpath, "/tmp/codebomb_compilation.c");

	char binpath[1024];
	sprintf(binpath, "/tmp/codebomb_compilation.bin");

	FILE *f = fopen(srcpath, "w");
	fprintf(f, "%s\n", code);
	fclose(f);

	char cmdline[1024];
	sprintf(cmdline, "%s %s -o %s", cmd, srcpath, binpath);
	int e = system(cmdline);

	return (e != 0);
}

int cb_compile_cxx(const char *cmd, const char *code)
{
	char srcpath[1024];
	sprintf(srcpath, "/tmp/codebomb_compilation.cpp");

	char binpath[1024];
	sprintf(binpath, "/tmp/codebomb_compilation.bin");

	FILE *f = fopen(srcpath, "w");
	fprintf(f, "%s\n", code);
	fclose(f);

	char cmdline[1024];
	sprintf(cmdline, "%s %s -o %s", cmd, srcpath, binpath);
	int e = system(cmdline);

	return (e != 0);
}

#ifdef __cplusplus
}
#endif

#endif
