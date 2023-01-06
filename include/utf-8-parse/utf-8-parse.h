#ifndef UTF_8_H
#define UTF_8_h


/// @brief Calculate next symbol postiton for utf-8 encoded string
/// @param data Pointer to the utf-8 encoded string
/// @param current_position Index in the array that points at the beginnig of the current symbol. Negative number means begin scan from the very start
/// @param max_size_bytes Size of the array
/// @return Position of the next utf-8 symbol entry. -1 on fail or end of buffer
int next_pos_utf8(const char* data, int current_position, int max_size_bytes);


/// @brief Decode UTF-8 symbol that begins under current_position index   
/// @param data Pointer to the utf-8 encoded string
/// @param current_position Index of the beginning of the utf-8 encoded symbol
/// @param max_size_bytes Size of the array
/// @return Decoded UTF-8 symbol. Returns zero on error
int get_utf8_symbol(const char* data, int current_position, int max_size_bytes);


/// @brief Decode UTF-8 symbol length in bytes that begins under current_position index   
/// @param data Pointer to the utf-8 encoded string
/// @param current_position Index of the beginning of the utf-8 encoded symbol
/// @param max_size_bytes Size of the array
/// @return Decoded UTF-8 symbol length. Returns zero on error
int get_utf8_field_length(const char* data, int current_position, int max_size_bytes);


#endif
