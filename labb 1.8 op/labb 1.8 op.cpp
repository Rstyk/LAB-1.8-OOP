#include "pch.h"
#include "CppUnitTest.h"
#include "../lab 1.8 op/Triangle.h"
#include "../lab 1.8 op/Triangle.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace labb18op
{
	TEST_CLASS(labb18op)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Triangle t;
			t.init(0, 0, 3, 0, 0, 4);
			double square = t.square();
			Assert::AreEqual(6.0, square);

		}
	};
}
