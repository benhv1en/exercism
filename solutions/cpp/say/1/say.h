#pragma once

#include <cmath>
#include <map>
#include <stdexcept>
#include <string>
#include <vector>

const std::map<long, std::string> kSayingNumbers{
    {0, "zero"},    {1, "one"},       {2, "two"},      {3, "three"},
    {4, "four"},    {5, "five"},      {6, "six"},      {7, "seven"},
    {8, "eight"},   {9, "nine"},      {10, "ten"},     {11, "eleven"},
    {12, "twelve"}, {13, "thirteen"}, {15, "fifteen"}, {18, "eighteen"},
    {20, "twenty"}, {30, "thirty"},   {40, "forty"},   {50, "fifty"},
    {80, "eighty"}

};

std::string SayThreeDigits(long number);

namespace say {
std::string in_english(long);
}

namespace say {

// TODO: add your solution here

}  // namespace say
