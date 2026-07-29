#pragma once
#include <array>
#include <cassert>
#include <stack>
#include <string>
#include <vector>


const std::array<std::string, 4> kActions = {"wink", "double blink",
                                             "close your eyes", "jump"};

namespace secret_handshake {
std::vector<std::string> commands(unsigned char);
}
