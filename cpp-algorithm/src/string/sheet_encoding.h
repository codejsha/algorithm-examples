#ifndef CPP_ALGORITHM_SHEET_ENCODING_H
#define CPP_ALGORITHM_SHEET_ENCODING_H

#include <string>

namespace SheetEncoding
{
    /**
     * \brief Convert a column title to a corresponding column number.
     * \param column column title
     * \return number
     */
    int DecodingSheetColumnId(const std::string& column);

    /**
     * \brief Convert a column number to a corresponding column title.
     * \param column_id column number
     * \return column title
     */
    std::string EncodingSheetColumnId(int column_id);
}

// ----------------------------------------------------------------------------
inline int SheetEncoding::DecodingSheetColumnId(const std::string& column)
{
    int result = 0;
    for (const char c : column)
    {
        result = (result * 26) + (c - 'A' + 1);
    }
    return result;
}

// ----------------------------------------------------------------------------
inline std::string SheetEncoding::EncodingSheetColumnId(int column_id)
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

#endif
