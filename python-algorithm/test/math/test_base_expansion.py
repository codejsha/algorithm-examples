from algorithm.math.base_expansion import base_expansion


def test_base_expansion():
    assert base_expansion(number=12345, base=8) == '30071'
    assert base_expansion(number=177130, base=16) == '2B3EA'
    assert base_expansion(number=241, base=2) == '11110001'
