from enum import IntEnum
from typing import Tuple, List

Nucleotide = IntEnum('Nucleotide', ('A', 'C', 'G', 'T'))
Codon = Tuple[Nucleotide, Nucleotide, Nucleotide]
Gene = List[Codon]


def string_to_gene(s: str) -> Gene:
    gene = [(Nucleotide[s[i]], Nucleotide[s[i + 1]], Nucleotide[s[i + 2]])
            for i in range(0, len(s), 3)
            if i + 2 < len(s)]
    return gene


def linear_contains(gene: Gene, key_codon: Codon) -> bool:
    return any(codon == key_codon for codon in gene)


def binary_contains(gene: Gene, key_codon: Codon) -> bool:
    low: int = 0
    high: int = len(gene) - 1
    while low <= high:
        mid: int = (low + high) // 2
        if gene[mid] < key_codon:
            low = mid + 1
        elif gene[mid] > key_codon:
            high = mid - 1
        else:
            return True
    return False
