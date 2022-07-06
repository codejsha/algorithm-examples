# Algorithm Examples

- [Algorithm Examples](#algorithm-examples)
  - [Sort](#sort)
    - [Bubble Sort](#bubble-sort)
    - [Bucket Sort](#bucket-sort)
    - [Counting Sort](#counting-sort)
    - [Heap Sort](#heap-sort)
    - [Insertion Sort](#insertion-sort)
    - [Merge Sort](#merge-sort)
    - [Quick Sort](#quick-sort)
    - [Selection Sort](#selection-sort)
  - [References](#references)

## Topics

## Sort

Code: [java](https://github.com/codejsha/algorithm-examples/tree/main/java-algorithms/src/main/java/com/example/demo/sort)([test](https://github.com/codejsha/algorithm-examples/tree/main/java-algorithms/src/test/java/com/example/demo/sort))

### Bubble Sort

- Best case: O(n)
  - if the list is already sorted
- Worst case: $O(n^2)$
- Average case: $O(n^2)$

### Bucket Sort

- Best case: $O(n + k)$
- Worst case: $O(n^2)$
- Average case: $O(n)$

### Counting Sort

- Best case: $O(n + k)$
- Worst case: $O(n + k)$
- Average case: $O(n + k)$

### Heap Sort

- Best case: $O(n log n)$
- Worst case: $O(n log n)$
- Average case: $O(n log n)$

### Insertion Sort

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

### Merge Sort

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

### Quick Sort

- Best case: $O(n log n)$
- Worst case: $O(n^2)$
- Average case: $O(n log n)$
- Features
  - devide and conquer algorithm

### Selection Sort

- Best case: $O(n^2)$
  - if the list is already sorted
- Worst case: $O(n^2)$
  - when sorted in ascending order, if you want to sort in descending order (vice versa)
- Average case: $O(n^2)$

## References

- Introduction to Algorithms, 3rd Edition, by CLRS
- Wikipedia
  - https://en.wikipedia.org/wiki/Bubble_sort
  - https://en.wikipedia.org/wiki/Counting_sort
  - https://en.wikipedia.org/wiki/Heapsort
  - https://en.wikipedia.org/wiki/Insertion_sort
  - https://en.wikipedia.org/wiki/Merge_sort
  - https://en.wikipedia.org/wiki/Quicksort
  - https://en.wikipedia.org/wiki/Selection_sort
