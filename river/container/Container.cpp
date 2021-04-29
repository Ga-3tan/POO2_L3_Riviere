/**
 * Name     : LAB003_Riviere
 * File     : Container.cpp
 * Authors  : Gaétan Zwick, Marco Maziero
 * Date     : 14.04.2021
 */

#include "Container.h"
#include <utility>
#include <algorithm>

Container::Container(std::string name) :
        name(std::move(name)),
        people(std::list<Person*>()) {}

std::list<Person*>::const_iterator Container::begin() const {
    return people.begin();
}

std::list<Person*>::const_iterator Container::end() const {
    return people.end();
}

std::ostream& operator<< (std::ostream& os, const Container& container){
    return container.toStream(os);
}

Container& Container::add(Person* person){
    people.push_back(person);
    return *this;
}

Container& Container::remove(Person* person){
    people.remove(person);
    return *this;
}

std::size_t Container::size() const {
    return people.size();
}

bool Container::validateState() {
    if (!people.empty()) {
        for (auto p : people) {
            p->canStayWith(*this);
        }
    }
    return false;
}

std::ostream& Container::toStream(std::ostream& os) const {
    for (Person* p : people)
        os << p->getName() << " ";
    return os;
}

std::list<Person*>::const_iterator Container::findPerson(Person* person) const {
    return std::find(begin(), end(), person);
}

//std::list<Person*>::const_iterator Container::findPerson(std::string person) const {
//    return ;
//}
