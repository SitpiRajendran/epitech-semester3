#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "Sorcerer.hpp"
#include "Peon.hpp"

/* #define NO_REDIRECT */

void stdout_trick()
{
#ifndef NO_REDIRECT
    cr_redirect_stdout();
#endif
}

#ifndef NO_REDIRECT
#define ASSERT_STDOUT(x) cr_assert_stdout_eq_str(x)
#else
#define ASSERT_STDOUT(x) (std::cout << "=== Expected: ===" << std::endl << x)
#endif

void subject()
{
    Sorcerer robert("Robert", "the Magnificent");
    Victim jim("Jimmy");
    Peon joe("Joe");

    std::cout << robert << jim << joe;

    robert.polymorph(jim);
    robert.polymorph(joe);
}

Test(ex00, subject, .init=stdout_trick)
{
    subject();
    ASSERT_STDOUT(
        "Robert, the Magnificent, is born!\n"
        "Some random victim called Jimmy just popped!\n"
        "Some random victim called Joe just popped!\n"
        "Zog zog.\n"
        "I am Robert, the Magnificent, and I like ponies!\n"
        "I'm Jimmy and I like otters!\n"
        "I'm Joe and I like otters!\n"
        "Jimmy has been turned into a cute little sheep!\n"
        "Joe has been turned into a pink pony!\n"
        "Bleuark...\n"
        "Victim Joe just died for no apparent reason!\n"
        "Victim Jimmy just died for no apparent reason!\n"
        "Robert, the Magnificent, is dead. Consequences will never be the same!\n"
    );
}

Test(ex00, actual_polymorphism, .init=stdout_trick)
{
    Victim *v1 = new Victim("V1");
    Victim *v2 = new Peon("V2");

    v1->getPolymorphed();
    v2->getPolymorphed();
    ASSERT_STDOUT(
        "Some random victim called V1 just popped!\n"
        "Some random victim called V2 just popped!\n"
        "Zog zog.\n"
        "V1 has been turned into a cute little sheep!\n"
        "V2 has been turned into a pink pony!\n"
        "Bleuark...\n"
        "Victim V2 just died for no apparent reason!\n"
        "Victim V1 just died for no apparent reason!\n"
    );
}