import time

from algorithm.greedy.interval_schedule import interval_scheduling_lecture


def test_schedule_lecture():
    lecture1 = {'title': 'lecture1',
                'start': time.strptime('2022-07-25 08:00:00', '%Y-%m-%d %H:%M:%S'),
                'end': time.strptime('2022-07-25 12:00:00', '%Y-%m-%d %H:%M:%S')}
    lecture2 = {'title': 'lecture2',
                'start': time.strptime('2022-07-25 09:00:00', '%Y-%m-%d %H:%M:%S'),
                'end': time.strptime('2022-07-25 10:00:00', '%Y-%m-%d %H:%M:%S')}
    lecture3 = {'title': 'lecture3',
                'start': time.strptime('2022-07-25 11:00:00', '%Y-%m-%d %H:%M:%S'),
                'end': time.strptime('2022-07-25 12:00:00', '%Y-%m-%d %H:%M:%S')}

    assert interval_scheduling_lecture([lecture1, lecture2, lecture3]) == [lecture2, lecture3]
