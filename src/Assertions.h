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

#ifndef __CODEBOMB_Assertions_H
#define __CODEBOMB_Assertions_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdio.h>

#include "Test.h"

typedef long cb_assertion_ivalue;
typedef long double cb_assertion_fvalue;
typedef char *cb_assertion_svalue;

#define CB_ASSERT_TRUE(expr) { \
	cb_assertion_ivalue _cb_value = (cb_assertion_ivalue)(expr); \
	if (!_cb_value) \
	{ \
		CB_MESSAGE_ASSERTION_FAILED(#expr); \
		CB_MESSAGE_ASSERTION_IVALUE("Value", _cb_value); \
		CB_TEST_FAIL(); \
	} \
}

#define CB_ASSERT_FALSE(expr) { \
	cb_assertion_ivalue _cb_value = (cb_assertion_ivalue)(expr); \
	if (_cb_value) \
	{ \
		CB_MESSAGE_ASSERTION_FAILED("not " #expr); \
		CB_MESSAGE_ASSERTION_IVALUE("Value", _cb_value); \
		CB_TEST_FAIL(); \
	} \
}

#define CB_ASSERT_EQ(exp, act) { \
	cb_assertion_ivalue _cb_exp = (cb_assertion_ivalue)(exp); \
	cb_assertion_ivalue _cb_act = (cb_assertion_ivalue)(act); \
	if (_cb_exp != _cb_act) \
	{ \
		CB_MESSAGE_ASSERTION_FAILED(#exp " == " #act); \
		CB_MESSAGE_ASSERTION_IVALUE("Expected", _cb_exp); \
		CB_MESSAGE_ASSERTION_IVALUE("Actual", _cb_act); \
		CB_TEST_FAIL(); \
	} \
}

#define CB_ASSERT_NE(lhs, rhs) { \
	cb_assertion_ivalue _cb_lhs = (cb_assertion_ivalue)(lhs); \
	cb_assertion_ivalue _cb_rhs = (cb_assertion_ivalue)(rhs); \
	if (_cb_lhs == _cb_rhs) \
	{ \
		CB_MESSAGE_ASSERTION_FAILED(#lhs " != " #rhs); \
		CB_MESSAGE_ASSERTION_IVALUE("LHS", _cb_lhs); \
		CB_MESSAGE_ASSERTION_IVALUE("RHS", _cb_rhs); \
		CB_TEST_FAIL(); \
	} \
}

#define CB_ASSERT_LT(lhs, rhs) { \
	cb_assertion_ivalue _cb_lhs = (cb_assertion_ivalue)(lhs); \
	cb_assertion_ivalue _cb_rhs = (cb_assertion_ivalue)(rhs); \
	if (_cb_lhs >= _cb_rhs) \
	{ \
		CB_MESSAGE_ASSERTION_FAILED(#lhs " < " #rhs); \
		CB_MESSAGE_ASSERTION_IVALUE("LHS", _cb_lhs); \
		CB_MESSAGE_ASSERTION_IVALUE("RHS", _cb_rhs); \
		CB_TEST_FAIL(); \
	} \
}

#define CB_ASSERT_LE(lhs, rhs) { \
	cb_assertion_ivalue _cb_lhs = (cb_assertion_ivalue)(lhs); \
	cb_assertion_ivalue _cb_rhs = (cb_assertion_ivalue)(rhs); \
	if (_cb_lhs > _cb_rhs) \
	{ \
		CB_MESSAGE_ASSERTION_FAILED(#lhs " <= " #rhs); \
		CB_MESSAGE_ASSERTION_IVALUE("LHS", _cb_lhs); \
		CB_MESSAGE_ASSERTION_IVALUE("RHS", _cb_rhs); \
		CB_TEST_FAIL(); \
	} \
}

#define CB_ASSERT_GT(lhs, rhs) { \
	cb_assertion_ivalue _cb_lhs = (cb_assertion_ivalue)(lhs); \
	cb_assertion_ivalue _cb_rhs = (cb_assertion_ivalue)(rhs); \
	if (_cb_lhs <= _cb_rhs) \
	{ \
		CB_MESSAGE_ASSERTION_FAILED(#lhs " > " #rhs); \
		CB_MESSAGE_ASSERTION_IVALUE("LHS", _cb_lhs); \
		CB_MESSAGE_ASSERTION_IVALUE("RHS", _cb_rhs); \
		CB_TEST_FAIL(); \
	} \
}

#define CB_ASSERT_GE(lhs, rhs) { \
	cb_assertion_ivalue _cb_lhs = (cb_assertion_ivalue)(lhs); \
	cb_assertion_ivalue _cb_rhs = (cb_assertion_ivalue)(rhs); \
	if (_cb_lhs < _cb_rhs) \
	{ \
		CB_MESSAGE_ASSERTION_FAILED(#lhs " >= " #rhs); \
		CB_MESSAGE_ASSERTION_IVALUE("LHS", _cb_lhs); \
		CB_MESSAGE_ASSERTION_IVALUE("RHS", _cb_rhs); \
		CB_TEST_FAIL(); \
	} \
}

#define CB_ASSERT_FEQ(exp, act) { \
	cb_assertion_fvalue _cb_exp = (cb_assertion_fvalue)(exp); \
	cb_assertion_fvalue _cb_act = (cb_assertion_fvalue)(act); \
	if (_cb_exp != _cb_act) \
	{ \
		CB_MESSAGE_ASSERTION_FAILED(#exp " == " #act); \
		CB_MESSAGE_ASSERTION_FVALUE("Expected", _cb_exp); \
		CB_MESSAGE_ASSERTION_FVALUE("Actual", _cb_act); \
		CB_TEST_FAIL(); \
	} \
}

#define CB_ASSERT_FNE(lhs, rhs) { \
	cb_assertion_fvalue _cb_lhs = (cb_assertion_fvalue)(lhs); \
	cb_assertion_fvalue _cb_rhs = (cb_assertion_fvalue)(rhs); \
	if (_cb_lhs == _cb_rhs) \
	{ \
		CB_MESSAGE_ASSERTION_FAILED(#lhs " != " #rhs); \
		CB_MESSAGE_ASSERTION_FVALUE("LHS", _cb_lhs); \
		CB_MESSAGE_ASSERTION_FVALUE("RHS", _cb_rhs); \
		CB_TEST_FAIL(); \
	} \
}

#define CB_ASSERT_FLT(lhs, rhs) { \
	cb_assertion_fvalue _cb_lhs = (cb_assertion_fvalue)(lhs); \
	cb_assertion_fvalue _cb_rhs = (cb_assertion_fvalue)(rhs); \
	if (_cb_lhs >= _cb_rhs) \
	{ \
		CB_MESSAGE_ASSERTION_FAILED(#lhs " < " #rhs); \
		CB_MESSAGE_ASSERTION_FVALUE("LHS", _cb_lhs); \
		CB_MESSAGE_ASSERTION_FVALUE("RHS", _cb_rhs); \
		CB_TEST_FAIL(); \
	} \
}

#define CB_ASSERT_FLE(lhs, rhs) { \
	cb_assertion_fvalue _cb_lhs = (cb_assertion_fvalue)(lhs); \
	cb_assertion_fvalue _cb_rhs = (cb_assertion_fvalue)(rhs); \
	if (_cb_lhs > _cb_rhs) \
	{ \
		CB_MESSAGE_ASSERTION_FAILED(#lhs " <= " #rhs); \
		CB_MESSAGE_ASSERTION_FVALUE("LHS", _cb_lhs); \
		CB_MESSAGE_ASSERTION_FVALUE("RHS", _cb_rhs); \
		CB_TEST_FAIL(); \
	} \
}

#define CB_ASSERT_FGT(lhs, rhs) { \
	cb_assertion_fvalue _cb_lhs = (cb_assertion_fvalue)(lhs); \
	cb_assertion_fvalue _cb_rhs = (cb_assertion_fvalue)(rhs); \
	if (_cb_lhs <= _cb_rhs) \
	{ \
		CB_MESSAGE_ASSERTION_FAILED(#lhs " > " #rhs); \
		CB_MESSAGE_ASSERTION_FVALUE("LHS", _cb_lhs); \
		CB_MESSAGE_ASSERTION_FVALUE("RHS", _cb_rhs); \
		CB_TEST_FAIL(); \
	} \
}

#define CB_ASSERT_FGE(lhs, rhs) { \
	cb_assertion_fvalue _cb_lhs = (cb_assertion_fvalue)(lhs); \
	cb_assertion_fvalue _cb_rhs = (cb_assertion_fvalue)(rhs); \
	if (_cb_lhs < _cb_rhs) \
	{ \
		CB_MESSAGE_ASSERTION_FAILED(#lhs " >= " #rhs); \
		CB_MESSAGE_ASSERTION_FVALUE("LHS", _cb_lhs); \
		CB_MESSAGE_ASSERTION_FVALUE("RHS", _cb_rhs); \
		CB_TEST_FAIL(); \
	} \
}

#define CB_ASSERT_SEQ(exp, act) { \
	cb_assertion_svalue _cb_exp = (cb_assertion_svalue)(exp); \
	cb_assertion_svalue _cb_act = (cb_assertion_svalue)(act); \
	if (strcmp(_cb_exp, _cb_act) != 0) \
	{ \
		CB_MESSAGE_ASSERTION_FAILED(#exp " == " #act); \
		CB_MESSAGE_ASSERTION_SVALUE("Expected", _cb_exp); \
		CB_MESSAGE_ASSERTION_SVALUE("Actual", _cb_act); \
		CB_TEST_FAIL(); \
	} \
}

#define CB_ASSERT_SNE(lhs, rhs) { \
	cb_assertion_svalue _cb_lhs = (cb_assertion_svalue)(lhs); \
	cb_assertion_svalue _cb_rhs = (cb_assertion_svalue)(rhs); \
	if (strcmp(_cb_lhs, _cb_rhs) == 0) \
	{ \
		CB_MESSAGE_ASSERTION_FAILED(#lhs " != " #rhs); \
		CB_MESSAGE_ASSERTION_SVALUE("LHS", _cb_lhs); \
		CB_MESSAGE_ASSERTION_SVALUE("RHS", _cb_rhs); \
		CB_TEST_FAIL(); \
	} \
}

#ifdef __cplusplus
extern "C"
}
#endif

#endif
