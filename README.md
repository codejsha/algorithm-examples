# Algorithm Examples

![C++ CI with CMake](https://github.com/codejsha/algorithm-examples/actions/workflows/cmake.yml/badge.svg) ![Python CI](https://github.com/codejsha/algorithm-examples/actions/workflows/python.yml/badge.svg) ![Java CI with Gradle](https://github.com/codejsha/algorithm-examples/actions/workflows/gradle.yml/badge.svg)

[Korean](README_ko-KR.md)

This repository is an implementation of algorithms, data structures, and problem solving. These are written in C++, Python, and Java, and each language uses the following test framework: [Google Test](https://google.github.io/googletest/)(C++), [pytest](https://docs.pytest.org/)(Python), [JUnit](https://junit.org/)(Java). Run tests to perform methods/functions on the algorithmic logic. GitHub Actions workflows that build and test code run manually.

Additionally, each project is configured in the following environments:

- C++ project: based on [CMake](https://cmake.org/) project and uses [GNU Scientific Library (GSL)](https://www.gnu.org/software/gsl/), [Google Test](https://google.github.io/googletest/), [Google Benchmark](https://github.com/google/benchmark), [fmt](https://github.com/fmtlib/fmt) packages (package manager [vcpkg](https://github.com/microsoft/vcpkg))
- Python project: uses [NumPy](https://numpy.org/), [SciPy](https://www.scipy.org/), [pytest](https://docs.pytest.org/), [pytest-benchmark](https://pytest-benchmark.readthedocs.io/en/latest/) packages
- Java project: based on [Gradle](https://gradle.org/) project and uses [JUnit](https://junit.org/), [Java Microbenchmark Harness (JMH)](https://github.com/openjdk/jmh) libraries

## Table of Contents

- [Table of Contents](#table-of-contents)
- [Data structures](#data-structures)
  - [Array](#array)
  - [Graph](#graph)
  - [Hash table](#hash-table)
  - [Heap](#heap)
  - [Linked list](#linked-list)
  - [Queue](#queue)
  - [Stack](#stack)
  - [Tree](#tree)
- [Topics](#topics)
  - [Dynamic programming](#dynamic-programming)
  - [Greedy](#greedy)
  - [Mathematics](#mathematics)
  - [Primitive type](#primitive-type)
  - [Search](#search)
  - [Sort](#sort)
  - [String](#string)
- [References](#references)

## Data structures

### Array

```cpp
//// c++ definition/methods
auto v = std::vector{1, 2, 3, 4, 5};
auto sub_v = std::vector<int>{v.begin(), v.end() - 1};
auto arr = std::array{1, 2, 3, 4, 5};
auto sub_arr = std::array{arr.begin(), arr.end() - 1};

// algorithm
std::ranges::any_of(v, [](auto x) { return x % 2 == 0; })
std::ranges::all_of(v, [](auto x) { return x % 2 == 0; })
std::ranges::none_of(v, [](auto x) { return x % 2 == 0; })
std::ranges::for_each(v, [](auto x) { std::cout << x << " "; }).fun
std::ranges::count(v, 42)
std::ranges::count_if(v, [](auto x) { return x % 2 == 0; })
std::ranges::find(v, 42)
std::ranges::find_if(v, [](auto x) { return x % 2 == 0; })
std::ranges::find_end(v, sub_v).begin() // cf. result - v.begin()
std::ranges::reverse(v)
std::ranges::rotate(v, v.end() - k)
std::ranges::sort(v)
std::ranges::binary_search(v, 42)
std::ranges::lower_bound(v, 42)
std::ranges::upper_bound(v, 42)
std::ranges::min_element(v)
std::ranges::max_element(v)
std::ranges::minmax_element(v)
```
- Advancing through an array: [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/array)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/array)) | Advance through the array to the last index.
- Arbitrary precision operation - increment an arbitrary-precision integer (PlusOne): [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/array)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/array)) | Add one to the number represented by the vector.
- Arbitrary precision operation - add two arbitrary-precision integers (StringAddition): [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/array)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/array)) | Add two numbers represented by strings.
- Arbitrary precision operation - multiply two arbitrary-precision integers (Multiply): [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/array)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/array)) | Multiply two numbers represented by vectors.
- Delete duplicates from a sorted array (DeleteDuplicates): [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/array)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/array)) | Delete duplicate elements in the array.
- Delete duplicates from a sorted array (DeleteDuplicateElements): [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/array)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/array)) | Delete duplicate elements in the array.
- Delete specific elements from a sorted array (DeleteSpecificElements): [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/array)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/array)) | Delete specific elements in the array.
- Dutch national flags problem: [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/array)
- Enumerate prime numbers: [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/array)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/array)) | Enumerate prime numbers in the range.
- Order elements in an array by even and odd (EvenOdd): [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/array) | Order even and odd numbers in the array.
- Order elements in an array by specified order (Rearrange): [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/array) | Rearrange arrays to have a specific order.
- Random data sampling - offline (OfflineRandomSampling): [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/array)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/array)) | Randomly select k elements from the array.
- Random data sampling - compute permutation (ComputeRandomPermutation): [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/array)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/array)) | Compute permutation of the array generated by random sampling.
- Replace elements - replace and remove (ReplaceAndRemoveString1): [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/array)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/array)) | Replace element and remove element in the array. Keep the array size.
- Replace elements - replace and remove (ReplaceAndRemoveString2): [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/array)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/array)) | Replace element and remove element in the array
- Replace elements - telex encoding (TelexEncoding): [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/array)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/array)) | Telex encoding for punctuation marks.
- Stock trading - buy and sell a stock once (BuyAndSellStockOnceBruteForce, BuyAndSellStockOnce): [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/array)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/array))
- Stock trading - buy and sell a stock twice (BuyAndSellStockTwice): [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/array)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/array))

### Graph

- Bellman-Ford algorithm: [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/graph)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/graph)) | Bellman-Ford algorithm is a shortest path algorithm for a single source. It finds the shortest path from a source vertex to all other vertices in a weighted graph. This includes cases where the weight is negative.
- Breadth-first search (BFS): [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/graph)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/graph)) | BFS is a search algorithm that traverses a graph layer by layer.
- Depth-first search (DFS): [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/graph)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/graph)) | DFS is a search algorithm that traverses a graph by exploring as far as possible along each branch before backtracking.
- Dijkstra's algorithm: [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/graph)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/graph)) | Dijkstra's algorithm is a graph search algorithm that finds the shortest path between two vertices in a graph. This is limited to cases where the weight is not negative.

### Hash table

```cpp
//// c++ definition/methods
auto map = std::unordered_map<std::string, int>{{"a", 1}, {"b", 2}};
insert({"c", 3}), emplace("d", 4), erase("a"), find("b"), size(), empty()

auto set = std::unordered_set{1, 2, 3, 4, 5};
insert(42), emplace(42), erase(42), find(42), size()
```

### Heap

```cpp
//// c++ definition/methods
auto queue = std::priority_queue<int>{};
push(1), emplace(2), pop(), top(), size(), empty()
```

### Linked list

```cpp
//// c++ definition/methods
auto list = std::list{1, 2, 3};
push_front(4), emplace_front(5), push_back(6), emplace_back(7),
pop_front(), pop_back(), reverse(), sort(), insert(list.begin(), 11),
emplace(list.end(), 12), splice(list.end(), std::list{8, 9, 10})

auto list = std::forward_list{1, 2, 3};
push_front(4), emplace_front(5), pop_front(), reverse(), sort()
```

- Add list-based integers (AddTwoNumbers): [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/linked_list)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/linked_list)) | Add two numbers represented by linked list.
- Delete a node from linked list (DeleteNodeFromList): [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/linked_list)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/linked_list)) | Delete a node from a linked list.
- Delete duplicate nodes from sorted linked list (DeleteDuplicateNode): [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/linked_list)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/linked_list)) | Delete duplicate nodes from a sorted linked list.
- Delete the k-th last node from linked list (DeleteNodeKthLast): [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/linked_list)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/linked_list)) | Delete the k-th last node from a linked list.
- Implement cyclic right shift for a singly linked list (CyclicallyRightShiftList): [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/linked_list)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/linked_list)) | Implement cyclic right shift for a singly linked list.
- Linked list has a cycle (HasCycle1, HasCycle2, HasCycle3): [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/linked_list)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/linked_list)) | Determine that a linked list has a cycle.
- List pivoting (ListPivoting): [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/linked_list)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/linked_list)) | Rearrange nodes smaller than pivot to the left and larger than pivot to the right.
- Merge even and odd nodes in linked list (MergeEvenOddLinkedList): [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/linked_list)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/linked_list)) | Merge even and odd nodes in a singly linked list.
- Merge two sorted linked lists: [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/linked_list)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/linked_list)) | Merge two sorted linked lists. In worst-case, this task has $O(n + m)$ time complexity, where $n$ and $m$ are the length of the lists.
- Palindrome list (IsListPalindrome): [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/linked_list)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/linked_list)) | Determine that a linked list is a palindrome.
- Reverse a single sublist: [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/linked_list)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/linked_list)) | Reverse a single sublist of a linked list.
- Two linked lists overlap (OverlappingNoCycleList): [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/linked_list)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/linked_list)) | Determine that two linked lists without cycle overlap.
- Two linked lists with cycles overlap (OverlappingCycleList) [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/linked_list)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/linked_list)) | Determine that two linked lists with cycle overlap.

### Queue

```cpp
//// c++ definition/methods
auto container = std::queue<int>{};
push(1), emplace(2), pop(), front(), back(), size(), empty()

auto container = std::deque<int>{};
push_back(1), emplace_back(2), push_front(3), emplace_front(4),
pop_back(), pop_front(), front(), back(), size(), empty()
```

### Stack

```cpp
//// c++ definition/methods
auto stack = std::stack<int>{};
push(1), emplace(2), pop(), top(), size(), empty()
```

- Pair of bracket (CheckPairOfBracket): [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/stack)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/stack)) | Checks if the input string contains bracket pairs and is well-formed.
- Print linked list in reverse order (PrintLinkedListInReverseOrder): [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/stack)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/stack)) | Print the linked list in reverse order using stack.
- Max stack element: [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/stack)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/stack)) | Implement stack that caches max value.

### Tree

- B-tree: [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/tree)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/tree)) | B-tree is a self-balancing data structure which can have many child nodes. It is commonly used in auxiliary storage devices and database system. B-tree has the following properties: 1) Nodes have lower and upper bounds on the number of keys they can contain. (represent using degree $t$) 2) Every node other than the root must have at least $t-1$ keys. 3) Every node may contain at most $2t-1$ keys.
- Balanced tree status: [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/tree)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/tree)) | Whether the binary tree is balanced or not.
- Binary search tree: [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/tree)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/tree)) | In binary search tree, all internal nodes are stored in ordered state. If y is a child of x and y is a node in the left subtree, then $y.key \leq x.key$, and if y is a node in the right subtree, then $y.key \geq x.key$.
- Construct binary tree from preorder and inorder traversal (ConstructTreeFromPreorderInorder): [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/tree)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/tree)) | Construct a binary search tree from preorder and inorder traversal. This task has $O(n)$ time complexity,
- Lowest common ancestor (FindLowestCommonAncestor): [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/tree)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/tree)) | Find the lowest common ancestor of two nodes in a binary tree.
- Lowest common ancestor with parent pointer (FindLowestCommonAncestor2): [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/tree)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/tree)) | Find the lowest common ancestor of two nodes in a binary tree. The nodes have parent pointers.
- Root to leaf path corresponding to the given sum (HasKeySum): [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/tree)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/tree)) | Whether the tree has a root-leaf path equal to the given sum.
- Sum of root to leaf (SumRootToLeafDecimal, SumRootToLeafBinary): [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/tree)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/tree)) | Sum of all root to leaf paths in a binary tree (decimal and binary representation).
- Tree symmetric: [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/tree)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/tree)) | Whether the binary tree is symmetric or not.

**Properties of Trees**

- A tree with $n$ vertices has $n-1$ edges.
- A full $m$-ary tree with $i$ internal vertices contains $n = mi + 1$ vertices. (cf. vertices $n$ = internal vertices $i$ + leaves $l$)
- A full $m$-ary tree with
    - $(i)$ $n$ vertices has $i = (n - 1)∕m$ internal vertices and $l = [(m - 1)n + 1]∕m$ leaves,
    - $(ii)$ $i$ internal vertices has $n = mi + 1$ vertices and $l = (m - 1)i + 1$ leaves,
    - $(iii)$ $l$ leaves has $n = (ml - 1)∕(m - 1)$ vertices and $i = (l - 1)∕(m - 1)$ internal vertices.
- There are at most $m^h$ leaves in an $m$-ary tree of height $h$. $(l = m^h)$
    - If an $m$-ary tree of height $h$ has $l$ leaves, then $h \geq \lceil \log_{m}{l} \rceil$.
    - If the $m$-ary tree is full and balanced, then $h = \lceil \log_{m}{l} \rceil$.

**Tree traversal in binary tree**

- Preorder traversal (root, left, right): best choice for applications where internal vertices must be explored before leaves.
- Inorder traversal (left, root, right): best choice for applications where internal vertices must be explored in-order.
- Postorder traversal (left, right, root): best choice for applications where leaves need to be explored before internal vertices.

## Topics

### Dynamic programming

- Fibonacci number: [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/dynamic_programming)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/dynamic_programming)) | Fibonacci sequence is a sequence of numbers where each number is the sum of the two preceding numbers. Fibonacci number is $n$th number in the sequence. The Fibonacci sequence is defined as follows:
    - $F_0 = 0$
    - $F_1 = 1$
    - $F_n = F_{n-1} + F_{n-2}$ (for $n > 1$)
- Interval subset sum: [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/problem_solving)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/problem_solving))
- Longest common subsequence: [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/dynamic_programming)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/dynamic_programming))
- Rod cutting: [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/dynamic_programming)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/dynamic_programming)) | Rod cutting is a problem of cutting a rod into pieces of a given length to determine the maximum profit.

### Greedy

- Activity selection: [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/greedy)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/greedy)) | Activity selection problem using greedy algorithm or recursive approach. This is similar to the Interval scheduling problem.
- Cashier's change: [python](https://github.com/codejsha/algorithm-examples/tree/main/python-algorithm/algorithm/greedy)([test](https://github.com/codejsha/algorithm-examples/tree/main/python-algorithm/test/greedy)) | Cashier's change problem is that finds the minimum number of coins required to make change for a given amount of money.
- Huffman code: [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/greedy)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/greedy)) | Huffman code constructs optimal prefix codes. This is always represented by a full binary tree.
- Interval scheduling: [python](https://github.com/codejsha/algorithm-examples/tree/main/python-algorithm/algorithm/greedy)([test](https://github.com/codejsha/algorithm-examples/tree/main/python-algorithm/test/greedy)) | Interval scheduling problem is that finds the minimum number of intervals required to schedule a set of activities(lectures).

### Mathematics

- Base expansion (base $b$ expansion of $n$): [python](https://github.com/codejsha/algorithm-examples/tree/main/python-algorithm/algorithm/math)([test](https://github.com/codejsha/algorithm-examples/tree/main/python-algorithm/test/math)) | Constructing the base $b$ expansion of an integer $n$. Such as binary, octal, decimal, hexadecimal expansion, etc.
- Binary operation (addition): [python](https://github.com/codejsha/algorithm-examples/tree/main/python-algorithm/algorithm/math)([test](https://github.com/codejsha/algorithm-examples/tree/main/python-algorithm/test/math))
- Combination: [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/math)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/math)) | Find the number of ways to choose $k$ items from $n$ items.
- Greatest common divisor (GCD): [python](https://github.com/codejsha/algorithm-examples/tree/main/python-algorithm/algorithm/math)([test](https://github.com/codejsha/algorithm-examples/tree/main/python-algorithm/test/math)) | Find the greatest common divisor of two numbers.
- Least common multiple (LCM): [python](https://github.com/codejsha/algorithm-examples/tree/main/python-algorithm/algorithm/math)([test](https://github.com/codejsha/algorithm-examples/tree/main/python-algorithm/test/math)) | Find the least common multiple of two numbers.
- Matrix multiplication: [python](https://github.com/codejsha/algorithm-examples/tree/main/python-algorithm/algorithm/math)([test](https://github.com/codejsha/algorithm-examples/tree/main/python-algorithm/test/math)) | This is the product of two matrices.
- Miller-Rabin primality test: [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/math)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/math)) | Miller-Rabin primality test is a mathematical algorithm that finds whether a given number is prime.
- Permutation (Permutation): [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/math)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/math)) | Find the permutation of a set of items.
- Permutation (ApplyPermutationWithAdditionalSpace, ApplyPermutationBySwap): [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/math)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/math)) | Permute the elements of an array
- Permutation (InversePermutation): [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/math)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/math))
- Permutation (NextPermutation/PreviousPermutation): [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/math)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/math)) | Compute the next/previous permutation.
- Permutation (KthPermutation): [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/math)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/math)) | Compute the k-th permutation.

### Primitive type

```cpp
//// c++ definition/methods
std::to_string(42), std::swap(x, y)
std::numeric_limits<int>::min(), std::numeric_limits<float>::max(), std::numeric_limits<double>::infinity() // constants
std::abs(-34), std::fabs(-3.14), std::ceil(2.17), std::floor(3.14), std::min(x, -4), std::max(3.14, y), pow(2.17, 3.14), log(7.12), sqrt(225) // cmath
std::stoi("42"), std::stod("3.14"), std::stoi("42", nullptr, 16), std::stoi("1000010", nullptr, 2) // string -> int/double/hex/binary
std::bitset<8>(42), std::bitset<8>(3.14), std::bitset<8>(0x42), std::bitset<8>(0b1000010) // int/double/hex/binary -> bitset
std::uniform_int_distribution<int> distribution(1, 6), std::uniform_real_distribution<double> distribution(0.0, 1.0) // random

// random number
std::random_device rd;
std::mt19937 generator(rd());
// integer in [1, 10]
std::uniform_int_distribution distribution(1, 10);
const auto i = distribution(generator);
// floating point number in [0, 1)
const auto d = std::generate_canonical<double, 10>(generator);
```

- Arithmetic operation (Multiply/Divide): [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/primitive_type)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/primitive_type)) | Calculate the product/fraction of two numbers without using arithmetic operators.
- Computing parity of word (CountBits): [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/primitive_type)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/primitive_type)) | Count the number of bits that are set to 1.
- Computing parity of word (Parity): [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/primitive_type)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/primitive_type)) | Compute parity of word.
- Computing parity of word (ParityDropLowestBits): [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/primitive_type)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/primitive_type)) | Compute parity by dropping the lowest set bit.
- Computing parity of word (ParityLookupTable): [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/primitive_type)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/primitive_type)) | Compute parity by caching the results.
- Generate random number: [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/primitive_type) | Generate a random number in a range with equal probability.
- Integer palindrome: [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/primitive_type) | Check if a number is a palindrome.
- Power operation: [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/primitive_type)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/primitive_type)) | Compute repeated squaring $x^y$.
- Rectangle intersection: [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/primitive_type)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/primitive_type)) | Check if two rectangles intersect.
- Reverse digits: [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/primitive_type) | Reverse the digits of a given integer.
- Swap bit: [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/primitive_type)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/primitive_type)) | Swap the bits at indices $i$ and $j$.

### Search

```cpp
//// c++ definition/methods
auto map = std::map<std::string, int>{{"a", 1}, {"b", 2}};
insert({"c", 3}), emplace("d", 4), erase("a"), find("b"), size(), empty(), equal_range("c")

auto set = std::set{1, 2, 3, 4, 5};
insert(42), emplace(42), erase(42), find(42), size(), equal_range(3)
```

- Binary search: [python](https://github.com/codejsha/algorithm-examples/tree/main/python-algorithm/algorithm/search)([test](https://github.com/codejsha/algorithm-examples/tree/main/python-algorithm/test/search)) | Binary search is a search algorithm that finds the position of a target value within a sorted array.
- Linear search: [python](https://github.com/codejsha/algorithm-examples/tree/main/python-algorithm/algorithm/search)([test](https://github.com/codejsha/algorithm-examples/tree/main/python-algorithm/test/search)) | Linear search is a search algorithm that compares x successively with each term of the list until a match is found.

### Sort

```cpp
//// c++ definition/methods
std::ranges::sort(v);         // introsort (quick sort + heap sort + insertion sort)
std::ranges::stable_sort(v);  // merge sort
```

- Bubble sort

[java](https://github.com/codejsha/algorithm-examples/tree/main/java-algorithm/src/main/java/com/example/algorithm/sort)([test](https://github.com/codejsha/algorithm-examples/tree/main/java-algorithm/src/test/java/com/example/algorithm/sort))

| **Case**    | **Time complexity** | **Remarks**                   |
| :---------- | :-----------------: | :---------------------------- |
| **Best**    |       $O(n)$        | if the list is already sorted |
| **Worst**   |      $O(n^2)$       |                               |
| **Average** |      $O(n^2)$       |                               |

- Bucket sort

[java](https://github.com/codejsha/algorithm-examples/tree/main/java-algorithm/src/main/java/com/example/algorithm/sort)([test](https://github.com/codejsha/algorithm-examples/tree/main/java-algorithm/src/test/java/com/example/algorithm/sort))

| **Case**    | **Time complexity** | **Remarks** |
| ----------- | :-----------------: | ----------- |
| **Best**    |     $O(n + k)$      |             |
| **Worst**   |      $O(n^2)$       |             |
| **Average** |       $O(n)$        |             |

- Counting sort

[java](https://github.com/codejsha/algorithm-examples/tree/main/java-algorithm/src/main/java/com/example/algorithm/sort)([test](https://github.com/codejsha/algorithm-examples/tree/main/java-algorithm/src/test/java/com/example/algorithm/sort))

| **Case**    | **Time complexity** | **Remarks** |
| ----------- | :-----------------: | ----------- |
| **Best**    |     $O(n + k)$      |             |
| **Worst**   |     $O(n + k)$      |             |
| **Average** |     $O(n + k)$      |             |

- Heap sort

[java](https://github.com/codejsha/algorithm-examples/tree/main/java-algorithm/src/main/java/com/example/algorithm/sort)([test](https://github.com/codejsha/algorithm-examples/tree/main/java-algorithm/src/test/java/com/example/algorithm/sort))

| **Case**    | **Time complexity** | **Remarks** |
| ----------- | :-----------------: | ----------- |
| **Best**    |    $O(n log n)$     |             |
| **Worst**   |    $O(n log n)$     |             |
| **Average** |    $O(n log n)$     |             |

- Insertion sort

[c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/sort)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/sort)), [java](https://github.com/codejsha/algorithm-examples/tree/main/java-algorithm/src/main/java/com/example/algorithm/sort)([test](https://github.com/codejsha/algorithm-examples/tree/main/java-algorithm/src/test/java/com/example/algorithm/sort))

one of the fastest algorithms for sorting very small arrays (around 10 elements)

| **Case**    | **Time complexity** | **Remarks**                                                                        |
| ----------- | :-----------------: | ---------------------------------------------------------------------------------- |
| **Best**    |       $O(n)$        | * if the list is already sorted<br>* this case has linear running time             |
| **Worst**   |      $O(n^2)$       | * if the list is sorted in reverse order<br>* this case has quadratic running time |
| **Average** |      $O(n^2)$       | * this case has quadratic running time                                             |

- Merge sort

[java](https://github.com/codejsha/algorithm-examples/tree/main/java-algorithm/src/main/java/com/example/algorithm/sort)([test](https://github.com/codejsha/algorithm-examples/tree/main/java-algorithm/src/test/java/com/example/algorithm/sort))

divide and conquer algorithm

| **Case**    | **Time complexity** | **Remarks**                                                                                              |
| ----------- | :-----------------: | -------------------------------------------------------------------------------------------------------- |
| **Best**    |    $O(n log n)$     | * running time of sorting for input length $n$ is $T(n)$<br>* $T(n) = 2T(n/2) + O(n) \approx O(n log n)$ |
| **Worst**   |    $O(n log n)$     |                                                                                                          |
| **Average** |    $O(n log n)$     |                                                                                                          |

- Quick sort

[java](https://github.com/codejsha/algorithm-examples/tree/main/java-algorithm/src/main/java/com/example/algorithm/sort)([test](https://github.com/codejsha/algorithm-examples/tree/main/java-algorithm/src/test/java/com/example/algorithm/sort))

divide and conquer algorithm

| **Case**    | **Time complexity** | **Remarks** |
| ----------- | :-----------------: | ----------- |
| **Best**    |    $O(n log n)$     |             |
| **Worst**   |      $O(n^2)$       |             |
| **Average** |    $O(n log n)$     |             |

- Selection sort

[c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/sort)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/sort)), [java](https://github.com/codejsha/algorithm-examples/tree/main/java-algorithm/src/main/java/com/example/algorithm/sort)([test](https://github.com/codejsha/algorithm-examples/tree/main/java-algorithm/src/test/java/com/example/algorithm/sort))

| **Case**    | **Time complexity** | **Remarks**                                                                            |
| ----------- | :-----------------: | -------------------------------------------------------------------------------------- |
| **Best**    |      $O(n^2)$       | * if the list is already sorted                                                        |
| **Worst**   |      $O(n^2)$       | * when sorted in ascending order, if you want to sort in descending order (vice versa) |
| **Average** |      $O(n^2)$       |                                                                                        |

### String

```cpp
//// c++ definition/methods
auto str = std::string{"hello"};
append("_world"), push_back('!'), pop_back(), insert(5, "_world"), substr(0, 5), compare("hello_world")
```

- Convert string (IntToString, StringToInt): [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/string)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/string)) | Convert integer to string and vice versa.
- IP address validation: [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/string)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/string)) | Validate IPv4 address that is in the form of `x.x.x.x` where `x` is a number between 0 and 255.
- Look and say problem: [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/string)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/string))
- Naive string matching: [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/string)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/string)), [python](https://github.com/codejsha/algorithm-examples/tree/main/python-algorithm/algorithm/string)([test](https://github.com/codejsha/algorithm-examples/tree/main/python-algorithm/test/string)) | Find all occurrences of a pattern in a string.
- Palindrome: [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/string)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/string)) | Check if a string is palindromic.
- Print sine wave pattern string (SineWaveString and PrintSineWaveString): [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/string)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/string)) | Print a string in sine wave pattern.
- Rabin-Karp algorithm: [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/string)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/string)) | Use the hash function to find all occurrences of a pattern in a string. It has $\theta(\text{pattern-size})$ preprocessing time and $\theta((\text{text-size} - \text{pattern-size} + 1) \text{pattern-size})$ time complexity.
- Roman number (VerifyRomanString): [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/string)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/string)) | Verify if a string is a valid roman number.
- Roman number (RomanStringToInteger): [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/string)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/string)) | Convert a roman number to integer.
- Run-length encoding (RLE): [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/string)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/string)) | Run-length encoding is a simple form of data compression in which runs of data are stored as a single data value and count.
- Spreadsheet column decoding/encoding (DecodingSheetColumnId/EncodingSheetColumnId): [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/string) | Convert a spreadsheet column id to integer and vice versa.

## References

- Introduction to Algorithms, 3rd Edition, by CLRS
- Discrete Mathematics and Its Applications, 8th Edition, by Kenneth H. Rosen
- Cracking the Coding Interview, 6th Edition, by Gayle Laakmann McDowell
- Elements of Programming Interviews, 2nd Edition, by Adnan Aziz, Tsung-Hsien Lee and Amit Prakash
