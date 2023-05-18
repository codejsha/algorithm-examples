#ifndef CPP_ALGORITHM_SHEET_ENCODING_H
#define CPP_ALGORITHM_SHEET_ENCODING_H

#include <string>

namespace SheetEncoding
{
    /// @brief Convert a column title to a corresponding column number.
    /// @param column column title
    /// @return number
    auto DecodingSheetColumnId(const std::string& column) -> int;

    /// @brief Convert a column number to a corresponding column title.
    /// @param column_id column number
    /// @return column title
    auto EncodingSheetColumnId(int column_id) -> std::string;
}

#endif
