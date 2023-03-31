#ifndef PERSON_HPP
#define PERSON_HPP

#include <QObject>

class Person : public QObject
{
    Q_OBJECT
public:
    explicit Person(QObject *parent = nullptr);

signals:

};

#endif // PERSON_HPP
