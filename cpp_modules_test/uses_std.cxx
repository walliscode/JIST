import std;
import repeat;

void hello_world(std::string const &name) {
  std::expected<int, std::string> test;
  std::cout << "Hello World! My name is " << name << std::endl;

  repeat_a_word(3, name);
}
