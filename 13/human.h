// human.h
#include <string>
#include <iostream>
#include <sstream>
#pragma once /* Защита от двойного подключения заголовочного файла */
class human {
public:
// Конструктор класса human
    human(std::string last_name, std::string name, std::string
    second_name)
    {
        this->last_name = last_name;
        this->name = name;
        this->second_name = second_name;
    }
// Получение ФИО человека
    std::string get_full_name()
    {
        std::ostringstream full_name;
        full_name << this->last_name << " "
                  << this->name << " "
                  << this->second_name;
        return full_name.str();
    }

    virtual void print_info(){
        std::cout << "Полное имя: " << get_full_name();
}
private:
    std::string name; // имя
    std::string last_name; // фамилия
    std::string second_name;
};
