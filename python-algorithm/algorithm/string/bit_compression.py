class CompressedGene:
    def __init__(self, gene: str) -> None:
        self._compress(gene)

    def __str__(self) -> str:  # string representation for pretty printing
        return self.decompress()

    def _compress(self, gene: str) -> None:
        self.bit_string: int = 1  # start with sentinel
        for nucleotide in gene.upper():
            self.bit_string <<= 2  # shift left two bits
            if nucleotide == 'A':  # change last two bits to 00
                self.bit_string |= 0b00
            elif nucleotide == 'C':  # change last two bits to 01
                self.bit_string |= 0b01
            elif nucleotide == 'G':  # change last two bits to 10
                self.bit_string |= 0b10
            elif nucleotide == 'T':  # change last two bits to 11
                self.bit_string |= 0b11
            else:
                raise ValueError('Invalid Nucleotide:{}'.format(nucleotide))

    def decompress(self) -> str:
        gene: str = ''
        for i in range(0, self.bit_string.bit_length() - 1, 2):  # - 1 to exclude sentinel
            bits: int = self.bit_string >> i & 0b11  # get just 2 relevant bits
            if bits == 0b00:  # A
                gene += 'A'
            elif bits == 0b01:  # C
                gene += 'C'
            elif bits == 0b10:  # G
                gene += 'G'
            elif bits == 0b11:  # T
                gene += 'T'
            else:
                raise ValueError('Invalid bits:{}'.format(bits))
        return gene[::-1]  # [::-1] reverses string by slicing backward
