#ifndef ROSPROCESS_H
#define ROSPROCESS_H

#include <QProcess>
#include <QVariant>

class RosProcess : public QObject
{
    Q_OBJECT
public:
    RosProcess(QString path, QStringList args);

private:
    void parseData(QByteArray data); // TODO
    void parseError();
    QProcess * m_processObj;

    double rpm;

public slots:
    void readData();
    void readError();

signals:
    void updateRPM(double rpm);
    void updateRPM(const QVariant & rpm);
    void updateSOC(double volt);
    void updateSOC(const QVariant & volt);
    void updateMotorTemp(double temp);
    void updateDcCurrent(double current);
    void updateOutputVolts(double volts);
    void updatePackVolts(double volts);
    void updatePackCurrent(double current);
    void updatePackTempHigh(double temp);
};

#endif // ROSPROCESS_H
