#include "ColorPair.h"

namespace TelCoColorCoder
{
    const char* MajorColorNames[] = {"White", "Red", "Black", "Yellow", "Violet"};
    int numberOfMajorColors =
        sizeof(MajorColorNames) / sizeof(MajorColorNames[0]);
    const char* MinorColorNames[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    int numberOfMinorColors = sizeof(MinorColorNames) / sizeof(MinorColorNames[0]);
    std::string ColorPair::ToString() {
        std::string colorPairStr = MajorColorNames[majorColor];
        colorPairStr += " ";
        colorPairStr += MinorColorNames[minorColor];
        return colorPairStr;
    }
    ColorPair::ColorPair(MajorColor major, MinorColor minor) : majorColor(major), minorColor(minor) {}
    MajorColor ColorPair::getMajor() { return majorColor; }
    MinorColor ColorPair::getMinor() { return minorColor; }
    ColorPair GetColorFromPairNumber(int pairNumber) {
        int zeroBasedPairNumber = pairNumber - 1;
        MajorColor majorColor =
            (MajorColor)(zeroBasedPairNumber / numberOfMinorColors);
        MinorColor minorColor =
            (MinorColor)(zeroBasedPairNumber % numberOfMinorColors);
        return ColorPair(majorColor, minorColor);
    }
    int GetPairNumberFromColor(MajorColor major, MinorColor minor) {
        return major * numberOfMinorColors + minor + 1;
    }
    std::string getColorCodingManual(){
        std::string message = "Color Coding Manual\n";
        for(int pairNumber = 1; pairNumber <= (numberOfMajorColors * numberOfMinorColors); pairNumber++) {
            ColorPair colorPair = GetColorFromPairNumber(pairNumber);
            message += std::to_string(pairNumber);
            message += " ";
            message += colorPair.ToString();
            message += "\n";
        }
        return message;
    }
}