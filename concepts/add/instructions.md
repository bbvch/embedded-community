# Instructions
## Stage1 to Stage2: Add concept support
* Show that original _add()_ function makes no sense to be called from _int_ and _const char*_.
* Show that function is not compiling for _int_ and _std::string_ parameter, but error message is again showing implementation details.
* Create a concept __addable__:
```
template<typename T1, typename T2>
concept addable = requires(T1 t1, T2 t2)
{
    { t1 + t2 };
};
```
* Apply this to add function. Since this is a 2 param concept, it must be reformulated:
```
template<typename T1, typename T2> requires addable<T1, T2>
auto add(T1 arg1, T2 arg2)
```
* Show that 4th add statement show a better error message.
* However: the 3rd add statement is still possible.
* Extend the concept:
```
template<typename T1, typename T2>
concept addable = requires(T1 t1, T2 t2)
{
    { t1 + t2 } -> std::convertible_to<std::common_type_t<T1, T2>>;
};
```
* Now 3rd add call is also no longer compiling
* Show that the concept could also be added inline (the famous _requires requires_):
```
template<typename T1, typename T2> requires requires(T1 t1, T2 t2)
{
    { t1 + t2 } -> std::convertible_to<std::common_type_t<T1, T2>>;
}
auto add(T1 arg1, T2 arg2)
```
__Don't try this at home!__