#pragma once
#include <string>
#include <memory>
#include <rttr/registration>
#include <rttr/type>

namespace rule_engine {

struct Utils {

  inline static rttr::type get_unwrapped_type(const rttr::variant& var){
    auto type = var.get_type(); 
	if (type.is_wrapper()){
	  type = type.get_wrapped_type();
	}
	return type;
  }


};


}
