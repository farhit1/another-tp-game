//
// Created by Fargat on 24/04/2018.
//

#include "Move.h"
#include "Token.h"
#include "Player.h"
#include "propertyPrinter.h"
#include "Game.h"


struct StartMove : Move {
    // this step is skipped for start move
    bool parse(const Token& token) override {
        return false;
    }

    void execute(const Token& token) override {
        token.owner->print("your move started");
        token.owner->money += token.owner->economy.getBonus();
    }

    Move::Signal signal() const override {
        return Move::Signal::start;
    }
};
Execute::MoveAdder startMove(std::unique_ptr<StartMove>(new struct StartMove()));


struct EndMove : Move {
    // end
    bool parse(const Token& token) override {
        if (token.size() != 1)
            return false;
        if (token[0] != "end")
            return false;
        return true;
    }

    void execute(const Token& token) override {
        token.owner->print("move ended");
    }

    Move::Signal signal() const override {
        return Move::Signal::end;
    }
};
Execute::MoveAdder endMove(std::unique_ptr<EndMove>(new struct EndMove()));


struct NewSquad : Move {
    // create squad [new squad name]
    bool parse(const Token& token) override {
        if (token.size() != 3)
            return false;
        if (token[0] != "create" && token[1] != "squad")
            return false;
        return true;
    }

    void execute(const Token& token) override {
        if (token.owner->war.findSquad(token[2]))
            throw Execute::Exception("squad with such name already exists");
        token.owner->war.addSquad(std::move(token[2]));
    }

    Move::Signal signal() const override {
        return Move::Signal::other;
    }
};
Execute::MoveAdder newSquadMove(std::unique_ptr<NewSquad>(new NewSquad()));


struct Squads : Move {
    // squads
    bool parse(const Token& token) override {
        if (token.size() != 1)
            return false;
        if (token[0] != "squads")
            return false;
        return true;
    }

    void execute(const Token& token) override {
        token.owner->print(token.owner->war.info());
    }

    Move::Signal signal() const override {
        return Move::Signal::other;
    }
};
Execute::MoveAdder squadsMove(std::unique_ptr<Squads>(new Squads()));


struct BuyUnit : Move {
    // buy unit [unit class] [unit name] to [squad name]
    bool parse(const Token& token) override {
        if (token.size() != 6)
            return false;
        if (token[0] != "buy" && token[1] != "unit" && token[4] != "to")
            return false;
        return true;
    }

    void execute(const Token& token) override {
        UnitClass* newUnitClass = nullptr;
        for (UnitClass& unitClass : Resource::availableUnits)
            if (unitClass.name == token[2])
                newUnitClass = &unitClass;
        if (!newUnitClass)
            throw Execute::Exception("no such unit class");

        token.owner->addUnit(newUnitClass, token[5], token[3]);
    }

    Move::Signal signal() const override {
        return Move::Signal::other;
    }
};
Execute::MoveAdder buyUnitMove(std::unique_ptr<BuyUnit>(new BuyUnit()));


struct Stat : Move {
    // stat
    bool parse(const Token& token) override {
        if (token.size() != 1)
            return false;
        if (token[0] != "stat")
            return false;
        return true;
    }

    void execute(const Token& token) override {
        std::string props = pprint(std::make_pair("Day", Time::getDay()),
                                   std::make_pair("Money", token.owner->money),
                                   std::make_pair("Bonus", token.owner->economy.getBonus()));
        props.pop_back();
        token.owner->print("here is your statistics:\n" + props);
    }

    Move::Signal signal() const override {
        return Move::Signal::other;
    }
};
Execute::MoveAdder statMove(std::unique_ptr<Stat>(new Stat()));


struct BuyFactor : Move {
    // buy factor [factor name]
    bool parse(const Token& token) override {
        if (token.size() != 3)
            return false;
        if (token[0] != "buy" || token[1] != "factor")
            return false;
        return true;
    }

    void execute(const Token& token) override {
        FactorClass* newFactorClass = nullptr;
        for (auto& factor : Resource::availableFactors)
            if (factor.name == token[2])
                newFactorClass = &factor;
        if (!newFactorClass)
            throw Execute::Exception("no such factor class");

        token.owner->addFactor(newFactorClass);
    }

    Move::Signal signal() const override {
        return Move::Signal::other;
    }
};
Execute::MoveAdder buyFactorMove(std::unique_ptr<BuyFactor>(new BuyFactor()));


struct FactorInfo : Move {
    // factor info [factor name]
    bool parse(const Token& token) override {
        if (token.size() != 3)
            return false;
        if (token[0] != "factor" || token[1] != "info")
            return false;
        return true;
    }

    void execute(const Token& token) override {
        FactorClass* newFactorClass = nullptr;
        for (auto& factor : Resource::availableFactors)
            if (factor.name == token[2])
                newFactorClass = &factor;
        if (!newFactorClass)
            throw Execute::Exception("no such factor class");

        auto info = newFactorClass->info();
        info.pop_back();
        token.owner->print("here is info about " + newFactorClass->name + " factor:\n" + info);
    }

    Move::Signal signal() const override {
        return Move::Signal::other;
    }
};
Execute::MoveAdder factorInfoMove(std::unique_ptr<FactorInfo>(new FactorInfo()));


struct Factors : Move {
    // factors
    bool parse(const Token& token) override {
        if (token.size() != 1)
            return false;
        if (token[0] != "factors")
            return false;
        return true;
    }

    void execute(const Token& token) override {
        std::string factorList;
        for (auto& factor : Resource::availableFactors)
            factorList += factor.name + '\n';
        if (!factorList.empty())
            factorList.pop_back();
        token.owner->print("here is the list of factors:\n" + factorList);
    }

    Move::Signal signal() const override {
        return Move::Signal::other;
    }
};
Execute::MoveAdder factorsMove(std::unique_ptr<Factors>(new Factors()));


struct UnitInfo : Move {
    // unit info [factor name]
    bool parse(const Token& token) override {
        if (token.size() != 3)
            return false;
        if (token[0] != "unit" || token[1] != "info")
            return false;
        return true;
    }

    void execute(const Token& token) override {
        UnitClass* unitClass = nullptr;
        for (auto& unit : Resource::availableUnits)
            if (unit.name == token[2])
                unitClass = &unit;
        if (!unitClass)
            throw Execute::Exception("no such unit class");

        auto info = unitClass->info();
        info.pop_back();
        token.owner->print("here is info about " + unitClass->name + " unit:\n" + info);
    }

    Move::Signal signal() const override {
        return Move::Signal::other;
    }
};
Execute::MoveAdder unitInfoMove(std::unique_ptr<UnitInfo>(new UnitInfo()));


struct Units : Move {
    // factors
    bool parse(const Token& token) override {
        if (token.size() != 1)
            return false;
        if (token[0] != "units")
            return false;
        return true;
    }

    void execute(const Token& token) override {
        std::string unitList;
        for (auto& unit : Resource::availableUnits)
            unitList += unit.name + '\n';
        if (!unitList.empty())
            unitList.pop_back();
        token.owner->print("here is the list of units:\n" + unitList);
    }

    Move::Signal signal() const override {
        return Move::Signal::other;
    }
};
Execute::MoveAdder unitsMove(std::unique_ptr<Units>(new Units()));


struct EmptyToken : Move {
    // factors
    bool parse(const Token& token) override {
        return (token.size() == 0);
    }

    void execute(const Token& token) override {}

    Move::Signal signal() const override {
        return Move::Signal::other;
    }
};
Execute::MoveAdder emptyTokenMove(std::unique_ptr<EmptyToken>(new EmptyToken()));


struct Attack : Move {
    // attack [attack to player] [attack from squad] [attack to squad]
    bool parse(const Token& token) override {
        if (token.size() != 4)
            return false;
        if (token[0] != "attack")
            return false;
        return true;
    }

    void execute(const Token& token) override {
        auto owner = token.owner;

        auto attackTo = token[1];
        auto attackFromS = token[2];
        auto attackToS = token[3];

        Player* attackToPlayer = nullptr;
        for (Player* player : owner->game->_players)
            if (player->name == attackTo)
                attackToPlayer = player;
        if (attackToPlayer == nullptr)
            throw Execute::Exception("no such player");

        Squad* attackFromSquad = nullptr;
        for (Squad& squad : owner->war._squads)
            if (squad._name == attackFromS)
                attackFromSquad = &squad;
        if (attackFromSquad == nullptr)
            throw Execute::Exception("you do not have squad " + attackFromS);

        Squad* attackToSquad = nullptr;
        for (Squad& squad : attackToPlayer->war._squads)
            if (squad._name == attackToS)
                attackToSquad = &squad;
        if (attackToSquad == nullptr)
            throw Execute::Exception("player " + attackTo + " does not have squad " + attackToS);

        attackFromSquad->attack(*attackToSquad);
    }

    Move::Signal signal() const override {
        return Move::Signal::other;
    }
};
Execute::MoveAdder attackMove(std::unique_ptr<Attack>(new Attack()));


