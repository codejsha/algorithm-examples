from typing import TypeVar, Iterable, Tuple, List, Sequence

T = TypeVar('T')
C = TypeVar("C", bound="Comparable")


def generic_linear_contains(iterable: Iterable[T], key: T) -> bool:
    return any(item == key for item in iterable)


def generic_binary_contains(sequence: Sequence[C], key: C) -> bool:
    low: int = 0
    high: int = len(sequence) - 1
    while low <= high:
        mid: int = (low + high) // 2
        if sequence[mid] < key:
            low = mid + 1
        elif sequence[mid] > key:
            high = mid - 1
        else:
            return True
    return False
