#include  <iostream>
#include "Toy.hpp"
#include "ToyStory.hpp"
#include "Buzz.hpp"
#include "Woody.hpp"
int  main() {
    Buzz b("buzzi");
    Woody w("wood");
    ToyStory::tellMeAStory("story.txt", b, &Toy::speak_es , w, &Toy::speak);
}