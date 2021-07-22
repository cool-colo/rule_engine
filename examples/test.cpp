#include <iostream>
#include "sol/sol.hpp"
#include "rule_engine.hpp"
#include <string>
#include <iostream>
#include <cassert>
#include <chrono>


int64_t GetNow()
{
    using namespace std::chrono;

    return duration_cast<milliseconds>(steady_clock::now().time_since_epoch()).count();
}
struct Target
{
    int age;
    std::string name;
    bool alive;
};

struct Killer
{
    int bullet;
    Target target;
    void kill()
    {
       // std::cout << "killing target: " << target.name << std::endl;
        bullet -= 1;
        bullet += 1;
        target.alive = false;
    }
};

struct TheManagement
{
    std::string location;
    Killer killer;
};

struct Police
{
    Police() : homicide_case(0) {}
    int homicide_case;
};

RTTR_REGISTRATION {
    rttr::registration::class_<TheManagement>("TheManagement")
        .property("location", &TheManagement::location)(rttr::policy::prop::as_reference_wrapper)
        .property("killer", &TheManagement::killer)(rttr::policy::prop::as_reference_wrapper)
    ;

    rttr::registration::class_<Killer>("Killer")
        .property("bullet", &Killer::bullet)(rttr::policy::prop::as_reference_wrapper)
        .property("target", &Killer::target)(rttr::policy::prop::as_reference_wrapper)
        .method("kill", &Killer::kill)
    ;

    rttr::registration::class_<Target>("Target")
        .property("age", &Target::age)(rttr::policy::prop::as_reference_wrapper)
        .property("name", &Target::name)(rttr::policy::prop::as_reference_wrapper)
        .property("alive", &Target::alive)(rttr::policy::prop::as_reference_wrapper)
    ;

    rttr::registration::class_<Police>("Police")
        .property("homicide_case", &Police::homicide_case)(rttr::policy::prop::as_reference_wrapper)
    ;
}
int test2() {
    std::cout<<"InMain test2"<<std::endl;
    const char* rule = R"(
        rule kill "this is a description" {
            if 
                 Assassin.target.age > 18 && Assassin.bullet > 0
            then
                Assassin.kill();
                Assassin.kill();
                Assassin.target.age += 13;
				Police.homicide_case += 11;
				Police.homicide_case -= 3;
				Police.homicide_case /= 3;
				Assassin.target.name = "xxx";
        }
    )";

    Killer killer;
    killer.target.age = 19;
    killer.target.name = "chuck norris";
    killer.target.alive = true;
    killer.bullet = 1;

    Police police;
    police.homicide_case = 22;
    rule_engine::Engine e;
    e.load_rules(rule);
    rule_engine::DataContext dctx;
    dctx.add("Assassin", killer);
    dctx.add("Police", police);

    auto startT = GetNow();
    for (int i = 0; i < 10000000; ++i) {
      e.execute(&dctx);
    }
    auto endT = GetNow();
    std::cout << "execute2: " << (endT - startT) << std::endl;

    e.execute(&dctx);
    std::cout<<"execute"<<std::endl;

    return 0;
}


int main()
{
	test2();
	return 0;
    std::cout << "InMain" << std::endl;
    const char *rule = R"(
function Foo()
    if Assassin.target.age > 18 and Assassin.bullet > 0 then
        Assassin:kill()
        Assassin:kill()
        Assassin.target.age = Assassin.target.age + 13
        Police.homicide_case = Police.homicide_case + 11
        Police.homicide_case = Police.homicide_case - 3
        Police.homicide_case = Police.homicide_case / 3
        Assassin.target.name = "xxx"
    end
end
    )";

    sol::state lua;
    lua.open_libraries(sol::lib::base);
    lua.new_usertype<TheManagement>("TheManagement",
                                    "location", &TheManagement::location,
                                    "killer", &TheManagement::killer);

    lua.new_usertype<Killer>("Killer",
                             "bullet", &Killer::bullet,
                             "target", &Killer::target,
                             "kill", &Killer::kill);

    lua.new_usertype<Target>("Target",
                             "age", &Target::age,
                             "name", &Target::name,
                             "alive", &Target::alive);

    lua.new_usertype<Police>("Police",
                             "homicide_case", &Police::homicide_case);

    Killer killer;
    killer.target.age = 19;
    killer.target.name = "chuck norris";
    killer.target.alive = true;
    killer.bullet = 1;

    Police police;
    police.homicide_case = 22;

    // e.load_rules(rule);

    lua["Assassin"] = std::ref(killer);
    lua["Police"] = std::ref(police);

    lua.script(rule);

    auto foo = lua["Foo"];

    auto startT = GetNow();
    for (int i = 0; i < 10000000; ++i) {
      foo.call();
    }
    auto endT = GetNow();
    std::cout << "execute: " << (endT - startT) << std::endl;

    return 0;
}


