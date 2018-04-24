cmake_minimum_required(VERSION 3.8)
project(tp2)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp DataTree.cpp DataTree.h XMLHandler.cpp XMLHandler.h UnitClass.cpp UnitClass.h Unit.cpp Unit.h Squad.cpp Squad.h FactorClass.cpp FactorClass.h Factor.cpp Factor.h WarEntity.cpp WarEntity.h EconomicEntity.cpp EconomicEntity.h Time.cpp Time.h Token.cpp Token.h Player.cpp Player.h Move.cpp Move.h Execute.cpp Execute.h ConsolePlayer.cpp ConsolePlayer.h Game.cpp Game.h Resource.cpp Resource.h ConsoleGame.cpp ConsoleGame.h Moves.cpp propertyPrinter.cpp propertyPrinter.h)
add_executable(tp2 ${SOURCE_FILES})