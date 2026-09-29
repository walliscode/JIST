
module;

export module repeat;
import std;

export void repeat_a_word(int n, const std::string &word) {

  for (int i = 0; i < n; ++i) {
    std::cout << i + 1 << " " << word << std::endl;
  }
}
