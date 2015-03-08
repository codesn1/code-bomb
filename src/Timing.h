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

#ifndef __CODEBOMB_Timing_H
#define __CODEBOMB_Timing_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdio.h>
#include <sys/time.h>

double cb_get_time_in_ms()
{
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return ((double)(tv.tv_usec + 1000000 * tv.tv_sec))/((double)1000.0);
}

#define CB_START_TIMER(name, repetitions) { \
	double cb_timer_start_##name = cb_get_time_in_ms(); \
	int cb_timer_repetitions_##name = repetitions; \
	for (int cb_timer_itr_##name = 0; cb_timer_itr_##name < repetitions; cb_timer_itr_##name++) \
	{

#define CB_STOP_TIMER(name) } \
	double cb_timer_end_##name = cb_get_time_in_ms(); \
	printf("= Timer '%s': %.03f (%i repetitions)\n", #name, cb_timer_end_##name - cb_timer_start_##name, cb_timer_repetitions_##name); \
}

#ifdef __cplusplus
extern "C"
}
#endif

#endif