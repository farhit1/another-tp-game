## TPGame2 `EN`

### Description
There are several players, each of those has it's economic and war enitiy. Goal - kill all the enemy squads.
#### War entity
Consists of squads, which consist of units. Squads can attack each other (several times it's randomly chosen one player from each squad, which attack each other). Squads can be supplemented by new soldiers.
#### Econimic entity
Consists of factors of economy growth, you can also buy them.

### Settings
#### Units and factors of economy growth
To be set up in `units.xml` and `factors.xml`.
#### Actions
Add new action to `Moves.cpp`:
```c++
struct NewAction : Move {
    // Token parser, returns true whether action can be handled there
    bool parse(const Token& token) override {...}

    // Query handling
    // Called if previous function returns true
    void execute(const Token& token) override {...}
    
    // Type of action
    Move::Signal signal() const override {
        return Move::Signal::other;
    }
};
// Add this action to list of available actions
Execute::MoveAdder emptyTokenMove(std::unique_ptr<EmptyToken>(new EmptyToken()));
```

### Architecture



## TPGame2 `RU`

### Описание
Есть несколько игроков. У каждого из них есть военная и экономическая сущности. Цель – убить все военные отряды соперников.
#### Военная сущность
Состоит из отрядов, которые состоят из юнитов. Отряды могут нападать друг на друга (несколько раз рандомно выбирается по юниту из каждого отряда, которые будут сражаться друг с другом). В отряды можно докупать солдат.
#### Экономическая сущность
Состоит из факторов экономического роста, которые также можно докупать.

### Настройка
#### Юниты и факторы экономического роста
Настраиваются в `units.xml` и `factors.xml` соответственно.
#### Действия
Добавьте новое действие в `Moves.cpp`:
```c++
struct NewAction : Move {
    // Парсер токена, сообщающий может ли это действие обработать приходящий запрос
    bool parse(const Token& token) override {...}

    // Непосредственно обработка запроса
    // Вызывается, если parse вернул true
    void execute(const Token& token) override {...}
    
    // Возвращаемый тип действия
    Move::Signal signal() const override {
        return Move::Signal::other;
    }
};
// Добавить действие в список доступных действий
Execute::MoveAdder emptyTokenMove(std::unique_ptr<EmptyToken>(new EmptyToken()));
```

