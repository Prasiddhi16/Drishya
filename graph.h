#ifndef GRAPH_H
#define GRAPH_H

#include <QMainWindow>

namespace Ui {
class graph;
}

class graph : public QMainWindow
{
    Q_OBJECT

public:
    // Modified constructor to accept income, expenses, and saving amounts
    // This declaration MUST match the definition in graph.cpp
    explicit graph(const QString &userEmail,int userId, QWidget *parent = nullptr);
    ~graph();

private:
    Ui::graph *ui;

};

#endif // GRAPH_H
