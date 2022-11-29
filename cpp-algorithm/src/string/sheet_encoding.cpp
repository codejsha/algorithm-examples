#include "sheet_encoding.h"

auto SheetEncoding::DecodingSheetColumnId(const std::string& column) -> int
{
    auto result = 0;
    for (const auto i : column)
    {
        result = (result * 26) + (i - 'A' + 1);
    }
    return result;
}

auto SheetEncoding::EncodingSheetColumnId(int column_id) -> std::string
{
    auto result = std::string{};
    while (column_id > 0)
    {
        result.push_back('A' + (column_id - 1) % 26);
        column_id = (column_id - 1) / 26;
    }
    std::reverse(result.begin(), result.end());
    return result;
}
