#include "sheet_encoding.h"

auto SheetEncoding::DecodingSheetColumnId(const std::string& column) -> int
{
    int result = 0;
    for (const char c : column)
    {
        result = (result * 26) + (c - 'A' + 1);
    }
    return result;
}

auto SheetEncoding::EncodingSheetColumnId(int column_id) -> std::string
{
    std::string result;
    while (column_id > 0)
    {
        result.push_back('A' + (column_id - 1) % 26);
        column_id = (column_id - 1) / 26;
    }
    std::reverse(result.begin(), result.end());
    return result;
}
