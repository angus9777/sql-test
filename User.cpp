#include "User.h"


SqlTest::User::User(long id, QString email, int age, long groupId, QObject* parent) :
        QObject(parent), id(id), email(email), age(age), groupId(groupId) {
}


SqlTest::User::User(const User& user) :
        SqlTest::User(user.getId(), user.getEmail(), user.getAge(), user.getGroupId()) {
}


SqlTest::User& SqlTest::User::operator =(const User& user) {
    id = user.id;
    email = user.email;
    age = user.age;
    groupId = user.groupId;

    return *this;
}


long SqlTest::User::getId() const {
    return id;
}


QString SqlTest::User::getEmail() const {
    return email;
}


int SqlTest::User::getAge() const {
    return age;
}


long SqlTest::User::getGroupId() const {
    return groupId;
}


void SqlTest::User::setId(long id) {
    this->id = id;
}


void SqlTest::User::setEmail(QString email) {
    this->email = email;
}


void SqlTest::User::setAge(int age) {
    this->age = age;
}


void SqlTest::User::setGroupId(long groupId) {
    this->groupId = groupId;
}
