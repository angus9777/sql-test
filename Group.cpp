#include "Group.h"


SqlTest::Group::Group(long id, QString name, QObject* parent) :
        QObject(parent), id(id), name(name) {
}


SqlTest::Group::Group(const Group& group) :
        SqlTest::Group::Group(group.getId(), group.getName()) {
}


SqlTest::Group& SqlTest::Group::operator =(const Group& group) {
    id = group.id;
    name = group.name;

    return *this;
}


long SqlTest::Group::getId() const {
    return id;
}


QString SqlTest::Group::getName() const {
    return name;
}


void SqlTest::Group::setId(long id) {
    this->id = id;
}


void SqlTest::Group::setName(QString name) {
    this->name = name;
}
