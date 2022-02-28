// Useful function traits.
template<typename R, typename... Args>
struct FunctionTraits<R(*)(Args...)> {
  using RetType = R;
  using ParameterTraits = ParameterTraits<0, 0, 0, true, Args...>;
};

// Determines if a type is std::optional<T> for some T
template<typename T>
struct is_optional_type {
  static constexpr bool value = false;
};

template<typename T>
struct is_optional_type<optional<T>> {
  static constexpr bool value = true;
};

template<typename T>
inline constexpr bool is_optional_type_v = is_optional_type<T>::value;

// Removes optional from a given type if it is present.
template<typename T>
struct remove_optional {
  using type = T;
};

template<typename T>
using remove_optional_t = typename remove_optional<T>::type;

template<typename T>
struct remove_optional<optional<T>> {
  using type = remove_optional_t<T>;
};

// Tweak to std::is_same to let caller provide a list of types.
template<typename A, typename First, typename... Rest>
struct is_type_any_of {
  static constexpr bool value = is_same_v<A, First> || is_type_any_of<A, Rest...>::value;
};

template<typename A, typename B>
struct is_type_any_of<A, B> {
  static constexpr bool value = is_same_v<A, B>;
};

template<typename A, typename... Rest>
inline constexpr bool is_type_any_of_v = is_type_any_of<A, Rest...>::value;
