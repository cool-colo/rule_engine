#include <string>
#include <iostream>
#include <cassert>
#include "rule_engine.hpp"

struct Target {
    int age;
    std::string name;
    bool alive;
    std::string* pname;
};

struct Killer {
    int bullet;
    Target target;
    void kill() {
        std::cout << "killing target: " << target.name << std::endl;
        bullet -= 1;
        target.alive =false;
    }
};

struct TheManagement {
    std::string location;
    Killer killer;
};

struct Police {
    Police():homicide_case(0) {}
    int homicide_case;
};


RTTR_REGISTRATION {
    rttr::registration::class_<TheManagement>("TheManagement")
        .property("location", &TheManagement::location)
        .property("killer", &TheManagement::killer)
    ;

    rttr::registration::class_<Killer>("Killer")
        .property("bullet", &Killer::bullet)
        .property("target", &Killer::target)
        .method("kill", &Killer::kill)
    ;

    rttr::registration::class_<Target>("Target")
        .property("age", &Target::age)
        .property("name", &Target::name)
        .property("alive", &Target::alive)
        .property("pname", &Target::pname)
    ;

    rttr::registration::class_<Police>("Police")
        .property("homicide_case", &Police::homicide_case)
    ;
}


int main() {
    std::cout<<"InMain"<<std::endl;
    const char* rule = R"(
        rule kill "this is a description" {
            if 
                Assassin.target.age > 18 && Assassin.bullet > 0
            then
                Assassin.kill();
                Police.homicide_case += 11;
                Police.homicide_case -= 3;
                Police.homicide_case /= 3;
                Assassin.target.pname = "xxxx";
                Assassin.target.name = "xxxx";

                rule kill "this is a description" {
                    if 
                        Assassin.target.age > 18 && Assassin.bullet > 0
                    then
                        Assassin.kill();
                        Assassin.target.name = "yyy";
                };
        }
    )";

    Killer killer;
    killer.target.age = 19;
    killer.target.name = "chuck norris";
    killer.target.pname = new std::string("chuck norris");
    killer.target.alive = true;
    killer.bullet = 2;

    Police police;
    police.homicide_case = 22;
    rule_engine::Engine e;
    std::cout<<"before loaded"<<std::endl;
    e.load_rules(rule);
    std::cout<<"loaded"<<std::endl;
    rule_engine::DataContext dctx;
    dctx.add("Assassin", killer);
    dctx.add("Police", police);
    e.execute(&dctx);
    std::cout<<"execute"<<std::endl;
    assert(killer.bullet == 0);  
    std::cout << "bullet " << killer.bullet << " homicide case " << police.homicide_case << std::endl;
    std::cout << "pname: "<< (*(killer.target.pname)) << std::endl;
    std::cout << "name: "<< killer.target.name << std::endl;
    assert(police.homicide_case == 10);
    assert(!killer.target.alive);

    TheManagement management;
    management.location = "hotel cortez";
    management.killer.bullet = 5;
    management.killer.target.age = 14;
    management.killer.target.name = "jesus christ";
    management.killer.target.alive = true;
    rule_engine::DataContext dctx1;
    dctx1.add("TheManagement", management);
    dctx1.add("Police", police);
    const char* rule1 = R"(
        rule kill "this is a description" {
            if 
                TheManagement.killer.bullet > 4
            then
                TheManagement.killer.kill();
        }
    )";
    e.load_rules(rule1);
    e.execute(&dctx1);
    
    assert(management.killer.bullet==4);
    assert(!management.killer.target.alive);
    return 0;
}
