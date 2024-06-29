from sys import getsizeof

import pytest

import algorithm.utils.logging as log_utils
from algorithm.string.bit_compression import CompressedGene


@pytest.mark.benchmark(group='gene_string_compression')
def test_bit_compression(benchmark):
    logger = log_utils.get_console_logger(__name__, 'DEBUG')
    original: str = 'TAGGGATTAACCGTTATATATATATAGCCATGGATCGATTATATAGGGATTAACCGTTATATATATATAGCCATGGATCGATTATA' * 100
    compressed: CompressedGene = benchmark(CompressedGene, original)

    print('')
    logger.debug('original is {} bytes'.format(getsizeof(original)))
    logger.debug('compressed is {} bytes'.format(getsizeof(compressed.bit_string)))

    assert original == compressed.decompress()
