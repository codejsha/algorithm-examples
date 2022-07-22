# Algorithm Examples

- [Algorithm Examples](#algorithm-examples)
  - [Search](#search)
  - [Sort](#sort)
  - [Tree](#tree)
  - [Problem solving](#problem-solving)
  - [References](#references)

## Search

- Binary search: [python](https://github.com/codejsha/algorithm-examples/tree/main/python-algorithm/algorithm/search)([test](https://github.com/codejsha/algorithm-examples/tree/main/python-algorithm/test/search))
- Linear search: [python](https://github.com/codejsha/algorithm-examples/tree/main/python-algorithm/algorithm/search)([test](https://github.com/codejsha/algorithm-examples/tree/main/python-algorithm/test/search))

## Sort

- Bubble Sort
- Bucket Sort
- Counting Sort
- Heap Sort
- Insertion Sort
- Merge Sort
- Quick Sort
- Selection Sort

**Bubble Sort**

- Code: [java](https://github.com/codejsha/algorithm-examples/tree/main/java-algorithm/src/main/java/com/example/demo/sort)([test](https://github.com/codejsha/algorithm-examples/tree/main/java-algorithm/src/test/java/com/example/demo/sort))
- Best case: O(n)
  - if the list is already sorted
- Worst case: $O(n^2)$
- Average case: $O(n^2)$

**Bucket Sort**

- Code: [java](https://github.com/codejsha/algorithm-examples/tree/main/java-algorithm/src/main/java/com/example/demo/sort)([test](https://github.com/codejsha/algorithm-examples/tree/main/java-algorithm/src/test/java/com/example/demo/sort))
- Best case: $O(n + k)$
- Worst case: $O(n^2)$
- Average case: $O(n)$

**Counting Sort**

- Code: [java](https://github.com/codejsha/algorithm-examples/tree/main/java-algorithm/src/main/java/com/example/demo/sort)([test](https://github.com/codejsha/algorithm-examples/tree/main/java-algorithm/src/test/java/com/example/demo/sort))
- Best case: $O(n + k)$
- Worst case: $O(n + k)$
- Average case: $O(n + k)$

**Heap Sort**

- Code: [java](https://github.com/codejsha/algorithm-examples/tree/main/java-algorithm/src/main/java/com/example/demo/sort)([test](https://github.com/codejsha/algorithm-examples/tree/main/java-algorithm/src/test/java/com/example/demo/sort))
- Best case: $O(n log n)$
- Worst case: $O(n log n)$
- Average case: $O(n log n)$

**Insertion Sort**

- Code: [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/sort)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/sort)), [java](https://github.com/codejsha/algorithm-examples/tree/main/java-algorithm/src/main/java/com/example/demo/sort)([test](https://github.com/codejsha/algorithm-examples/tree/main/java-algorithm/src/test/java/com/example/demo/sort))
- Best case: $O(n)$
  - if the list is already sorted
  - this case has linear running time
- Worst case: $O(n^2)$
  - if the list is sorted in reverse order
  - this case has quadratic running time
- Average case: $O(n^2)$
  - this case has quadratic running time
- Features
  - one of the fastest algorithms for sorting very small arrays (around 10 elements)

**Merge Sort**

- Code: [java](https://github.com/codejsha/algorithm-examples/tree/main/java-algorithm/src/main/java/com/example/demo/sort)([test](https://github.com/codejsha/algorithm-examples/tree/main/java-algorithm/src/test/java/com/example/demo/sort))
- Best case: $O(n log n)$
  - running time of sorting for input length $n$ is $T(n)$

$$
\begin{align*}
T(n) &= 2T(n/2) + O(n) \\
     &=> O(n log n)
\end{align*}
$$

- Worst case: $O(n log n)$
- Average case: $O(n log n)$
- Features
  - divide and conquer algorithm

**Quick Sort**

- Code: [java](https://github.com/codejsha/algorithm-examples/tree/main/java-algorithm/src/main/java/com/example/demo/sort)([test](https://github.com/codejsha/algorithm-examples/tree/main/java-algorithm/src/test/java/com/example/demo/sort))
- Best case: $O(n log n)$
- Worst case: $O(n^2)$
- Average case: $O(n log n)$
- Features
  - divide and conquer algorithm

**Selection Sort**

- Code: [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/sort)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/sort)), [java](https://github.com/codejsha/algorithm-examples/tree/main/java-algorithm/src/main/java/com/example/demo/sort)([test](https://github.com/codejsha/algorithm-examples/tree/main/java-algorithm/src/test/java/com/example/demo/sort))
- Best case: $O(n^2)$
  - if the list is already sorted
- Worst case: $O(n^2)$
  - when sorted in ascending order, if you want to sort in descending order (vice versa)
- Average case: $O(n^2)$

## Tree

- Binary search tree: [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/tree)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/tree))

## Problem solving

- Interval subset sum: [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/problem)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/problem))
- Combination: [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/problem)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/problem))

## References

- Introduction to Algorithms, 3rd Edition, by CLRS
- Discrete Mathematics and Its Applications, 8th Edition, by Kenneth H. Rosen
- 프로그래밍 대회에서 배우는 알고리즘 문제 해결 전략 by 구종만 (Algorithmic Problem Solving Strategies)
- [Bubble sort - Wikipedia](https://en.wikipedia.org/wiki/Bubble_sort)
- [Counting sort - Wikipedia](https://en.wikipedia.org/wiki/Counting_sort)
- [Heapsort - Wikipedia](https://en.wikipedia.org/wiki/Heapsort)
- [Insertion sort - Wikipedia](https://en.wikipedia.org/wiki/Insertion_sort)
- [Merge sort - Wikipedia](https://en.wikipedia.org/wiki/Merge_sort)
- [Quicksort - Wikipedia](https://en.wikipedia.org/wiki/Quicksort)
- [Selection sort - Wikipedia](https://en.wikipedia.org/wiki/Selection_sort)
