#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <iostream>
#include <cassert>
#include "rule_engine.hpp"

class Family;
struct Family {
    std::map<std::string, std::string> members;
    std::unordered_map<std::string, int> ages;
	std::vector<int> indexs;
    std::unordered_map<std::string, std::unordered_map<std::string, int>> scores;
};


RTTR_REGISTRATION {
    rttr::registration::class_<Family>("Family")
        .property("members", &Family::members)(rttr::policy::prop::as_reference_wrapper)
        .property("ages", &Family::ages)(rttr::policy::prop::as_reference_wrapper)
        .property("indexs", &Family::indexs)(rttr::policy::prop::as_reference_wrapper)
        .property("scores", &Family::scores)(rttr::policy::prop::as_reference_wrapper)
    ;

    rttr::registration::class_<std::unordered_map<std::string, int>>("std::unordered_map<std::string, int>")
	    .constructor<>()(rttr::policy::ctor::as_object);
    rttr::registration::class_<std::string>("<std::string")
	    .constructor<>()(rttr::policy::ctor::as_object);
    rttr::registration::class_<int>("int")
	    .constructor<>()(rttr::policy::ctor::as_object);
}
int main() {
    const char* rule = R"(
        rule family "this is a description" {
            if 
                Family.members["mother"] == "judith harper"
            then
                Family.members["step mother"] = "candy";
                Family.members["mother"] = "judith melnick";
                Family.indexs[2] = 100;
                Family.scores["fanglc"]["english"] = 100;
        }
    )";

    Family family;
    family.members["uncle"] = "charlie harper";
    family.members["dad"] = "alan harper";
    family.members["grandma"] = "evalyn harper";
    family.members["mother"] = "judith harper";

    family.ages["jake"] = 13;
	family.indexs.push_back(0);
	family.indexs.push_back(0);
	family.indexs.push_back(0);

    rule_engine::Engine e;
    e.load_rules(rule);
    rule_engine::DataContext dctx;
    dctx.add("Family", family);
    e.execute(&dctx);


   
    assert(family.members["mother"] == "judith melnick");  
    assert(family.members["step mother"] == "candy");
    assert(family.indexs[2] == 100);
    assert(family.scores.count("fanglc") > 0);
    assert(family.scores["fanglc"]["english"] == 100);

    return 0;
}
