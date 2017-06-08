// previously rosprocess.h

#ifndef DATA_NODE_H
#define DATA_NODE_H

#include <QVariant>
#include <QThread>
#include <QTextStream>
#include <ros/ros.h>
#include <ros/master.h>
#include <ros/node_handle.h>

#include "std_msgs/String.h"
#include "std_msgs/Bool.h"
#include "std_msgs/Int16.h"

// TODO : Fix cmakelists so this works how it's supposed to
#include "../../../devel/include/dash_gui/can_msg.h"
#include "../../../devel/include/dash_gui/fault_msg.h"
#include "../../../devel/include/dash_gui/gpio_msg.h"


class DataNode : public QThread
{
    Q_OBJECT
public:
    DataNode();

private:
    double rpm;
    int max_rinehart_temp = 0;
    
    void run();
    void chatterCallback_can_msg(const dash_gui::can_msg::ConstPtr& msg);
    void chatterCallback_fault_msg(const dash_gui::fault_msg::ConstPtr& msg);
    void gpio_callback(const dash_gui::gpio_msg::ConstPtr& msg);

	void parseData(const dash_gui::can_msg::ConstPtr& msg); // TODO
    void parseError();

Q_SIGNALS:
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
    void updateDelta(double delta);
    void updateControllerTemp(double temp);
    void updateRmsCurrent(double rms);
    void updateFieldWeakening(double angle);
    void updateIGNOK(int state);
    void updateIMD(int state);
    void updatePRESSURE(int state);
    void updateBMSDE(int state);
    void updateFAULT(int value);
    void updateRMSVSM(int value);
    void updateInverter(int value);

private Q_SLOTS:
 	void readData();
    void readError();
};

#endif //DATA_NODE_H
