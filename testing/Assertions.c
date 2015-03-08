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

#include <CodeBomb.h>

TEST(IntegerAssertions)
{
	ASSERT_TRUE(1);
	ASSERT_FALSE(0);
	ASSERT_EQ(1, 1);
	ASSERT_NE(1, 2);
	ASSERT_LT(1, 2);
	ASSERT_LE(1, 1);
	ASSERT_GT(2, 1);
	ASSERT_GE(1, 1);
}

TEST(FloatAssertions)
{
	ASSERT_FEQ(5.0, 5.0);
	ASSERT_FNE(5.0, 3.0);
	ASSERT_FLT(3.0, 5.0);
	ASSERT_FLE(3.0, 3.0);
	ASSERT_FGT(5.0, 3.0);
	ASSERT_FGE(3.0, 3.0);
}

TEST(StringAssertions)
{
	ASSERT_SEQ("hi", "hi");
	ASSERT_SNE("hi", "lo");
}

int main(int argc, char *argv[])
{
	INIT(argc, argv);

	RUN(IntegerAssertions);
	RUN(FloatAssertions);
	RUN(StringAssertions);

	return STATUS();
}
