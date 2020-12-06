#pragma once
#include <algorithm>
#include <iostream>
#include <optional>

template <typename T> class queue {
private:
  std::optional<T> *ptr;
  int capacity;
  int head;
  int tail;
  int count;

public:
  queue(int cap = 4)
      : capacity(cap), ptr(new std::optional<T>[cap]), head(0), tail(0),
        count(0) {
    for (int i = 0; i < cap; i++)
      ptr[i] = std::nullopt;
  }

  void push_back(T val) {
    if (count >= capacity) {
      throw std::exception("Queue is full");
    }
    if (ptr[head % capacity] != std::nullopt) {
      throw std::exception("Queue is full");
    }
    ptr[head % capacity] = std::make_optional(std::move(val));
    head++;
    count++;
  }
  T get() {
    if (ptr[tail] == std::nullopt) {
      throw std::exception("Queue is empty");
    }

    auto ret = ptr[tail].value();
    ptr[tail] = std::nullopt;
    if (++tail >= capacity) {
      tail = 0;
    }
    if (count-- <= 0) {
      throw std::exception("Queue is empty");
    }

    return ret;
  }
  ~queue() { delete[] ptr; }

  friend std::ostream &operator<<(std::ostream &cout, queue &q) {
    std::for_each(q.ptr, q.ptr + q.capacity,
                  [&cout](auto q) { cout << q.value() << " "; });
    return cout;
  }
};