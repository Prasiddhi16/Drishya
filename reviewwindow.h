#ifndef REVIEWWINDOW_H
#define REVIEWWINDOW_H

#include <QMainWindow>
#include <QtCharts/QPieSeries>
#include <QtCharts/QChart>              // ✅ Add this
#include <QtCharts/QChartView>          // ✅ If you're going to use QChartView too

//QT_CHARTS_USE_NAMESPACE ;               // ✅ Important to avoid prefixing all QtCharts classes



namespace Ui {
class reviewWindow;
}

class reviewWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit reviewWindow(QWidget *parent = nullptr);
    ~reviewWindow();

private:
    Ui::reviewWindow *ui;
};

#endif // REVIEWWINDOW_H
