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

#ifndef __CODEBOMB_Test_H
#define __CODEBOMB_Test_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdio.h>
#include <pthread.h>

#include "Message.h"
#include "Colors.h"

int cb_n_succeeded = 0;
int cb_n_failed = 0;
int cb_result = 0;

#define CB_TEST_FAIL() {cb_test_fail(cb_result); return;}

#define CB_TEST(name) void cb_##name(int *cb_result)

#define CB_RUN(name) cb_run(cb_##name, #name)

#define CB_STATUS() cb_status()

void cb_test_fail(int *r)
{
	*r = 1;

	if (cb_test_fail_on_first_assertion)
		_exit(1);
}

int cb_status()
{
	if (cb_n_succeeded + cb_n_failed == 0)
	{
		CB_MESSAGE_WARNING("no test cases run");
	}

	if (cb_n_failed == 0)
	{
		printf("= %sAll tests passed!%s\n", cb_color_pass(), cb_color_default());
		return 0;
	}
	else
	{
		printf("= %s%i%s test%s passed, %s%i%s test%s failed.\n", cb_color_pass(), cb_n_succeeded, cb_color_default(), (cb_n_succeeded == 1 ? "" : "s"), cb_color_fail(), cb_n_failed, cb_color_default(), (cb_n_failed == 1 ? "" : "s"));
		return 1;
	}
}

void cb_run(void (*test)(int *), const char *name)
{
	CB_MESSAGE_TEST(name);
	if (!cb_has_been_initted)
	{
		CB_MESSAGE_FATAL("INIT (or CB_INIT) has not been called");
	}

	cb_result = 0;
	pthread_t thread;

	if (pthread_create(&thread, NULL, (void *(*)(void *))test, (void *)&cb_result))
	{
		CB_MESSAGE_FATAL("pthread_create failed");
		perror("perror: ");
	}

	pthread_join(thread, NULL);

	if (cb_result != 0)
	{
		cb_n_failed++;
		if (cb_test_fail_on_first_test_case)
			_exit(cb_status());
	}
	else
	{
		cb_n_succeeded++;
	}
}

#ifdef __cplusplus
}
#endif

#endif
