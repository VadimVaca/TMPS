// LAB_3_Chain_of_Responsibility.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
/**
 * Интерфейс Обработчика объявляет метод построения цепочки обработчиков. Он
 * также объявляет метод для выполнения запроса.
 */
class Handler {
public:
    virtual Handler* SetNext(Handler* handler) = 0;
    virtual std::string Handle(std::string request) = 0;
};
/**
 * Поведение цепочки по умолчанию может быть реализовано внутри базового класса
 * обработчика.
 */
class AbstractHandler : public Handler {
    /**
     * @var Handler
     */
private:
    Handler* next_handler_;

public:
    AbstractHandler() : next_handler_(nullptr) {
    }
    Handler* SetNext(Handler* handler) override {
        this->next_handler_ = handler;
        // Возврат обработчика отсюда позволит связать обработчики простым способом,
        // вот так:
        // $defence->setNext($transport)->setNext($busines);
        return handler;
    }
    std::string Handle(std::string request) override {
        if (this->next_handler_) {
            return this->next_handler_->Handle(request);
        }

        return {};
    }
};
/**
 * Все Конкретные Обработчики либо обрабатывают запрос, либо передают его
 * следующему обработчику в цепочке.
 */
class DefenceHandler : public AbstractHandler {
public:
    std::string Handle(std::string request) override {
        if (request == "F-35") {
            return "Defence_DP: We'll recive " + request + ".\n";
        }
        else {
            return AbstractHandler::Handle(request);
        }
    }
};
class TransportHandler : public AbstractHandler {
public:
    std::string Handle(std::string request) override {
        if (request == "B747") {
            return "Transport_DP: We'll recive " + request + ".\n";
        }
        else {
            return AbstractHandler::Handle(request);
        }
    }
};
class BusinesHandler : public AbstractHandler {
public:
    std::string Handle(std::string request) override {
        if (request == "B737") {
            return "Busines: We'll recive " + request + ".\n";
        }
        else {
            return AbstractHandler::Handle(request);
        }
    }
};
/**
 * Обычно клиентский код приспособлен для работы с единственным обработчиком. В
 * большинстве случаев клиенту даже неизвестно, что этот обработчик является
 * частью цепочки.
 */
void ClientCode(Handler& handler) {
    std::vector<std::string> product = { "F-35", "B747", "B737", "B727" };
    for (const std::string& f : product) {
        std::cout << "Client: Who wants a " << f << "?\n";
        const std::string result = handler.Handle(f);
        if (!result.empty()) {
            std::cout << "  " << result;
        }
        else {
            std::cout << "  " << f << " was left untouched.\n";
        }
    }
}
/**
 * Другая часть клиентского кода создает саму цепочку.
 */
int main() {
    DefenceHandler* defence = new DefenceHandler;
    TransportHandler* transport = new TransportHandler;
    BusinesHandler* busines = new BusinesHandler;
    defence->SetNext(transport)->SetNext(busines);

    /**
     * Клиент должен иметь возможность отправлять запрос любому обработчику, а не
     * только первому в цепочке.
     */
    std::cout << "Chain: Defence DP, Transport DP, Busines\n\n";
    ClientCode(*defence);


    delete defence;
    delete transport;
    delete busines;

    return 0;
}