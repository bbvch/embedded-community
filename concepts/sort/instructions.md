# Test program "sort"
## About
This is the first example where we first show how concept-like techniques where possible by using SFINAE-based tricks.

## Instructions
### Stage1 to Stage2: Adding SFINAE based solution
* Pass flag `--std=c++17` to compiler explorer.
* Load _stage1.cpp_ into compiler explorer.
* Show that _my_regular_sort_ can indeed not be called with iterators to a list by uncommenting statement.
* Rename _my_regular_sort_ and _my_copy_sort_ to _my_sort_.

__Code will no longer compile!__

* Add _using_ statements for type_traits:
```
template <typename It>
using is_random_access_it = std::is_base_of<
	std::random_access_iterator_tag,
	typename std::iterator_traits<It>::iterator_category>;

```
* Change signature of first _my_sort_ method with 
```
template<typename It>
typename std::enable_if<is_random_access_it<It>::value, void>::type 
my_sort(It first, It last)
```
__Code is still not compiling: Ambiguity remains!__

* Add second __using__ statement:
```
template <typename It>
using is_forward_it = std::is_base_of<
	std::forward_iterator_tag,
	typename std::iterator_traits<It>::iterator_category>;
```
* Change signature of second _my_sort_ method with:
```
template<typename It>
typename std::enable_if<is_forward_it<It>::value, void>::type 
my_sort(It first, It last)

```
* Add a third __using__ clause:
```
template <typename It>
using is_forward_only_it = std::conjunction<
	is_forward_it<It>, 
	std::negation<is_random_access_it<It>>>;

```
* Replace `is_forward_it` with `is_forward_only_it`: __Now compiles!__

__Solution prior concepts: Works also with C++17!__

### Stage2 to Stage3: Replace SFINAE with concept
* Change compiler flag to `--std=c++20` 
* Replace `is_random_access_it` by a concept:
```
template <typename It>
concept is_random_access_it = std::is_base_of<
	std::random_access_iterator_tag,
	typename std::iterator_traits<It>::iterator_category>::value;
```
* Comment out `is_forward_only_it`.
* Replace first _my_sort_ signature with
```
template <typename It>
void my_sort(It first, It last) requires is_random_access_it<It>
```
* Replace second _my_sort_ signature with what it had originally.

__Surprise: already compiles without ambiguity!__

* Show that its still a good idea to restrict second _my_sort_. Add the following line to _main_: `my_sort(2, 5);`
* Comment the line out again.
* Change the second __using__ declaration to a concept:
```
template <typename It>
concept is_forward_it = std::is_base_of<
	std::forward_iterator_tag,
	typename std::iterator_traits<It>::iterator_category>::value;

```
* Change the function signature of the second _my_sort_ call:
```
template <typename It>
void my_sort(It first, It last) requires is_forward_it<It>
```
__Ambiguity is back!__
* Explain that this happens because the compiler doesn't know that _is_random_access_it_ is an extension of _is_forward_it_.
* Change order of the 2 concepts.
* Change _is_random_access_it_ to:
```
template <typename It>
concept is_random_access_it = 
    is_forward_it<It> &&
    std::is_base_of<
        std::random_access_iterator_tag,
        typename std::iterator_traits<It>::iterator_category>::value;
```
__Compiles again.__
* Show that error message is much better when uncommenting the `my_sort(2, 5);` line.
* Comment out line again.

__Working solution with concepts.__

### Step3 to Step4: Other options with concepts.
* Showcase other possibilities of _requires_ clause after _template_ statement:
```
template <typename It> requires is_random_access_it<It>
void my_sort(It first, It last)
```
__=> Preferred solution if concept is not dependent on method parameters.__
* Showcase most simple possibility of concept:
```
template <is_random_access_it It>
void my_sort(It first, It last)
```
__=> Preferred solution with concept having one template param.__
* Names are no longer ideal: Remove _is__ prefix from concept names. Use the same requirements definition technique also for second_my_sort_ call.
* Defining the concept ourselves is not really required: They exist already in the standard: Replace _random_access_it_ with __std::random_access_iterator__ and _forward_it_ with __std::forward_iterator__.
* Show that the error message is now a bit different when uncommenting the `my_sort(2, 5);` call.
