#pragma once

#include <memory>
#include <stdexcept>
#include <string>

namespace circular_buffer {

template <typename T>
class circular_buffer {
 private:
  std::unique_ptr<T[]> value_;
  size_t size_, read_index_, write_index_;
  bool empty_;
  std::unique_ptr<bool[]> has_read_, has_written_;

 public:
  circular_buffer(const size_t& size)
      : size_(size), read_index_(0), write_index_(0), empty_(true) {
    value_ = std::make_unique<T[]>(size_);
    has_read_ = std::make_unique<bool[]>(size_);
    has_written_ = std::make_unique<bool[]>(size_);
    for (size_t i = 0; i < size_; ++i) {
      has_read_[i] = false;
      has_written_[i] = false;
    }
  }

  T read() {
    if (empty_) throw std::domain_error("reading_empty_buffer_should_fail");
    if (has_read_[read_index_])
      throw std::domain_error("each_item_may_only_be_read_once");
    has_read_[read_index_] = true;
    has_written_[read_index_] = false;
    read_index_ = (read_index_ + 1) % size_;
    return value_[(size_ + read_index_ - 1) % size_];
  }

  void write(const T& element) {
    bool full = true;
    for (size_t i = 0; i < size_; ++i)
      if (!has_written_[i]) {
        full = false;
        break;
      }
    if (full) throw std::domain_error("full_buffer_cant_be_written");
    empty_ = false;
    while (has_written_[write_index_]) ++write_index_;
    value_[write_index_] = element;
    has_written_[write_index_] = true;
    has_read_[write_index_] = false;
    write_index_ = (write_index_ + 1) % size_;
  }
  void clear() {
    if (empty_) return;
    empty_ = true;
    for (size_t i = 0; i < size_; ++i) {
      has_read_[i] = false;
      has_written_[i] = false;
    }
    read_index_ = write_index_ = 0;
  }
  void overwrite(const T& element) {
    bool full = true;
    for (size_t i = 0; i < size_; ++i)
      if (!has_written_[i]) {
        full = false;
        break;
      }
    if (!full)
      write(element);
    else {
      value_[write_index_] = element;
      has_read_[write_index_] = false;
      read_index_ = (write_index_ + 1) % size_;
      write_index_ = (write_index_ + 1) % size_;
    }
  }
};
}  // namespace circular_buffer
