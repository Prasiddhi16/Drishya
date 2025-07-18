#ifndef PROFILE_H
#define PROFILE_H

#include <QDialog>  // Because .ui is based on QDialog

namespace Ui {
class profile;
}

class profile : public QDialog
{
    Q_OBJECT

public:
    explicit profile(QWidget *parent = nullptr);
    ~profile();

private slots:
    void on_Editprofile_clicked();

    void on_toolButton_triggered(QAction *arg1);

    void on_toolButton_clicked();

    void on_saveChanges_clicked();

private:
    Ui::profile *ui;
};

#endif // PROFILE_H
