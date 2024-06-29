# Algorithm Examples

<!-- markdownlint-disable MD033 MD036 -->

![C++ CMake Test](https://github.com/codejsha/algorithm-examples/actions/workflows/cmake.yml/badge.svg) ![Python Poetry Test](https://github.com/codejsha/algorithm-examples/actions/workflows/poetry.yml/badge.svg) ![Java Gradle Test](https://github.com/codejsha/algorithm-examples/actions/workflows/gradle.yml/badge.svg) ![Go Test](https://github.com/codejsha/algorithm-examples/actions/workflows/go.yml/badge.svg)

[English](README.md) | [Korean](README_ko-KR.md)

This repository is an implementation of algorithms, data structures, and problem-solving. These are written in C++, Python, Java, and Go, and each language uses the following test framework: [Google Test](https://google.github.io/googletest/)(C++), [pytest](https://docs.pytest.org/)(Python), [JUnit](https://junit.org/)(Java), [go test](https://pkg.go.dev/cmd/go)(Go). Run tests to perform methods/functions on the algorithmic logic.

## Project Environments

Each project is configured in specific environments, as described below:

| Language | Version | Build                                | Packages                                                                                                                                                                                                              | Remarks                                     |
| -------- | ------- | ------------------------------------ | --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | ------------------------------------------- |
| C++      | C++20   | [CMake](https://cmake.org/)          | [GNU Scientific Library (GSL)](https://www.gnu.org/software/gsl/), [Google Test](https://google.github.io/googletest/), [Google Benchmark](https://github.com/google/benchmark), [fmt](https://github.com/fmtlib/fmt) | [vcpkg](https://github.com/microsoft/vcpkg) |
| Python   | 3.12    | [Poetry](https://python-poetry.org/) | [NumPy](https://numpy.org/), [SciPy](https://www.scipy.org/), [NetworkX](https://networkx.org/), [pytest](https://docs.pytest.org/), [pytest-benchmark](https://pytest-benchmark.readthedocs.io/en/latest/)           |                                             |
| Java     | 21      | [Gradle](https://gradle.org/)        | [Google Guava](https://github.com/google/guava), [JUnit](https://junit.org/), [Java Microbenchmark Harness (JMH)](https://github.com/openjdk/jmh)                                                                     |                                             |
| Go       | 1.22    | [Go](https://pkg.go.dev/cmd/go)      | [Testify](https://github.com/stretchr/testify)                                                                                                                                                                        |                                             |

## Table of Contents

- [Project Environments](#project-environments)
- [Table of Contents](#table-of-contents)
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
  - [:jigsaw: Dynamic programming (DP)](#jigsaw-dynamic-programming-dp)
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
del(number_list[0:2])   # remove the slice
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
int[] arr = new int[]{1, 2, 3, 4, 5};   // array
int[][] matrix = new int[m][n];         // 2d array (m by n matrix)
```

```java
import java.util.*;

// Arrays
binarySearch(arr, 3), equals(arr, another_arr), copyOf(arr, arr.length), copyOfRange(arr, from, to),
sort(arr), sort(arr, from, to), fill(arr, 42), fill(arr, from, to, 42),
// Arrays.stream()
anyMatch(x -> x % 2 == 0), allMatch(x -> x % 2 == 0), noneMatch(x -> x % 2 == 0),
count(), sum(), min(), max(), average(), map(x -> x * 2).toArray(), filter(x -> x % 2 == 0).count()

// Collections
sort(list), binarySearch(list, 3), min(list), max(list), swap(list, 0, 1), replaceAll(list, 1, 2),
frequency(list, 1), reverse(list), rotate(list, 1), shuffle(list), unmodifiableList(list)

// list
var list = Arrays.asList(boxedArray);
Arrays.stream(arr).boxed().collect(Collectors.toList())
sort(), sort(Comparator.naturalOrder()), sort(Comparator.reverseOrder())

// string
String.join(", ", arr)                          // array to string
str.split(""), str.split(" "), str.split(", ")  // string to array
str.toCharArray()                               // string to char array
str.chars().toArray()                           // string to int array

// boxing
var arr1 = Arrays.stream(arr).boxed().toArray(Integer[]::new);                     // int[] to Integer[]
var arr2 = Arrays.stream(arr).mapToObj(String::valueOf).toArray(String[]::new);    // int[] to String[]
var arr3 = Arrays.stream(arr).boxed().collect(Collectors.toList());                // int[] to List<Integer>

// integer sequence
var arr = IntStream.range(0, n).toArray();          // range to int array in [0, n)
var arr = IntStream.rangeClosed(1, n).toArray();    // range to int array in [1, n]
var list = IntStream.range(0, n).boxed().toList();  // range to list

var list = List.of(arr);        // array to list
var list = Arrays.asList(arr);  // array to list
var arr = strList.toArray(String[]::new);  // List<String> to String[]
var arr = intList.stream().mapToInt(Integer::intValue).toArray();  // List<Integer> to int[]
var list = Arrays.stream(arr).boxed().sorted().collect(Collectors.toCollection(ArrayList::new));    // array to sorted list

// guava
import com.google.common.collect.*;
List<String> list = Lists.newArrayList();
List<String> list = Lists.asList(boxedArray);
```

**Examples**

- Advancing through an array, EPI#5.4: [c++](cpp-algorithm/src/array) | Advance through the array to the last index.
- Arbitrary precision operation - increment an arbitrary-precision integer, EPI#5.2: [c++](cpp-algorithm/src/array)(`PlusOne`) | Add one to the number represented by the vector.
- Arbitrary precision operation - add two arbitrary-precision integers: [c++](cpp-algorithm/src/array)(`StringAddition`) | Add two numbers represented by strings.
- Arbitrary precision operation - multiply two arbitrary-precision integers, EPI#5.3: [c++](cpp-algorithm/src/array)(`Multiply`) | Multiply two numbers represented by vectors.
- Delete duplicates from a sorted array, EPI#5.5: [c++](cpp-algorithm/src/array)(`DeleteDuplicates`) | Delete duplicate elements in the array.
- Delete duplicates from a sorted array: [c++](cpp-algorithm/src/array)(`DeleteDuplicateElements`) | Delete duplicate elements in the array.
- Delete specific elements from a sorted array: [c++](cpp-algorithm/src/array)(`DeleteSpecificElements`) | Delete specific elements in the array.
- Dutch national flags problem, EPI#5.1: [c++](cpp-algorithm/src/array)
- Enumerate prime numbers, EPI#5.9: [c++](cpp-algorithm/src/array) | Enumerate prime numbers in the range.
- Order elements in an array by even and odd: [c++](cpp-algorithm/src/array)(`EvenOdd`) | Order even and odd numbers in the array.
- Order elements in an array by specified order, EPI#5.8: [c++](cpp-algorithm/src/array)(`Rearrange`) | Rearrange arrays to have a specific order.
- Random data sampling - offline, EPI#5.12: [c++](cpp-algorithm/src/array)(`OfflineRandomSampling`) | Randomly select _k_ elements from the array.
- Random data sampling - compute permutation, EPI#5.14: [c++](cpp-algorithm/src/array)(`ComputeRandomPermutation`) | Compute permutation of the array generated by random sampling.
- Replace elements - replace and remove: [c++](cpp-algorithm/src/array)(`ReplaceAndRemoveString1`) | Replace element and remove element in the array. Keep the array size.
- Replace elements - replace and remove: [c++](cpp-algorithm/src/array)(`ReplaceAndRemoveString2`) | Replace element and remove element in the array
- Replace elements - telex encoding: [c++](cpp-algorithm/src/array)(`TelexEncoding`) | Telex encoding for punctuation marks.
- Stock trading - buy and sell a stock once, EPI#5.6: [c++](cpp-algorithm/src/array)(`BuyAndSellStockOnceBruteForce`, `BuyAndSellStockOnce`)
- Stock trading - buy and sell a stock twice, EPI#5.7: [c++](cpp-algorithm/src/array)(`BuyAndSellStockTwice`)

[:arrow_up_small: back to toc](#table-of-contents)

### :chart_with_upwards_trend: Graph

- Shortest path algorithm
  - Single-source: Bellman-Ford algorithm, Dijkstra's algorithm
  - Single-pair: A\* search algorithm
  - All-pair: Floyd-Warshall algorithm, Johnson's algorithm
- Minimum spanning tree algorithm: Kruskal's algorithm, Prim's algorithm
- Maximum flow algorithm: Edmonds-Karp algorithm, Ford-Fulkerson algorithm, Push-relabel algorithm, Maximum bipartite matching

**Python declaration/functions**

```python
# networkx
import networkx
graph = networkx.Graph()

# edges
edges = [(seattle, chicago), (seattle, san_francisco), ...]
graph.add_edges_from(edges)

# weighted edges
weighted_edges = [(seattle, chicago, 1737), (seattle, san_francisco, 678), ...]
graph.add_weighted_edges_from(weighted_edges)

# operations
networkx.bfs_layers(graph, "Boston")
networkx.minimum_spanning_tree(graph, algorithm="kruskal")
networkx.dijkstra_path(graph, "Los Angeles", "Boston")
```

**Java declaration/methods**

```java
// guava graph
import com.google.common.graph.*;
MutableGraph<Integer> graph = GraphBuilder.undirected().build();
MutableValueGraph<City, Distance> roads = ValueGraphBuilder.directed()
        .incidentEdgeOrder(ElementOrder.stable())
        .build();
```

**Graph algorithms**

- A\* search algorithm, CCSP#2.2.5: A single-pair shortest path algorithm. This is a variant of Dijkstra's algorithm using heuristics to try to speed up the search.
- Bellman-Ford algorithm, CLRS#24.1: [c++](cpp-algorithm/src/graph), [java](java-algorithm/src/main/java/com/example/algorithm/graph) | A single source the shortest path algorithm that can handle negative edge weights. It finds the shortest path from a source vertex to all other vertices in a weighted graph.

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

- Breadth-first search (BFS), CLRS#22.2, CCSP#2.2.4, CCSP#4.3.1: [c++](cpp-algorithm/src/graph), [java](java-algorithm/src/main/java/com/example/algorithm/graph), [python(test)](python-algorithm/algorithm/graph/test) | A search algorithm that traverses a graph layer by layer. Check the shortest path and compute the distance from the source vertex to all other vertices.

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

- Depth-first search (DFS), CLRS#22.3, CCSP#2.2.3: [c++](cpp-algorithm/src/graph), [java](java-algorithm/src/main/java/com/example/algorithm/graph) | A search algorithm that traverses a graph by exploring as far as possible along each branch before backtracking. Check to exists cycle in a graph.

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

- Dijkstra's algorithm, CLRS#24.3, CCSP#4.5.1: [c++](cpp-algorithm/src/graph), [python(test)](python-algorithm/algorithm/graph/test), [java](java-algorithm/src/main/java/com/example/algorithm/graph) | A single source the shortest path algorithm that handle non-negative edge weights. It finds the shortest path between two vertices in a graph.

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
- Floyd-Warshall algorithm, CLRS#25.2: [java](java-algorithm/src/main/java/com/example/algorithm/graph) | A all pairs shortest paths algorithm.

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

- Ford-Fulkerson algorithm, CLRS#26.2
- Johnson's algorithm, CLRS#25.3: A all pairs shortest paths algorithm. This is a combination of Dijkstra's algorithm and the Bellman-Ford algorithm. It may be faster than Floyd–Warshall on sparse graphs.
- Kruskal's algorithm, CLRS#23.2, CLRS#21.1: [java](java-algorithm/src/main/java/com/example/algorithm/graph) | A minimum spanning tree algorithm. It finds a minimum spanning forest of an undirected edge-weighted graph. The algorithm uses path compression (FIND-SET) and union by rank (UNION) to improve the performance.

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

- Maximum bipartite matching, CLRS#26.3
- Prim's algorithm, CLRS#23.2: [java](java-algorithm/src/main/java/com/example/algorithm/graph) | A minimum spanning tree algorithm. It is a greedy algorithm that finds a minimum spanning tree for a weighted undirected graph.

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

- Push-relabel algorithm, CLRS#26.4
- Viterbi algorithm: Shortest stochastic path algorithm. It solves with additional probabilistic weights on each node.

**Examples**

- Maze problem: [java](java-algorithm/src/main/java/com/example/algorithm/graph) | A maze problem is that find a path from the start to the goal. The maze is represented by a graph. The start and the goal are represented by vertices. The path is represented by a sequence of vertices.
- Minimum spanning tree (Kruskal, Prim, Boruvka), CLRS#23, CCSP#4.4.2: [python(test)](python-algorithm/algorithm/graph/test) | Find the minimum spanning tree of a graph. cf. Kruskal(CLRS#23.2, CLRS#21.1), Prim(CLRS#23.2)

[:arrow_up_small: back to toc](#table-of-contents)

### :key: Hash table

(CLRS#11)

**C++ declaration/methods**

```cpp
// map
auto map = std::unordered_map<std::string, int>{{"a", 1}, {"b", 2}};
insert({"c", 3}), emplace("d", 4), find("b"), end(), erase("a"), size(), empty()

// set
auto set = std::unordered_set{1, 2, 3, 4, 5};
insert(42), emplace(42), find(42), end(), erase(42), size(), empty()

// tuple
auto t1 = std::tuple{-1, -1};
auto t2 = std::make_tuple(-1, -1);
auto [x, y] = t1;

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
import java.util.*;

// map
Map<String, Integer> map = new HashMap<>();
put("a", 1), putIfAbsent("b", 2), get("a"), getOrDefault("f", 6), remove("a"), size(), isEmpty(),
keySet(), values(), entrySet(), containsKey("a"), containsValue(1), replace("a", 2), clear()
var keys = map.keySet().toArray(String[]::new);
var values = map.values().toArray(Integer[]::new);

// set
Set<Integer> set = new HashSet<>();
add(1), remove(1), size(), isEmpty(), contains(1), clear(), iterator()
var arr = set.toArray(Integer[]::new);

// enum map
Map<City, Integer> map = new EnumMap<>(City.class);

// linked hash map, linked hash set
Map<String, Integer> map = new LinkedHashMap<>();
Set<Integer> set = new LinkedHashSet<>();

// unboxing
int[] result = map.entrySet().stream()
        .sorted(Map.Entry.comparingByValue(Comparator.reverseOrder()))
        .map(Map.Entry::getKey)
        .mapToInt(Integer::parseInt)
        .toArray();

// guava
import com.google.common.collect.*;
Map<String, Integer> map = Maps.newHashMap();
Set<Integer> set = Sets.newHashSet();
Map<City, Country> map = Maps.newEnumMap(City.class);
Map<String, Integer> map = Maps.newLinkedHashMap();
Set<Integer> set = Sets.newLinkedHashSet();

// guava multiset (implements Multiset<E>)
Multiset<String> multiset = HashMultiset.create();
Multiset<String> multiset = TreeMultiset.create();
Multiset<String> multiset = LinkedHashMultiset.create();
Multiset<String> multiset = ConcurrentHashMultiset.create();
Multiset<String> multiset = ImmutableMultiset.of("a", "b", "c");

// guava multimap (implements Multimap<K, V>)
Multimap<String, Integer> multimap = ArrayListMultimap.create();
Multimap<String, Integer> multimap = HashMultimap.create();
Multimap<String, Integer> multimap = LinkedListMultimap.create();
Multimap<String, Integer> multimap = LinkedHashMultimap.create();
Multimap<String, Integer> multimap = TreeMultimap.create();
Multimap<String, Integer> multimap = ImmutableListMultimap.of("a", 1, "a", 2, "b", 3);
Multimap<String, Integer> multimap = ImmutableSetMultimap.of("a", 1, "a", 2, "b", 3);

// guava bimap (implements BiMap<K, V>, Map<K, V>)
BiMap<String, Integer> bimap = HashBiMap.create();
BiMap<String, Integer> bimap = ImmutableBiMap.of("a", 1, "b", 2);
BiMap<City, Country> bimap = EnumBiMap.create(City.class, Country.class);
BiMap<City, Integer> bimap = EnumHashBiMap.create(City.class);

// guava table (implements Table<R, C, V>)
Table<Vertex, Vertex, Double> weightedGraph = HashBasedTable.create();
Table<Vertex, Vertex, Double> weightedGraph = TreeBasedTable.create();
Table<Vertex, Vertex, Double> weightedGraph = ArrayTable.create(Arrays.asList(v1, v2), Arrays.asList(v3, v4));
Table<Vertex, Vertex, Double> weightedGraph = ImmutableTable.of(v1, v2, 4.0);
```

**Examples**

- Anonymous letter constructible, EPI#12.2: [c++](cpp-algorithm/src/hashtable)(`IsLetterConstructibleFromMagazine`) | Check if a letter can be written using the characters in a magazine.
- Anonymous words constructible: [c++](cpp-algorithm/src/hashtable)(`IsWordConstructibleFromMagazine`) | Check if a letter can be written using the words in a magazine.
- Collatz conjecture, EPI#12.11: [c++](cpp-algorithm/src/hashtable)(`FindNumbersSatisfyingCollatzConjecture`) | Find the numbers satisfying the Collatz conjecture.
- Find anagrams: [c++](cpp-algorithm/src/hashtable)(`FindAnagramMappings`) | Given an array of strings, group anagrams together.
- Find the smallest subarray covering all values, EPI#12.6: [c++](cpp-algorithm/src/hashtable)(`FindSmallestSubarrayCoveringSubset`) | Find the smallest subarray that covers all the elements in a set.
- Find the smallest subarray sequentially covering all values, EPI#12.7: [c++](cpp-algorithm/src/hashtable)(`FindSmallestSubarraySequentiallyCoveringSubset`) | Find the smallest subarray that sequentially covers all the elements in a set.
- ISBN cache, EPI#12.3: [c++](cpp-algorithm/src/hashtable) | Implement an LRU (Least Recently Used) cache for ISBN lookups.
- Nearest repeated entry, EPI#12.5: [c++](cpp-algorithm/src/hashtable)(`FindNearestRepeatedEntry`) | Find the nearest repeated entry in an array of strings.
- Optimized the lowest common ancestor, EPI#12.4: [c++](cpp-algorithm/src/hashtable)(`FindOptimizedLowestCommonAncestor`) | Find the lowest common ancestor of two nodes in a binary tree using a hash table. This traverses together until node1 and node2 meet.
- Palindromic permutation, EPI#12.1: [c++](cpp-algorithm/src/hashtable)(`IsPalindromePermutation`) | Given a string, determine if a permutation of the string could form a palindrome.

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
import java.util.*;
Queue<Integer> queue = new PriorityQueue<>();
Queue<Integer> queue = new PriorityQueue<>(Collections.reverseOrder());
add(1), peek(), poll(), remove(), size(), isEmpty(),
contains(1), clear(), iterator()

// guava
import com.google.common.collect.*;
Queue<Integer> queue = Queues.newPriorityQueue();
```

**Heap algorithms**

- Fibonacci heap, CLRS#19

**Examples**

- Compute the k closest stars: [c++](cpp-algorithm/src/heap)(`FindClosestStar`) | Find the $k$ closest stars to the earth. The stars are represented by a sequence of points(coordinates).
- Compute the median of a sequence of numbers: [c++](cpp-algorithm/src/heap)(`FindMedian`) | Find the median of a sequence of numbers. The median is the number separating the higher half of a data sample from the lower half.
- Merge sorted arrays: [c++](cpp-algorithm/src/heap)(`MergeSortedArray`) | Merge k sorted arrays into one heap.
- Sort an increasing-decreasing array: [c++](cpp-algorithm/src/heap)(`SortIncreasingDecreasingArray`) | Sort an array that is repeatedly increasing then decreasing.

[:arrow_up_small: back to toc](#table-of-contents)

### :paperclips: Linked list

A linked list is a data structure that consists of a sequence of elements, where each element points to the next. (CLRS#10.2)<br>In Python, there is no built-in type or library for LinkedList.

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
import java.util.*;

// doubly linked list
List<Integer> list = new LinkedList<>();
add(1), addAll(List.of(2, 3, 4, 5)),
remove(0), removeFirst(), removeLast(), removeIf(x -> x % 2 == 0), subList(1, 3),
get(0), getFirst(), getLast(), size(), isEmpty(), contains(1), containsAll(List.of(1, 2, 3)),
iterator(), listIterator()

// dynamically resized array
List<Integer> list = new ArrayList<>();
add(1), addAll(List.of(2, 3, 4, 5)), remove(0), subList(1, 3),
get(0), size(), isEmpty(), contains(3), containsAll(List.of(3, 4)),
iterator(), listIterator()

// guava
import com.google.common.collect.*;
List<Integer> list = Lists.newLinkedList();
List<Integer> list = Lists.newArrayList();
```

**Examples**

- Add list-based integers, EPI#7.13: [c++](cpp-algorithm/src/linkedlist)(`AddTwoNumbers`) | Add two numbers represented by linked list.
- Delete a node from linked list, EPI#7.6: [c++](cpp-algorithm/src/linkedlist)(`DeleteNodeFromList`) | Delete a node from a linked list.
- Delete duplicate nodes from sorted linked list, EPI#7.8: [c++](cpp-algorithm/src/linkedlist)(`DeleteDuplicateNode`) | Delete duplicate nodes from a sorted linked list.
- Delete the k-th last node from linked list, EPI#7.7: [c++](cpp-algorithm/src/linkedlist)(`DeleteNodeKthLast`) | Delete the $k$-th last node from a linked list.
- Implement cyclic right shift for a singly linked list, EPI#7.9: [c++](cpp-algorithm/src/linkedlist)(`CyclicallyRightShiftList`) | Implement cyclic right shift for a singly linked list.
- Linked list has a cycle, EPI#7.3: [c++](cpp-algorithm/src/linkedlist)(`HasCycle1`, `HasCycle2`, `HasCycle3`) | Determine that a linked list has a cycle.
- List pivoting, EPI#7.12: [c++](cpp-algorithm/src/linkedlist)(`ListPivoting`) | Rearrange nodes smaller than pivot to the left and larger than pivot to the right.
- Merge even and odd nodes in linked list, EPI#7.10: [c++](cpp-algorithm/src/linkedlist)(`MergeEvenOddLinkedList`) | Merge even and odd nodes in a singly linked list.
- Merge two sorted linked lists, EPI#7.1: [c++](cpp-algorithm/src/linkedlist)(`MergeTwoSortedLinkedList`) | Merge two sorted linked lists. In worst-case, this task has $O(n + m)$ time complexity, where $n$ and $m$ are the length of the lists.
- Palindrome list, EPI#7.11: [c++](cpp-algorithm/src/linkedlist)(`IsListPalindrome`) | Determine that a linked list is a palindrome.
- Reverse a single sublist, EPI#7.2: [c++](cpp-algorithm/src/linkedlist)(`ReverseSubList`) | Reverse a single sublist of a linked list.
- Two linked lists overlap, EPI#7.4: [c++](cpp-algorithm/src/linkedlist)(`OverlappingNoCycleList`) | Determine that two linked lists without cycle overlap.
- Two linked lists with cycles overlap, EPI#7.5 [c++](cpp-algorithm/src/linkedlist)(`OverlappingCycleList`) | Determine that two linked lists with cycle overlap.

[:arrow_up_small: back to toc](#table-of-contents)

### :walking: Queue

A queue is a data structure that implements the FIFO (first-in, first-out) policy. It has the following operations: enqueue (insert an element), dequeue (delete the least recently inserted element). (CLRS#10.1)

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
import java.util.*;
Deque<Integer> deque = new ArrayDeque<>();
add(1), remove(), pop(), size(), isEmpty(), contains(1), clear(),
offerFirst(6), offerLast(7), pollFirst(), pollLast(), peekFirst(), peekLast(),
addFirst(8), addLast(9), removeFirst(), removeLast(), getFirst(), getLast(),
iterator(), descendingIterator()

var array = deque.toArray(Integer[]::new);  // deque to array
var list = new ArrayList<>(deque);          // deque to list

// guava
import com.google.common.collect.*;
Deque<Integer> deque = Queues.newArrayDeque();
```

**Examples**

[:arrow_up_small: back to toc](#table-of-contents)

### :hamburger: Stack

A stack is a data structure that implements the LIFO (last-in, first-out) policy. It has the following operations: push (insert an element), pop (delete the most recently inserted element). (CLRS#10.1)

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
import java.util.*;
Stack<Integer> stack = new Stack<>();
push(1), add(1, 2), addAll(anotherList), pop(), peek(), size(), isEmpty(),
contains(1), search(1), size(),
remove(1), removeIf(x -> x == 1), clear(),
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
import java.util.*;

// tree map (based on red-black tree)
Map<Integer, Integer> map = new TreeMap<>();
Map<Integer, Integer> map = new TreeMap<>(Collections.reverseOrder());
Map<String, Integer> map = new TreeMap<>(Map.of("a", 1, "b", 2, "c", 3));
put("a", 1), putIfAbsent("b", 2), get("a"), getOrDefault("f", 6), remove("a"), size(), isEmpty(),
keySet(), values(), entrySet(), containsKey("a"), containsValue(1), replace("a", 2), clear()
firstKey(), lastKey(), lowerKey("b"), higherKey("b"), floorKey("b"), ceilingKey("b"),pollFirstEntry(), pollLastEntry(),
headMap("c"), tailMap("c"), subMap("a", "c"), descendingMap(), descendingKeySet()

// tree set (based on red-black tree)
Set<Integer> set = new TreeSet<>();
Set<Integer> set = new TreeSet<>(Collections.reverseOrder());
Set<Integer> set = new TreeSet<>(List.of(1, 2, 3, 4, 5));
add(1), remove(1), size(), isEmpty(), contains(1), clear(), iterator(), descendingIterator(),
first(), last(), lower(3), higher(3), floor(3), ceiling(3), pollFirst(), pollLast(),
headSet(3), tailSet(3), subSet(2, 4), descendingSet()

// guava
import com.google.common.collect.*;
Map<Integer, Integer> map = Maps.newTreeMap();
Set<Integer> set = Sets.newTreeSet();
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

**Tree algorithms**

- AVL tree
- B-tree, CLRS#18: [c++](cpp-algorithm/src/tree) | B-tree is a self-balancing data structure which can have many child nodes. It is commonly used in auxiliary storage devices and database system. B-tree has the following properties: 1) Nodes have lower and upper bounds on the number of keys they can contain. (represent using degree $t$) 2) Every node other than the root must have at least $t-1$ keys. 3) Every node may contain at most $2t-1$ keys.
- Binary search tree, CLRS#12: [c++](cpp-algorithm/src/tree) | In binary search tree, all internal nodes are stored in ordered state. If $y$ is a child of $x$ and $y$ is a node in the left subtree, then $y.key \leq x.key$, and if $y$ is a node in the right subtree, then $y.key \geq x.key$.
- Red-black tree, CLRS#13
- Trie
- van Emde Boas tree (vEB tree), CLRS#20

**Examples**

- Balanced tree status: [c++](cpp-algorithm/src/tree) | Whether the binary tree is balanced or not.
- Binary tree exterior: [c++](cpp-algorithm/src/tree)(`CreateExteriorNodeList`) | Create a vector of exterior nodes in a binary tree.
- Construct binary tree from preorder and inorder traversal: [c++](cpp-algorithm/src/tree)(`ConstructTreeFromPreorderInorder`) | Construct a binary search tree from preorder and inorder traversal. This task has $O(n)$ time complexity.
- Construct binary tree from preorder with marker: [c++](cpp-algorithm/src/tree)(`ConstructTreeFromMarkerPreorder`) | Construct a binary search tree from preorder traversal with marker. This task has $O(n)$ time complexity.
- Leaf node list: [c++](cpp-algorithm/src/tree)(`CreateLeafNodeList`) | Create a vector of leaf nodes in a binary tree.
- Lowest common ancestor: [c++](cpp-algorithm/src/tree)(`FindLowestCommonAncestor`) | Find the lowest common ancestor of two nodes in a binary tree.
- Lowest common ancestor with parent pointer: [c++](cpp-algorithm/src/tree)(`FindLowestCommonAncestor2`) | Find the lowest common ancestor of two nodes in a binary tree. The nodes have parent pointers.
- Populate right sibling: [c++](cpp-algorithm/src/tree)(`PopulateRightSibling`) | Populate the right sibling of a binary tree.
- Root to leaf path corresponding to the given sum: [c++](cpp-algorithm/src/tree)(`HasKeySum`) | Whether the tree has a root-leaf path equal to the given sum.
- Sum of root to leaf: [c++](cpp-algorithm/src/tree)(`SumRootToLeafDecimal`, `SumRootToLeafBinary`) | Sum of all root to leaf paths in a binary tree (decimal and binary representation).
- Tree symmetric: [c++](cpp-algorithm/src/tree) | Whether the binary tree is symmetric or not.

[:arrow_up_small: back to toc](#table-of-contents)

## Topics

### :jigsaw: Dynamic programming (DP)

(CLRS#15)

**Examples**

- Fibonacci number, CCSP#1.1: [c++](cpp-algorithm/src/dp),[python](python-algorithm/algorithm/dp) | Fibonacci sequence is a sequence of numbers where each number is the sum of the two preceding numbers. Fibonacci number is $n$th number in the sequence. The Fibonacci sequence is defined as follows:
  - $F_0 = 0$
  - $F_1 = 1$
  - $F_n = F_{n-1} + F_{n-2}$ (for $n > 1$)
- Interval subset sum (`SubsetSum1`, `SubsetSum2`, `DivideAndConquerSubsetSum`, `DynamicProgrammingSubsetSum`): [c++](cpp-algorithm/src/dp) | Interval subset sum problem is that finds the maximum sum of a subset of intervals.
- Longest common subsequence, CLRS#15.4: [c++](cpp-algorithm/src/dp)
- Rod cutting, CLRS#15.1: [c++](cpp-algorithm/src/dp) | Rod cutting is a problem of cutting a rod into pieces of a given length to determine the maximum profit.

[:arrow_up_small: back to toc](#table-of-contents)

### :clock9: Greedy

(CLRS#16)

**Examples**

- Activity selection problem, CLRS#16.1: [c++](cpp-algorithm/src/greedy) | Activity selection problem using greedy algorithm or recursive approach. This is similar to the Interval scheduling problem.
- Cashier's change: [python](python-algorithm/algorithm/greedy) | Cashier's change problem is that finds the minimum number of coins required to make change for a given amount of money.
- Huffman code, CLRS#16.3: [c++](cpp-algorithm/src/greedy) | Huffman code constructs optimal prefix codes. This is always represented by a full binary tree.
- Interval scheduling: [python](python-algorithm/algorithm/greedy) | Interval scheduling problem is that finds the minimum number of intervals required to schedule a set of activities(lectures).

[:arrow_up_small: back to toc](#table-of-contents)

### :triangular_ruler: Mathematics

**C++ declaration/methods**

```cpp
std::numeric_limits<int>::min(), std::numeric_limits<float>::max(), std::numeric_limits<double>::infinity()
std::abs(-34), std::fabs(-3.14), std::ceil(2.17), std::floor(3.14), std::min(x, -4), std::max(3.14, y), pow(2.17, 3.14), log(7.12), sqrt(225) // cmath
```

**Python declaration/functions**

```python
float('inf'), float('-inf'), math.inf, -math.inf
math.fabs(-34.5), math.ceil(2.17), math.floor(3.14), math.max(x, -3), math.min(x, 3.14), math.pow(2.71, 3.15), math.round(3.14), math.sqrt(225) # math
```

**Java declaration/methods**

```java
Integer.MIN_VALUE, Float.MAX_VALUE, Double.POSITIVE_INFINITY, Double.NEGATIVE_INFINITY, Boolean.TRUE
Math.abs(-34.5), Math.ceil(2.17), Math.floor(3.14), Math.max(x, -3), Math.min(x, 3.14), Math.pow(2.71, 3.15), Math.round(3.14), Math.sqrt(225) // math
```

**Mathematical algorithms**

- Combination: [c++](cpp-algorithm/src/math)(`GenerateCombination`) | Find the number of ways to choose $k$ items from $n$ items.
- Fast Fourier transform: Fast Fourier transform is a mathematical algorithm that finds the discrete Fourier transform of a set of real numbers.
- Greatest common divisor (GCD), CLRS#31.2: [python](python-algorithm/algorithm/math), [java](java-algorithm/src/main/java/com/example/algorithm/math), [go](go-algorithm/pkg/math) | Find the greatest common divisor of two numbers.
- Integer factorization: [c++](cpp-algorithm/src/math), [java](java-algorithm/src/main/java/com/example/algorithm/math) | Integer factorization is the process of determining which prime numbers divide a given positive integer.
- Least common multiple (LCM): [python](python-algorithm/algorithm/math), [java](java-algorithm/src/main/java/com/example/algorithm/math), [go](go-algorithm/pkg/math) | Find the least common multiple of two numbers.
- Miller-Rabin primality test, CLRS#31.8: [c++](cpp-algorithm/src/math) | Miller-Rabin primality test is a mathematical algorithm that finds whether a given number is prime.
- Permutation: [c++](cpp-algorithm/src/math)(`Permutation`) | Find the permutation of a set of items.
- Permutation, EPI#5.10: [c++](cpp-algorithm/src/math)(`ApplyPermutationWithAdditionalSpace`, `ApplyPermutationBySwap`) | Permute the elements of an array
- Permutation: [c++](cpp-algorithm/src/math)(`InversePermutation`)
- Permutation, EPI#5.11: [c++](cpp-algorithm/src/math)(`NextPermutation`, `PreviousPermutation`) | Compute the next/previous permutation.
- Permutation, EPI#5.11: [c++](cpp-algorithm/src/math)(`KthPermutation`) | Compute the $k$-th permutation.
- Prime number: [java](java-algorithm/src/main/java/com/example/algorithm/math)(`isPrime`) | Check whether a given number is prime.
- Simplex algorithm: Simplex algorithm is a mathematical algorithm that finds the optimal solution to a linear programming problem.
- System of linear equations: System of linear equations is a mathematical algorithm that finds the solution to a system of linear equations.

**Examples**

- Base expansion (base $b$ expansion of $n$): [python](python-algorithm/algorithm/math) | Constructing the base $b$ expansion of an integer $n$. Such as binary, octal, decimal, hexadecimal expansion, etc.
- Binary operation: [python](python-algorithm/algorithm/math)(`addition`)
- Inverse of matrix: Inverse of matrix is a mathematical algorithm that finds the inverse of a matrix.
- Matrix multiplication: [python](python-algorithm/algorithm/math) | This is the product of two matrices.

[:arrow_up_small: back to toc](#table-of-contents)

### :1234: Primitive type

**C++ declaration/methods**

```cpp
std::to_string(42), std::swap(x, y)
std::numeric_limits<int>::min(), std::numeric_limits<float>::max(), std::numeric_limits<double>::infinity()
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
float('inf'), float('-inf'), math.inf, -math.inf
math.fabs(-34.5), math.ceil(2.17), math.floor(3.14), math.max(x, -3), math.min(x, 3.14), math.pow(2.71, 3.15), math.round(3.14), math.sqrt(225) # math
abs(-34), min(number_list), max(number_list), sum(number_list), sorted(number_list)
len(sample_string), len(number_list), len(sample_dict)  # length
str(42), str(3.14), str(True)           # int/float/bool -> string
int("42"), float("3.14"), bool("true")  # string -> int/float/bool
int("1000010", 2), int("52", 8), int("2a", 16)  # string -> binary/octal/hex
bin(42), oct(42), hex(42)       # int -> binary/octal/hex
ascii('a'), chr(97), ord('a')   # unicode <-> ascii code

# copy
copy.deepcopy(number_list) # deep copy
copy.copy(number_list)     # shallow copy

# random
random.randrange(28)       # [0, 28)
random.randrange(1, 100)   # [1, 100)
random.randrange(8, 16)    # [8, 16)
random.randrange(8, 16, 2) # [8, 16) with step 2
random.shuffle(number_list)
random.choice(number_list)
```

**Java declaration/methods**

```java
Integer.MIN_VALUE, Float.MAX_VALUE, Double.POSITIVE_INFINITY, Double.NEGATIVE_INFINITY, Boolean.TRUE
Math.abs(-34.5), Math.ceil(2.17), Math.floor(3.14), Math.max(x, -3), Math.min(x, 3.14), Math.pow(2.71, 3.15), Math.round(3.14), Math.sqrt(225) // math
Integer.valueOf("1"), Double.valueOf("3.14"), Boolean.valueOf("true"), Float.toString(3.14f)  // reference type
Integer.parseInt("42"), Double.parseDouble("3.14")  // primitive type
Double.compare(x, 1.23) == 0, Integer.compare(x, 2) == 0  // comparing values

// bitwise operation
Integer.parseInt("1000010", 2), Integer.parseInt("52", 8), Integer.parseInt("2a", 16) // string -> binary/octal/hex
Integer.toBinaryString(42), Integer.toHexString(42), Integer.toOctalString(42)      // int -> binary/hex/octal string
Integer.toString(num, base)     // int -> string with base
Integer.bitCount(42)            // number of 1-bits
Long.parseLong("1000010", 2), Long.parseLong("52", 8), Long.parseLong("2a", 16) // string -> binary/octal/hex
Long.toBinaryString(42), Long.toHexString(42), Long.toOctalString(42)       // long -> binary/hex/octal string
Long.toString(num, base)    // long -> string with base
Long.bitCount(42)           // number of 1-bits

// bitset
import java.util.*;
new BitSet(16), set(0), set(0, 8), set(0, 8, true)

// hex digits
import java.util.*;
HexFormat hex = HexFormat.of();
byte b = 127;
String byteStr = hex.toHexDigits(b);

// random values
import java.util.Random;
var random = new Random();
var randomInt = random.nextInt(100);      // [0, 100)
var randomLong = random.nextLong();       // [0, 2^48)
var randomDouble = random.nextDouble();   // [0.0, 1.0)
var randomBoolean = random.nextBoolean(); // true/false
```

**Primitive type algorithms**

- Arithmetic operation, EPI#4.5, EPI#4.6: [c++](cpp-algorithm/src/primitive)(`Multiply`, `Divide`) | Calculate the product/fraction of two numbers without using arithmetic operators.
- Power operation, EPI#4.7: [c++](cpp-algorithm/src/primitive) | Compute repeated squaring $x^y$.

**Examples**

- Computing parity of word: [c++](cpp-algorithm/src/primitive)(`CountBits`) | Count the number of bits that are set to 1.
- Computing parity of word, EPI#4.1: [c++](cpp-algorithm/src/primitive)(`Parity`) | Compute parity of word.
- Computing parity of word, EPI#4.1: [c++](cpp-algorithm/src/primitive)(`ParityDropLowestBits`) | Compute parity by dropping the lowest set bit.
- Computing parity of word, EPI#4.1: [c++](cpp-algorithm/src/primitive)(`ParityLookupTable`) | Compute parity by caching the results.
- Generate random number, EPI#4.10: [c++](cpp-algorithm/src/primitive) | Generate a random number in a range with equal probability.
- Integer palindrome, EPI#4.9: [c++](cpp-algorithm/src/primitive) | Check if a number is a palindrome.
- Rectangle intersection, EPI#4.11: [c++](cpp-algorithm/src/primitive) | Check if two rectangles intersect.
- Reverse digits, EPI#4.8: [c++](cpp-algorithm/src/primitive) | Reverse the digits of a given integer.
- Swap bit, EPI#4.2: [c++](cpp-algorithm/src/primitive) | Swap the bits at indices $i$ and $j$.

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
std::ranges::find_end(v, sub_v).begin() // result - v.begin()
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
import java.util.*;

int[] array = new int[]{1, 2, 3, 4, 5};
List<Integer> arrayList = new ArrayList<>(List.of(1, 2, 3, 4, 5));
List<Integer> linkedList = new LinkedList<>(List.of(1, 2, 3, 4, 5));
Set<Integer> hashSet = new HashSet<>(List.of(1, 2, 3, 4, 5));
Set<Integer> linkedHashSet = new LinkedHashSet<>(List.of(1, 2, 3, 4, 5));
Set<Integer> treeSet = new TreeSet<>(List.of(1, 2, 3, 4, 5));

// binary search
Arrays.binarySearch(array, 3)             // for array
Collections.binarySearch(arrayList, 3);   // for list
```

**Search algorithms**

- Binary search: [python](python-algorithm/algorithm/search) | Binary search is a search algorithm that finds the position of a target value within a sorted array.
- Integer square root, EPI#11.4: [c++](cpp-algorithm/src/search)(`ComputeIntegerSquareRoot`) | Compute the integer square root of a given integer. This function returns the largest integer whose square is less than or equal to the given integer.
- Linear search: [python](python-algorithm/algorithm/search) | Linear search is a search algorithm that compares x successively with each term of the list until a match is found.
- Quick select algorithm: [c++](cpp-algorithm/src/search)(`QuickSelectAlgorithm`) | QuickSelect is an algorithm used to select the k-th smallest (or largest) element in an unordered list of elements.

**Examples**

- DNA search (Search a codon(combinations of three nucleotides) in a gene), CCSP#2.1: [python](python-algorithm/algorithm/search)(`linear_contains`, `binary_contains`) | Search a codon(combinations of three nucleotides) in a gene using linear search and binary search.
- Find k-th smallest/largest element in an array, EPI#11.8: [c++](cpp-algorithm/src/search)(`FindKthSmallestElement`, `FindKthLargestElement`) | Find the k-th smallest/largest element in an array using the quickselect algorithm (`QuickSelectAlgorithm`).
- Find the minimum and maximum elements in an array, EPI#11.7: [c++](cpp-algorithm/src/search)(`FindMinMax`)
- Search an element in generic list, CCSP#2.1: [python](python-algorithm/algorithm/search)(`generic_linear_contains`, `generic_linear_contains`) | Search an element in generic list using linear search and binary search.
- Search a sorted array for entry equal to its index, EPI#11.2: [c++](cpp-algorithm/src/search)(`SearchEntryEqualToItsIndex`)
- Search a sorted array for the first greater than a key: [c++](cpp-algorithm/src/search)(`SearchFirstGreaterThanKey`)
- Search a sorted array for the first occurrence of a key, EPI#11.1: [c++](cpp-algorithm/src/search)(`SearchFirstOfKey`)
- Search a cyclically sorted array for the smallest element, EPI#11.3: [c++](cpp-algorithm/src/search)(`SearchSmallestElementInCyclicallySortedArray`)
- Search in a 2D sorted array(matrix), EPI#11.6: [c++](cpp-algorithm/src/search)(`SearchSortedMatrix`) | Search in a 2D sorted array(matrix) for a given element.

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

`Arrays.sort()` and `Collections.sort()` sort the array and list in ascending order in-place.

```java
import java.util.*;

// Arrays
Arrays.sort(arr);           // dual pivot quick sort (primitive types)
                            // timsort (insertion sort + merge sort) (reference types)
Arrays.sort(arr, Comparator.comparingInt(String::length));
Arrays.sort(arr, Comparator.comparingInt(String::length).reversed());

// Collections
Collections.sort(list);     // timsort (insertion sort + merge sort)
list.sort(Comparator.naturalOrder());
list.sort(Comparator.reverseOrder());
list.sort(Comparator.comparingInt(String::length));
```

**Sorting algorithms**

- Bubble sort, CLRS#2-problems2.2: [java](java-algorithm/src/main/java/com/example/algorithm/sort) | Bubble sort is a sorting algorithm that repeatedly steps through the list to be sorted, compares each pair of adjacent items, and swaps them if needed.<br>(_n_ is the number of elements)

| **Case**    | **Time complexity** | **Remarks**                                                                             |
| :---------- | :-----------------: | :-------------------------------------------------------------------------------------- |
| **Best**    |       $O(n)$        | when the input list is already sorted in the desired order (ascending or descending)    |
| **Worst**   |      $O(n^2)$       | when the input list is already sorted in the reverse order of the desired sorting order |
| **Average** |      $O(n^2)$       | when the input list is in jumbled order                                                 |

- Bucket sort, CLRS#8.4: [java](java-algorithm/src/main/java/com/example/algorithm/sort) | Bucket sort is a sorting algorithm that works by distributing the elements of an array into a number of buckets. Each bucket contains a range of values and the elements are sorted within these buckets using any of the suitable sorting algorithms (such as insertion sort, merge sort, selection sort).<br>(_n_ is the number of elements and _k_ is the number of buckets)

| **Case**    | **Time complexity** | **Remarks**                                                                                                    |
| ----------- | :-----------------: | -------------------------------------------------------------------------------------------------------------- |
| **Best**    |     $O(n + k)$      | when input elements are uniformly distributed<br> and each bucket contains roughly the same number of elements |
| **Worst**   |      $O(n^2)$       | when all elements are placed into a single bucket                                                              |
| **Average** |       $O(n)$        |                                                                                                                |

- Counting sort, CLRS#8.2: [java](java-algorithm/src/main/java/com/example/algorithm/sort) | Counting sort is a non-comparative sorting algorithm that sorts the elements of an array by counting the occurrences of each element in the array. The count is stored in an auxiliary array and the sorting is done by mapping the count as an index of the auxiliary array. It is used as a subroutine in radix sort (CLRS#8.3).<br>(_n_ is the number of elements and _k_ is the range of input values)

| **Case**    | **Time complexity** | **Remarks**                                             |
| ----------- | :-----------------: | ------------------------------------------------------- |
| **Best**    |     $O(n + k)$      | when the input elements have a small range of values    |
| **Worst**   |     $O(n + k)$      | when the input elements have a large range of values    |
| **Average** |     $O(n + k)$      | when the elements are distributed randomly in the array |

- Heap sort, CLRS#6: [java](java-algorithm/src/main/java/com/example/algorithm/sort) | Heap sort is a comparison-based sorting algorithm that uses a binary heap data structure to sort an array. It is used for the implementation of priority queue.<br>(_n_ is the number of elements)

| **Case**    | **Time complexity** | **Remarks** |
| ----------- | :-----------------: | ----------- |
| **Best**    |    $O(n log n)$     |             |
| **Worst**   |    $O(n log n)$     |             |
| **Average** |    $O(n log n)$     |             |

- Insertion sort, CLRS#2.1: [c++](cpp-algorithm/src/sort), [java](java-algorithm/src/main/java/com/example/algorithm/sort) | Insertion sort is a comparison-based sorting algorithm that builds the final sorted array one element at a time. One of the fastest algorithms for sorting very small arrays (around 10 elements).<br>(_n_ is the number of elements)

| **Case**    | **Time complexity** | **Remarks**                                                                     |
| ----------- | :-----------------: | ------------------------------------------------------------------------------- |
| **Best**    |       $O(n)$        | if the list is already sorted.<br>this case has linear running time             |
| **Worst**   |      $O(n^2)$       | if the list is sorted in reverse order.<br>this case has quadratic running time |
| **Average** |      $O(n^2)$       | this case has quadratic running time                                            |

- Merge sort, CLRS#2.3: [java](java-algorithm/src/main/java/com/example/algorithm/sort) | divide and conquer algorithm

| **Case**    | **Time complexity** | **Remarks**                                                                                           |
| ----------- | :-----------------: | ----------------------------------------------------------------------------------------------------- |
| **Best**    |    $O(n log n)$     | running time of sorting for input length $n$ is $T(n)$.<br>$T(n) = 2T(n/2) + O(n) \approx O(n log n)$ |
| **Worst**   |    $O(n log n)$     |                                                                                                       |
| **Average** |    $O(n log n)$     |                                                                                                       |

- Quick sort, CLRS#7: [java](java-algorithm/src/main/java/com/example/algorithm/sort) | divide and conquer algorithm

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
| **Average** |      $O(n^2)$       | when the input list is in jumbled order                                              |

**Examples**

- H-Index, EPI#13.3: [c++](cpp-algorithm/src/sort)(`HIndex`) | Compute the researcher's h-index given a citation count array. The h-index is the largest number _h_ such that _h_ articles have at least _h_ citations each.
- Intersection of two sorted arrays, EPI#13.1: [c++](cpp-algorithm/src/sort)(`IntersectTwoSortedArray`) | Compute the intersection of two sorted array. The input arrays may have duplicate entries, but the output should be free of duplicates.
- Merge intervals, EPI#13.7, LeetCode#merge-intervals: [c++](cpp-algorithm/src/sort)(`MergeIntervals`) | Given a collection of intervals, merge all overlapping intervals.
- Merge two sorted arrays, EPI#13.2, LeetCode#merge-sorted-array: [c++](cpp-algorithm/src/sort)(`MergeTwoSortedArray`) | Merge two sorted array. Merge the second array into the first array.
- Partitioning and sorting an array with many repeated entries, EPI#13.9: [java](java-algorithm/src/main/java/com/example/algorithm/sort)(`GroupByAge`) | Given an array of objects with an age field, reorder the array so that objects of equal age appear together. They should be sorted in ascending order of age, and the order of objects with the same age is not important.
- Remove first-name duplicates, EPI#13.4: [c++](cpp-algorithm/src/sort)(`EliminateFirstNameDuplicate`) | Given an array of names, remove the duplicates of the first name.
- Salary threshold, EPI#13.12: [java](java-algorithm/src/main/java/com/example/algorithm/sort)(`SalaryThreshold`) | Given an array of salaries and a budget, compute the salary cap so that the total salaries equal the budget.
- Team photo day, EPI#13.10: [java](java-algorithm/src/main/java/com/example/algorithm/sort)(`SortPlayerByHeight`) | Given two arrays of numbers, for team photos, players are arranged in front and back rows and then photographed. The players in the back row must necessarily be taller than those in the front row. Additionally, all players in a row should belong to the same team.
- Union of intervals, EPI#13.8: [c++](cpp-algorithm/src/sort)(`UnionOfIntervals`) | Given a set of intervals, compute their union.

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
reverse(), replace(0, 5, "World"), substring(0, 5), toString(),
subSequence(0, 5), chars()

// character
var ch = new Character('a');
Character.isDigit('0'), Character.isLetter('a'), Character.isLetterOrDigit('a'), Character.isAlphabetic('a'),
Character.isLowerCase('a'), Character.isUpperCase('A'), Character.toLowerCase('A'), Character.toUpperCase('a'),
Character.isWhitespace(' ')

// list/stack/deque to string
var str = collection.stream()
    .map(String::valueOf)
    .collect(StringBuilder::new, StringBuilder::append, StringBuilder::append);
```

**String algorithms**

- Finite automata, CLRS#32.3
- Knuth-Morris-Pratt algorithm (KMP), CLRS#32.4
- Naive string matching, CLRS#32.1: [c++](cpp-algorithm/src/string), [python](python-algorithm/algorithm/string) | Find all occurrences of a pattern in a string.
- Rabin-Karp algorithm, CLRS#32.2, EPI#6.12: [c++](cpp-algorithm/src/string) | Use the hash function to find all occurrences of a pattern in a string. It has $\theta(\text{pattern-size})$ preprocessing time and $\theta((\text{text-size} - \text{pattern-size} + 1) \text{pattern-size})$ time complexity.

**Examples**

- Convert string, EPI#6.1: [c++](cpp-algorithm/src/string)(`IntToString`, `StringToInt`) | Convert integer to string and vice versa.
- IP address validation, EPI#6.9: [c++](cpp-algorithm/src/string) | Validate IPv4 address that is in the form of _x.x.x.x_ where _x_ is a number between 0 and 255.
- Look and say problem, EPI#6.7: [c++](cpp-algorithm/src/string)
- Palindrome, EPI#6.5: [c++](cpp-algorithm/src/string) | Check if a string is palindromic.
- Print sine wave pattern string, EPI#6.10: [c++](cpp-algorithm/src/string)(`SineWaveString` and `PrintSineWaveString`) | Print a string in sine wave pattern.
- Roman number, EPI#6.8: [c++](cpp-algorithm/src/string)(`VerifyRomanString`) | Verify if a string is a valid roman number.
- Roman number, EPI#6.8: [c++](cpp-algorithm/src/string)(`RomanStringToInteger`) | Convert a roman number to integer.
- Run-length encoding (RLE), EPI#6.11: [c++](cpp-algorithm/src/string) | Run-length encoding is a simple form of data compression in which runs of data are stored as a single data value and count.
- Spreadsheet column decoding/encoding, EPI#6.3: [c++](cpp-algorithm/src/string)(`DecodingSheetColumnId`, `EncodingSheetColumnId`) | Convert a spreadsheet column id to integer and vice versa.

[:arrow_up_small: back to toc](#table-of-contents)

## References

- Introduction to Algorithms, 3rd Edition, by Thomas H. Cormen, Charles E. Leiserson, Ronald L. Rivest, and Clifford Stein (CLRS)
- Discrete Mathematics and Its Applications, 8th Edition, by Kenneth H. Rosen
- Cracking the Coding Interview, 6th Edition, by Gayle Laakmann McDowell | _CTCI_
- Elements of Programming Interviews, 2nd Edition, by Adnan Aziz, Tsung-Hsien Lee and Amit Prakash | _EPI_
- Classic Computer Science Problems in Python, by David Kopec | _CCSP_

[:arrow_up_small: back to toc](#table-of-contents)
