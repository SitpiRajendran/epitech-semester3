#include "Box.hpp"
#include "ConveyorBelt.hpp"
#include "Elf.hpp"
#include "GiftPaper.hpp"
#include "LittlePony.hpp"
#include "Object.hpp"
#include "PapaXmasConveyorBelt.hpp"
#include "PapaXmasTable.hpp"
#include "Table.hpp"
#include "Teddy.hpp"
#include "Toy.hpp"
#include "Wrap.hpp"
#include "Hand.hpp"

int main(void)
{
    Teddy teddy("teddy");
    Box box("box");
    Wrap wrap("wrap");
    Table table = *(new Table);
    ConveyorBelt conveyorbelt = *(new ConveyorBelt);
    Elf elf = *(new Elf);

    conveyorbelt.IN();
    elf.UseHand()->takeObject(conveyorbelt.takeObject());
    table.putTable(elf.UseHand()->putObject());
    conveyorbelt.IN();
    elf.UseHand()->takeObject(conveyorbelt.takeObject());
    table.putTable(elf.UseHand()->putObject());
    conveyorbelt.IN();
    elf.UseHand()->takeObject(conveyorbelt.takeObject());
    table.putTable(elf.UseHand()->putObject());
    table.putTable(&teddy);
    table.lookTable();
    table.putTable(elf.MakeToy(&table));
    elf.UseHand()->takeObject(table.takeTable(2));
    conveyorbelt.putObject(elf.UseHand()->putObject());
    conveyorbelt.OUT();
    return (0);
}