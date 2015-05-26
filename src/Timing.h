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
}
#endif

#endif