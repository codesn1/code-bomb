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
}
#endif

#endif
