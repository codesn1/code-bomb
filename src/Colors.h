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

#ifndef __CODEBOMB_Colors_H
#define __CODEBOMB_Colors_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdio.h>

#include "Init.h"

const char *cb_color_default()
{
	if (cb_output_no_color)
		return "";
	else
		return "\033[0;0m";
}

const char *cb_color_binary_name()
{
	if (cb_output_no_color)
		return "";
	else
		return "\033[1;35m";
}

const char *cb_color_output_value()
{
	if (cb_output_no_color)
		return "";
	else
		return "\033[0;32m";
}

const char *cb_color_option_name()
{
	if (cb_output_no_color)
		return "";
	else
		return "\033[0;32m";
}

const char *cb_color_option_value()
{
	if (cb_output_no_color)
		return "";
	else
		return "\033[1;28m";
}

const char *cb_color_pass()
{
	if (cb_output_no_color)
		return "";
	else
		return "\033[1;32m";
}

const char *cb_color_fail()
{
	if (cb_output_no_color)
		return "";
	else
		return "\033[1;31m";
}

const char *cb_color_test_name()
{
	if (cb_output_no_color)
		return "";
	else
		return "\033[0;35m";
}

const char *cb_color_location()
{
	if (cb_output_no_color)
		return "";
	else
		return "\033[4m\033[1;28m";
}

#ifdef __cplusplus
}
#endif

#endif
