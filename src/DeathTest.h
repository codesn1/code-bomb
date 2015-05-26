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

#ifndef __CODEBOMB_DeathTest_H
#define __CODEBOMB_DeathTest_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdio.h>
#include <unistd.h>
#include <signal.h>

#include "Test.h"

char *cb_current_death_test = (char *)"";

#define CB_DEATH_TEST(name) void cb_death_##name(int *cb_result); \
void cb_##name(int *cb_result) { \
	struct sigaction cb_sa; \
	memset(&cb_sa, 0, sizeof(sigaction)); \
	sigemptyset(&cb_sa.sa_mask); \
	cb_sa.sa_sigaction = cb_death_test_on_signal; \
	cb_sa.sa_flags = SA_SIGINFO; \
	sigaction(SIGSEGV, &cb_sa, NULL); \
	*cb_result = 1; \
	cb_current_death_test = #name; \
	cb_death_##name(cb_result); \
} \
void cb_death_##name(int *cb_result)

void cb_death_test_on_signal(int signal, siginfo_t *si, void *arg)
{
	cb_result = 0;
	printf("=     death test '%s%s%s' died successfully!\n", cb_color_pass(), cb_current_death_test, cb_color_default());
	pthread_exit(0);
}

#ifdef __cplusplus
}
#endif

#endif
