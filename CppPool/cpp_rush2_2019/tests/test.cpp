/*
** EPITECH PROJECT, 2018
** test.c
** File description:
** gcc test.c -I../include -L../lib/my -lmy --coverage -lcriterion && clear && ./a.out
*/

#include <string>
#include <cstring>
#include <iostream>
#include <stddef.h>
#include <signal.h>
#include <alloca.h>
#include "../Box.hpp"
#include "../Toy.hpp"
#include "../Wrap.hpp"
#include "../Teddy.hpp"
#include "../Object.hpp"
#include "../GiftPaper.hpp"
#include "../LittlePony.hpp"
#include "../PapaXmasTable.hpp"
#include <criterion/criterion.h>
#include <criterion/redirect.h>
using namespace std;

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(Objects, Test_1, .init = redirect_all_std)
{
    Object *Alpha = new Teddy("happy pony");

    cr_assert(Alpha);
}

Test(Objects, Test_2, .init = redirect_all_std)
{
    string str = "happy pony";
    Object *Alpha = new Teddy("happy pony");
    string str2 = Alpha->getTitle();

    cr_assert_str_eq(str2.c_str(), str.c_str());
}

Test(Objects, Test_3, .init = redirect_all_std)
{
    Object *Alpha = new LittlePony("happy pony");

    cr_assert(Alpha);
}

Test(Objects, Test_4, .init = redirect_all_std)
{
    string str = "happy pony";
    Object *Alpha = new LittlePony("happy pony");
    string str2 = Alpha->getTitle();

    cr_assert_str_eq(str2.c_str(), str.c_str());
}

Test(Objects, Test_5, .init = redirect_all_std)
{
    Object *Alpha = new LittlePony("happy pony");

    cr_assert(!Alpha->getObject());
}

Test(Objects, Test_6, .init = redirect_all_std)
{
    Object *Alpha = new Box("box");

    cr_assert(!Alpha->getObject());
}

Test(Objects, Test_7, .init = redirect_all_std)
{
    Object *Alpha = new GiftPaper("gift");

    cr_assert(!Alpha->getObject());
}

Test(Objects, Test_8, .init = redirect_all_std)
{
    GiftPaper gift("yes");
    Object *Boxe = new Box("box");

    gift.wrapMeThat(Boxe);
}

Test(Objects, Test_9, .init = redirect_all_std)
{
    GiftPaper gift("yes");

    gift.closeMe();
}

Test(Objects, Test_10, .init = redirect_all_std)
{
    GiftPaper gift("yes");

    gift.openMe();
}

Test(Objects, Test_11, .init = redirect_all_std)
{
    GiftPaper gift("yes");

    gift.isTaken();
}

Test(Objects, Test_12, .init = redirect_all_std)
{
    LittlePony Alpha("happy pony");

    Alpha.isTaken();
}

Test(Objects, Test_13, .init = redirect_all_std)
{
    Teddy Alpha("happy pony");

    Alpha.isTaken();
}

Test(Objects, Test_14, .init = redirect_all_std)
{
    Object *end;
    Object **object = new Object*[3];

    object[0] = new Teddy("happy pony");
    object[1] = new Box("box");
    object[2] = new GiftPaper("gift");
    end = MyUnitTests(object);
    cout << end->getTitle() << end->getObject()->getTitle() << end->getObject()->getObject()->getTitle() << endl;
    delete (end->getObject()->getObject());
    delete end->getObject();
    delete end;
}

Test(Objects, Test_15, .init = redirect_all_std)
{
    MyUnitTests();
}