# Algorithm Examples

[English](README.md)

목차:

- [개요 (Introduction)](#개요-introduction)
- [데이터 구조 (Data structures)](#데이터-구조-data-structures)
  - [그래프 (Graph)](#그래프-graph)
  - [트리 (Tree)](#트리-tree)
- [주제 (Topics)](#주제-topics)
  - [동적 프로그래밍 (Dynamic programming)](#동적-프로그래밍-dynamic-programming)
  - [그리디 (Greedy)](#그리디-greedy)
  - [수학 (Mathematics)](#수학-mathematics)
  - [기본 자료형 (Primitive type)](#기본-자료형-primitive-type)
  - [검색 (Search)](#검색-search)
  - [정렬 (Sort)](#정렬-sort)
  - [문자열 (String)](#문자열-string)
- [문제 해결 (Problem solving)](#문제-해결-problem-solving)
- [참조 (References)](#참조-references)

## 개요 (Introduction)

이 리포지토리는 알고리즘, 데이터 구조, 문제 해결에 대한 구현 예제입니다. 예제들은 C++, Python, Java로 작성되었으며, 각 언어는 다음과 같은 테스트 프레임워크를 사용합니다: [Google Test](https://google.github.io/googletest/)(C++), [pytest](https://docs.pytest.org/)(Python), [JUnit](https://junit.org/)(Java).

추가로, 각 프로젝트는 다음과 같은 환경에서 구성되었습니다:

- C++ project: [CMake](https://cmake.org/) 프로젝트 기반, [GNU Scientific Library (GSL)](https://www.gnu.org/software/gsl/) 사용
- Python project: [NumPy](https://numpy.org/), [SciPy](https://www.scipy.org/) 사용
- Java project: [Spring Boot](https://spring.io/projects/spring-boot) 프로젝트 기반, [Java Microbenchmark Harness (JMH)](https://github.com/openjdk/jmh) 사용

## 데이터 구조 (Data structures)

### 그래프 (Graph)

- 벨만 포드 알고리즘 (Bellman-Ford algorithm): [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/graph)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/graph))
- 넓이 우선 탐색 (Breadth-first search (BFS)): [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/graph)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/graph))
- 깊이 우선 탐색 (Depth-first search (DFS)): [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/graph)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/graph))
- 다익스트라 알고리즘 (Dijkstra's algorithm): [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/graph)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/graph))

### 트리 (Tree)

- B-tree: [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/tree)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/tree))
- 이진 검색 트리 (Binary search tree): [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/tree)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/tree))

## 주제 (Topics)

### 동적 프로그래밍 (Dynamic programming)

- 피보나치 숫자 (Fibonacci number): [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/dynamic_programming)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/dynamic_programming))
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
- 순열 (Permutation): [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/math)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/math))

### 기본 자료형 (Primitive type)

- 패리티 계산하기 (Computing parity of word): [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/primitive_type)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/primitive_type))
- 산술 연산자 없이 나눗셈 계산하기 (Divide operation): [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/primitive_type)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/primitive_type))
- 임의의 숫자를 균등한 확룰로 생성하기 (Generate random number): [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/primitive_type)
- 회문 확인하기 (Integer palindrome): [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/primitive_type)
- 곱셈과 덧셈 없이 $x \times y$ 계산하기 (Multiply operation): [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/primitive_type)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/primitive_type))
- pow(x,y) 계산하기 (Power operation): [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/primitive_type)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/primitive_type))
- 사각형이 겹치는지 확인하기 (Rectangle intersection): [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/primitive_type)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/primitive_type))
- 숫자 뒤집기 (Reverse digit): [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/primitive_type)
- 비트 스왑 (Swap bit): [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/primitive_type)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/primitive_type))

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

- Naive string search: [python](https://github.com/codejsha/algorithm-examples/tree/main/python-algorithm/algorithm/string)([test](https://github.com/codejsha/algorithm-examples/tree/main/python-algorithm/test/string))

## 문제 해결 (Problem solving)

- Interval subset sum: [c++](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/src/problem)([test](https://github.com/codejsha/algorithm-examples/tree/main/cpp-algorithm/test/problem))

## 참조 (References)

- Introduction to Algorithms, 3rd Edition, by CLRS
- Discrete Mathematics and Its Applications, 8th Edition, by Kenneth H. Rosen
- Cracking the Coding Interview, 6th Edition, by Gayle Laakmann McDowell
- Elements of Programming Interviews, 2nd Edition, by Adnan Aziz, Tsung-Hsien Lee and Amit Prakash
