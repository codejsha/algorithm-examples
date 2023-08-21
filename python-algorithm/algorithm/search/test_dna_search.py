import pytest
from algorithm.search.dna_search import Nucleotide, string_to_gene, linear_contains, binary_contains


@pytest.mark.benchmark(group="linear_contains")
@pytest.mark.parametrize("gene, key_codon, expected", [
    ("ACGTGGCTCTCTAACGTACGTACGTACGGGGTTTATATATACCCTAGGACTCCCTTT", (Nucleotide.A, Nucleotide.C, Nucleotide.G), True),
    ("ACGTGGCTCTCTAACGTACGTACGTACGGGGTTTATATATACCCTAGGACTCCCTTT", (Nucleotide.G, Nucleotide.A, Nucleotide.T), False),
], ids=["successful", "failed"])
def test_linear_contains(benchmark, gene_str, key_codon, expected):
    gene = string_to_gene(gene_str)
    result = benchmark(linear_contains, gene, key_codon)
    assert expected == result


@pytest.mark.benchmark(group="binary_contains")
@pytest.mark.parametrize("gene, key_codon, expected", [
    ("ACGTGGCTCTCTAACGTACGTACGTACGGGGTTTATATATACCCTAGGACTCCCTTT", (Nucleotide.A, Nucleotide.C, Nucleotide.G), True),
    ("ACGTGGCTCTCTAACGTACGTACGTACGGGGTTTATATATACCCTAGGACTCCCTTT", (Nucleotide.G, Nucleotide.A, Nucleotide.T), False),
], ids=["successful", "failed"])
def test_binary_contains(benchmark, gene_str, key_codon, expected):
    sorted_gene = sorted(string_to_gene(gene_str))
    result = benchmark(binary_contains, sorted_gene, key_codon)
    assert expected == result
