#pragma once
#include <string>
#include <memory>
#include <unordered_map>
#include "ast_processor/crl.hpp"
namespace rule_engine {

// DataContext holds the data to be manipulated by crule, usually structs.
class KnowledgeBase {
public:
    KnowledgeBase() {
        // TODO:
    }
    void set_crl(std::shared_ptr<Crl> crl) {
        crl_ = crl;
    }
    std::shared_ptr<Crl> get_crl() {
        return crl_;
    }
private:
    std::shared_ptr<Crl> crl_;
};

}

