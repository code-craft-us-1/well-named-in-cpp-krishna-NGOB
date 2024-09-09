#include <iostream>
#include <assert.h>
#include "ColorPair.h"

namespace TelCoColorCoder
{
    void testNumberToPair(int pairNumber,
        TelCoColorCoder::MajorColor expectedMajor,
        TelCoColorCoder::MinorColor expectedMinor)
    {
        TelCoColorCoder::ColorPair colorPair =
            TelCoColorCoder::GetColorFromPairNumber(pairNumber);
        std::cout << "Got pair " << colorPair.ToString() << std::endl;
        assert(colorPair.getMajor() == expectedMajor);
        assert(colorPair.getMinor() == expectedMinor);
    }
 
    void testPairToNumber(
        TelCoColorCoder::MajorColor major,
        TelCoColorCoder::MinorColor minor,
        int expectedPairNumber)
    {
        int pairNumber = TelCoColorCoder::GetPairNumberFromColor(major, minor);
        std::cout << "Got pair number " << pairNumber << std::endl;
        assert(pairNumber == expectedPairNumber);
    }

    // Test function to print color coding manual
    void testPrintColorCodingManual() {
        std::string expectedOutput = "Color Coding Manual\n";
        int totalPairs = numberOfMajorColors * numberOfMinorColors;
        for(int pairNumber = 1; pairNumber <= totalPairs; pairNumber++) {
            ColorPair colorPair = GetColorFromPairNumber(pairNumber);
            expectedOutput += std::to_string(pairNumber);
            expectedOutput += " ";
            expectedOutput += colorPair.ToString();
            expectedOutput += "\n";
        }

        std::string actualOutput = getColorCodingManual();
        assert(actualOutput == expectedOutput);
        std::cout << "testPrintColorCodingManual passed!" << std::endl;
    }
}