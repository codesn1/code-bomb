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
#endif

#ifdef __cplusplus
extern "C"
}
#endif

#endif