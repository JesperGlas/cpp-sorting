#include "gtest/gtest.h"

int main(int argc, char **argv)
{
	std::clog << "Running all tests.." << std::endl;
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
