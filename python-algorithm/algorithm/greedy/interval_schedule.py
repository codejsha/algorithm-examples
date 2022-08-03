def interval_scheduling_lecture(lectures: list[dict]) -> list[dict]:
    """
    Greedy algorithm to schedule lectures.
    :param lectures: list of lectures
    :return: list of scheduled lectures
    """

    lectures.sort(key=lambda t: t['start'])
    lectures.sort(key=lambda t: t['end'])
    scheduled_lectures = []

    for index, lecture in enumerate(lectures):
        if not scheduled_lectures:
            scheduled_lectures.append(lecture)
        else:
            if lecture['start'] >= scheduled_lectures[-1]['end']:
                scheduled_lectures.append(lecture)

    return scheduled_lectures
