import pytest

from algorithm.string.naive_string_search import naive_string_matcher


@pytest.mark.benchmark(group="naive_string_matcher")
@pytest.mark.parametrize("text, pattern, expected", [
    ('eceyeye', 'eye', [2, 4]),
], ids=["successful"])
def test_naive_string_matcher(benchmark, text, pattern, expected):
    result = benchmark(naive_string_matcher, text, pattern)
    assert expected == result
