#include <chrono>

unsigned long millis() {
  static const auto startTime = std::chrono::steady_clock::now();

  auto now = std::chrono::steady_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(now - startTime);

  return static_cast<unsigned long>(duration.count());
}
