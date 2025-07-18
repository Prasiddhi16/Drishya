#ifndef GOALDATA_H
#define GOALDATA_H
#include <QString>
 struct GoalData
{
    QString id;
    QString name;
    double incomeRequired;
    double downpayment;
    int duration;
    GoalData() : name(""), incomeRequired(0), downpayment(0) {}

    // You might also have a constructor for setting values
    GoalData(const QString& n, int ir, int dp)
        : name(n), incomeRequired(ir), downpayment(dp) {}
};
#endif // GOALDATA_H
