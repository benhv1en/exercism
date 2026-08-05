#include "clock.h"

namespace date_independent {

std::pair<int, int> clock::Normalise(const int& hour, const int& minute) {
  int normalised_hour = hour, normalised_minute = minute;

  if (normalised_minute >= 0) {
    normalised_minute %= 60;
    normalised_hour += minute / 60;
  } else {
    normalised_minute = (60 + normalised_minute % 60) % 60;
    if (normalised_minute == 0)
      normalised_hour += minute / 60;
    else
      normalised_hour += minute / 60 - 1;
  }

  if (normalised_hour >= 0)
    normalised_hour %= 24;
  else
    normalised_hour = (24 + normalised_hour % 24) % 24;

  return std::make_pair(normalised_hour, normalised_minute);
}

clock clock::at(const int& hour, const int& minute) {
  int normalised_hour = hour, normalised_minute = minute;
  std::pair<int, int> hm = Normalise(normalised_hour, normalised_minute);
  return *(new clock(hm.first, hm.second));
}

clock clock::plus(const int& minute) {
  std::pair<int, int> normalised = Normalise(hour_, minutes_ + minute);
  return *(new clock(normalised.first, normalised.second));
}

clock::operator std::string() const {
  std::ostringstream stream;
  stream << std::setfill('0') << std::setw(2) << hour_ << ":" << std::setw(2) << minutes_;
  return stream.str();
}

int clock::Hour() { return hour_; }

int clock::Minute() { return minutes_; }

bool clock::operator==(const clock other) const {
  std::pair<int, int> normalised = Normalise(hour_, minutes_);
  std::pair<int, int> normalised_other = Normalise(other.hour_, other.minutes_);
  return normalised == normalised_other;
}

bool clock::operator!=(const clock other) const {
  std::pair<int, int> normalised = Normalise(hour_, minutes_);
  std::pair<int, int> normalised_other = Normalise(other.hour_, other.minutes_);
  return normalised != normalised_other;
}
}  // namespace date_independant
