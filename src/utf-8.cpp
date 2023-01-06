#include "utf-8-parse/utf-8-parse.h"



int next_pos_utf8(const char* data, int current_position, int max_size_bytes){

    if(current_position < 0){
        return 0;
    }

    auto length = get_utf8_field_length(data, current_position, max_size_bytes);
    if(length == 0){
        return -1;
    }
    return current_position + length;
}

int get_utf8_symbol(const char* data, int current_position, int max_size_bytes){

    int result = 0;

    if(current_position < 0){
        return 0;
    }
    
    auto length = get_utf8_field_length(data, current_position, max_size_bytes);
    if(length == 0){
        return 0;
    }

    switch(length){
        case 1:
        result = data[current_position];
        break;
        case 2:
        result = (data[current_position] & 0x1f) << 6;
        result |= data[current_position + 1] & 0x3f;
        break;
        case 3:
        result = (data[current_position] & 0xf) << 12;
        result |= (data[current_position + 1] & 0x3f) << 6;
        result |= (data[current_position + 2] & 0x3f);
        break;
        case 4:
        result = (data[current_position] & 0x7) << 18;
        result |= (data[current_position + 1] & 0x3f) << 12;
        result |= (data[current_position + 2] & 0x3f) << 6;
        result |= (data[current_position + 3] & 0x3f);
        break;
    }

    return result;
}

int get_utf8_field_length(const char* data, int current_position, int max_size_bytes){
    
    if(current_position >= max_size_bytes){
        return 0;
    }

    int result = 0;

    const auto mark = static_cast<unsigned char>(data[current_position] >> 3);
    
    if((mark & 0b11111) == 0b11110){
        result = 4;
    }else if(((mark >> 1) & 0b1111) == 0b1110){
        result = 3;
    }else if(((mark >> 2) & 0b111) == 0b110){
        result = 2;
    }else if(((mark >> 4) & 0b1) == 0x0){
        result = 1;
    }else{
        return 0;
    }

    if(current_position + result > max_size_bytes){
        return 0;
    }

    return result;

}

