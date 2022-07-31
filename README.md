# Algorithm Examples

- [Algorithm Examples](#algorithm-examples)
  - [Greedy](#greedy)
  - [Math](#math)
  - [Search](#search)
  - [Sort](#sort)
  - [String](#string)
  - [Tree](#tree)
  - [Problem solving](#problem-solving)
  - [Others](#others)
  - [References](#references)

## Greedy

- Cashier's Change: [python](https://github.com/codejsha/algorithm-examples/tree/main/python-algorithm/algorithm/greedy)([test](https://github.com/codejsha/algorithm-examples/tree/main/python-algorithm/test/greedy))
- Interval scheduling: [python](https://github.com/codejsha/algorithm-examples/tree/main/python-algorithm/algorithm/greedy)([test](https://github.com/codejsha/algorithm-examples/tree/main/python-algorithm/test/greedy))

## Math

- Combination: [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/math)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/math))
- Fibonacci number: [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/math)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/math))

## Search

- Binary search: [python](https://github.com/codejsha/algorithm-examples/tree/main/python-algorithm/algorithm/search)([test](https://github.com/codejsha/algorithm-examples/tree/main/python-algorithm/test/search))
- Linear search: [python](https://github.com/codejsha/algorithm-examples/tree/main/python-algorithm/algorithm/search)([test](https://github.com/codejsha/algorithm-examples/tree/main/python-algorithm/test/search))

## Sort

**Bubble Sort**

[java](https://github.com/codejsha/algorithm-examples/tree/main/java-algorithm/src/main/java/com/example/demo/sort)([test](https://github.com/codejsha/algorithm-examples/tree/main/java-algorithm/src/test/java/com/example/demo/sort))

| **Case**    | **Time Complexity** | **Remarks**                   |
| :---------- | :-----------------: | :---------------------------- |
| **Best**    |       $O(n)$        | if the list is already sorted |
| **Worst**   |      $O(n^2)$       |                               |
| **Average** |      $O(n^2)$       |                               |

**Bucket Sort**

[java](https://github.com/codejsha/algorithm-examples/tree/main/java-algorithm/src/main/java/com/example/demo/sort)([test](https://github.com/codejsha/algorithm-examples/tree/main/java-algorithm/src/test/java/com/example/demo/sort))

| **Case**    | **Time Complexity** | **Remarks** |
| ----------- | :-----------------: | ----------- |
| **Best**    |     $O(n + k)$      |             |
| **Worst**   |      $O(n^2)$       |             |
| **Average** |       $O(n)$        |             |

**Counting Sort**

[java](https://github.com/codejsha/algorithm-examples/tree/main/java-algorithm/src/main/java/com/example/demo/sort)([test](https://github.com/codejsha/algorithm-examples/tree/main/java-algorithm/src/test/java/com/example/demo/sort))

| **Case**    | **Time Complexity** | **Remarks** |
| ----------- | :-----------------: | ----------- |
| **Best**    |     $O(n + k)$      |             |
| **Worst**   |     $O(n + k)$      |             |
| **Average** |     $O(n + k)$      |             |

**Heap Sort**

[java](https://github.com/codejsha/algorithm-examples/tree/main/java-algorithm/src/main/java/com/example/demo/sort)([test](https://github.com/codejsha/algorithm-examples/tree/main/java-algorithm/src/test/java/com/example/demo/sort))

| **Case**    | **Time Complexity** | **Remarks** |
| ----------- | :-----------------: | ----------- |
| **Best**    |    $O(n log n)$     |             |
| **Worst**   |    $O(n log n)$     |             |
| **Average** |    $O(n log n)$     |             |

**Insertion Sort**

[c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/sort)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/sort)), [java](https://github.com/codejsha/algorithm-examples/tree/main/java-algorithm/src/main/java/com/example/demo/sort)([test](https://github.com/codejsha/algorithm-examples/tree/main/java-algorithm/src/test/java/com/example/demo/sort))

one of the fastest algorithms for sorting very small arrays (around 10 elements)

| **Case**    | **Time Complexity** | **Remarks**                                                                        |
| ----------- | :-----------------: | ---------------------------------------------------------------------------------- |
| **Best**    |       $O(n)$        | * if the list is already sorted<br>* this case has linear running time             |
| **Worst**   |      $O(n^2)$       | * if the list is sorted in reverse order<br>* this case has quadratic running time |
| **Average** |      $O(n^2)$       | * this case has quadratic running time                                             |

**Merge Sort**

[java](https://github.com/codejsha/algorithm-examples/tree/main/java-algorithm/src/main/java/com/example/demo/sort)([test](https://github.com/codejsha/algorithm-examples/tree/main/java-algorithm/src/test/java/com/example/demo/sort))

divide and conquer algorithm

| **Case**    | **Time Complexity** | **Remarks**                                                                                              |
| ----------- | :-----------------: | -------------------------------------------------------------------------------------------------------- |
| **Best**    |    $O(n log n)$     | * running time of sorting for input length $n$ is $T(n)$<br>* $T(n) = 2T(n/2) + O(n) \approx	O(n log n)$ |
| **Worst**   |    $O(n log n)$     |                                                                                                          |
| **Average** |    $O(n log n)$     |                                                                                                          |

**Quick Sort**

[java](https://github.com/codejsha/algorithm-examples/tree/main/java-algorithm/src/main/java/com/example/demo/sort)([test](https://github.com/codejsha/algorithm-examples/tree/main/java-algorithm/src/test/java/com/example/demo/sort))

divide and conquer algorithm

| **Case**    | **Time Complexity** | **Remarks** |
| ----------- | :-----------------: | ----------- |
| **Best**    |    $O(n log n)$     |             |
| **Worst**   |      $O(n^2)$       |             |
| **Average** |    $O(n log n)$     |             |

**Selection Sort**

[c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/sort)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/sort)), [java](https://github.com/codejsha/algorithm-examples/tree/main/java-algorithm/src/main/java/com/example/demo/sort)([test](https://github.com/codejsha/algorithm-examples/tree/main/java-algorithm/src/test/java/com/example/demo/sort))

| **Case**    | **Time Complexity** | **Remarks**                                                                            |
| ----------- | :-----------------: | -------------------------------------------------------------------------------------- |
| **Best**    |      $O(n^2)$       | * if the list is already sorted                                                        |
| **Worst**   |      $O(n^2)$       | * when sorted in ascending order, if you want to sort in descending order (vice versa) |
| **Average** |      $O(n^2)$       |                                                                                        |

## String

- Naive string search: [python](https://github.com/codejsha/algorithm-examples/tree/main/python-algorithm/algorithm/string)([test](https://github.com/codejsha/algorithm-examples/tree/main/python-algorithm/test/string))

## Tree

- Binary search tree: [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/tree)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/tree))

## Problem solving

- Interval subset sum: [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/problem)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/problem))

## Others

- Base expansion (base b expansion of n): [python](https://github.com/codejsha/algorithm-examples/tree/main/python-algorithm/algorithm/math)([test](https://github.com/codejsha/algorithm-examples/tree/main/python-algorithm/test/math))
- Binary operation (addition): [python](https://github.com/codejsha/algorithm-examples/tree/main/python-algorithm/algorithm/math)([test](https://github.com/codejsha/algorithm-examples/tree/main/python-algorithm/test/math))
- Matrix multiplication: [python](https://github.com/codejsha/algorithm-examples/tree/main/python-algorithm/algorithm/matrix)([test](https://github.com/codejsha/algorithm-examples/tree/main/python-algorithm/test/matrix))
- Numbers (GCD, LCM): [python](https://github.com/codejsha/algorithm-examples/tree/main/python-algorithm/algorithm/math)([test](https://github.com/codejsha/algorithm-examples/tree/main/python-algorithm/test/math))

## References

- Introduction to Algorithms, 3rd Edition, by CLRS
- Discrete Mathematics and Its Applications, 8th Edition, by Kenneth H. Rosen
- Cracking the Coding Interview, 6th Edition, by Gayle Laakmann McDowell
- [Bubble sort - Wikipedia](https://en.wikipedia.org/wiki/Bubble_sort)
- [Counting sort - Wikipedia](https://en.wikipedia.org/wiki/Counting_sort)
- [Heapsort - Wikipedia](https://en.wikipedia.org/wiki/Heapsort)
- [Insertion sort - Wikipedia](https://en.wikipedia.org/wiki/Insertion_sort)
- [Merge sort - Wikipedia](https://en.wikipedia.org/wiki/Merge_sort)
- [Quicksort - Wikipedia](https://en.wikipedia.org/wiki/Quicksort)
- [Selection sort - Wikipedia](https://en.wikipedia.org/wiki/Selection_sort)
