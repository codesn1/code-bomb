/* Copyright (c) 2015, Oliver Katz
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without 
 * modification, are permitted provided that the following conditions are 
 * met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, 
 * this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright 
 * notice, this list of conditions and the following disclaimer in the 
 * documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" 
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE 
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE 
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE 
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR 
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF 
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS 
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN 
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) 
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE 
 * POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef __CODEBOMB_Test_H
#define __CODEBOMB_Test_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdio.h>

#include "Message.h"

int cb_printedHeader = 0;
int cb_nSucceeded = 0;
int cb_nFailed = 0;
int cb_result = 0;

#define TEST(name) void cb_##name(int *cb_result)

#define RUN(name) { \
	if (!cb_printedHeader) \
	{ \
		CB_MESSAGE_HEADER(); \
		cb_printedHeader = 1; \
	} \
	cb_result = 0; \
	cb_##name(&cb_result); \
	if (cb_result != 0) \
		cb_nFailed++; \
	else \
		cb_nSucceeded++; \
}

#define STATUS() (cb_nFailed > 0)

#ifdef __cplusplus
extern "C"
}
#endif

#endif