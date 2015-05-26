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

#ifndef __CODEBOMB_Init_H
#define __CODEBOMB_Init_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdio.h>
#include <string.h>

#include "Message.h"
#include "Version.h"

int cb_has_been_initted = 0;
int cb_output_compiler_name = 0;
int cb_output_compiler_version = 0;
int cb_output_os_name = 0;
int cb_output_os_version = 0;
int cb_output_codebomb_version = 0;
int cb_output_options = 0;
int cb_output_no_color = 0;
int cb_test_fail_on_first_assertion = 0;
int cb_test_fail_on_first_test_case = 0;

#include "Colors.h"

#define CB_INIT(argc, argv) cb_init(argc, argv)

void cb_init(int argc, char *argv[])
{
	if (cb_has_been_initted)
	{
		CB_MESSAGE_FATAL("INIT (or CB_INIT) has been called multiple times");
	}

	cb_has_been_initted = 1;

	for (int i = 1; i < argc; i++)
	{
		if (strcmp(argv[i], "--cb-output-compiler-name") == 0)
		{
			cb_output_compiler_name = 1;
		}
		else if (strcmp(argv[i], "--cb-output-compiler-version") == 0)
		{
			cb_output_compiler_version = 1;
		}
		else if (strcmp(argv[i], "--cb-output-os-name") == 0)
		{
			cb_output_os_name = 1;
		}
		else if (strcmp(argv[i], "--cb-output-os-version") == 0)
		{
			cb_output_os_version = 1;
		}
		else if (strcmp(argv[i], "--cb-output-codebomb-version") == 0)
		{
			cb_output_codebomb_version = 1;
		}
		else if (strcmp(argv[i], "--cb-output-options") == 0)
		{
			cb_output_options = 1;
		}
		else if (strcmp(argv[i], "--cb-output-full") == 0)
		{
			cb_output_compiler_name = 1;
			cb_output_compiler_version = 1;
			cb_output_os_name = 1;
			cb_output_os_version = 1;
			cb_output_codebomb_version = 1;
			cb_output_options = 1;
		}
		else if (strcmp(argv[i], "--cb-output-no-color") == 0)
		{
			cb_output_no_color = 1;
		}
		else if (strcmp(argv[i], "--cb-test-fail-on-first-assertion") == 0)
		{
			cb_test_fail_on_first_assertion = 1;
		}
		else if (strcmp(argv[i], "--cb-test-fail-on-first-test-case") == 0)
		{
			cb_test_fail_on_first_test_case = 1;
		}
		else if (strcmp(argv[i], "--cb-help") == 0)
		{
			printf("Code Bomb 0.0.1-alpha\n");
			printf("Copyright (C) 2015, Oliver Katz\n");
			printf("\n");
			printf("usage: %s [OPTIONS]\n", argv[0]);
			printf("\n");
			printf("OPTIONS\n");
			printf(" --cb-help                         Display this help.\n");
			printf(" --cb-version                      Display version info.\n");
			printf(" --cb-output-compiler-name         Enable displaying of compiler name.\n");
			printf(" --cb-output-compiler-version      Enable displaying of compiler version.\n");
			printf(" --cb-output-os-name               Enable displaying of os name.\n");
			printf(" --cb-output-os-version            Enable displaying of os version.\n");
			printf(" --cb-output-codebomb-version      Enable displaying of Code Bomb version.\n");
			printf(" --cb-output-options               Enable displaying of all options.\n");
			printf(" --cb-output-full                  Enable full output.\n");
			printf(" --cb-output-no-color              Disable use of terminal colors.\n");
			printf(" --cb-test-fail-on-first-assertion Fail on the first failed assertion.\n");
			printf(" --cb-test-fail-on-first-test-case Fail on the first failed test case.\n");
			printf("\n");
			_exit(0);
		}
		else if (strcmp(argv[i], "--cb-version") == 0)
		{
			printf("Code Bomb 0.0.1-alpha\n");
			printf("Copyright (C) 2015, Oliver Katz\n");
			printf("\n");
			_exit(0);
		}
		else
		{
			CB_MESSAGE_FATAL("unknown argument: %s", argv[i])
		}
	}

	printf("= %s%s%s\n", cb_color_binary_name(), argv[0], cb_color_default());

	if (cb_output_compiler_name || cb_output_compiler_version)
	{
		#if defined(__clang__) && defined(__GNUC__)
			printf("= Compiler: %sApple GCC with Clang/LLVM%s\n", cb_color_output_value(), cb_color_default());
		#else
			#ifdef __clang__
			printf("= Compiler: %sClang%s\n", cb_color_output_value(), cb_color_default());
			#endif

			#ifdef __GNUC__
			printf("= Compiler: %sGCC%s\n", cb_color_output_value(), cb_color_default());
			#endif
		#endif
	}

	if (cb_output_compiler_version)
	{
		#ifdef __clang__
		printf("= Compiler version: %s%s%s\n", cb_color_output_value(), __VERSION__, cb_color_default());
		#endif
	}

	if (cb_output_os_name || cb_output_os_version)
	{
		#ifdef __APPLE__
		printf("= OS (compiled under): %sMac OS X%s\n", cb_color_output_value(), cb_color_default());
		#endif

		#ifdef _WIN32
		printf("= OS (compiled under): %sWindows (32-bit)%s\n", cb_color_output_value(), cb_color_default());
		#endif

		#ifdef _WIN64
		printf("= OS (compiled under): %sWindows (64-bit)%s\n", cb_color_output_value(), cb_color_default());
		#endif

		#ifdef __linux
		printf("= OS (compiled under): %sLinux%s\n", cb_color_output_value(), cb_color_default());
		#endif
	}

	if (cb_output_os_version)
	{
		#ifdef __unix
		printf("= OS version (running): %s", cb_color_output_value();
		system("uname -msrv");
		printf("%s", cb_color_default())
		#endif
	}

	if (cb_output_codebomb_version)
	{
		printf("= Code Bomb version: %s%s%s\n", cb_color_output_value(), CB_VERSION, cb_color_default());
	}

	if (cb_output_options)
	{
		printf("= %scb_output_compiler_name%s == %s%i%s\n", cb_color_option_name(), cb_color_default(), cb_color_option_value(), cb_output_compiler_name, cb_color_default());
		printf("= %scb_output_compiler_version%s == %s%i%s\n", cb_color_option_name(), cb_color_default(), cb_color_option_value(), cb_output_compiler_version, cb_color_default());
		printf("= %scb_output_os_name%s == %s%i%s\n", cb_color_option_name(), cb_color_default(), cb_color_option_value(), cb_output_os_name, cb_color_default());
		printf("= %scb_output_os_version%s == %s%i%s\n", cb_color_option_name(), cb_color_default(), cb_color_option_value(), cb_output_os_version, cb_color_default());
		printf("= %scb_output_codebomb_version%s == %s%i%s\n", cb_color_option_name(), cb_color_default(), cb_color_option_value(), cb_output_codebomb_version, cb_color_default());
		printf("= %scb_output_options%s == %s%i%s\n", cb_color_option_name(), cb_color_default(), cb_color_option_value(), cb_output_options, cb_color_default());
		printf("= %scb_output_no_color%s == %s%i%s\n", cb_color_option_name(), cb_color_default(), cb_color_option_value(), cb_output_no_color, cb_color_default());
		printf("= %scb_test_fail_on_first_assertion%s == %s%i%s\n", cb_color_option_name(), cb_color_default(), cb_color_option_value(), cb_test_fail_on_first_assertion, cb_color_default());
		printf("= %scb_test_fail_on_first_test_case%s == %s%i%s\n", cb_color_option_name(), cb_color_default(), cb_color_option_value(), cb_test_fail_on_first_test_case, cb_color_default());
	}

	printf("==");
	for (int i = 0; argv[0][i] != 0; i++)
		putc('=', stdout);
	printf("\n");
}

#ifdef __cplusplus
}
#endif

#endif