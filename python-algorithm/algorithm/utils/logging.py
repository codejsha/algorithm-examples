import logging
from typing import Union


def get_console_logger(name: str, level: Union[int, str, None] = None) -> logging.Logger:
    """
    Get a console logger with the specified name and log level.
    :param name: logger name
    :param level: log level which can be an integer, string, or None
    :return: console logger
    """
    if level is None:
        level = logging.INFO
    elif isinstance(level, str):
        level = _str_to_log_level(level)
    elif not isinstance(level, int):
        raise TypeError(f'Invalid log level type: {type(level)}')

    return _create_console_logger(name, level)


def _str_to_log_level(level: str) -> int:
    """
    Convert a string log level to an integer log level.
    :param level: string log level
    :return: integer log level
    """
    level = level.upper()
    log_levels = {
        'NOTSET': logging.NOTSET,
        'DEBUG': logging.DEBUG,
        'INFO': logging.INFO,
        'WARNING': logging.WARNING,
        'WARN': logging.WARNING,
        'ERROR': logging.ERROR,
        'CRITICAL': logging.CRITICAL,
        'FATAL': logging.CRITICAL
    }

    if level in log_levels:
        return log_levels[level]
    else:
        raise ValueError(f'Invalid log level: {level}')


def _create_console_logger(name: str, level: int) -> logging.Logger:
    """
    Get a console logger with the specified name and log level.
    :param name: logger name
    :param level: log level
    :return: console logger
    """
    logger = logging.getLogger(name)
    logger.setLevel(level)
    formatter = logging.Formatter('%(asctime)s - %(name)s - %(levelname)s - %(message)s')
    console_handler = logging.StreamHandler()
    console_handler.setFormatter(formatter)
    logger.addHandler(console_handler)
    return logger
