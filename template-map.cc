#include <iostream>
#include <array>

using namespace std;


template<typename T>
constexpr size_t paramTypeAnalysis() {
  if constexpr (is_same_v<T, int>) {
    return 1;
  } else {
    return 0;
  }
}


// template<int parametersRemaining, auto MapFn, typename Callable, auto... Results>
// struct ArgumentAnalyzer {};

// template<int parametersRemaining, auto MapFn, typename R, typename FirstParam, typename... Args, int... Results>
// struct ArgumentAnalyzer<parametersRemaining, MapFn, R(*)(FirstParam, Args...), Results...> :
//   ArgumentAnalyzer<parametersRemaining - 1, MapFn, R(*)(Args...), MapFn(), Results...> {
// };

// template<auto MapFn, typename R, int... Results>
// struct ArgumentAnalyzer<0, MapFn, R(*)(), Results...> {
//   static constexpr std::initializer_list<int> parameterInfo = { Results... };
// };

#define CreateTypeMapperMacro(UninstantiatedTemplateFunctionName, args...) \
  template<typename... Args>  \
  struct Foo ## UninstantiatedTemplateFunctionName { \
    static constexpr std::array<size_t, sizeof...(Args)> results = { \
						   UninstantiatedTemplateFunctionName<Args>() ... \
						   }; \
  };

// template<auto... Fns, typename... Types>
// struct TypeMapper {
//   std::array<size_t, sizeof... (Types)> results = {
//     Fns() ...
//   };
// };

void foo(int a, float b, double c) {
  cout << "Hello, world!" << endl;
}

template<typename T>
struct TD;

CreateTypeMapperMacro(paramTypeAnalysis, int, float, double)

int main(int argc, char* argv[]) {
  // TypeMapper<&paramTypeAnalysis<int>, &paramTypeAnalysis<float>, &paramTypeAnalysis<double>, int, double, double> ft;
  for (const auto& x : FooparamTypeAnalysis<int, float, double>::results) {
    cout << x << endl;
  }
}
