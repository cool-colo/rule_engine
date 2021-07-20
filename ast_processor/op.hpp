#pragma once
#include <rttr/registration>
#include "log/logger.hpp"

namespace rule_engine {

struct Op {

static rttr::variant process_multiplication(rttr::variant& left, rttr::variant& right) {
	auto left_type = left.get_type().is_wrapper() ? left.get_type().get_wrapped_type() : left.get_type();
	auto right_type = right.get_type().is_wrapper() ? right.get_type().get_wrapped_type() : right.get_type();
     
    if(!left_type.is_arithmetic() || !right_type.is_arithmetic()) {
	    Log::Log::runtime_error("invalid oprand for *, must be arithmetic");
    } else if(left_type != right_type) {
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

static rttr::variant process_division(rttr::variant& left, rttr::variant& right) {
	auto left_type = left.get_type().is_wrapper() ? left.get_type().get_wrapped_type() : left.get_type();
	auto right_type = right.get_type().is_wrapper() ? right.get_type().get_wrapped_type() : right.get_type();
     
    if(!left_type.is_arithmetic() || !right_type.is_arithmetic()) {
	    Log::Log::runtime_error("invalid oprand for /, must be arithmetic");
    } else if(left_type != right_type) {
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

static rttr::variant process_mod(rttr::variant& left, rttr::variant& right) {
	auto left_type = left.get_type().is_wrapper() ? left.get_type().get_wrapped_type() : left.get_type();
	auto right_type = right.get_type().is_wrapper() ? right.get_type().get_wrapped_type() : right.get_type();
     
    if(!left_type.is_arithmetic() || !right_type.is_arithmetic()) {
	    Log::Log::runtime_error("invalid oprand for %, must be arithmetic");
    } else if(left_type != right_type) {
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

static rttr::variant process_addition(rttr::variant& left, rttr::variant& right) {

	auto left_type = left.get_type().is_wrapper() ? left.get_type().get_wrapped_type() : left.get_type();
	auto right_type = right.get_type().is_wrapper() ? right.get_type().get_wrapped_type() : right.get_type();
     

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

static rttr::variant process_subtraction(rttr::variant& left, rttr::variant& right) {
	auto left_type = left.get_type().is_wrapper() ? left.get_type().get_wrapped_type() : left.get_type();
	auto right_type = right.get_type().is_wrapper() ? right.get_type().get_wrapped_type() : right.get_type();
     
    if(!left_type.is_arithmetic() || !right_type.is_arithmetic()) {
	    Log::Log::runtime_error("invalid oprand for -, must be arithmetic");
    } else if(left_type != right_type) {
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
static rttr::variant process_and(rttr::variant& left, rttr::variant& right) {
	auto left_type = left.get_type().is_wrapper() ? left.get_type().get_wrapped_type() : left.get_type();
	auto right_type = right.get_type().is_wrapper() ? right.get_type().get_wrapped_type() : right.get_type();

    if(left_type != rttr::type::get<bool>() || right_type != rttr::type::get<bool>()) {
        Log::error("oprand has to be boolean type in process_and");
    }

    if(left.to_bool() && right.to_bool()) return true;
    return false;
}

static rttr::variant process_or(rttr::variant& left, rttr::variant& right) {
	auto left_type = left.get_type().is_wrapper() ? left.get_type().get_wrapped_type() : left.get_type();
	auto right_type = right.get_type().is_wrapper() ? right.get_type().get_wrapped_type() : right.get_type();
    if(left_type != rttr::type::get<bool>() || right_type != rttr::type::get<bool>()) {
        Log::error("oprand has to be boolean type in process_and");
    }

    if(left.to_bool() || right.to_bool()) return true;
    return false;
}

static rttr::variant process_gt(rttr::variant& left, rttr::variant& right) {
	std::cout<<"lvalue:"<<left.to_int64()<<std::endl;
	std::cout<<"rvalue:"<<right.to_int64()<<std::endl;

	auto left_type = left.get_type().is_wrapper() ? left.get_type().get_wrapped_type() : left.get_type();
	auto right_type = right.get_type().is_wrapper() ? right.get_type().get_wrapped_type() : right.get_type();

    if(left_type != right_type) {
        Log::error("mismatched type in process_gt");
    }
    
    return left > right;
}

static rttr::variant process_get(rttr::variant& left, rttr::variant& right) {
	auto left_type = left.get_type().is_wrapper() ? left.get_type().get_wrapped_type() : left.get_type();
	auto right_type = right.get_type().is_wrapper() ? right.get_type().get_wrapped_type() : right.get_type();
    if(left_type != right_type) {
        Log::error("mismatched type in process_get");
    }
    
    return left >= right;
}

static rttr::variant process_lt(rttr::variant& left, rttr::variant& right) {
	auto left_type = left.get_type().is_wrapper() ? left.get_type().get_wrapped_type() : left.get_type();
	auto right_type = right.get_type().is_wrapper() ? right.get_type().get_wrapped_type() : right.get_type();
    if(left_type != right_type) {
        Log::error("mismatched type in process_lt");
    }
    
    return left < right;
}

static rttr::variant process_let(rttr::variant& left, rttr::variant& right) {
	auto left_type = left.get_type().is_wrapper() ? left.get_type().get_wrapped_type() : left.get_type();
	auto right_type = right.get_type().is_wrapper() ? right.get_type().get_wrapped_type() : right.get_type();
    if(left_type != right_type) {
        Log::error("mismatched type in process_let");
    }
    
    return left <= right;
}

static rttr::variant process_bit_and(rttr::variant& left, rttr::variant& right) {
	auto left_type = left.get_type().is_wrapper() ? left.get_type().get_wrapped_type() : left.get_type();
	auto right_type = right.get_type().is_wrapper() ? right.get_type().get_wrapped_type() : right.get_type();
    if(!left_type.is_arithmetic() || !right_type.is_arithmetic()) {
        Log::Log::runtime_error("invalid oprand for &, must be arithmetic");
    } else if(left_type != right_type) {
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
    else if (left_type == rttr::type::get<float>() || left_type == rttr::type::get<double>())
        Log::Log::runtime_error("float number cannot be applied by operator &");
    return rttr::variant();
}

static rttr::variant process_bit_or(rttr::variant& left, rttr::variant& right) {
	auto left_type = left.get_type().is_wrapper() ? left.get_type().get_wrapped_type() : left.get_type();
	auto right_type = right.get_type().is_wrapper() ? right.get_type().get_wrapped_type() : right.get_type();
    if(!left_type.is_arithmetic() || !right_type.is_arithmetic()) {
        Log::Log::runtime_error("invalid oprand for |, must be arithmetic");
    } else if(left_type != right_type) {
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
    else if (left_type == rttr::type::get<float>() || left_type == rttr::type::get<double>())
        Log::Log::runtime_error("float number cannot be applied by operator |");
    return rttr::variant();
}

static rttr::variant process_equal(rttr::variant& left, rttr::variant& right) {
	auto left_type = left.get_type().is_wrapper() ? left.get_type().get_wrapped_type() : left.get_type();
	auto right_type = right.get_type().is_wrapper() ? right.get_type().get_wrapped_type() : right.get_type();
    if(left_type != right_type) {
        Log::error("mismatched type in process_equal");
    }
	//std::cout<<"equal lvalue:"<<left.get_value<std::string>()<<std::endl;
	//std::cout<<"equal rvalue:"<<right.get_value<std::string>()<<std::endl;
    return left == right;
}

static rttr::variant process_not_equal(rttr::variant& left, rttr::variant& right) {
	auto left_type = left.get_type().is_wrapper() ? left.get_type().get_wrapped_type() : left.get_type();
	auto right_type = right.get_type().is_wrapper() ? right.get_type().get_wrapped_type() : right.get_type();
    if(left_type != right_type) {
        Log::error("mismatched type in process_not_equal");
    }
    
    return left != right;
}
};

}
