#include "util.tcc"
#include <optional>

using namespace std;

/****/
template<typename A, typename B>
struct assert_same_types {
  static_assert(is_same_v<A, B>);
};

assert_same_types<remove_optional_t<int>, int> a;
/****/

/****/
static_assert(is_type_any_of_v<int, int, char*, bool>);
static_assert(is_type_any_of_v<bool, int, char*, bool>);
static_assert(!is_type_any_of_v<is_type_any_of<int, char*>, int, char*, bool>);
static_assert(!is_type_any_of_v<is_type_any_of<int, char*>, is_type_any_of<int, char>>);
static_assert(is_type_any_of_v<is_type_any_of<int, char*>, is_type_any_of<int, char*>>);
static_assert(!is_type_any_of_v<int, char*, bool>);
/****/
