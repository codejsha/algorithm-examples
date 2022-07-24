import time

from algorithm.greedy.interval_schedule import interval_scheduling_talk


def test_schedule_talk():
    talk1 = {'title': 'talk1',
             'start': time.strptime('2022-07-25 08:00:00', '%Y-%m-%d %H:%M:%S'),
             'end': time.strptime('2022-07-25 12:00:00', '%Y-%m-%d %H:%M:%S')}
    talk2 = {'title': 'talk2',
             'start': time.strptime('2022-07-25 09:00:00', '%Y-%m-%d %H:%M:%S'),
             'end': time.strptime('2022-07-25 10:00:00', '%Y-%m-%d %H:%M:%S')}
    talk3 = {'title': 'talk3',
             'start': time.strptime('2022-07-25 11:00:00', '%Y-%m-%d %H:%M:%S'),
             'end': time.strptime('2022-07-25 12:00:00', '%Y-%m-%d %H:%M:%S')}

    assert interval_scheduling_talk([talk1, talk2, talk3]) == [talk2, talk3]
