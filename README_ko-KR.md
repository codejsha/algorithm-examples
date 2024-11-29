# Algorithm Examples

<!-- markdownlint-disable MD033 MD036 -->

![C++ CMake Test](https://github.com/codejsha/algorithm-examples/actions/workflows/cmake.yml/badge.svg) ![Python Poetry Test](https://github.com/codejsha/algorithm-examples/actions/workflows/poetry.yml/badge.svg) ![Go Test](https://github.com/codejsha/algorithm-examples/actions/workflows/go.yml/badge.svg) ![Java Gradle Test](https://github.com/codejsha/algorithm-examples/actions/workflows/gradle.yml/badge.svg)

[English](README.md) | [Korean](README_ko-KR.md)

이 리포지토리는 알고리즘, 데이터 구조, 문제 해결 접근방식의 예제들을 제공하며 실제 응용을 위한 목적으로 구현되었습니다. 예제들은 C++, Python, Go, Java로 구현되었으며, 각 언어는 테스트 프레임워크를 활용합니다. 테스트를 실행하여 알고리즘 로직에 대한 메서드/함수를 수행할 수 있습니다.

## Project Environments

각 프로젝트는 다음과 같은 환경에서 구성되었습니다:

| Language | Version | Build                                | Packages                                                                                                                                                                                                              | Remarks                                     |
| -------- | ------- | ------------------------------------ | --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | ------------------------------------------- |
| C++      | C++20   | [CMake](https://cmake.org/)          | [GNU Scientific Library (GSL)](https://www.gnu.org/software/gsl/), [Google Test](https://google.github.io/googletest/), [Google Benchmark](https://github.com/google/benchmark), [fmt](https://github.com/fmtlib/fmt) | [vcpkg](https://github.com/microsoft/vcpkg) |
| Python   | 3.12    | [Poetry](https://python-poetry.org/) | [NumPy](https://numpy.org/), [SciPy](https://www.scipy.org/), [NetworkX](https://networkx.org/), [pytest](https://docs.pytest.org/), [pytest-benchmark](https://pytest-benchmark.readthedocs.io/en/latest/)           |                                             |
| Go       | 1.22    | [Go](https://pkg.go.dev/cmd/go)      | [Gonum](https://github.com/gonum/gonum), [Testify](https://github.com/stretchr/testify)                                                                                                                               |                                             |
| Java     | 21      | [Gradle](https://gradle.org/)        | [Google Guava](https://github.com/google/guava), [JUnit](https://junit.org/), [Java Microbenchmark Harness (JMH)](https://github.com/openjdk/jmh)                                                                     |                                             |
