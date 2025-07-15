#ifndef HOMEWINDOW_H
#define HOMEWINDOW_H

#include <QMainWindow>
#include "analysiswindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class homeWindow; }
QT_END_NAMESPACE

class homeWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit homeWindow(const QString &userEmail, int userId, QWidget *parent = nullptr);
    ~homeWindow();

private slots:
    void openAnalytics();  // Only Analytics wired up

private:
    Ui::homeWindow *ui;
    QString currentUserEmail;
    int currentUserId;
    analysisWindow *analysis_window;
};

#endif // HOMEWINDOW_H
