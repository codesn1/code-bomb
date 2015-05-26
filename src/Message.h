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

#ifndef __CODEBOMB_Message_H
#define __CODEBOMB_Message_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdio.h>
#include <unistd.h>

#define CB_MESSAGE_TEST(name) printf("= Running test '%s%s%s'...\n", cb_color_test_name(), name, cb_color_default())

#define CB_MESSAGE_ASSERTION_FAILED(desc) printf("=     Assertion '%s%s%s' failed!\n=       on %s%s:%i%s\n", cb_color_fail(), desc, cb_color_default(), cb_color_location(), __FILE__, __LINE__, cb_color_default())
#define CB_MESSAGE_ASSERTION_IVALUE(name, value) printf("=       %s: %li == %lu == %08x\n", name, value, (unsigned long)value, (unsigned int)value)
#define CB_MESSAGE_ASSERTION_FVALUE(name, value) printf("=       %s: %f\n", name, (float)value)
#define CB_MESSAGE_ASSERTION_SVALUE(name, value) printf("=       %s: \"%s\"\n", name, (char *)value)

#define CB_MESSAGE_WARNING(msg, ...) printf("CodeBomb: warning: " msg "\n", ##__VA_ARGS__);

#define CB_MESSAGE_FATAL(msg, ...) { \
	fprintf(stderr, "CodeBomb: FATAL: " msg "\n", ##__VA_ARGS__); \
	_exit(1); \
}

#ifdef __cplusplus
}
#endif

#endif