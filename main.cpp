#include "Resource.h"
#include "ConsoleGame.h"

int main() {
    Resource::get();
    ConsoleGame game({"England", "France"});
    game.launch();
}