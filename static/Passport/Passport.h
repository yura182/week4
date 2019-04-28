#ifndef PASSPORT_H
#define PASSPORT_H

#include <string>
#include <iostream>
#include "Date.h"

class Passport {
    private:
        std::string series;
        std::string number;
        std::string name;
        std::string surname;
        Date *dateOfBirth;
        
        static char firstLetter;
        static char secondLetter;
        static int nextNumber;
        
        const std::string newSeries();
        const std::string newSeries(const std::string series);
        
        const std::string newNumber();
        const std::string newNumber(int number);
    public:
        Passport(const std::string name, const std::string surname, Date& date);
        Passport(const std::string name, const std::string surname, Date& date,
                 const std::string series, int number=0);
        ~Passport();
        
        const std::string getSeries() const;
        const std::string getNumber() const;
        const std::string getName() const;
        const std::string getSurname() const;
        const std::string getDate() const;
        
        static void setSeries(const std::string series, int number=0);
        
        std::ostream& operator<<(std::ostream& out, const Passport& passport);
        
};

#endif // PASSPORT_H
