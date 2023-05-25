# Algorithm Examples

![C++ CMake Build](https://github.com/codejsha/algorithm-examples/actions/workflows/cmake.yml/badge.svg) ![Python Build](https://github.com/codejsha/algorithm-examples/actions/workflows/python.yml/badge.svg) ![Java Gradle Build](https://github.com/codejsha/algorithm-examples/actions/workflows/gradle.yml/badge.svg)

[English](README.md) | [Korean](README_ko-KR.md)

This repository is an implementation of algorithms, data structures, and problem solving. These are written in C++, Python, and Java, and each language uses the following test framework: [Google Test](https://google.github.io/googletest/)(C++), [pytest](https://docs.pytest.org/)(Python), [JUnit](https://junit.org/)(Java). Run tests to perform methods/functions on the algorithmic logic. GitHub Actions workflows that build and test code run manually.

## Project Environments

Each project is configured in specific environments, as described below:

- C++ project: C++20 / [CMake](https://cmake.org/) build / [GNU Scientific Library (GSL)](https://www.gnu.org/software/gsl/), [Google Test](https://google.github.io/googletest/), [Google Benchmark](https://github.com/google/benchmark), [fmt](https://github.com/fmtlib/fmt) packages / [vcpkg](https://github.com/microsoft/vcpkg) package manager
- Python project: Python 3.11 / [NumPy](https://numpy.org/), [SciPy](https://www.scipy.org/), [pytest](https://docs.pytest.org/), [pytest-benchmark](https://pytest-benchmark.readthedocs.io/en/latest/) packages / [pip](https://pip.pypa.io/en/stable/) package manager
- Java project: Java 17 / [Gradle](https://gradle.org/) build / [JUnit](https://junit.org/), [Java Microbenchmark Harness (JMH)](https://github.com/openjdk/jmh) libraries

## Table of Contents

- [Data structures](#data-structures)
  - [:train: Array](#train-array)
  - [:chart\_with\_upwards\_trend: Graph](#chart_with_upwards_trend-graph)
  - [:key: Hash table](#key-hash-table)
  - [:rocket: Heap](#rocket-heap)
  - [:paperclips: Linked list](#paperclips-linked-list)
  - [:walking: Queue](#walking-queue)
  - [:hamburger: Stack](#hamburger-stack)
  - [:deciduous\_tree: Tree](#deciduous_tree-tree)
- [Topics](#topics)
  - [:jigsaw: Dynamic programming](#jigsaw-dynamic-programming)
  - [:clock9: Greedy](#clock9-greedy)
  - [:triangular\_ruler: Mathematics](#triangular_ruler-mathematics)
  - [:1234: Primitive type](#1234-primitive-type)
  - [:mag: Search](#mag-search)
  - [:abc: Sort](#abc-sort)
  - [:page\_facing\_up: String](#page_facing_up-string)
- [References](#references)

## Data structures

### :train: Array

**C++ declaration/methods**

```cpp
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
std::ranges::reverse(v)
std::ranges::rotate(v, v.end() - k)
std::ranges::sort(v)
std::ranges::min_element(v)
std::ranges::max_element(v)
std::ranges::minmax_element(v)
```

**Python declaration/functions**

```python
# list
number_list: list[int] = [1, 2, 3, 4, 5]
append(6), insert(3, 3), remove(4), pop(), pop(0), index(3), count(3), clear(), extend([6, 7, 8])
number_list.reverse()   # in-place
reversed(number_list)   # return an iterator
number_list.sort()      # in-place
sorted(number_list)     # return a new list(copy)
del(number_list[0])     # delete the first element
del(number_list[0:2])   # removes the slice
bisect.bisect_left(number_list, 3), bisect.bisect_right(number_list, 3), bisect.bisect(number_list, 3)
bisect.insort_left(number_list, 3), bisect.insort_right(number_list, 3), bisect.insort(number_list, 3)

# tuple
sample_tuple: tuple[int] = (1, 2, 3, 4, 5)
index(3), count(3)

### list comprehension
# single level of loop
even_list = [x for x in number_list if x % 2 == 0]
# two levels of loop
sample_list = [[1, 2, 3], [4, 5, 6]]
square_list = [[n ** 2 for n in row] for row in sample_list]
# multi levels of loop
list_a: list[int] = [1, 3, 5]
list_b: list[str] = ['a', 'b']
set_ab: set[tuple[int, str]] = {(a, b) for a in list_a for b in list_b}
# 2d array to 1d array
list_2d = [['a', 'b', 'c'], ['d', 'e', 'f']]
list_1d: list[str] = [ch for row in list_2d for ch in row]
# any/all
any(x % 2 == 0 for x in number_list)
all(x % 2 == 0 for x in number_list)
```

**Java declaration/methods**

```java
var array = new int[]{1, 2, 3, 4, 5};
// Arrays
binarySearch(array, 3), equals(array, another_arr), copyOf(array, array.length), copyOfRange(array, 0, array.length),
sort(array), sort(array, 0, array.length), fill(array, 42), fill(array, 0, array.length, 42),
// Arrays.stream()
anyMatch(x -> x % 2 == 0), allMatch(x -> x % 2 == 0), noneMatch(x -> x % 2 == 0),
count(), sum(), min(), max(), average(), map(x -> x * 2).toArray(), filter(x -> x % 2 == 0).count()
// Collections
sort(list), binarySearch(list, 3), min(list), max(list), swap(list, 0, 1), replaceAll(list, 1, 2),
frequency(list, 1), reverse(list), rotate(list, 1), shuffle(list), unmodifiableList(list)
// list
var list = Arrays.asList(boxedArray);       // Arrays.stream(array).boxed().toArray(Integer[]::new);
sort(Comparator.naturalOrder()), sort(Comparator.reverseOrder())

Arrays.stream(array).boxed().toArray(Integer[]::new)    // int[] to Integer[]
Arrays.stream(array).mapToObj(String::valueOf).toArray(String[]::new)   // int[] to String[]
String.join(", ", strArray)     // array to string
str.split(", ")                 // string to array
List.of(array), Arrays.asList(array)  // array to list
Arrays.asList("foo", "bar", "baz").toArray(String[]::new)   // string list to string array
```

**Examples**

- Advancing through an array: [c++](cpp-algorithm/src/array) | Advance through the array to the last index.
- Arbitrary precision operation - increment an arbitrary-precision integer (`PlusOne`): [c++](cpp-algorithm/src/array) | Add one to the number represented by the vector.
- Arbitrary precision operation - add two arbitrary-precision integers (`StringAddition`): [c++](cpp-algorithm/src/array) | Add two numbers represented by strings.
- Arbitrary precision operation - multiply two arbitrary-precision integers (`Multiply`): [c++](cpp-algorithm/src/array) | Multiply two numbers represented by vectors.
- Delete duplicates from a sorted array (`DeleteDuplicates`): [c++](cpp-algorithm/src/array) | Delete duplicate elements in the array.
- Delete duplicates from a sorted array (`DeleteDuplicateElements`): [c++](cpp-algorithm/src/array) | Delete duplicate elements in the array.
- Delete specific elements from a sorted array (`DeleteSpecificElements`): [c++](cpp-algorithm/src/array) | Delete specific elements in the array.
- Dutch national flags problem: [c++](cpp-algorithm/src/array)
- Enumerate prime numbers: [c++](cpp-algorithm/src/array) | Enumerate prime numbers in the range.
- Order elements in an array by even and odd (`EvenOdd`): [c++](cpp-algorithm/src/array) | Order even and odd numbers in the array.
- Order elements in an array by specified order (`Rearrange`): [c++](cpp-algorithm/src/array) | Rearrange arrays to have a specific order.
- Random data sampling - offline (`OfflineRandomSampling`): [c++](cpp-algorithm/src/array) | Randomly select k elements from the array.
- Random data sampling - compute permutation (`ComputeRandomPermutation`): [c++](cpp-algorithm/src/array) | Compute permutation of the array generated by random sampling.
- Replace elements - replace and remove (`ReplaceAndRemoveString1`): [c++](cpp-algorithm/src/array) | Replace element and remove element in the array. Keep the array size.
- Replace elements - replace and remove (`ReplaceAndRemoveString2`): [c++](cpp-algorithm/src/array) | Replace element and remove element in the array
- Replace elements - telex encoding (`TelexEncoding`): [c++](cpp-algorithm/src/array) | Telex encoding for punctuation marks.
- Stock trading - buy and sell a stock once (`BuyAndSellStockOnceBruteForce`, `BuyAndSellStockOnce`): [c++](cpp-algorithm/src/array)
- Stock trading - buy and sell a stock twice (`BuyAndSellStockTwice`): [c++](cpp-algorithm/src/array)

[:arrow_up_small: back to toc](#table-of-contents)

### :chart_with_upwards_trend: Graph

- Shortest path algorithm
  - Single-source: Bellman-Ford algorithm, Dijkstra's algorithm
  - Single-pair: A\* search algorithm
  - All-pair: Floyd-Warshall algorithm, Johnson's algorithm
- Minimum spanning tree algorithm: Kruskal's algorithm, Prim's algorithm
- Maximum flow algorithm: Edmonds-Karp algorithm, Ford-Fulkerson algorithm, Push-relabel algorithm, Maximum bipartite matching

**Graph algorithms**

- A\* search algorithm: A single-pair shortest path algorithm. This is a variant of Dijkstra's algorithm using heuristics to try to speed up the search.
- Bellman-Ford algorithm: [c++](cpp-algorithm/src/graph), [java](java-algorithm/src/main/java/com/example/algorithm/graph) | A single source shortest path algorithm that can handle negative edge weights. It finds the shortest path from a source vertex to all other vertices in a weighted graph.

```txt
algorithm BellmanFord(G, source):
    // Initialize single source
    for each u in G.V:
        u.distance = ∞
        u.parent = NIL
    source.distance = 0

    for i = 0 to |G.V| - 2:
        for each edge (u, v) in G.E:
            // Relaxation
            if v.distance > u.distance + w(u, v):
                v.distance = u.distance + w(u, v)
                v.parent = u

    for each edge (u, v) in G.E:
        if v.distance > u.distance + w(u, v):
            return false
    return true
```

- Breadth-first search (BFS): [c++](cpp-algorithm/src/graph), [java](java-algorithm/src/main/java/com/example/algorithm/graph) | A search algorithm that traverses a graph layer by layer. Check the shortest path and compute the distance from the source vertex to all other vertices.

```txt
algorithm BFS(G, source):
    for each u in G.V:
        u.color = WHITE
        u.distance = ∞
        u.parent = NIL
    source.color = GRAY
    source.distance = 0
    source.parent = NIL
    Queue = ∅
    Queue.enqueue(source)

    while Queue != ∅:
        u = Queue.dequeue()
        for each v in G.Adj[u]:
            if v.color == WHITE:
                v.color = GRAY
                v.distance = u.distance + 1
                v.parent = u
                Queue.enqueue(v)
        u.color = BLACK
```

- Depth-first search (DFS): [c++](cpp-algorithm/src/graph), [java](java-algorithm/src/main/java/com/example/algorithm/graph) | A search algorithm that traverses a graph by exploring as far as possible along each branch before backtracking. Check to exists cycle in a graph.

```txt
algorithm DFS(G):
    for each u in G.V:
        u.color = WHITE
        u.parent = NIL
    time = 0
    for each u in G.V:
        if u.color == WHITE:
            DFS-VISIT(G, u)

algorithm DFS-VISIT(G, u):
    time = time + 1               // discovered
    u.discovered = time
    u.color = GRAY
    for each v in G.Adj[u]:
        if v.color == WHITE:
            v.parent = u
            DFS-VISIT(G, v)
    u.color = BLACK
    time = time + 1               // finished
    u.finished = time
```

- Dijkstra's algorithm: [c++](cpp-algorithm/src/graph), [java](java-algorithm/src/main/java/com/example/algorithm/graph) | A single source shortest path algorithm that handle non-negative edge weights. It find the shortest path between two vertices in a graph.

```txt
algorithm Dijkstra(G, source):
    // Initialize single source
    for each u in G.V:
        u.distance = ∞
        u.parent = NIL
    source.distance = 0

    Set = ∅
    Queue = G.V
    while Queue != ∅:
        u = EXTRACT-MIN(Queue)
        Set = Set ∪ {u}
        for each v in G.Adj[u]:
            // Relaxation
            if v.distance > u.distance + w(u, v):
                v.distance = u.distance + w(u, v)
                v.parent = u
```

- Edmonds-Karp algorithm:

```txt
algorithm EdmondsKarp(G, source, sink):
    // Initialize flow
    for each edge (u, v) in G.E:
        f(u, v) = 0

    while there exists an augmenting path P from source to sink in residual graph Gf:
        cf(P) = min{cf(u, v) | (u, v) in P}
        for each edge (u, v) in P:
            f(u, v) = f(u, v) + cf(P)
            f(v, u) = f(v, u) - cf(P)
    return f
```

- Floyd-Warshall algorithm: [java](java-algorithm/src/main/java/com/example/algorithm/graph) | A all pairs shortest paths algorithm.

```txt
algorithm InitializeAdjacencyMatrix(G):
    d = matrix of size |G.V| × |G.V|
    for each u in G.V:
        for each v in G.V:
            if u == v:
                d[u][v] = 0
            else if (u, v) in G.E:
                d[u][v] = w(u, v)
            else:
                d[u][v] = ∞
    return d

algorithm FloydWarshall(G):
    d = InitializeAdjacencyMatrix(G)
    for k = 0 to |G.V| - 1:
        for i = 0 to |G.V| - 1:
            for j = 0 to |G.V| - 1:
                dᵏ[i, j] = MIN(dᵏ⁻¹[i, j], dᵏ⁻¹[i, k] + dᵏ⁻¹[k, j])
    return d
```

- Ford-Fulkerson algorithm:

```txt
algorithm FordFulkerson(G, s, t):
    f = 0
    while there exists an augmenting path p from s to t in Gf:
        cf(p) = min{cf(u, v) | (u, v) in p}
        for each edge (u, v) in p:
            f(u, v) = f(u, v) + cf(p)
            f(v, u) = f(v, u) - cf(p)
        f = f + cf(p)
    return f
```

- Johnson's algorithm: A all pairs shortest paths algorithm. This is a combination of Dijkstra's algorithm and the Bellman-Ford algorithm. It may be faster than Floyd–Warshall on sparse graphs.

```txt
algorithm Johnson(G):
    G' = G ∪ {(s, v) | v in G.V}
    for each v in G.V:
        (s, v).weight = 0
    if BellmanFord(G', s) == false:
        return false
    for each edge (u, v) in G.E:
        w(u, v) = w(u, v) + h(u) - h(v)
    for each u in G.V:
        Dijkstra(G, w, u)
    for each u in G.V:
        for each v in G.V:
            d[u, v] = d[u, v] + h(v) - h(u)
    return d
```

- Kruskal's algorithm: [java](java-algorithm/src/main/java/com/example/algorithm/graph) | A minimum spanning tree algorithm. It finds a minimum spanning forest of an undirected edge-weighted graph. The algorithm uses path compression (FIND-SET) and union by rank (UNION) to improve the performance.

```txt
algorithm Kruskal(G, w):
    Set = ∅
    for each v in G.V:
        MAKE-SET(v)                                 // initialize vertice
    for each edge (u, v) in G.E ordered by w(u, v), increasing:
        if FIND-SET(u) != FIND-SET(v):
            Set = Set ∪ {(u, v)}
            UNION(u, v)                             // combine trees
    return Set
```

- Maximum bipartite matching
- Prim's algorithm: [java](java-algorithm/src/main/java/com/example/algorithm/graph) | A minimum spanning tree algorithm. It is a greedy algorithm that finds a minimum spanning tree for a weighted undirected graph.

```txt
algorithm Prim(G, root):
    for each u in G.V:
        u.key = ∞
        u.parent = NIL
    root.key = 0
    Queue = G.V                                       // queue is a min priority queue
    while Queue != ∅:
        u = EXTRACT-MIN(Queue)
        for each v in G.Adj[u]:
            if v in Queue and w(u, v) < v.key:
                v.parent = u
                v.key = w(u, v)
```

- Push-relabel algorithm

```txt
algorithm PushRelabel(G):
    for each v in G.V:
        v.height = 0
        v.excess = 0
    source.height = |G.V|
    for each edge (u, v) in G.E:
        push(u, v)
    while there exists a vertex u with excess > 0:
        if u has a neighbor v with height < u.height:
            push(u, v)
        else:
            relabel(u)
    return f
```

- Viterbi algorithm: A shortest stochastic path algorithm. It solves with additional probabilistic weights on each node.

**Examples**

- Maze problem: [java](java-algorithm/src/main/java/com/example/algorithm/graph) | A maze problem is that find a path from the start to the goal. The maze is represented by a graph. The start and the goal are represented by vertices. The path is represented by a sequence of vertices.

[:arrow_up_small: back to toc](#table-of-contents)

### :key: Hash table

**C++ declaration/methods**

```cpp
// map
auto map = std::unordered_map<std::string, int>{{"a", 1}, {"b", 2}};
insert({"c", 3}), emplace("d", 4), find("b"), end(), erase("a"), size(), empty()
// set
auto set = std::unordered_set{1, 2, 3, 4, 5};
insert(42), emplace(42), find(42), end(), erase(42), size(), empty()
// tuple
auto t = std::tuple{-1, -1};

// transform
std::ranges::transform(nums, std::inserter(map, map.end()),
    [i = 0](auto num) mutable { return std::pair{num, i++}; });
```

**Python declaration/functions**

```python
# set
number_set: set[int] = set()
add(1), update([2, 3, 4])
# dictionary
sample_dict: dict[str, int] = {'a': 1, 'b': 2, 'c': 3}
# defaultdict
sample_dict: collections.defaultdict[str, int] = collections.defaultdict(int)
sample_dict['a'] = 1
sample_dict.update({'b': 2, 'c': 3})
# counter
sample_counter: collections.Counter = collections.Counter()
sample_counter.update([1, 1, 2, 2, 3])
```

**Java declaration/methods**

```java
// map
var map = new HashMap<String, Integer>();
put("a", 1), putIfAbsent("b", 2), get("a"), getOrDefault("f", 6), remove("a"), size(), isEmpty(),
keySet(), values(), entrySet(), containsKey("a"), containsValue(1), replace("a", 2), clear()
// set
var set = new HashSet<Integer>();
add(1), remove(1), size(), isEmpty(), contains(1), clear(), iterator()

Collections.unmodifiableMap(map);
Collections.unmodifiableSet(set);
Collections.unmodifiableSortedMap(map);
Collections.unmodifiableSortedSet(set);
```

**Examples**

- Anonymous letter constructible (`IsLetterConstructibleFromMagazine`), EPI#12.2: [c++](cpp-algorithm/src/hash_table) | Check if a letter can be written using the characters in a magazine.
- Anonymous words constructible (`IsWordConstructibleFromMagazine`): [c++](cpp-algorithm/src/hash_table) | Check if a letter can be written using the words in a magazine.
- Collatz conjecture (`FindNumbersSatisfyingCollatzConjecture`), EPI#12.11: [c++](cpp-algorithm/src/hash_table) | Find the numbers satisfying the Collatz conjecture.
- Find anagrams (`FindAnagramMappings`): [c++](cpp-algorithm/src/hash_table) | Given an array of strings, group anagrams together.
- Find smallest subarray covering all values (`FindSmallestSubarrayCoveringSubset`), EPI#12.6: [c++](cpp-algorithm/src/hash_table) | Find the smallest subarray that covers all the elements in a set.
- Find smallest subarray sequentially covering all values (`FindSmallestSubarraySequentiallyCoveringSubset`), EPI#12.7: [c++](cpp-algorithm/src/hash_table) | Find the smallest subarray that sequentially covers all the elements in a set.
- ISBN cache, EPI#12.3: [c++](cpp-algorithm/src/hash_table) | Implement a LRU cache for ISBN lookups.
- Nearest repeated entry (`FindNearestRepeatedEntry`), EPI#12.5: [c++](cpp-algorithm/src/hash_table) | Find the nearest repeated entry in an array of strings.
- Optimized lowest common ancestor (`FindOptimizedLowestCommonAncestor`), EPI#12.4: [c++](cpp-algorithm/src/hash_table) | Find the lowest common ancestor of two nodes in a binary tree using a hash table. This traverses together until node1 and node2 meet.
- Palindromic permutation (`IsPalindromePermutation`), EPI#12.1: [c++](cpp-algorithm/src/hash_table) | Given a string, determine if a permutation of the string could form a palindrome.

[:arrow_up_small: back to toc](#table-of-contents)

### :rocket: Heap

A min-heap/max-heap is ideal for maintaining a collection of elements when we need to add arbitrary values and extract the smallest/largest element.

**C++ declaration/methods**

```cpp
auto queue = std::priority_queue<int>{};    // max heap
auto queue = std::priority_queue<int, std::vector<int>, std::greater<int>>{};   // min heap
push(1), emplace(2), pop(), top(), size(), empty()
```

**Python declaration/functions**

```python
number_list: list[int] = [5, 4, 3, 2, 1]
heapq.heapify(number_list)
heapq.nlargest(3, number_list), heapq.nsmallest(3, number_list)
heapq.heappush(number_list, 6), heapq.heappop(number_list), heapq.heapreplace(number_list, 0)
```

**Java declaration/methods**

```java
var queue = new PriorityQueue<Integer>();
add(1), peek(), poll(), remove(), size(), isEmpty(),
contains(1), clear(), iterator()
```

**Examples**

- Compute the k closest stars (`FindClosestStar`): [c++](cpp-algorithm/src/heap) | Find the $k$ closest stars to the earth. The stars are represented by a sequence of points(coordinates).
- Compute the median of a sequence of numbers (`FindMedian`): [c++](cpp-algorithm/src/heap) | Find the median of a sequence of numbers. The median is the number separating the higher half of a data sample from the lower half.
- Fibonacci heap
- Merge sorted arrays (`MergeSortedArray`): [c++](cpp-algorithm/src/heap) | Merge k sorted arrays into one heap.
- Sort an increasing-decreasing array (`SortIncreasingDecreasingArray`): [c++](cpp-algorithm/src/heap) | Sort an array that is repeatedly increasing then decreasing.

[:arrow_up_small: back to toc](#table-of-contents)

### :paperclips: Linked list

In Python, there is no built-in type or library for LinkedList.

**C++ declaration/methods**

```cpp
auto list = std::list{1, 2, 3};   // doubly linked list
push_front(4), emplace_front(5), push_back(6), emplace_back(7),
pop_front(), pop_back(), reverse(), sort(), insert(list.begin(), 11),
emplace(list.end(), 12), splice(list.end(), std::list{8, 9, 10})

auto list = std::forward_list{1, 2, 3};   // singly linked list
push_front(4), emplace_front(5), pop_front(), reverse(), sort()
```

**Java declaration/methods**

```java
var list = new LinkedList<Integer>();   // doubly linked list
add(1), addAll(List.of(2, 3, 4, 5)),
remove(0), removeFirst(), removeLast(), removeIf(x -> x % 2 == 0), subList(1, 3),
get(0), getFirst(), getLast(), size(), isEmpty(), contains(1), containsAll(List.of(1, 2, 3)),
iterator(), listIterator()

var list = new ArrayList<Integer>();    // dynamically resized array
add(1), addAll(List.of(2, 3, 4, 5)), remove(0), subList(1, 3),
get(0), size(), isEmpty(), contains(3), containsAll(List.of(3, 4)),
iterator(), listIterator()
```

**Examples**

- Add list-based integers (`AddTwoNumbers`): [c++](cpp-algorithm/src/linked_list) | Add two numbers represented by linked list.
- Delete a node from linked list (`DeleteNodeFromList`): [c++](cpp-algorithm/src/linked_list) | Delete a node from a linked list.
- Delete duplicate nodes from sorted linked list (`DeleteDuplicateNode`): [c++](cpp-algorithm/src/linked_list) | Delete duplicate nodes from a sorted linked list.
- Delete the k-th last node from linked list (`DeleteNodeKthLast`): [c++](cpp-algorithm/src/linked_list) | Delete the $k$-th last node from a linked list.
- Implement cyclic right shift for a singly linked list (`CyclicallyRightShiftList`): [c++](cpp-algorithm/src/linked_list) | Implement cyclic right shift for a singly linked list.
- Linked list has a cycle (`HasCycle1`, `HasCycle2`, `HasCycle3`): [c++](cpp-algorithm/src/linked_list) | Determine that a linked list has a cycle.
- List pivoting (`ListPivoting`): [c++](cpp-algorithm/src/linked_list) | Rearrange nodes smaller than pivot to the left and larger than pivot to the right.
- Merge even and odd nodes in linked list (`MergeEvenOddLinkedList`): [c++](cpp-algorithm/src/linked_list) | Merge even and odd nodes in a singly linked list.
- Merge two sorted linked lists: [c++](cpp-algorithm/src/linked_list) | Merge two sorted linked lists. In worst-case, this task has $O(n + m)$ time complexity, where $n$ and $m$ are the length of the lists.
- Palindrome list (`IsListPalindrome`): [c++](cpp-algorithm/src/linked_list) | Determine that a linked list is a palindrome.
- Reverse a single sublist: [c++](cpp-algorithm/src/linked_list) | Reverse a single sublist of a linked list.
- Two linked lists overlap (`OverlappingNoCycleList`): [c++](cpp-algorithm/src/linked_list) | Determine that two linked lists without cycle overlap.
- Two linked lists with cycles overlap (`OverlappingCycleList`) [c++](cpp-algorithm/src/linked_list) | Determine that two linked lists with cycle overlap.

[:arrow_up_small: back to toc](#table-of-contents)

### :walking: Queue

**C++ declaration/methods**

```cpp
auto container = std::queue<int>{};
push(1), emplace(2), pop(), front(), back(), size(), empty()

auto container = std::deque<int>{};
push_back(1), emplace_back(2), push_front(3), emplace_front(4),
pop_back(), pop_front(), front(), back(), size(), empty()
```

**Python declaration/functions**

```python
deque: collections.deque = collections.deque([1, 2, 3, 4, 5])
deque[0], deque[-1]
append(6), appendleft(7), pop(), popleft()
```

**Java declaration/methods**

```java
var deque = new ArrayDeque<Integer>();
add(1), remove(), pop(), size(), isEmpty(), contains(1), clear(),
offerFirst(6), offerLast(7), pollFirst(), pollLast(), peekFirst(), peekLast(),
addFirst(8), addLast(9), removeFirst(), removeLast(), getFirst(), getLast(),
iterator(), descendingIterator()

var array = deque.toArray(Integer[]::new);  // deque to array
var list = new ArrayList<>(deque);          // deque to list
```

**Examples**

[:arrow_up_small: back to toc](#table-of-contents)

### :hamburger: Stack

**C++ declaration/methods**

```cpp
auto stack = std::stack<int>{};
push(1), emplace(2), pop(), top(), size(), empty()
```

**Python declaration/functions**

```python
# use list type
stack: list[int] = [1, 2, 3]
stack[-1], len(stack)
append(4), pop()
```

**Java declaration/methods**

```java
var stack = new Stack<Integer>();
push(1), add(1, 2), addAll(anotherList), pop(), peek(), size(), isEmpty()
contains(1), search(1), size(),
remove(1), removeIf(x -> x == 1), clear()
iterator(), listIterator()

var array = stack.toArray(Integer[]::new);  // stack to array
var list = new ArrayList<>(stack);          // stack to list
```

**Examples**

- Pair of bracket (`CheckPairOfBracket`): [c++](cpp-algorithm/src/stack) | Checks if the input string contains bracket pairs and is well-formed.
- Print linked list in reverse order (`PrintLinkedListInReverseOrder`): [c++](cpp-algorithm/src/stack) | Print the linked list in reverse order using stack.
- Max stack element: [c++](cpp-algorithm/src/stack) | Implement stack that caches max value.

[:arrow_up_small: back to toc](#table-of-contents)

### :deciduous_tree: Tree

The tree is a specific type of graph. A tree is an undirected graph in which any two vertices are connected by exactly one path. It is connected without cycles.

**C++ declaration/methods (binary search tree based)**

```cpp
// map
auto map = std::map<std::string, int>{{"a", 1}, {"b", 2}};
insert({"c", 3}), emplace("d", 4), erase("a"), find("b"), size(), empty(), equal_range("c")
// set
auto set = std::set{1, 2, 3, 4, 5};
insert(42), emplace(42), erase(42), find(42), size(), equal_range(3)
```

**Python declaration/functions (binary search tree based)**

```python
# sortedcontainers
sort_list = SortedList([1, 2, 3, 4, 5])
sort_set = SortedSet([1, 2, 3, 4, 5])
sort_dict = SortedDict({'a': 1, 'b': 2, 'c': 3, 'd': 4, 'e': 5})
```

**Java declaration/methods (binary search tree based)**

```java
// TreeMap (based on red-black tree)
var treeMap = new TreeMap<String, Integer>(Map.of("a", 1, "b", 2, "c", 3));
put("a", 1), putIfAbsent("b", 2), get("a"), getOrDefault("f", 6), remove("a"), size(), isEmpty(),
keySet(), values(), entrySet(), containsKey("a"), containsValue(1), replace("a", 2), clear()
firstKey(), lastKey(), lowerKey("b"), higherKey("b"), floorKey("b"), ceilingKey("b"),pollFirstEntry(), pollLastEntry(),
headMap("c"), tailMap("c"), subMap("a", "c"), descendingMap(), descendingKeySet()

// treeSet (based on red-black tree)
var treeSet = new TreeSet<Integer>(List.of(1, 2, 3, 4, 5));
add(1), remove(1), size(), isEmpty(), contains(1), clear(), iterator(), descendingIterator(),
first(), last(), lower(3), higher(3), floor(3), ceiling(3), pollFirst(), pollLast(),
headSet(3), tailSet(3), subSet(2, 4), descendingSet()
```

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

**Balanced binary tree**

- Depending on the balance: complete binary tree, full binary tree, perfect binary tree
- Balanced binary tree: Red-black tree, AVL tree (from Adelson-Velsky and Landis)

**Tree traversal in binary tree**

- Preorder traversal (root, left, right): best choice for applications where internal vertices must be explored before leaves.
- Inorder traversal (left, root, right): best choice for applications where internal vertices must be explored in-order.
- Postorder traversal (left, right, root): best choice for applications where leaves need to be explored before internal vertices.

**Examples**

- AVL tree
- B-tree: [c++](cpp-algorithm/src/tree) | B-tree is a self-balancing data structure which can have many child nodes. It is commonly used in auxiliary storage devices and database system. B-tree has the following properties: 1) Nodes have lower and upper bounds on the number of keys they can contain. (represent using degree $t$) 2) Every node other than the root must have at least $t-1$ keys. 3) Every node may contain at most $2t-1$ keys.
- Balanced tree status: [c++](cpp-algorithm/src/tree) | Whether the binary tree is balanced or not.
- Binary search tree: [c++](cpp-algorithm/src/tree) | In binary search tree, all internal nodes are stored in ordered state. If $y$ is a child of $x$ and $y$ is a node in the left subtree, then $y.key \leq x.key$, and if $y$ is a node in the right subtree, then $y.key \geq x.key$.
- Binary tree exterior (`CreateExteriorNodeList`): [c++](cpp-algorithm/src/tree) | Create a vector of exterior nodes in a binary tree.
- Construct binary tree from preorder and inorder traversal (`ConstructTreeFromPreorderInorder`): [c++](cpp-algorithm/src/tree) | Construct a binary search tree from preorder and inorder traversal. This task has $O(n)$ time complexity.
- Construct binary tree from preorder with marker (`ConstructTreeFromMarkerPreorder`): [c++](cpp-algorithm/src/tree) | Construct a binary search tree from preorder traversal with marker. This task has $O(n)$ time complexity.
- Leaf node list (`CreateLeafNodeList`): [c++](cpp-algorithm/src/tree) | Create a vector of leaf nodes in a binary tree.
- Lowest common ancestor (`FindLowestCommonAncestor`): [c++](cpp-algorithm/src/tree) | Find the lowest common ancestor of two nodes in a binary tree.
- Lowest common ancestor with parent pointer (`FindLowestCommonAncestor2`): [c++](cpp-algorithm/src/tree) | Find the lowest common ancestor of two nodes in a binary tree. The nodes have parent pointers.
- Populate right sibling (`PopulateRightSibling`): [c++](cpp-algorithm/src/tree) | Populate the right sibling of a binary tree.
- Red-black search tree
- Root to leaf path corresponding to the given sum (`HasKeySum`): [c++](cpp-algorithm/src/tree) | Whether the tree has a root-leaf path equal to the given sum.
- Sum of root to leaf (`SumRootToLeafDecimal`, `SumRootToLeafBinary`): [c++](cpp-algorithm/src/tree) | Sum of all root to leaf paths in a binary tree (decimal and binary representation).
- Tree symmetric: [c++](cpp-algorithm/src/tree) | Whether the binary tree is symmetric or not.
- Trie
- van Emde Boas tree (vEB tree)

[:arrow_up_small: back to toc](#table-of-contents)

## Topics

### :jigsaw: Dynamic programming

**Examples**

- Fibonacci number: [c++](cpp-algorithm/src/dynamic_programming) | Fibonacci sequence is a sequence of numbers where each number is the sum of the two preceding numbers. Fibonacci number is $n$th number in the sequence. The Fibonacci sequence is defined as follows:
  - $F_0 = 0$
  - $F_1 = 1$
  - $F_n = F_{n-1} + F_{n-2}$ (for $n > 1$)
- Interval subset sum (`SubsetSum1`, `SubsetSum2`, `DivideAndConquerSubsetSum`, `DynamicProgrammingSubsetSum`): [c++](cpp-algorithm/src/dynamic_programming) | Interval subset sum problem is that finds the maximum sum of a subset of intervals.
- Longest common subsequence: [c++](cpp-algorithm/src/dynamic_programming)
- Rod cutting: [c++](cpp-algorithm/src/dynamic_programming) | Rod cutting is a problem of cutting a rod into pieces of a given length to determine the maximum profit.

[:arrow_up_small: back to toc](#table-of-contents)

### :clock9: Greedy

**Examples**

- Activity selection: [c++](cpp-algorithm/src/greedy) | Activity selection problem using greedy algorithm or recursive approach. This is similar to the Interval scheduling problem.
- Cashier's change: [python](python-algorithm/algorithm/greedy) | Cashier's change problem is that finds the minimum number of coins required to make change for a given amount of money.
- Huffman code: [c++](cpp-algorithm/src/greedy) | Huffman code constructs optimal prefix codes. This is always represented by a full binary tree.
- Interval scheduling: [python](python-algorithm/algorithm/greedy) | Interval scheduling problem is that finds the minimum number of intervals required to schedule a set of activities(lectures).

[:arrow_up_small: back to toc](#table-of-contents)

### :triangular_ruler: Mathematics

**Examples**

- Base expansion (base $b$ expansion of $n$): [python](python-algorithm/algorithm/math) | Constructing the base $b$ expansion of an integer $n$. Such as binary, octal, decimal, hexadecimal expansion, etc.
- Binary operation (`addition`): [python](python-algorithm/algorithm/math)
- Combination (`GenerateCombination`): [c++](cpp-algorithm/src/math) | Find the number of ways to choose $k$ items from $n$ items.
- Fast Fourier transform: Fast Fourier transform is a mathematical algorithm that finds the discrete Fourier transform of a set of real numbers.
- Greatest common divisor (GCD): [python](python-algorithm/algorithm/math) | Find the greatest common divisor of two numbers.
- Inverse of matrix: Inverse of matrix is a mathematical algorithm that finds the inverse of a matrix.
- Least common multiple (LCM): [python](python-algorithm/algorithm/math) | Find the least common multiple of two numbers.
- Matrix multiplication: [python](python-algorithm/algorithm/math) | This is the product of two matrices.
- Miller-Rabin primality test: [c++](cpp-algorithm/src/math) | Miller-Rabin primality test is a mathematical algorithm that finds whether a given number is prime.
- Permutation (`Permutation`): [c++](cpp-algorithm/src/math) | Find the permutation of a set of items.
- Permutation (`ApplyPermutationWithAdditionalSpace`, `ApplyPermutationBySwap`): [c++](cpp-algorithm/src/math) | Permute the elements of an array
- Permutation (`InversePermutation`): [c++](cpp-algorithm/src/math)
- Permutation (`NextPermutation`/`PreviousPermutation`): [c++](cpp-algorithm/src/math) | Compute the next/previous permutation.
- Permutation (`KthPermutation`): [c++](cpp-algorithm/src/math) | Compute the $k$-th permutation.
- Simplex algorithm: Simplex algorithm is a mathematical algorithm that finds the optimal solution to a linear programming problem.
- System of linear equations: System of linear equations is a mathematical algorithm that finds the solution to a system of linear equations.

[:arrow_up_small: back to toc](#table-of-contents)

### :1234: Primitive type

**C++ declaration/methods**

```cpp
std::to_string(42), std::swap(x, y)
std::numeric_limits<int>::min(), std::numeric_limits<float>::max(), std::numeric_limits<double>::infinity() // constants
std::abs(-34), std::fabs(-3.14), std::ceil(2.17), std::floor(3.14), std::min(x, -4), std::max(3.14, y), pow(2.17, 3.14), log(7.12), sqrt(225) // cmath
std::stoi("42"), std::stod("3.14"), std::stoi("42", nullptr, 16), std::stoi("1000010", nullptr, 2) // string -> int/double/hex/binary
std::bitset<8>(42), std::bitset<8>(3.14), std::bitset<8>(0x42), std::bitset<8>(0b1000010) // int/double/hex/binary -> bitset
std::uniform_int_distribution<int> distribution(1, 6), std::uniform_real_distribution<double> distribution(0.0, 1.0) // random

// random values
std::random_device rd;
std::mt19937 generator(rd());
std::uniform_int_distribution distribution(1, 10);  // integer in [1, 10]
const auto i = distribution(generator);
const auto d = std::generate_canonical<double, 10>(generator);  // floating point number in [0, 1)
```

**Python declaration/functions**

```python
float('inf'), float('-inf')     # constants
math.fabs(-34.5), math.ceil(2.17), math.floor(3.14), math.max(x, -3), math.min(x, 3.14), math.pow(2.71, 3.15), math.round(3.14), math.sqrt(225) # math
abs(-34), min(number_list), max(number_list), sum(number_list), sorted(number_list)
len(sample_string), len(number_list), len(sample_dict)  # length
str(42), str(3.14), str(True)           # int/float/bool -> string
int("42"), float("3.14"), bool("true")  # string -> int/float/bool
int("1000010", 2), int("52", 8), int("2a", 16)  # string -> binary/octal/hex
bin(42), oct(42), hex(42)       # int -> binary/octal/hex
ascii('a'), chr(97), ord('a')   # unicode <-> ascii code

### copy
copy.deepcopy(number_list) # deep copy
copy.copy(number_list)     # shallow copy

### random
random.randrange(28)       # [0, 28)
random.randrange(1, 100)   # [1, 100)
random.randrange(8, 16)    # [8, 16)
random.randrange(8, 16, 2) # [8, 16) with step 2
random.shuffle(number_list)
random.choice(number_list)
```

**Java declaration/methods**

```java
Integer.MIN_VALUE, Float.MAX_VALUE, Double.POSITIVE_INFINITY, Double.NEGATIVE_INFINITY, Boolean.TRUE  // constants
Math.abs(-34.5), Math.ceil(2.17), Math.floor(3.14), Math.max(x, -3), Math.min(x, 3.14), Math.pow(2.71, 3.15), Math.round(3.14), Math.sqrt(225) // math
Integer.valueOf("1"), Double.valueOf("3.14"), Boolean.valueOf("true"), Float.toString(3.14f)  // reference type
Integer.parseInt("42"), Double.parseDouble("3.14")  // primitive type
Integer.parseInt("1000010", 2), Integer.parseInt("52", 8), Integer.parseInt("2a", 16) // string -> binary/octal/hex
Integer.toBinaryString(42), Integer.toHexString(42), Integer.toOctalString(42)  // int -> binary/hex/octal string
new BitSet(16), set(0), set(0, 8), set(0, 8, true)  // bitset
Double.compare(x, 1.23) == 0, Integer.compare(x, 2) == 0  // comparing values

// random values
var random = new Random();  // java.util.Random
var randomInt = random.nextInt(100);      // [0, 100)
var randomLong = random.nextLong();       // [0, 2^48)
var randomDouble = random.nextDouble();   // [0.0, 1.0)
var randomBoolean = random.nextBoolean(); // true/false
```

**Examples**

- Arithmetic operation (`Multiply`/`Divide`): [c++](cpp-algorithm/src/primitive_type) | Calculate the product/fraction of two numbers without using arithmetic operators.
- Computing parity of word (`CountBits`): [c++](cpp-algorithm/src/primitive_type) | Count the number of bits that are set to 1.
- Computing parity of word (`Parity`): [c++](cpp-algorithm/src/primitive_type) | Compute parity of word.
- Computing parity of word (`ParityDropLowestBits`): [c++](cpp-algorithm/src/primitive_type) | Compute parity by dropping the lowest set bit.
- Computing parity of word (`ParityLookupTable`): [c++](cpp-algorithm/src/primitive_type) | Compute parity by caching the results.
- Generate random number: [c++](cpp-algorithm/src/primitive_type) | Generate a random number in a range with equal probability.
- Integer palindrome: [c++](cpp-algorithm/src/primitive_type) | Check if a number is a palindrome.
- Power operation: [c++](cpp-algorithm/src/primitive_type) | Compute repeated squaring $x^y$.
- Rectangle intersection: [c++](cpp-algorithm/src/primitive_type) | Check if two rectangles intersect.
- Reverse digits: [c++](cpp-algorithm/src/primitive_type) | Reverse the digits of a given integer.
- Swap bit: [c++](cpp-algorithm/src/primitive_type) | Swap the bits at indices $i$ and $j$.

[:arrow_up_small: back to toc](#table-of-contents)

### :mag: Search

**C++ declaration/methods**

```cpp
// map
auto map = std::map<std::string, int>{{"a", 1}, {"b", 2}};
insert({"c", 3}), emplace("d", 4), erase("a"), find("b"), size(), empty(), equal_range("c")
// set
auto set = std::set{1, 2, 3, 4, 5};
insert(42), emplace(42), erase(42), find(42), size(), equal_range(3)

// algorithm
std::ranges::find(v, 42)
std::ranges::find(v, 42)
std::ranges::find_if(v, [](auto x) { return x % 2 == 0; })
std::ranges::find_end(v, sub_v).begin() // cf. result - v.begin()
std::ranges::binary_search(v, 42)
std::ranges::lower_bound(v, 42)
std::ranges::upper_bound(v, 42)
```

**Python declaration/functions**

```python
bisect.bisect_left(number_list, 3), bisect.bisect_right(number_list, 3), bisect.bisect(number_list, 3)
```

**Java declaration/methods**

```java
var array = new int[]{1, 2, 3, 4, 5};
var arrayList = new ArrayList<Integer>(List.of(1, 2, 3, 4, 5));
var linkedList = new LinkedList<Integer>(List.of(1, 2, 3, 4, 5));
var hashSet = new HashSet<Integer>(List.of(1, 2, 3, 4, 5));
var linkedHashSet = new LinkedHashSet<Integer>(List.of(1, 2, 3, 4, 5));
var treeSet = new TreeSet<Integer>(List.of(1, 2, 3, 4, 5));

// binary search
Arrays.binarySearch(array, 3)             // for array
Collections.binarySearch(arrayList, 3);   // for list
```

**Examples**

- Binary search: [python](python-algorithm/algorithm/search) | Binary search is a search algorithm that finds the position of a target value within a sorted array.
- Find k-th smallest/largest element in an array (`FindKthSmallestElement`/`FindKthLargestElement`), EPI#11.8: [c++](cpp-algorithm/src/search) | Find the k-th smallest/largest element in an array using the quickselect algorithm (`QuickSelectAlgorithm`).
- Find the minimum and maximum elements in an array (`FindMinMax`), EPI#11.7: [c++](cpp-algorithm/src/search)
- Integer square root (`ComputeIntegerSquareRoot`), EPI#11.4: [c++](cpp-algorithm/src/search) | Compute the integer square root of a given integer. This function returns the largest integer whose square is less than or equal to the given integer.
- Linear search: [python](python-algorithm/algorithm/search) | Linear search is a search algorithm that compares x successively with each term of the list until a match is found.
- Quick select algorithm (`QuickSelectAlgorithm`): [c++](cpp-algorithm/src/search) | QuickSelect is an algorithm used to select the k-th smallest (or largest) element in an unordered list of elements.
- Search a sorted array for entry equal to its index (`SearchEntryEqualToItsIndex`), EPI#11.2: [c++](cpp-algorithm/src/search)
- Search a sorted array for the first greater than a key (`SearchFirstGreaterThanKey`): [c++](cpp-algorithm/src/search)
- Search a sorted array for the first occurrence of a key (`SearchFirstOfKey`), EPI#11.1: [c++](cpp-algorithm/src/search)
- Search a cyclically sorted array for the smallest element (`SearchSmallestElementInCyclicallySortedArray`), EPI11.3: [c++](cpp-algorithm/src/search)
- Search in a 2D sorted array(matrix) (`SearchSortedMatrix`), EPI11.6: [c++](cpp-algorithm/src/search) | Search in a 2D sorted array(matrix) for a given element.

[:arrow_up_small: back to toc](#table-of-contents)

### :abc: Sort

**C++ declaration/methods**

```cpp
std::ranges::sort(v);         // introsort (quick sort + heap sort + insertion sort)
std::ranges::stable_sort(v);  // merge sort
```

**Python declaration/functions**

```python
number_list: list[int] = [1, 2, 3, 4, 5]
number_list.sort()              # in-place
result = sorted(number_list)    # return a new list(copy)
```

**Java declaration/methods**

```java
Arrays.sort(array);     // dual pivot quick sort (primitive types)
                        // timsort (insertion sort + merge sort) (reference types)
Collections.sort(list); // timsort (insertion sort + merge sort)
```

**Sorting algorithms**

- Bubble sort: [java](java-algorithm/src/main/java/com/example/algorithm/sort) | Bubble sort is a sorting algorithm that repeatedly steps through the list to be sorted, compares each pair of adjacent items, and swaps them if needed.<br>(`n` is the number of elements)

| **Case**    | **Time complexity** | **Remarks**                                                                             |
| :---------- | :-----------------: | :-------------------------------------------------------------------------------------- |
| **Best**    |       $O(n)$        | when the input list is already sorted in the desired order                              |
| **Worst**   |      $O(n^2)$       | when the input list is already sorted in the reverse order of the desired sorting order |
| **Average** |      $O(n^2)$       |                                                                                         |

- Bucket sort: [java](java-algorithm/src/main/java/com/example/algorithm/sort) | Bucket sort is a sorting algorithm that works by distributing the elements of an array into a number of buckets. Each bucket contains a range of values and the elements are sorted within these buckets using any of the suitable sorting algorithms (such as insertion sort, merge sort, selection sort).<br>(`n` is the number of elements and `k` is the number of buckets)

| **Case**    | **Time complexity** | **Remarks**                                                                                                    |
| ----------- | :-----------------: | -------------------------------------------------------------------------------------------------------------- |
| **Best**    |     $O(n + k)$      | when input elements are uniformly distributed<br> and each bucket contains roughly the same number of elements |
| **Worst**   |      $O(n^2)$       | when all elements are placed into a single bucket                                                              |
| **Average** |       $O(n)$        |                                                                                                                |

- Counting sort: [java](java-algorithm/src/main/java/com/example/algorithm/sort) | Counting sort is a non-comparative sorting algorithm that sorts the elements of an array by counting the occurrences of each element in the array. The count is stored in an auxiliary array and the sorting is done by mapping the count as an index of the auxiliary array. It is used as a subroutine in radix sort.<br>(`n` is the number of elements and `k` is the range of input values)

| **Case**    | **Time complexity** | **Remarks**                                          |
| ----------- | :-----------------: | ---------------------------------------------------- |
| **Best**    |     $O(n + k)$      | when the input elements have a small range of values |
| **Worst**   |     $O(n + k)$      | when the input elements have a large range of values |
| **Average** |     $O(n + k)$      |                                                      |

- Heap sort: [java](java-algorithm/src/main/java/com/example/algorithm/sort) | Heap sort is a comparison-based sorting algorithm that uses a binary heap data structure to sort an array. It is used for the implementation of priority queue.<br>(`n` is the number of elements)

| **Case**    | **Time complexity** | **Remarks** |
| ----------- | :-----------------: | ----------- |
| **Best**    |    $O(n log n)$     |             |
| **Worst**   |    $O(n log n)$     |             |
| **Average** |    $O(n log n)$     |             |

- Insertion sort: [c++](cpp-algorithm/src/sort), [java](java-algorithm/src/main/java/com/example/algorithm/sort) | Insertion sort is a comparison-based sorting algorithm that builds the final sorted array one element at a time. One of the fastest algorithms for sorting very small arrays (around 10 elements).<br>(`n` is the number of elements)

| **Case**    | **Time complexity** | **Remarks**                                                                     |
| ----------- | :-----------------: | ------------------------------------------------------------------------------- |
| **Best**    |       $O(n)$        | if the list is already sorted.<br>this case has linear running time             |
| **Worst**   |      $O(n^2)$       | if the list is sorted in reverse order.<br>this case has quadratic running time |
| **Average** |      $O(n^2)$       | this case has quadratic running time                                            |

- Merge sort: [java](java-algorithm/src/main/java/com/example/algorithm/sort) | divide and conquer algorithm

| **Case**    | **Time complexity** | **Remarks**                                                                                           |
| ----------- | :-----------------: | ----------------------------------------------------------------------------------------------------- |
| **Best**    |    $O(n log n)$     | running time of sorting for input length $n$ is $T(n)$.<br>$T(n) = 2T(n/2) + O(n) \approx O(n log n)$ |
| **Worst**   |    $O(n log n)$     |                                                                                                       |
| **Average** |    $O(n log n)$     |                                                                                                       |

- Quick sort: [java](java-algorithm/src/main/java/com/example/algorithm/sort) | divide and conquer algorithm

| **Case**    | **Time complexity** | **Remarks** |
| ----------- | :-----------------: | ----------- |
| **Best**    |    $O(n log n)$     |             |
| **Worst**   |      $O(n^2)$       |             |
| **Average** |    $O(n log n)$     |             |

- Selection sort: [c++](cpp-algorithm/src/sort), [java](java-algorithm/src/main/java/com/example/algorithm/sort)

| **Case**    | **Time complexity** | **Remarks**                                                                          |
| ----------- | :-----------------: | ------------------------------------------------------------------------------------ |
| **Best**    |      $O(n^2)$       | if the list is already sorted                                                        |
| **Worst**   |      $O(n^2)$       | when sorted in ascending order, if you want to sort in descending order (vice versa) |
| **Average** |      $O(n^2)$       |                                                                                      |

**Examples**

- H-Index (`HIndex`), EPI#13.3: [c++](cpp-algorithm/src/sort) | Compute the researcher's h-index given a citation count array. The h-index is the largest number `h` such that `h` articles have at least `h` citations each.
- Intersection of two sorted arrays (`IntersectTwoSortedArray`), EPI#13.1: [c++](cpp-algorithm/src/sort) | Compute the intersection of two sorted array. The input arrays may have duplicate entries, but the output should be free of duplicates.
- Merge intervals (`MergeIntervals`), EPI#13.7, LeetCode#merge-intervals: [c++](cpp-algorithm/src/sort) | Given a collection of intervals, merge all overlapping intervals.
- Merge two sorted arrays (`MergeTwoSortedArray`), EPI#13.2, LeetCode#merge-sorted-array: [c++](cpp-algorithm/src/sort) | Merge two sorted array. Merge the second array into the first array.
- Partitioning and sorting an array with many repeated entries (`GroupByAge`), EPI#13.9: [java](java-algorithm/src/main/java/com/example/algorithm/sort) | Given an array of objects with an age field, reorder the array so that objects of equal age appear together. They should be sorted in ascending order of age, and the order of objects with the same age is not important.
- Remove first-name duplicates (`EliminateFirstNameDuplicate`), EPI#13.4: [c++](cpp-algorithm/src/sort) | Given an array of names, remove the duplicates of the first name.
- Salary threadhold (`SalaryThreshold`), EPI#13.12: [java](java-algorithm/src/main/java/com/example/algorithm/sort) | Given an array of salaries and a budget, compute the salary cap so that the total salaries equal the budget.
- Team photo day (`SortPlayerByHeight`), EPI#13.10: [java](java-algorithm/src/main/java/com/example/algorithm/sort) | Given two arrays of numbers, for team photos, players are arranged in front and back rows and then photographed. The players in the back row must necessarily be taller than those in the front row. Additionally, all players in a row should belong to the same team.
- Union of intervals (`UnionOfIntervals`), EPI#13.8: [c++](cpp-algorithm/src/sort) | Given a set of intervals, compute their union.

[:arrow_up_small: back to toc](#table-of-contents)

### :page_facing_up: String

**C++ declaration/methods**

```cpp
auto str = std::string{"hello"};
append("_world"), push_back('!'), pop_back(), insert(5, "_world"), substr(0, 5), compare("hello_world")

// string stream
std::stringstream ss(str);
good(), bad(), fail(), eof(), clear(), operator<<(), operator>>()
```

**Python declaration/functions**

```python
hello_world: str = 'hello world'
len(hello_world), count('l'), find('world'), rfind('world'), index('world'), rindex('world'),
strip(), split(' '), replace(' ', ''), startswith('hello'), endswith('world'),
lower(), upper(), capitalize(), title(), swapcase()

# string concatenation
s = s[6:]
s += 'abc'
```

**Java declaration/methods**

```java
var str = "Hello World";
length(), charAt(0), substring(0, 5), indexOf("Java"), lastIndexOf("Java"),
contains("Java"), startsWith("Hello"), endsWith("World"),
compareTo("Hello Java"), compareToIgnoreCase("hello world"),
concat("!"), replace("World", "Java"), toUpperCase(), toLowerCase(), trim(),
toCharArray(), chars()

// static methods
String.format("%s %s", "Hello", "World")
String.join(" ", "Hello", "World")
String.valueOf(123)

// string builder
var sb = new StringBuilder();
append("!"), insert(0, "Hello"), delete(0, 5), deleteCharAt(0),
length(), charAt(0), indexOf("Java"), lastIndexOf("Java"),
reverse(), replace(0, 5, "World"), substring(0, 5), toString()
subSequence(0, 5), chars()

// list/stack/deque to string
var str = collection.stream()
    .map(String::valueOf)
    .collect(StringBuilder::new, StringBuilder::append, StringBuilder::append);
```

**Examples**

- Convert string (`IntToString`, `StringToInt`): [c++](cpp-algorithm/src/string) | Convert integer to string and vice versa.
- Finite automata
- IP address validation: [c++](cpp-algorithm/src/string) | Validate IPv4 address that is in the form of `x.x.x.x` where `x` is a number between 0 and 255.
- Knuth-Morris-Pratt algorithm (KMP)
- Look and say problem: [c++](cpp-algorithm/src/string)
- Naive string matching: [c++](cpp-algorithm/src/string), [python](python-algorithm/algorithm/string) | Find all occurrences of a pattern in a string.
- Palindrome: [c++](cpp-algorithm/src/string) | Check if a string is palindromic.
- Print sine wave pattern string (`SineWaveString` and `PrintSineWaveString`): [c++](cpp-algorithm/src/string) | Print a string in sine wave pattern.
- Rabin-Karp algorithm: [c++](cpp-algorithm/src/string) | Use the hash function to find all occurrences of a pattern in a string. It has $\theta(\text{pattern-size})$ preprocessing time and $\theta((\text{text-size} - \text{pattern-size} + 1) \text{pattern-size})$ time complexity.
- Roman number (`VerifyRomanString`): [c++](cpp-algorithm/src/string) | Verify if a string is a valid roman number.
- Roman number (`RomanStringToInteger`): [c++](cpp-algorithm/src/string) | Convert a roman number to integer.
- Run-length encoding (RLE): [c++](cpp-algorithm/src/string) | Run-length encoding is a simple form of data compression in which runs of data are stored as a single data value and count.
- Spreadsheet column decoding/encoding (`DecodingSheetColumnId`/`EncodingSheetColumnId`): [c++](cpp-algorithm/src/string) | Convert a spreadsheet column id to integer and vice versa.

[:arrow_up_small: back to toc](#table-of-contents)

## References

- Introduction to Algorithms, 3rd Edition, by CLRS
- Discrete Mathematics and Its Applications, 8th Edition, by Kenneth H. Rosen
- Cracking the Coding Interview, 6th Edition, by Gayle Laakmann McDowell
- Elements of Programming Interviews, 2nd Edition, by Adnan Aziz, Tsung-Hsien Lee and Amit Prakash

[:arrow_up_small: back to toc](#table-of-contents)
