def binary_search(sequence: list, target: int) -> int:
    low = 0
    high = len(sequence)

    while low < high:
        mid = (low + high) // 2
        if sequence[mid] == target:
            return mid
        elif sequence[mid] < target:
            low = mid + 1
        else:
            high = mid

    return -1
