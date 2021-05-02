/**
 * Name     : LAB003_Riviere
 * File     : Container.cpp
 * Authors  : Gaétan Zwick, Marco Maziero
 * Date     : 14.04.2021
 */

#include "Container.h"
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

bool Container::validateState() const {
    if (!people.empty()) {
        bool out = true;
        for (auto p : people) {
            out = out && p->canStayWith(*this);
        }
        return out;
    }
    return true;
}

std::ostream& Container::toStream(std::ostream& os) const {
    for (Person* p : people)
        os << p->getName() << " ";
    return os;
}

void Container::clear() noexcept {
    people.clear();
}
