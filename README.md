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
```

**Examples**

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

- Shortest path algorithm
  - Single-source: Bellman-Ford algorithm, Dijkstra's algorithm
  - Single-pair: A* search algorithm
  - All-pair: Floyd-Warshall algorithm, Johnson's algorithm
- Minimum spanning tree algorithm: Kruskal's algorithm, Prim's algorithm
- Maximum flow algorithm: Edmonds-Karp algorithm, Ford-Fulkerson algorithm, Push-relabel algorithm, Maximum bipartite matching

**Examples**

- A* search algorithm: A single-pair shortest path algorithm. This is a variant of Dijkstra's algorithm using heuristics to try to speed up the search.
- Bellman-Ford algorithm: [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/graph)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/graph)), [java](https://github.com/codejsha/algorithm-examples/tree/main/java-algorithm/src/main/java/com/example/algorithm/graph)([test](https://github.com/codejsha/algorithm-examples/tree/main/java-algorithm/src/test/java/com/example/algorithm/graph)) | A single source shortest path algorithm that can handle negative edge weights. It finds the shortest path from a source vertex to all other vertices in a weighted graph.

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

- Breadth-first search (BFS): [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/graph)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/graph)), [java](https://github.com/codejsha/algorithm-examples/tree/main/java-algorithm/src/main/java/com/example/algorithm/graph)([test](https://github.com/codejsha/algorithm-examples/tree/main/java-algorithm/src/test/java/com/example/algorithm/graph)) | A search algorithm that traverses a graph layer by layer. Check the shortest path and compute the distance from the source vertex to all other vertices.

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

- Depth-first search (DFS): [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/graph)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/graph)), [java](https://github.com/codejsha/algorithm-examples/tree/main/java-algorithm/src/main/java/com/example/algorithm/graph)([test](https://github.com/codejsha/algorithm-examples/tree/main/java-algorithm/src/test/java/com/example/algorithm/graph)) | A search algorithm that traverses a graph by exploring as far as possible along each branch before backtracking. Check to exists cycle in a graph.

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

- Dijkstra's algorithm: [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/graph)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/graph)), [java](https://github.com/codejsha/algorithm-examples/tree/main/java-algorithm/src/main/java/com/example/algorithm/graph)([test](https://github.com/codejsha/algorithm-examples/tree/main/java-algorithm/src/test/java/com/example/algorithm/graph)) | A single source shortest path algorithm that handle non-negative edge weights. It find the shortest path between two vertices in a graph.

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

- Edmonds-Karp algorithm
- Floyd-Warshall algorithm: [java](https://github.com/codejsha/algorithm-examples/tree/main/java-algorithm/src/main/java/com/example/algorithm/graph)([test](https://github.com/codejsha/algorithm-examples/tree/main/java-algorithm/src/test/java/com/example/algorithm/graph)) | A all pairs shortest paths algorithm.

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

- Ford-Fulkerson algorithm
- Johnson's algorithm: A all pairs shortest paths algorithm. This is a combination of Dijkstra's algorithm and the Bellman-Ford algorithm. It may be faster than Floyd–Warshall on sparse graphs.
- Kruskal's algorithm: [java](https://github.com/codejsha/algorithm-examples/tree/main/java-algorithm/src/main/java/com/example/algorithm/graph)([test](https://github.com/codejsha/algorithm-examples/tree/main/java-algorithm/src/test/java/com/example/algorithm/graph)) | A minimum spanning tree algorithm. It finds a minimum spanning forest of an undirected edge-weighted graph. The algorithm uses  path compression (FIND-SET) and union by rank (UNION) to improve the performance.

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

- Maze problem: [java](https://github.com/codejsha/algorithm-examples/tree/main/java-algorithm/src/main/java/com/example/algorithm/graph)([test](https://github.com/codejsha/algorithm-examples/tree/main/java-algorithm/src/test/java/com/example/algorithm/graph)) | A maze problem is that find a path from the start to the goal. The maze is represented by a graph. The start and the goal are represented by vertices. The path is represented by a sequence of vertices.
- Maximum bipartite matching
- Prim's algorithm: [java](https://github.com/codejsha/algorithm-examples/tree/main/java-algorithm/src/main/java/com/example/algorithm/graph)([test](https://github.com/codejsha/algorithm-examples/tree/main/java-algorithm/src/test/java/com/example/algorithm/graph)) | A minimum spanning tree algorithm. It is a greedy algorithm that finds a minimum spanning tree for a weighted undirected graph.

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
- Viterbi algorithm: A shortest stochastic path algorithm. It solves with additional probabilistic weights on each node.

### Hash table

**C++ declaration/methods**

```cpp
auto map = std::unordered_map<std::string, int>{{"a", 1}, {"b", 2}};
insert({"c", 3}), emplace("d", 4), find("b"), erase("a"), size(), empty()
auto set = std::unordered_set{1, 2, 3, 4, 5};
insert(42), emplace(42), find(42), erase(42), size(), empty()
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
var map = new HashMap<String, Integer>();
put("a", 1), putIfAbsent("b", 2), get("a"), getOrDefault("f", 6), remove("a"), size(), isEmpty(),
keySet(), values(), entrySet(), containsKey("a"), containsValue(1), replace("a", 2), clear()
var set = new HashSet<Integer>();
add(1), remove(1), size(), isEmpty(), contains(1), clear(), iterator()

Collections.unmodifiableMap(map);
Collections.unmodifiableSet(set);
Collections.unmodifiableSortedMap(map);
Collections.unmodifiableSortedSet(set);
```

### Heap

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

- Compute the k closest stars (FindClosestStar): [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/heap)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/heap)) | Find the $k$ closest stars to the earth. The stars are represented by a sequence of points(coordinates).
- Compute the median of a sequence of numbers (FindMedian): [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/heap)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/heap)) | Find the median of a sequence of numbers. The median is the number separating the higher half of a data sample from the lower half.
- Fibonacci heap
- Merge sorted arrays (MergeSortedArray): [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/heap)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/heap)) | Merge k sorted arrays into one heap.
- Sort an increasing-decreasing array (SortIncreasingDecreasingArray): [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/heap)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/heap)) | Sort an array that is repeatedly increasing then decreasing.

### Linked list

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

- Add list-based integers (AddTwoNumbers): [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/linked_list)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/linked_list)) | Add two numbers represented by linked list.
- Delete a node from linked list (DeleteNodeFromList): [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/linked_list)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/linked_list)) | Delete a node from a linked list.
- Delete duplicate nodes from sorted linked list (DeleteDuplicateNode): [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/linked_list)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/linked_list)) | Delete duplicate nodes from a sorted linked list.
- Delete the k-th last node from linked list (DeleteNodeKthLast): [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/linked_list)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/linked_list)) | Delete the $k$-th last node from a linked list.
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

### Stack

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

- Pair of bracket (CheckPairOfBracket): [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/stack)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/stack)) | Checks if the input string contains bracket pairs and is well-formed.
- Print linked list in reverse order (PrintLinkedListInReverseOrder): [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/stack)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/stack)) | Print the linked list in reverse order using stack.
- Max stack element: [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/stack)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/stack)) | Implement stack that caches max value.

### Tree

The tree is a specific type of graph. A tree is an undirected graph in which any two vertices are connected by exactly one path. It is connected without cycles.

**C++ declaration/methods (binary search tree based)**

```cpp
auto map = std::map<std::string, int>{{"a", 1}, {"b", 2}};
insert({"c", 3}), emplace("d", 4), erase("a"), find("b"), size(), empty(), equal_range("c")
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
var treeMap = new TreeMap<String, Integer>(Map.of("a", 1, "b", 2, "c", 3));
put("a", 1), putIfAbsent("b", 2), get("a"), getOrDefault("f", 6), remove("a"), size(), isEmpty(),
keySet(), values(), entrySet(), containsKey("a"), containsValue(1), replace("a", 2), clear()
firstKey(), lastKey(), lowerKey("b"), higherKey("b"), floorKey("b"), ceilingKey("b"), pollFirstEntry(), pollLastEntry(),
headMap("c"), tailMap("c"), subMap("a", "c"), descendingMap(), descendingKeySet()
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
- B-tree: [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/tree)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/tree)) | B-tree is a self-balancing data structure which can have many child nodes. It is commonly used in auxiliary storage devices and database system. B-tree has the following properties: 1) Nodes have lower and upper bounds on the number of keys they can contain. (represent using degree $t$) 2) Every node other than the root must have at least $t-1$ keys. 3) Every node may contain at most $2t-1$ keys.
- Balanced tree status: [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/tree)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/tree)) | Whether the binary tree is balanced or not.
- Binary search tree: [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/tree)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/tree)) | In binary search tree, all internal nodes are stored in ordered state. If $y$ is a child of $x$ and $y$ is a node in the left subtree, then $y.key \leq x.key$, and if $y$ is a node in the right subtree, then $y.key \geq x.key$.
- Binary tree exterior (CreateExteriorNodeList): [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/tree)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/tree)) | Create a vector of exterior nodes in a binary tree.
- Construct binary tree from preorder and inorder traversal (ConstructTreeFromPreorderInorder): [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/tree)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/tree)) | Construct a binary search tree from preorder and inorder traversal. This task has $O(n)$ time complexity.
- Construct binary tree from preorder with marker (ConstructTreeFromMarkerPreorder): [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/tree)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/tree)) | Construct a binary search tree from preorder traversal with marker. This task has $O(n)$ time complexity.
- Leaf node list (CreateLeafNodeList): [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/tree)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/tree)) | Create a vector of leaf nodes in a binary tree.
- Lowest common ancestor (FindLowestCommonAncestor): [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/tree)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/tree)) | Find the lowest common ancestor of two nodes in a binary tree.
- Lowest common ancestor with parent pointer (FindLowestCommonAncestor2): [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/tree)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/tree)) | Find the lowest common ancestor of two nodes in a binary tree. The nodes have parent pointers.
- Populate right sibling (PopulateRightSibling): [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/tree)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/tree)) | Populate the right sibling of a binary tree.
- Red-black search tree
- Root to leaf path corresponding to the given sum (HasKeySum): [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/tree)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/tree)) | Whether the tree has a root-leaf path equal to the given sum.
- Sum of root to leaf (SumRootToLeafDecimal, SumRootToLeafBinary): [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/tree)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/tree)) | Sum of all root to leaf paths in a binary tree (decimal and binary representation).
- Tree symmetric: [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/tree)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/tree)) | Whether the binary tree is symmetric or not.
- Trie
- van Emde Boas tree (vEB tree)

## Topics

### Dynamic programming

**Examples**

- Fibonacci number: [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/dynamic_programming)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/dynamic_programming)) | Fibonacci sequence is a sequence of numbers where each number is the sum of the two preceding numbers. Fibonacci number is $n$th number in the sequence. The Fibonacci sequence is defined as follows:
    - $F_0 = 0$
    - $F_1 = 1$
    - $F_n = F_{n-1} + F_{n-2}$ (for $n > 1$)
- Interval subset sum: [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/problem_solving)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/problem_solving))
- Longest common subsequence: [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/dynamic_programming)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/dynamic_programming))
- Rod cutting: [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/dynamic_programming)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/dynamic_programming)) | Rod cutting is a problem of cutting a rod into pieces of a given length to determine the maximum profit.

### Greedy

**Examples**

- Activity selection: [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/greedy)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/greedy)) | Activity selection problem using greedy algorithm or recursive approach. This is similar to the Interval scheduling problem.
- Cashier's change: [python](https://github.com/codejsha/algorithm-examples/tree/main/python-algorithm/algorithm/greedy)([test](https://github.com/codejsha/algorithm-examples/tree/main/python-algorithm/test/greedy)) | Cashier's change problem is that finds the minimum number of coins required to make change for a given amount of money.
- Huffman code: [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/greedy)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/greedy)) | Huffman code constructs optimal prefix codes. This is always represented by a full binary tree.
- Interval scheduling: [python](https://github.com/codejsha/algorithm-examples/tree/main/python-algorithm/algorithm/greedy)([test](https://github.com/codejsha/algorithm-examples/tree/main/python-algorithm/test/greedy)) | Interval scheduling problem is that finds the minimum number of intervals required to schedule a set of activities(lectures).

### Mathematics

**Examples**

- Base expansion (base $b$ expansion of $n$): [python](https://github.com/codejsha/algorithm-examples/tree/main/python-algorithm/algorithm/math)([test](https://github.com/codejsha/algorithm-examples/tree/main/python-algorithm/test/math)) | Constructing the base $b$ expansion of an integer $n$. Such as binary, octal, decimal, hexadecimal expansion, etc.
- Binary operation (addition): [python](https://github.com/codejsha/algorithm-examples/tree/main/python-algorithm/algorithm/math)([test](https://github.com/codejsha/algorithm-examples/tree/main/python-algorithm/test/math))
- Combination: [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/math)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/math)) | Find the number of ways to choose $k$ items from $n$ items.
- Fast Fourier transform: Fast Fourier transform is a mathematical algorithm that finds the discrete Fourier transform of a set of real numbers.
- Greatest common divisor (GCD): [python](https://github.com/codejsha/algorithm-examples/tree/main/python-algorithm/algorithm/math)([test](https://github.com/codejsha/algorithm-examples/tree/main/python-algorithm/test/math)) | Find the greatest common divisor of two numbers.
- Inverse of matrix: Inverse of matrix is a mathematical algorithm that finds the inverse of a matrix.
- Least common multiple (LCM): [python](https://github.com/codejsha/algorithm-examples/tree/main/python-algorithm/algorithm/math)([test](https://github.com/codejsha/algorithm-examples/tree/main/python-algorithm/test/math)) | Find the least common multiple of two numbers.
- Matrix multiplication: [python](https://github.com/codejsha/algorithm-examples/tree/main/python-algorithm/algorithm/math)([test](https://github.com/codejsha/algorithm-examples/tree/main/python-algorithm/test/math)) | This is the product of two matrices.
- Miller-Rabin primality test: [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/math)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/math)) | Miller-Rabin primality test is a mathematical algorithm that finds whether a given number is prime.
- Permutation (Permutation): [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/math)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/math)) | Find the permutation of a set of items.
- Permutation (ApplyPermutationWithAdditionalSpace, ApplyPermutationBySwap): [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/math)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/math)) | Permute the elements of an array
- Permutation (InversePermutation): [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/math)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/math))
- Permutation (NextPermutation/PreviousPermutation): [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/math)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/math)) | Compute the next/previous permutation.
- Permutation (KthPermutation): [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/math)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/math)) | Compute the $k$-th permutation.
- Simplex algorithm: Simplex algorithm is a mathematical algorithm that finds the optimal solution to a linear programming problem.
- System of linear equations: System of linear equations is a mathematical algorithm that finds the solution to a system of linear equations.

### Primitive type

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

**C++ declaration/methods**

```cpp
auto map = std::map<std::string, int>{{"a", 1}, {"b", 2}};
insert({"c", 3}), emplace("d", 4), erase("a"), find("b"), size(), empty(), equal_range("c")
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

- Binary search: [python](https://github.com/codejsha/algorithm-examples/tree/main/python-algorithm/algorithm/search)([test](https://github.com/codejsha/algorithm-examples/tree/main/python-algorithm/test/search)) | Binary search is a search algorithm that finds the position of a target value within a sorted array.
- Linear search: [python](https://github.com/codejsha/algorithm-examples/tree/main/python-algorithm/algorithm/search)([test](https://github.com/codejsha/algorithm-examples/tree/main/python-algorithm/test/search)) | Linear search is a search algorithm that compares x successively with each term of the list until a match is found.
- Search a sorted array for the first greater than a key (SearchFirstGreaterThanKey): [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/search)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/search))
- Search a sorted array for the first occurrence of a key (SearchFirstOfKey): [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/search)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/search))

### Sort

**C++ declaration/methods**

```cpp
std::ranges::sort(v);         // introsort (quick sort + heap sort + insertion sort)
std::ranges::stable_sort(v);  // merge sort
```

**Python declaration/functions**

```python
number_list: list[int] = [1, 2, 3, 4, 5]
number_list.sort()      # in-place
sorted(number_list)     # return a new list(copy)
```

**Java declaration/methods**

```java
Arrays.sort(array);     // dual pivot quick sort (primitive types)
                        // timsort (insertion sort + merge sort) (reference types)
Collections.sort(list); // timsort (insertion sort + merge sort)
```

**Examples**

- Bubble sort: [java](https://github.com/codejsha/algorithm-examples/tree/main/java-algorithm/src/main/java/com/example/algorithm/sort)([test](https://github.com/codejsha/algorithm-examples/tree/main/java-algorithm/src/test/java/com/example/algorithm/sort))

| **Case**    | **Time complexity** | **Remarks**                   |
| :---------- | :-----------------: | :---------------------------- |
| **Best**    |       $O(n)$        | if the list is already sorted |
| **Worst**   |      $O(n^2)$       |                               |
| **Average** |      $O(n^2)$       |                               |

- Bucket sort: [java](https://github.com/codejsha/algorithm-examples/tree/main/java-algorithm/src/main/java/com/example/algorithm/sort)([test](https://github.com/codejsha/algorithm-examples/tree/main/java-algorithm/src/test/java/com/example/algorithm/sort))

| **Case**    | **Time complexity** | **Remarks** |
| ----------- | :-----------------: | ----------- |
| **Best**    |     $O(n + k)$      |             |
| **Worst**   |      $O(n^2)$       |             |
| **Average** |       $O(n)$        |             |

- Counting sort: [java](https://github.com/codejsha/algorithm-examples/tree/main/java-algorithm/src/main/java/com/example/algorithm/sort)([test](https://github.com/codejsha/algorithm-examples/tree/main/java-algorithm/src/test/java/com/example/algorithm/sort))

| **Case**    | **Time complexity** | **Remarks** |
| ----------- | :-----------------: | ----------- |
| **Best**    |     $O(n + k)$      |             |
| **Worst**   |     $O(n + k)$      |             |
| **Average** |     $O(n + k)$      |             |

- Heap sort: [java](https://github.com/codejsha/algorithm-examples/tree/main/java-algorithm/src/main/java/com/example/algorithm/sort)([test](https://github.com/codejsha/algorithm-examples/tree/main/java-algorithm/src/test/java/com/example/algorithm/sort))

| **Case**    | **Time complexity** | **Remarks** |
| ----------- | :-----------------: | ----------- |
| **Best**    |    $O(n log n)$     |             |
| **Worst**   |    $O(n log n)$     |             |
| **Average** |    $O(n log n)$     |             |

- Insertion sort: [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/sort)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/sort)), [java](https://github.com/codejsha/algorithm-examples/tree/main/java-algorithm/src/main/java/com/example/algorithm/sort)([test](https://github.com/codejsha/algorithm-examples/tree/main/java-algorithm/src/test/java/com/example/algorithm/sort)) | One of the fastest algorithms for sorting very small arrays (around 10 elements)

| **Case**    | **Time complexity** | **Remarks**                                                                        |
| ----------- | :-----------------: | ---------------------------------------------------------------------------------- |
| **Best**    |       $O(n)$        | * if the list is already sorted<br>* this case has linear running time             |
| **Worst**   |      $O(n^2)$       | * if the list is sorted in reverse order<br>* this case has quadratic running time |
| **Average** |      $O(n^2)$       | * this case has quadratic running time                                             |

- Merge sort: [java](https://github.com/codejsha/algorithm-examples/tree/main/java-algorithm/src/main/java/com/example/algorithm/sort)([test](https://github.com/codejsha/algorithm-examples/tree/main/java-algorithm/src/test/java/com/example/algorithm/sort)) | divide and conquer algorithm

| **Case**    | **Time complexity** | **Remarks**                                                                                              |
| ----------- | :-----------------: | -------------------------------------------------------------------------------------------------------- |
| **Best**    |    $O(n log n)$     | * running time of sorting for input length $n$ is $T(n)$<br>* $T(n) = 2T(n/2) + O(n) \approx O(n log n)$ |
| **Worst**   |    $O(n log n)$     |                                                                                                          |
| **Average** |    $O(n log n)$     |                                                                                                          |

- Quick sort: [java](https://github.com/codejsha/algorithm-examples/tree/main/java-algorithm/src/main/java/com/example/algorithm/sort)([test](https://github.com/codejsha/algorithm-examples/tree/main/java-algorithm/src/test/java/com/example/algorithm/sort)) | divide and conquer algorithm

| **Case**    | **Time complexity** | **Remarks** |
| ----------- | :-----------------: | ----------- |
| **Best**    |    $O(n log n)$     |             |
| **Worst**   |      $O(n^2)$       |             |
| **Average** |    $O(n log n)$     |             |

- Selection sort: [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/sort)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/sort)), [java](https://github.com/codejsha/algorithm-examples/tree/main/java-algorithm/src/main/java/com/example/algorithm/sort)([test](https://github.com/codejsha/algorithm-examples/tree/main/java-algorithm/src/test/java/com/example/algorithm/sort))

| **Case**    | **Time complexity** | **Remarks**                                                                            |
| ----------- | :-----------------: | -------------------------------------------------------------------------------------- |
| **Best**    |      $O(n^2)$       | * if the list is already sorted                                                        |
| **Worst**   |      $O(n^2)$       | * when sorted in ascending order, if you want to sort in descending order (vice versa) |
| **Average** |      $O(n^2)$       |                                                                                        |

### String

**C++ declaration/methods**

```cpp
auto str = std::string{"hello"};
append("_world"), push_back('!'), pop_back(), insert(5, "_world"), substr(0, 5), compare("hello_world")
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

- Convert string (IntToString, StringToInt): [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/string)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/string)) | Convert integer to string and vice versa.
- Finite automata
- IP address validation: [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/string)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/string)) | Validate IPv4 address that is in the form of `x.x.x.x` where `x` is a number between 0 and 255.
- Knuth-Morris-Pratt algorithm (KMP)
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
