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

char *cb_current_death_test = "";

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
extern "C"
}
#endif

#endif
