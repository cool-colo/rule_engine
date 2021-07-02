#pragma once
#include <stack>
#include <memory>
#include <iostream>
#include <string>


namespace rule_engine {

struct Log {

static void info(const std::string& s) {
    std::cout << s << std::endl;
}

static void warn(const std::string& s) {

}

static void error(const std::string& s) {
    std::cout << s << std::endl;
}

static void semantic_error(const std::string& s) {
    std::cout << s << std::endl;
}

static void syntax_error(const std::string& s) {
    std::cout << s << std::endl;
}

static void runtime_error(const std::string& s) {
    std::cout << s << std::endl;
}

template<typename T>
static void assert_type_semantic(std::shared_ptr<Node> ptr, const std::string& s) {
    if(dynamic_cast<T*>(ptr.get()) == nullptr) {
        error(s);
    }
}

template<typename T>
static void assert_type(std::shared_ptr<Node> ptr, const std::string& s) {
    if(dynamic_cast<T*>(ptr.get()) == nullptr) {
        error(s);
    }
}

template<typename T>
static void assert_type(std::unique_ptr<Node>& ptr, const std::string& s) {
    if(dynamic_cast<T*>(ptr.get()) == nullptr) {
        error(s);
    }
}
};

}
