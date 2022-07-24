from algorithm.string.naive_string_search import naive_string_matcher


def test_naive_string_matcher():
    assert naive_string_matcher(text='eceyeye', pattern='eye') == [2, 4]
