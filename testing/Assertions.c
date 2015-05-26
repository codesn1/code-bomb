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
