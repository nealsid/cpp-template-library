#include <iostream>
#include <variant>

using namespace std;

template <typename... Args>
struct foo : variant<Args...> {
  using variant<Args...>::variant;

  void operator()() {
    ( [&] () {
      if (holds_alternative<Args>(*this)) {
        f<Args>(get<Args>(*this));
      }
    }(), ...);
  }

  template<typename T>
  void f(T a);

  template<>
  void f<int>(int a) {
    cout << a << endl;
    return;
  }

  template<>
  void f<string>(string a) {
    cout << a << endl;
    return;
  }

};

int main(int argc, char* argv[]) {
  cout << "hello, world!" << endl;

  foo<int, string> v = "hello";
  v();
}
