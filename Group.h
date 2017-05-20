#ifndef GROUP_H
#define GROUP_H


#include "SqlTest.h"

#include <QObject>


class SqlTest::Group : public QObject {

    public:
        Group(long id, QString name, QObject* parent = 0);
        Group(const Group& group);

        Group& operator =(const Group& group);

        long getId() const;
        QString getName() const;

        void setId(long id);
        void setName(QString name);

    private:
        long id;
        QString name;
};


#endif // GROUP_H
