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

COMPILATION_TEST_C(CSuccess, "clang --std=c99", " \
	#include <stdio.h>\n \
\n \
	int main()\n \
	{\n \
		return 0;\n \
	}\n \
");

COMPILATION_TEST_C(CFail, "clang --std=c99", " \
	#include <stdio.h>\n \
\n \
	int main(\n \
	{\n \
		return 0;\n \
	}\n \
");

COMPILATION_TEST_CXX(CxxSuccess, "clang++ -std=c++11", " \
	#include <iostream>\n \
\n \
	int main()\n \
	{\n \
		return 0;\n \
	}\n \
");

COMPILATION_TEST_CXX(CxxFail, "clang++ -std=c++11", " \
	#include <iostream>\n \
\n \
	int main(\n \
	{\n \
		return 0;\n \
	}\n \
");

int main(int argc, char *argv[])
{
	INIT(argc, argv);

	RUN(CSuccess);
	//RUN(CFail);
	RUN(CxxSuccess);
	//RUN(CxxFail);

	return STATUS();
}
