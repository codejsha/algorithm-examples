def naive_string_matcher(text: str, pattern: str) -> list[int]:
    text_length = len(text)
    pattern_length = len(pattern)
    position = []

    for i in range(text_length - pattern_length + 1):
        for j in range(pattern_length):
            if text[i + j] != pattern[j]:
                break
        else:
            position.append(i)

    return position
