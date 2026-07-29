#include "secret_handshake.h"

namespace secret_handshake {
std::vector<std::string> commands(unsigned char code) {
  assert(code <= 0b11111);

  unsigned char mask = 0b10000;
  std::stack<bool> bits;
  const bool reversed = code & mask;
  for (unsigned char i = 0; i < 4; ++i) {
    if (reversed) {
      bits.push(code & 0b00001);
      code >>= 1;
    } else {
      bits.push(code & 0b01000);
      code <<= 1;
    }
  }

  std::vector<std::string> actions;

  for (unsigned char i = 0; i < 4; ++i) {
    if (bits.top()) {
      if (!reversed)
        actions.push_back(kActions[i]);
      else
        actions.push_back(kActions[3 - i]);
    }
    bits.pop();
  }

  return actions;
}
}  // namespace secret_handshake
