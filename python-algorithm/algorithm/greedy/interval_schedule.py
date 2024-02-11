def interval_scheduling_lecture(lectures: list[dict]) -> list[dict]:
    """
    Schedule lectures to maximize the number of lectures that can be attended. This uses the greedy algorithm.
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
