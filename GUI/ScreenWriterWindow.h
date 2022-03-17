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
#include "DevelopWindow.h"
#include "IdeasRepo.h"

class ScreenWriterWindow: public  Observer, public QWidget{

private:
    IdeasRepo& repo;
    ScreenWriter& s;
    TableModel* tableModel;
    QTableView* ideasTableView;
    QVBoxLayout* mainLayout;
    QGridLayout* buttonsLayout;
    QPushButton* addIdeaButton, *acceptIdeaButton;
    QPushButton* developButton;
    QLineEdit* descriptionLineEdit, *actLineEdit;
    QPushButton* savePlotButton;

public:
    ScreenWriterWindow(IdeasRepo& repo, ScreenWriter& s);
    ~ScreenWriterWindow();
    void initGUI();
    void connectSignals();
    void notifyModel();
    void update() override;
    void addIdea();
    void check();
    void checkIdea();
    int getSelectedIndex();
    void openApplication();
    void savePlot();

};

