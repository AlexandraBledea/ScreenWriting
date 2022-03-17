//
// Created by Alexandra on 6/21/2021.
//

#pragma once
#include "Observer.h"
#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QListWidget>
#include <QLabel>
#include "TableModel.h"
#include <QTableView>
#include <QVBoxLayout>
#include <QCheckBox>
#include "ScreenWriter.h"
#include <QMessageBox>
#include "IdeasRepo.h"
#include <QTextEdit>
#include <QFileDialog>

class DevelopWindow: public QWidget{

private:

    QTextEdit* ideaTextEdit;
    QPushButton* saveButton;
    QVBoxLayout* mainLayout;
    Idea& i;

public:

    DevelopWindow(Idea& i, QWidget*parent=Q_NULLPTR);
    ~DevelopWindow();
    void initGUI();
    void connectSignals();
    void save();


};
