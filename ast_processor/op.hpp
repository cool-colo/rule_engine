#pragma once
#include <rttr/registration>
#include "log/logger.hpp"
#include "utils.hpp"

namespace rule_engine {

struct Op {

static rttr::variant process_multiplication(const rttr::variant& left, rttr::variant& right) {
    auto left_type = Utils::get_unwrapped_type(left);
    auto right_type = Utils::get_unwrapped_type(right);
     
    if(!left_type.is_arithmetic() || !right_type.is_arithmetic()) [[ unlikely ]] {
	    Log::Log::runtime_error("invalid oprand for *, must be arithmetic");
    } else if(left_type != right_type) [[ unlikely ]] {
        Log::Log::runtime_error("mismatched type for *");
    }
    if (left_type == rttr::type::get<int8_t>())
        return left.to_int8() * right.to_int8();
    else if (left_type == rttr::type::get<int16_t>())
        return left.to_int16() * right.to_int16();
    else if (left_type == rttr::type::get<int32_t>())
        return left.to_int32() * right.to_int32();
    else if (left_type == rttr::type::get<int64_t>())
        return left.to_int64() * right.to_int64();
    else if (left_type == rttr::type::get<uint8_t>())
        return left.to_uint8() * right.to_uint8();
    else if (left_type == rttr::type::get<uint16_t>())
        return left.to_uint16() * right.to_uint16();
    else if (left_type == rttr::type::get<uint32_t>())
        return left.to_uint32() * right.to_uint32();
    else if (left_type == rttr::type::get<uint64_t>())
        return left.to_uint64() * right.to_uint64();
    else if (left_type == rttr::type::get<float>() || left_type == rttr::type::get<double>())
        return left.to_double() * right.to_double();
    return rttr::variant();
}

static rttr::variant process_division(const rttr::variant& left, rttr::variant& right) {
    auto left_type = Utils::get_unwrapped_type(left);
    auto right_type = Utils::get_unwrapped_type(right);
     
    if(!left_type.is_arithmetic() || !right_type.is_arithmetic()) [[ unlikely ]]{
	    Log::Log::runtime_error("invalid oprand for /, must be arithmetic");
    } else if(left_type != right_type) [[ unlikely ]]{
        Log::Log::runtime_error("mismatched type for /");
    }


    if (left_type == rttr::type::get<int8_t>())
        return left.to_int8() / right.to_int8();
    else if (left_type == rttr::type::get<int16_t>())
        return left.to_int16() / right.to_int16();
    else if (left_type == rttr::type::get<int32_t>())
        return left.to_int32() / right.to_int32();
    else if (left_type == rttr::type::get<int64_t>())
        return left.to_int64() / right.to_int64();
    else if (left_type == rttr::type::get<uint8_t>())
        return left.to_uint8() / right.to_uint8();
    else if (left_type == rttr::type::get<uint16_t>())
        return left.to_uint16() / right.to_uint16();
    else if (left_type == rttr::type::get<uint32_t>())
        return left.to_uint32() / right.to_uint32();
    else if (left_type == rttr::type::get<uint64_t>())
        return left.to_uint64() / right.to_uint64();
    else if (left_type == rttr::type::get<float>() || left_type == rttr::type::get<double>())
        return left.to_double() / right.to_double();
    return rttr::variant();
}

static rttr::variant process_mod(const rttr::variant& left, rttr::variant& right) {
    auto left_type = Utils::get_unwrapped_type(left);
    auto right_type = Utils::get_unwrapped_type(right);
     
    if(!left_type.is_arithmetic() || !right_type.is_arithmetic()) [[ unlikely ]]{
	    Log::Log::runtime_error("invalid oprand for %, must be arithmetic");
    } else if(left_type != right_type) [[ unlikely ]]{
        Log::Log::runtime_error("mismatched type for %");
    }

    if (left_type == rttr::type::get<int8_t>())
        return left.to_int8() % right.to_int8();
    else if (left_type == rttr::type::get<int16_t>())
        return left.to_int16() % right.to_int16();
    else if (left_type == rttr::type::get<int32_t>())
        return left.to_int32() % right.to_int32();
    else if (left_type == rttr::type::get<int64_t>())
        return left.to_int64() % right.to_int64();
    else if (left_type == rttr::type::get<uint8_t>())
        return left.to_uint8() % right.to_uint8();
    else if (left_type == rttr::type::get<uint16_t>())
        return left.to_uint16() % right.to_uint16();
    else if (left_type == rttr::type::get<uint32_t>())
        return left.to_uint32() % right.to_uint32();
    else if (left_type == rttr::type::get<uint64_t>())
        return left.to_uint64() % right.to_uint64();
    else if (left_type == rttr::type::get<float>() || left_type == rttr::type::get<double>())
        Log::Log::runtime_error("float number cannot be applied by operator %");
    return rttr::variant();
}

static rttr::variant process_addition(const rttr::variant& left, rttr::variant& right) {

    auto left_type = Utils::get_unwrapped_type(left);
    auto right_type = Utils::get_unwrapped_type(right);
     

    if(!left_type.is_arithmetic() || !right_type.is_arithmetic()) {
	    Log::Log::runtime_error("invalid oprand for +, must be arithmetic");
    } else if(left_type != right_type) {
        Log::Log::runtime_error("mismatched type for +");
    }
    if (left_type == rttr::type::get<int8_t>())
        return left.to_int8() + right.to_int8();
    else if (left_type == rttr::type::get<int16_t>())
        return left.to_int16() + right.to_int16();
    else if (left_type == rttr::type::get<int32_t>())
        return left.to_int32() + right.to_int32();
    else if (left_type == rttr::type::get<int64_t>())
        return left.to_int64() + right.to_int64();
    else if (left_type == rttr::type::get<uint8_t>())
        return left.to_uint8() + right.to_uint8();
    else if (left_type == rttr::type::get<uint16_t>())
        return left.to_uint16() + right.to_uint16();
    else if (left_type == rttr::type::get<uint32_t>())
        return left.to_uint32() + right.to_uint32();
    else if (left_type == rttr::type::get<uint64_t>())
        return left.to_uint64() + right.to_uint64();
    else if (left_type == rttr::type::get<float>() || left_type == rttr::type::get<double>())
        return left.to_double() + right.to_double();
    return rttr::variant();
}

static rttr::variant process_subtraction(const rttr::variant& left, rttr::variant& right) {
    auto left_type = Utils::get_unwrapped_type(left);
    auto right_type = Utils::get_unwrapped_type(right);
     
    if(!left_type.is_arithmetic() || !right_type.is_arithmetic()) [[ unlikely ]]{
	    Log::Log::runtime_error("invalid oprand for -, must be arithmetic");
    } else if(left_type != right_type) [[ unlikely ]]{
        Log::Log::runtime_error("mismatched type for -");
    }
    if (left_type == rttr::type::get<int8_t>())
        return left.to_int8() - right.to_int8();
    else if (left_type == rttr::type::get<int16_t>())
        return left.to_int16() - right.to_int16();
    else if (left_type == rttr::type::get<int32_t>())
        return left.to_int32() - right.to_int32();
    else if (left_type == rttr::type::get<int64_t>())
        return left.to_int64() - right.to_int64();
    else if (left_type == rttr::type::get<uint8_t>())
        return left.to_uint8() - right.to_uint8();
    else if (left_type == rttr::type::get<uint16_t>())
        return left.to_uint16() - right.to_uint16();
    else if (left_type == rttr::type::get<uint32_t>())
        return left.to_uint32() - right.to_uint32();
    else if (left_type == rttr::type::get<uint64_t>())
        return left.to_uint64() - right.to_uint64();
    else if (left_type == rttr::type::get<float>() || left_type == rttr::type::get<double>())
        return left.to_double() - right.to_double();
    return rttr::variant();
}

// TODO: tune and & or ops
static rttr::variant process_and(const rttr::variant& left, rttr::variant& right) {
    auto left_type = Utils::get_unwrapped_type(left);
    auto right_type = Utils::get_unwrapped_type(right);

    if(left_type != rttr::type::get<bool>() || right_type != rttr::type::get<bool>()) [[ unlikely ]]{
        Log::error("oprand has to be boolean type in process_and");
    }

    if(left.to_bool() && right.to_bool()) return true;
    return false;
}

static rttr::variant process_or(const rttr::variant& left, rttr::variant& right) {
    auto left_type = Utils::get_unwrapped_type(left);
    auto right_type = Utils::get_unwrapped_type(right);
    if(left_type != rttr::type::get<bool>() || right_type != rttr::type::get<bool>()) [[ unlikely ]]{
        Log::error("oprand has to be boolean type in process_and");
    }

    if(left.to_bool() || right.to_bool()) return true;
    return false;
}

static rttr::variant process_gt(const rttr::variant& left, rttr::variant& right) {

    auto left_type = Utils::get_unwrapped_type(left);
    auto right_type = Utils::get_unwrapped_type(right);

    if(left_type != right_type) [[ unlikely ]]{
        Log::error("mismatched type in process_gt");
    }
    
    return left > right;
}

static rttr::variant process_get(const rttr::variant& left, rttr::variant& right) {
    auto left_type = Utils::get_unwrapped_type(left);
    auto right_type = Utils::get_unwrapped_type(right);
    if(left_type != right_type) [[ unlikely ]]{
        Log::error("mismatched type in process_get");
    }
    
    return left >= right;
}

static rttr::variant process_lt(const rttr::variant& left, rttr::variant& right) {
    auto left_type = Utils::get_unwrapped_type(left);
    auto right_type = Utils::get_unwrapped_type(right);
    if(left_type != right_type) [[ unlikely ]]{
        Log::error("mismatched type in process_lt");
    }
    
    return left < right;
}

static rttr::variant process_let(const rttr::variant& left, rttr::variant& right) {
    auto left_type = Utils::get_unwrapped_type(left);
    auto right_type = Utils::get_unwrapped_type(right);
    if(left_type != right_type) [[ unlikely ]]{
        Log::error("mismatched type in process_let");
    }
    
    return left <= right;
}

static rttr::variant process_bit_and(const rttr::variant& left, rttr::variant& right) {
    auto left_type = Utils::get_unwrapped_type(left);
    auto right_type = Utils::get_unwrapped_type(right);
    if(!left_type.is_arithmetic() || !right_type.is_arithmetic()) [[ unlikely ]]{
        Log::Log::runtime_error("invalid oprand for &, must be arithmetic");
    } else if(left_type != right_type)[[ unlikely ]] {
        Log::Log::runtime_error("mismatched type for &");
    }
    if (left_type == rttr::type::get<int8_t>())
        return left.to_int8() & right.to_int8();
    else if (left_type == rttr::type::get<int16_t>())
        return left.to_int16() & right.to_int16();
    else if (left_type == rttr::type::get<int32_t>())
        return left.to_int32() & right.to_int32();
    else if (left_type == rttr::type::get<int64_t>())
        return left.to_int64() & right.to_int64();
    else if (left_type == rttr::type::get<uint8_t>())
        return left.to_uint8() & right.to_uint8();
    else if (left_type == rttr::type::get<uint16_t>())
        return left.to_uint16() & right.to_uint16();
    else if (left_type == rttr::type::get<uint32_t>())
        return left.to_uint32() & right.to_uint32();
    else if (left_type == rttr::type::get<uint64_t>())
        return left.to_uint64() & right.to_uint64();
    else if (left_type == rttr::type::get<float>() || left_type == rttr::type::get<double>())[[ unlikely ]]
        Log::Log::runtime_error("float number cannot be applied by operator &");
    return rttr::variant();
}

static rttr::variant process_bit_or(const rttr::variant& left, rttr::variant& right) {
    auto left_type = Utils::get_unwrapped_type(left);
    auto right_type = Utils::get_unwrapped_type(right);
    if(!left_type.is_arithmetic() || !right_type.is_arithmetic()) [[ unlikely ]]{
        Log::Log::runtime_error("invalid oprand for |, must be arithmetic");
    } else if(left_type != right_type) [[ unlikely ]]{
        Log::Log::runtime_error("mismatched type for |");
    }
    if (left_type == rttr::type::get<int8_t>())
        return left.to_int8() | right.to_int8();
    else if (left_type == rttr::type::get<int16_t>())
        return left.to_int16() | right.to_int16();
    else if (left_type == rttr::type::get<int32_t>())
        return left.to_int32() | right.to_int32();
    else if (left_type == rttr::type::get<int64_t>())
        return left.to_int64() | right.to_int64();
    else if (left_type == rttr::type::get<uint8_t>())
        return left.to_uint8() | right.to_uint8();
    else if (left_type == rttr::type::get<uint16_t>())
        return left.to_uint16() | right.to_uint16();
    else if (left_type == rttr::type::get<uint32_t>())
        return left.to_uint32() | right.to_uint32();
    else if (left_type == rttr::type::get<uint64_t>())
        return left.to_uint64() | right.to_uint64();
    else if (left_type == rttr::type::get<float>() || left_type == rttr::type::get<double>())[[ unlikely ]]
        Log::Log::runtime_error("float number cannot be applied by operator |");
    return rttr::variant();
}

static rttr::variant process_equal(const rttr::variant& left, rttr::variant& right) {
    auto left_type = Utils::get_unwrapped_type(left);
    auto right_type = Utils::get_unwrapped_type(right);
    if(left_type != right_type) [[ unlikely ]]{
        Log::error("mismatched type in process_equal");
    }
    return left == right;
}

static rttr::variant process_not_equal(const rttr::variant& left, rttr::variant& right) {
    auto left_type = Utils::get_unwrapped_type(left);
    auto right_type = Utils::get_unwrapped_type(right);
    if(left_type != right_type) [[ unlikely ]]{
        Log::error("mismatched type in process_not_equal");
    }
    
    return left != right;
}
};

}
