# Code Bomb

Code Bomb is a header-only unit testing framework for C. It has the following features:
- Assertions for boolean, integer, float, and string values.
- Each test runs in its own address space.
- Death tests.
- Timers.
- Fuzzing.

Code Bomb is licensed under the BSD-2 license.

    #include <stdio.h>
    #include <CodeBomb.h>

    int add(int a, int b)
    {
    	return a+b;
    }

    TEST(MakeSureAddWorks)
    {
    	ASSERT_EQ(5, add(2, 3));
    }

    DEATH_TEST(ThisShouldntWork)
    {
    	int *illegal = (int *)add;
    	*illegal[0] = 5;
    }

    int main(int argc, char *argv[])
    {
    	INIT(argc, argv);

    	RUN(MakeSureAddWorks);
    	RUN(ThisShouldntWork);

    	return STATUS();
    }