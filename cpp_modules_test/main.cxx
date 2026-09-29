
#include <string>

void hello_world(std::string const &name = "Ben");

int main(int argc, char *argv[]) {
  hello_world("Wallis");
  return 0;
}
