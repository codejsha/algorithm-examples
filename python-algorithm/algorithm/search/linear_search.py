def linear_search(sequence: list, target: int) -> int:
    for index, element in enumerate(sequence):
        if element == target:
            return index
    return -1
