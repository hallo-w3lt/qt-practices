#ifndef TEST_H
#define TEST_H

#include <QObject>
#include <QTimer>
#include <QDebug>

class Test : public QObject
{
    Q_OBJECT

public:
    explicit Test(QObject *parent = nullptr);

signals:

public slots:
    void timeout();

private:
    QTimer m_timer;
    int m_count {0};

};

#endif // TEST_H
