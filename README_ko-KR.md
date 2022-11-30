# Algorithm Examples

![C++ CI with CMake](https://github.com/codejsha/algorithm-examples/actions/workflows/cmake.yml/badge.svg)

[English](README.md)

이 리포지토리는 알고리즘, 데이터 구조, 문제 해결에 대한 구현 예제입니다. 예제들은 C++, Python, Java로 작성되었으며, 각 언어는 다음과 같은 테스트 프레임워크를 사용합니다: [Google Test](https://google.github.io/googletest/)(C++), [pytest](https://docs.pytest.org/)(Python), [JUnit](https://junit.org/)(Java). 테스트를 실행하여 알고리즘 로직에 대한 메서드/함수를 수행합니다. 코드를 빌드하고 테스트하는 GitHub Actions 워크플로우는 매일 00:00 UTC(09:00 KST)에 실행됩니다.

추가로, 각 프로젝트는 다음과 같은 환경에서 구성되었습니다:

- C++ project: [CMake](https://cmake.org/) 프로젝트 기반, [GNU Scientific Library (GSL)](https://www.gnu.org/software/gsl/), [Google Test](https://google.github.io/googletest/) 패키지 사용 (패키지 매니저 [vcpkg](https://github.com/microsoft/vcpkg))
- Python project: [NumPy](https://numpy.org/), [SciPy](https://www.scipy.org/), [pytest](https://docs.pytest.org/) 패키지 사용
- Java project: [Spring Boot](https://spring.io/projects/spring-boot) 프로젝트 기반, [Java Microbenchmark Harness (JMH)](https://github.com/openjdk/jmh), [JUnit](https://junit.org/) 라이브러리 사용

## 목차 (Table of Contents)

- [목차 (Table of Contents)](#목차-table-of-contents)
- [데이터 구조 (Data structures)](#데이터-구조-data-structures)
  - [배열 (Array)](#배열-array)
  - [그래프 (Graph)](#그래프-graph)
  - [링크드 리스트 (Linked list)](#링크드-리스트-linked-list)
  - [트리 (Tree)](#트리-tree)
- [주제 (Topics)](#주제-topics)
  - [동적 프로그래밍 (Dynamic programming)](#동적-프로그래밍-dynamic-programming)
  - [그리디 (Greedy)](#그리디-greedy)
  - [수학 (Mathematics)](#수학-mathematics)
  - [기본 자료형 (Primitive type)](#기본-자료형-primitive-type)
  - [검색 (Search)](#검색-search)
  - [정렬 (Sort)](#정렬-sort)
  - [문자열 (String)](#문자열-string)
- [참조 (References)](#참조-references)

## 데이터 구조 (Data structures)

### 배열 (Array)

- 배열에서 이동하기 (Advancing through an array): [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/array)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/array))
- 임의의 정숫값 증가시키기 (Arbitrary precision operation - increment an arbitrary-precision integer (PlusOne)): [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/array)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/array))
- 임의의 두 정숫값 더하기 (Arbitrary precision operation - add two arbitrary-precision integers (StringAddition)): [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/array)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/array))
- 임의의 두 정숫값 곱하기 (Arbitrary precision operation - multiply two arbitrary-precision integers (Multiply)): [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/array)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/array))
- 정렬된 배열에서 중복 제거하기 (Delete duplicates from a sorted array (DeleteDuplicates)): [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/array)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/array))
- 정렬된 배열에서 중복 제거하기 (Delete duplicates from a sorted array (DeleteDuplicateElements)): [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/array)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/array))
- 정렬된 배열에서 특정 원소 제거하기 (Delete specific elements from a sorted array (DeleteSpecificElements)): [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/array)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/array))
- 네덜란드 국기 문제 (Dutch national flags problem): [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/array)
- 소수 나열하기 (Enumerate prime numbers): [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/array)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/array))
- 배열 정렬하기 (Order elements in an array by even and odd (EvenOdd)): [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/array)
- 배열 정렬하기 (Order elements in an array by specified order (Rearrange)): [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/array)
- 데이터 샘플 구하기 (Random data sampling - offline (OfflineRandomSampling)): [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/array)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/array))
- 데이터 샘플 구하기 (Random data sampling - compute permutation (ComputeRandomPermutation)): [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/array)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/array))
- 문자열 치환하기 (Replace elements - replace and remove (ReplaceAndRemoveString1)): [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/array)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/array))
- 문자열 치환하기 (Replace elements - replace and remove (ReplaceAndRemoveString2)): [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/array)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/array))
- 문자열 Telex 인코딩 치환하기 (Replace elements - telex encoding (TelexEncoding)): [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/array)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/array))
- 주식 사고 팔기 (Stock trading - buy and sell a stock once (BuyAndSellStockOnceBruteForce, BuyAndSellStockOnce)): [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/array)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/array))
- 주식 사고 팔기 (Stock trading - buy and sell a stock twice (BuyAndSellStockTwice)): [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/array)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/array))

### 그래프 (Graph)

- 벨만-포드 알고리즘 (Bellman-Ford algorithm): [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/graph)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/graph))
- 넓이 우선 탐색 (Breadth-first search (BFS)): [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/graph)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/graph))
- 깊이 우선 탐색 (Depth-first search (DFS)): [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/graph)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/graph))
- 다익스트라 알고리즘 (Dijkstra's algorithm): [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/graph)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/graph))

### 링크드 리스트 (Linked list)

- 리스트에서 노드 삭제하기 (Delete a node from linked list (DeleteNodeFromList)): [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/linked_list)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/linked_list))
- 정렬된 리스트에서 중복된 노드 삭제하기 (Delete duplicate nodes from sorted linked list (DeleteDuplicateNode)): [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/linked_list)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/linked_list))
- 리스트에서 k번째 마지막 노드 삭제하기 (Delete the k-th last node from linked list (DeleteNodeKthLast)): [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/linked_list)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/linked_list))
- 리스트에서 사이클이 존재하는지 확인하기 (Linked list has a cycle (HasCycle1, HasCycle2, HasCycle3)): [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/linked_list)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/linked_list))
- 두 개의 정렬된 링크드 리스트 합치기 (Merge two sorted linked lists): [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/linked_list)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/linked_list))
- 부분 리스트 하나 뒤집기 (Reverse a single sublist): [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/linked_list)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/linked_list))
- 사이클이 없는 두 리스트가 겹치는지 확인 (Two linked lists overlap (OverlappingNoCycleList)): [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/linked_list)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/linked_list))
- 사이클이 있는 두 리스트가 겹치는지 확인 (Two linked lists with cycles overlap (OverlappingNoCycleList)): [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/linked_list)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/linked_list))

### 트리 (Tree)

- B-tree: [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/tree)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/tree))
- 이진 검색 트리 (Binary search tree): [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/tree)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/tree))

## 주제 (Topics)

### 동적 프로그래밍 (Dynamic programming)

- 피보나치 숫자 (Fibonacci number): [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/dynamic_programming)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/dynamic_programming))
- Interval subset sum: [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/problem_solving)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/problem_solving))
- 최장 공통 부분 수열 (Longest common subsequence): [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/dynamic_programming)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/dynamic_programming))
- Rod cutting: [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/dynamic_programming)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/dynamic_programming))

### 그리디 (Greedy)

- Activity selection: [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/greedy)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/greedy))
- Cashier's change: [python](https://github.com/codejsha/algorithm-examples/tree/main/python-algorithm/algorithm/greedy)([test](https://github.com/codejsha/algorithm-examples/tree/main/python-algorithm/test/greedy))
- 허프만 코드 (Huffman code): [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/greedy)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/greedy))
- Interval scheduling: [python](https://github.com/codejsha/algorithm-examples/tree/main/python-algorithm/algorithm/greedy)([test](https://github.com/codejsha/algorithm-examples/tree/main/python-algorithm/test/greedy))

### 수학 (Mathematics)

- Base expansion (base $b$ expansion of $n$): [python](https://github.com/codejsha/algorithm-examples/tree/main/python-algorithm/algorithm/math)([test](https://github.com/codejsha/algorithm-examples/tree/main/python-algorithm/test/math))
- Binary operation (addition): [python](https://github.com/codejsha/algorithm-examples/tree/main/python-algorithm/algorithm/math)([test](https://github.com/codejsha/algorithm-examples/tree/main/python-algorithm/test/math))
- 조합 (Combination): [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/math)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/math))
- 최대 공약수 (Greatest common divisor (GCD)): [python](https://github.com/codejsha/algorithm-examples/tree/main/python-algorithm/algorithm/math)([test](https://github.com/codejsha/algorithm-examples/tree/main/python-algorithm/test/math))
- 최소 공배수 (Least common multiple (LCM)): [python](https://github.com/codejsha/algorithm-examples/tree/main/python-algorithm/algorithm/math)([test](https://github.com/codejsha/algorithm-examples/tree/main/python-algorithm/test/math))
- 행렬 곱셈 (Matrix multiplication): [python](https://github.com/codejsha/algorithm-examples/tree/main/python-algorithm/algorithm/math)([test](https://github.com/codejsha/algorithm-examples/tree/main/python-algorithm/test/math))
- 밀러-라빈 소수 판별법 (Miller-Rabin primality test): [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/math)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/math))
- 순열 (Permutation (Permutation)): [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/math)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/math))
- 순열 구하기 (Permutation (ApplyPermutationWithAdditionalSpace, ApplyPermutationBySwap)): [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/math)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/math))
- 순열 뒤집기 (Permutation (InversePermutation)): [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/math)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/math))
- 다음/이전 순열 구하기 (Permutation (NextPermutation/PreviousPermutation)): [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/math)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/math))
- K-번째 순열 구하기 (Permutation (KthPermutation)): [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/math)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/math))

### 기본 자료형 (Primitive type)

- 산술 연산자 없이 산술 연산 계산하기 (Arithmetic operation (Multiply/Divide)): [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/primitive_type)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/primitive_type))
- 패리티 계산하기 (Computing parity of word (CountBits)): [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/primitive_type)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/primitive_type))
- 패리티 계산하기 (Computing parity of word (Parity)): [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/primitive_type)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/primitive_type))
- 패리티 계산하기 (Computing parity of word (ParityDropLowestBits)): [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/primitive_type)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/primitive_type))
- 패리티 계산하기 (Computing parity of word (ParityLookupTable)): [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/primitive_type)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/primitive_type))
- 임의의 숫자를 균등한 확룰로 생성하기 (Generate random number): [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/primitive_type)
- 회문 확인하기 (Integer palindrome): [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/primitive_type)
- pow(x,y) 계산하기 (Power operation): [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/primitive_type)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/primitive_type))
- 사각형이 겹치는지 확인하기 (Rectangle intersection): [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/primitive_type)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/primitive_type))
- 숫자 뒤집기 (Reverse digits): [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/primitive_type)
- 비트 스왑 (Swap bits): [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/primitive_type)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/primitive_type))

### 검색 (Search)

- 이진 검색 (Binary search): [python](https://github.com/codejsha/algorithm-examples/tree/main/python-algorithm/algorithm/search)([test](https://github.com/codejsha/algorithm-examples/tree/main/python-algorithm/test/search))
- 선형 검색 (Linear search): [python](https://github.com/codejsha/algorithm-examples/tree/main/python-algorithm/algorithm/search)([test](https://github.com/codejsha/algorithm-examples/tree/main/python-algorithm/test/search))

### 정렬 (Sort)

- 버블 정렬 (Bubble sort): [java](https://github.com/codejsha/algorithm-examples/tree/main/java-algorithm/src/main/java/com/example/demo/sort)([test](https://github.com/codejsha/algorithm-examples/tree/main/java-algorithm/src/test/java/com/example/demo/sort))
- 버킷 정렬 (Bucket sort): [java](https://github.com/codejsha/algorithm-examples/tree/main/java-algorithm/src/main/java/com/example/demo/sort)([test](https://github.com/codejsha/algorithm-examples/tree/main/java-algorithm/src/test/java/com/example/demo/sort))
- 계수 정렬 (Counting sort): [java](https://github.com/codejsha/algorithm-examples/tree/main/java-algorithm/src/main/java/com/example/demo/sort)([test](https://github.com/codejsha/algorithm-examples/tree/main/java-algorithm/src/test/java/com/example/demo/sort))
- 힙 정렬 (Heap sort): [java](https://github.com/codejsha/algorithm-examples/tree/main/java-algorithm/src/main/java/com/example/demo/sort)([test](https://github.com/codejsha/algorithm-examples/tree/main/java-algorithm/src/test/java/com/example/demo/sort))
- 삽입 정렬 (Insertion sort): [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/sort)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/sort)), [java](https://github.com/codejsha/algorithm-examples/tree/main/java-algorithm/src/main/java/com/example/demo/sort)([test](https://github.com/codejsha/algorithm-examples/tree/main/java-algorithm/src/test/java/com/example/demo/sort))
- 병합 정렬 (Merge sort): [java](https://github.com/codejsha/algorithm-examples/tree/main/java-algorithm/src/main/java/com/example/demo/sort)([test](https://github.com/codejsha/algorithm-examples/tree/main/java-algorithm/src/test/java/com/example/demo/sort))
- 퀵 정렬 (Quick sort): [java](https://github.com/codejsha/algorithm-examples/tree/main/java-algorithm/src/main/java/com/example/demo/sort)([test](https://github.com/codejsha/algorithm-examples/tree/main/java-algorithm/src/test/java/com/example/demo/sort))
- 선택 정렬 (Selection sort): [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/sort)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/sort)), [java](https://github.com/codejsha/algorithm-examples/tree/main/java-algorithm/src/main/java/com/example/demo/sort)([test](https://github.com/codejsha/algorithm-examples/tree/main/java-algorithm/src/test/java/com/example/demo/sort))

### 문자열 (String)

- 문자열/숫자 변환하기 (Convert string (IntToString, StringToInt)): [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/string)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/string))
- 유효한 IP 주소 구하기 (IP address validation): [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/string)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/string))
- 개미 수열 문제 (Look and say problem): [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/string)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/string))
- Naive string search: [python](https://github.com/codejsha/algorithm-examples/tree/main/python-algorithm/algorithm/string)([test](https://github.com/codejsha/algorithm-examples/tree/main/python-algorithm/test/string))
- 회문 확인하기 (Palindrome): [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/string)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/string))
- 사인파 곡선 패턴으로 문자열 프린트하기 (Print sine wave pattern string (SineWaveString and PrintSineWaveString)): [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/string)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/string))
- 라빈-카프 알고리즘 (Rabin-Karp algorithm): [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/string)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/string))
- 로마 숫자 (Roman number (VerifyRomanString)): [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/string)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/string))
- 로마 숫자 (Roman number (RomanStringToInteger)): [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/string)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/string))
- 반복 길이 부호화로 문자열 압축하기 (Run-length encoding (RLE)): [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/string)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/string))
- 스프레드시트 컬럼 디코딩/인코딩 (Spreadsheet column decoding/encoding (DecodingSheetColumnId/EncodingSheetColumnId)): [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/string)

## 참조 (References)

- Introduction to Algorithms, 3rd Edition, by CLRS
- Discrete Mathematics and Its Applications, 8th Edition, by Kenneth H. Rosen
- Cracking the Coding Interview, 6th Edition, by Gayle Laakmann McDowell
- Elements of Programming Interviews, 2nd Edition, by Adnan Aziz, Tsung-Hsien Lee and Amit Prakash
