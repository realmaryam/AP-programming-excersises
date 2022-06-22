#include <iostream>
#include "gtest/gtest.h"

#include <limits.h>
#include <iostream>
#include "gtest/gtest.h"
#include "rectangle.h"
#include "triangle.h"
#include "square.h"
#include "prism.h"
#include "pyramid.h"
int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    std::cout << "RUNNING TESTS ..." << std::endl;
    int ret{RUN_ALL_TESTS()};
    if (!ret)
        std::cout << "<<<SUCCESS>>>" << std::endl;
    else
        std::cout << "FAILED" << std::endl;
    return 0;
}

