# Algorithm Examples

![C++ CI with CMake](https://github.com/codejsha/algorithm-examples/actions/workflows/cmake.yml/badge.svg) ![Python CI](https://github.com/codejsha/algorithm-examples/actions/workflows/python.yml/badge.svg)

[Korean](README_ko-KR.md)

This repository is an implementation of algorithms, data structures, and problem solving. These are written in C++, Python, and Java, and each language uses the following test framework: [Google Test](https://google.github.io/googletest/)(C++), [pytest](https://docs.pytest.org/)(Python), [JUnit](https://junit.org/)(Java). Run a test to perform the method/function for algorithm logic. GitHub Actions workflows that build and test code run daily at 00:00 UTC.

Additionally, each project is configured in the following environments:

- C++ project: based on [CMake](https://cmake.org/) project and uses [GNU Scientific Library (GSL)](https://www.gnu.org/software/gsl/), [Google Test](https://google.github.io/googletest/) packages (package manager [vcpkg](https://github.com/microsoft/vcpkg))
- Python project: uses [NumPy](https://numpy.org/), [SciPy](https://www.scipy.org/), [pytest](https://docs.pytest.org/) packages
- Java project: based on [Gradle](https://gradle.org/) project and uses [JUnit](https://junit.org/), [Java Microbenchmark Harness (JMH)](https://github.com/openjdk/jmh) libraries

## Table of Contents

- [Table of Contents](#table-of-contents)
- [Data structures](#data-structures)
  - [Array](#array)
  - [Graph](#graph)
  - [Linked list](#linked-list)
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

### Linked list

- Delete a node from linked list (DeleteNodeFromList): [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/linked_list)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/linked_list)) | Delete a node from a linked list.
- Delete duplicate nodes from sorted linked list (DeleteDuplicateNode): [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/linked_list)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/linked_list)) | Delete duplicate nodes from a sorted linked list.
- Delete the k-th last node from linked list (DeleteNodeKthLast): [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/linked_list)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/linked_list)) | Delete the k-th last node from a linked list.
- Implement cyclic right shift for a singly linked list (CyclicallyRightShiftList): [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/linked_list)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/linked_list)) | Implement cyclic right shift for a singly linked list.
- Linked list has a cycle (HasCycle1, HasCycle2, HasCycle3): [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/linked_list)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/linked_list)) | Determine that a linked list has a cycle.
- Merge two sorted linked lists: [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/linked_list)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/linked_list)) | Merge two sorted linked lists. In worst-case, this task has $O(n + m)$ time complexity, where $n$ and $m$ are the length of the lists.
- Reverse a single sublist: [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/linked_list)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/linked_list)) | Reverse a single sublist of a linked list.
- Two linked lists overlap (OverlappingNoCycleList): [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/linked_list)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/linked_list)) | Determine that two linked lists without cycle overlap.
- Two linked lists with cycles overlap (OverlappingCycleList) [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/linked_list)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/linked_list)) | Determine that two linked lists with cycle overlap.

### Tree

- B-tree: [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/tree)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/tree)) | B-tree is a self-balancing data structure which can have many child nodes. It is commonly used in auxiliary storage devices and database system. B-tree has the following properties: 1) Nodes have lower and upper bounds on the number of keys they can contain. (represent using degree $t$) 2) Every node other than the root must have at least $t-1$ keys. 3) Every node may contain at most $2t-1$ keys.
- Binary search tree: [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/tree)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/tree)) | In binary search tree, all internal nodes are stored in ordered state. If y is a child of x and y is a node in the left subtree, then $y.key \leq x.key$, and if y is a node in the right subtree, then $y.key \geq x.key$.

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

- Binary search: [python](https://github.com/codejsha/algorithm-examples/tree/main/python-algorithm/algorithm/search)([test](https://github.com/codejsha/algorithm-examples/tree/main/python-algorithm/test/search)) | Binary search is a search algorithm that finds the position of a target value within a sorted array.
- Linear search: [python](https://github.com/codejsha/algorithm-examples/tree/main/python-algorithm/algorithm/search)([test](https://github.com/codejsha/algorithm-examples/tree/main/python-algorithm/test/search)) | Linear search is a search algorithm that compares x successively with each term of the list until a match is found.

### Sort

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
| **Best**    |    $O(n log n)$     | * running time of sorting for input length $n$ is $T(n)$<br>* $T(n) = 2T(n/2) + O(n) \approx	O(n log n)$ |
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
