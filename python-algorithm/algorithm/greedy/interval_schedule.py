def interval_scheduling_talk(talks: list[dict]) -> list[dict]:
    talks.sort(key=lambda t: t['start'])
    talks.sort(key=lambda t: t['end'])
    scheduled_talks = []

    for index, talk in enumerate(talks):
        if not scheduled_talks:
            scheduled_talks.append(talk)
        else:
            if talk['start'] >= scheduled_talks[-1]['end']:
                scheduled_talks.append(talk)

    return scheduled_talks
