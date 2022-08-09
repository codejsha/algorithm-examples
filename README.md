# Algorithm Examples

- [Algorithm Examples](#algorithm-examples)
  - [Introduction](#introduction)
  - [Data structures](#data-structures)
    - [Tree](#tree)
  - [Topics](#topics)
    - [Dynamic programming](#dynamic-programming)
    - [Greedy](#greedy)
    - [Mathematics](#mathematics)
    - [Search](#search)
    - [Sort](#sort)
    - [String](#string)
  - [Problem solving](#problem-solving)
  - [References](#references)

## Introduction

This repository is an implementation of algorithms, data structures, and problem solving. These are written in C++, Python, and Java, and each language uses the following test framework: [Google Test](https://google.github.io/googletest/)(C++), [pytest](https://docs.pytest.org/)(Python), [JUnit](https://junit.org/)(Java).

Additionally, each project is configured in the following environments:

- C++ project: based on [CMake](https://cmake.org/) project and uses [GNU Scientific Library (GSL)](https://www.gnu.org/software/gsl/)
- Python project: uses [NumPy](https://numpy.org/) and [SciPy](https://www.scipy.org/)
- Java project: based on [Spring Boot](https://spring.io/projects/spring-boot) project and uses [Java Microbenchmark Harness (JMH)](https://github.com/openjdk/jmh)

## Data structures

### Tree

- B-tree: [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/tree)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/tree)) | The B-tree is a self-balancing data structure which can have many child nodes. It is commonly used in auxiliary storage devices and database system. B-tree has the following properties: 1) Nodes have lower and upper bounds on the number of keys they can contain. (represent using degree $t$) 2) Every node other than the root must have at least $t-1$ keys. 3) Every node may contain at most $2t-1$ keys.
- Binary search tree: [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/tree)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/tree)) | In binary search tree, all internal nodes are stored in ordered state. If y is a child of x and y is a node in the left subtree, then $y.key \leq x.key$, and if y is a node in the right subtree, then $y.key \geq x.key$.

## Topics

### Dynamic programming

- Fibonacci number: [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/dynamic_programming)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/dynamic_programming))
- Longest common subsequence: [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/dynamic_programming)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/dynamic_programming))
- Rod cutting: [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/dynamic_programming)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/dynamic_programming))

### Greedy

- Activity selection: [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/greedy)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/greedy)) | Activity selection problem using greedy algorithm or recursive approach. This is similar to the Interval scheduling problem.
- Cashier's change: [python](https://github.com/codejsha/algorithm-examples/tree/main/python-algorithm/algorithm/greedy)([test](https://github.com/codejsha/algorithm-examples/tree/main/python-algorithm/test/greedy))
- Huffman code: [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/greedy)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/greedy)) | Huffman code constructs optimal prefix codes. This is always represented by a full binary tree.
- Interval scheduling: [python](https://github.com/codejsha/algorithm-examples/tree/main/python-algorithm/algorithm/greedy)([test](https://github.com/codejsha/algorithm-examples/tree/main/python-algorithm/test/greedy))

### Mathematics

- Base expansion (base b expansion of n): [python](https://github.com/codejsha/algorithm-examples/tree/main/python-algorithm/algorithm/math)([test](https://github.com/codejsha/algorithm-examples/tree/main/python-algorithm/test/math))
- Binary operation (addition): [python](https://github.com/codejsha/algorithm-examples/tree/main/python-algorithm/algorithm/math)([test](https://github.com/codejsha/algorithm-examples/tree/main/python-algorithm/test/math))
- Combination: [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/math)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/math))
- Matrix multiplication: [python](https://github.com/codejsha/algorithm-examples/tree/main/python-algorithm/algorithm/math)([test](https://github.com/codejsha/algorithm-examples/tree/main/python-algorithm/test/math))
- Numbers (GCD, LCM): [python](https://github.com/codejsha/algorithm-examples/tree/main/python-algorithm/algorithm/math)([test](https://github.com/codejsha/algorithm-examples/tree/main/python-algorithm/test/math))
- Permutation: [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/math)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/math))

### Search

- Binary search: [python](https://github.com/codejsha/algorithm-examples/tree/main/python-algorithm/algorithm/search)([test](https://github.com/codejsha/algorithm-examples/tree/main/python-algorithm/test/search))
- Linear search: [python](https://github.com/codejsha/algorithm-examples/tree/main/python-algorithm/algorithm/search)([test](https://github.com/codejsha/algorithm-examples/tree/main/python-algorithm/test/search))

### Sort

- **Bubble sort**

[java](https://github.com/codejsha/algorithm-examples/tree/main/java-algorithm/src/main/java/com/example/demo/sort)([test](https://github.com/codejsha/algorithm-examples/tree/main/java-algorithm/src/test/java/com/example/demo/sort))

| **Case**    | **Time complexity** | **Remarks**                   |
| :---------- | :-----------------: | :---------------------------- |
| **Best**    |       $O(n)$        | if the list is already sorted |
| **Worst**   |      $O(n^2)$       |                               |
| **Average** |      $O(n^2)$       |                               |

- **Bucket sort**

[java](https://github.com/codejsha/algorithm-examples/tree/main/java-algorithm/src/main/java/com/example/demo/sort)([test](https://github.com/codejsha/algorithm-examples/tree/main/java-algorithm/src/test/java/com/example/demo/sort))

| **Case**    | **Time complexity** | **Remarks** |
| ----------- | :-----------------: | ----------- |
| **Best**    |     $O(n + k)$      |             |
| **Worst**   |      $O(n^2)$       |             |
| **Average** |       $O(n)$        |             |

- **Counting sort**

[java](https://github.com/codejsha/algorithm-examples/tree/main/java-algorithm/src/main/java/com/example/demo/sort)([test](https://github.com/codejsha/algorithm-examples/tree/main/java-algorithm/src/test/java/com/example/demo/sort))

| **Case**    | **Time complexity** | **Remarks** |
| ----------- | :-----------------: | ----------- |
| **Best**    |     $O(n + k)$      |             |
| **Worst**   |     $O(n + k)$      |             |
| **Average** |     $O(n + k)$      |             |

- **Heap sort**

[java](https://github.com/codejsha/algorithm-examples/tree/main/java-algorithm/src/main/java/com/example/demo/sort)([test](https://github.com/codejsha/algorithm-examples/tree/main/java-algorithm/src/test/java/com/example/demo/sort))

| **Case**    | **Time complexity** | **Remarks** |
| ----------- | :-----------------: | ----------- |
| **Best**    |    $O(n log n)$     |             |
| **Worst**   |    $O(n log n)$     |             |
| **Average** |    $O(n log n)$     |             |

- **Insertion sort**

[c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/sort)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/sort)), [java](https://github.com/codejsha/algorithm-examples/tree/main/java-algorithm/src/main/java/com/example/demo/sort)([test](https://github.com/codejsha/algorithm-examples/tree/main/java-algorithm/src/test/java/com/example/demo/sort))

one of the fastest algorithms for sorting very small arrays (around 10 elements)

| **Case**    | **Time complexity** | **Remarks**                                                                        |
| ----------- | :-----------------: | ---------------------------------------------------------------------------------- |
| **Best**    |       $O(n)$        | * if the list is already sorted<br>* this case has linear running time             |
| **Worst**   |      $O(n^2)$       | * if the list is sorted in reverse order<br>* this case has quadratic running time |
| **Average** |      $O(n^2)$       | * this case has quadratic running time                                             |

- **Merge sort**

[java](https://github.com/codejsha/algorithm-examples/tree/main/java-algorithm/src/main/java/com/example/demo/sort)([test](https://github.com/codejsha/algorithm-examples/tree/main/java-algorithm/src/test/java/com/example/demo/sort))

divide and conquer algorithm

| **Case**    | **Time complexity** | **Remarks**                                                                                              |
| ----------- | :-----------------: | -------------------------------------------------------------------------------------------------------- |
| **Best**    |    $O(n log n)$     | * running time of sorting for input length $n$ is $T(n)$<br>* $T(n) = 2T(n/2) + O(n) \approx	O(n log n)$ |
| **Worst**   |    $O(n log n)$     |                                                                                                          |
| **Average** |    $O(n log n)$     |                                                                                                          |

- **Quick sort**

[java](https://github.com/codejsha/algorithm-examples/tree/main/java-algorithm/src/main/java/com/example/demo/sort)([test](https://github.com/codejsha/algorithm-examples/tree/main/java-algorithm/src/test/java/com/example/demo/sort))

divide and conquer algorithm

| **Case**    | **Time complexity** | **Remarks** |
| ----------- | :-----------------: | ----------- |
| **Best**    |    $O(n log n)$     |             |
| **Worst**   |      $O(n^2)$       |             |
| **Average** |    $O(n log n)$     |             |

- **Selection sort**

[c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/sort)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/sort)), [java](https://github.com/codejsha/algorithm-examples/tree/main/java-algorithm/src/main/java/com/example/demo/sort)([test](https://github.com/codejsha/algorithm-examples/tree/main/java-algorithm/src/test/java/com/example/demo/sort))

| **Case**    | **Time complexity** | **Remarks**                                                                            |
| ----------- | :-----------------: | -------------------------------------------------------------------------------------- |
| **Best**    |      $O(n^2)$       | * if the list is already sorted                                                        |
| **Worst**   |      $O(n^2)$       | * when sorted in ascending order, if you want to sort in descending order (vice versa) |
| **Average** |      $O(n^2)$       |                                                                                        |

### String

- Naive string search: [python](https://github.com/codejsha/algorithm-examples/tree/main/python-algorithm/algorithm/string)([test](https://github.com/codejsha/algorithm-examples/tree/main/python-algorithm/test/string))

## Problem solving

- Interval subset sum: [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/problem)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/problem))

## References

- Introduction to Algorithms, 3rd Edition, by CLRS
- Discrete Mathematics and Its Applications, 8th Edition, by Kenneth H. Rosen
- Cracking the Coding Interview, 6th Edition, by Gayle Laakmann McDowell
- Elements of Programming Interviews, 2nd Edition, by Adnan Aziz, Tsung-Hsien Lee and Amit Prakash
