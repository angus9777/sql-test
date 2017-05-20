#ifndef USER_H
#define USER_H

#include "SqlTest.h"

#include <QObject>


class SqlTest::User : public QObject {

    public:
        User(long id, QString email, int age, long groupId, QObject* parent = 0);
        User(const User& user);

        User& operator =(const User& user);

        long getId() const;
        QString getEmail() const;
        int getAge() const;
        long getGroupId() const;

        void setId(long id);
        void setEmail(QString email);
        void setAge(int age);
        void setGroupId(long groupId);

    private:
        long id;
        QString email;
        int age;
        long groupId;
};


#endif // USER_H
