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

#ifndef __CODEBOMB_CodeBomb_H
#define __CODEBOMB_CodeBomb_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "Init.h"
#include "Test.h"
#include "Version.h"
#include "Assertions.h"
#include "DeathTest.h"
#include "Timing.h"
#include "Fuzzer.h"
#include "CompilationTest.h"

#ifndef CB_USE_LONG_MACROS
#define INIT(argc, argv) CB_INIT(argc, argv)
#define TEST(name) CB_TEST(name)
#define RUN(name) CB_RUN(name)
#define STATUS() CB_STATUS()
#define ASSERT_TRUE(expr) CB_ASSERT_TRUE(expr)
#define ASSERT_FALSE(expr) CB_ASSERT_FALSE(expr)
#define ASSERT_EQ(exp, act) CB_ASSERT_EQ(exp, act)
#define ASSERT_NE(lhs, rhs) CB_ASSERT_NE(lhs, rhs)
#define ASSERT_LT(lhs, rhs) CB_ASSERT_LT(lhs, rhs)
#define ASSERT_LE(lhs, rhs) CB_ASSERT_LE(lhs, rhs)
#define ASSERT_GT(lhs, rhs) CB_ASSERT_GT(lhs, rhs)
#define ASSERT_GE(lhs, rhs) CB_ASSERT_GE(lhs, rhs)
#define ASSERT_FEQ(exp, act) CB_ASSERT_FEQ(exp, act)
#define ASSERT_FNE(lhs, rhs) CB_ASSERT_FNE(lhs, rhs)
#define ASSERT_FLT(lhs, rhs) CB_ASSERT_FLT(lhs, rhs)
#define ASSERT_FLE(lhs, rhs) CB_ASSERT_FLE(lhs, rhs)
#define ASSERT_FGT(lhs, rhs) CB_ASSERT_FGT(lhs, rhs)
#define ASSERT_FGE(lhs, rhs) CB_ASSERT_FGE(lhs, rhs)
#define ASSERT_SEQ(exp, act) CB_ASSERT_SEQ(exp, act)
#define ASSERT_SNE(lhs, rhs) CB_ASSERT_SNE(lhs, rhs)
#define DEATH_TEST(name) CB_DEATH_TEST(name)
#define START_TIMER(name, repetitions) CB_START_TIMER(name, repetitions)
#define STOP_TIMER(name) CB_STOP_TIMER(name)
#define FUZZ(type, fuzzer, repetitions, true_assertion) CB_FUZZ(type, fuzzer, repetitions, true_assertion)
#define COMPILATION_TEST_C(name, cmd, code) CB_COMPILATION_TEST_C(name, cmd, code)
#define COMPILATION_TEST_CXX(name, cmd, code) CB_COMPILATION_TEST_CXX(name, cmd, code)
#endif

#ifdef __cplusplus
}
#endif

#endif