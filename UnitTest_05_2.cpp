#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_05_2/Lab_05_2.cpp" // Шлях до вашого файлу Lab_05_2.cpp

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest052
{
    TEST_CLASS(UnitTest052)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            int n = 0;
            double s = 0;
            double eps = 0.00001;

            // Перевірка 1: S(0.0) має дорівнювати 0.0
            double actual0 = S(0.0, eps, n, s);
            Assert::AreEqual(0.0, actual0, eps);

            // Перевірка 2: S(0.5) має збігатися з atan(0.5)
            double actual05 = S(0.5, eps, n, s);
            double expected05 = atan(0.5);
            Assert::AreEqual(expected05, actual05, eps);
        }
    };
}