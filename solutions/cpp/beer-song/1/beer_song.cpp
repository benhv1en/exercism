#include "beer_song.h"

namespace beer_song {

std::string verse(const char& bottle) {
  if (0 >= bottle)
    return "No more bottles of beer on the wall, no more bottles of beer.\n"
           "Go to the store and buy some more, 99 bottles of beer on the "
           "wall.\n";
  if (1 == bottle)
    return "1 bottle of beer on the wall, 1 bottle of beer.\n"
           "Take it down and pass it around, no more bottles of beer "
           "on the "
           "wall.\n";
  if (2 == bottle)
    return "2 bottles of beer on the wall, 2 bottles of beer.\n"
           "Take one down and pass it around, 1 bottle of beer on the "
           "wall.\n";
  return std::to_string(bottle) + " bottles of beer on the wall, " +
         std::to_string(bottle) +
         " bottles of beer.\n"
         "Take one down and pass it around, " +
         std::to_string(bottle - 1) + " bottles of beer on the wall.\n";
}

std::string sing(const char& start) {
  std::string song = "";
  for (char bottle = start; bottle > 0; --bottle) song += verse(bottle) + "\n";
  song += verse(0);
  return song;
}

std::string sing(const char& start, const char& end) {
  std::string song = "";
  for (char bottle = start; bottle > end; --bottle)
    song += verse(bottle) + "\n";
  song += verse(end);
  return song;
}
}  // namespace beer_song
