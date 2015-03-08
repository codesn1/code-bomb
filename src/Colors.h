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
extern "C"
}
#endif

#endif
