import pytest
from algorithm.search.dna_search import Nucleotide, string_to_gene, linear_contains, binary_contains


@pytest.mark.benchmark(group="linear_contains")
@pytest.mark.parametrize("gene, key_codon, expected", [
    (string_to_gene("ACGTGGCTCTCTAACGTACGTACGTACGGGGTTTATATATACCCTAGGACTCCCTTT"),
     (Nucleotide.A, Nucleotide.C, Nucleotide.G),
     True),
    (string_to_gene("ACGTGGCTCTCTAACGTACGTACGTACGGGGTTTATATATACCCTAGGACTCCCTTT"),
     (Nucleotide.G, Nucleotide.A, Nucleotide.T),
     False),
], ids=["successful", "failed"])
def test_linear_contains(benchmark, gene, key_codon, expected):
    result = benchmark(linear_contains, gene, key_codon)
    assert expected == result


@pytest.mark.benchmark(group="binary_contains")
@pytest.mark.parametrize("gene, key_codon, expected", [
    (sorted(string_to_gene("ACGTGGCTCTCTAACGTACGTACGTACGGGGTTTATATATACCCTAGGACTCCCTTT")),
     (Nucleotide.A, Nucleotide.C, Nucleotide.G),
     True),
    (sorted(string_to_gene("ACGTGGCTCTCTAACGTACGTACGTACGGGGTTTATATATACCCTAGGACTCCCTTT")),
     (Nucleotide.G, Nucleotide.A, Nucleotide.T),
     False),
], ids=["successful", "failed"])
def test_binary_contains(benchmark, gene, key_codon, expected):
    result = benchmark(binary_contains, gene, key_codon)
    assert expected == result
