#ifndef TEST_H
#define TEST_H

#include <QObject>

class Test : public QObject
{
    Q_OBJECT

public:
    explicit Test(QObject *parent = nullptr);

    Q_PROPERTY(QString message READ getMessage WRITE setMessage NOTIFY messageChanged)

    const QString &getMessage() const;
    void setMessage(const QString &inMessage);

signals:
    void messageChanged(QString &message);

private:
    QString message {};
};

#endif // TEST_H
