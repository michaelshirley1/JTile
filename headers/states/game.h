#pragma once
#include "baseGameState.h"
#include "character.h"

class Game : public baseGameState {
   public:
       Game();
       void run() override;
       void inputLoop() override;
       void renderLoop() override;
       void baseProcesses() override;
    private:
        std::vector<character*> characters;
        std::vector<baseObject*> objects;
};