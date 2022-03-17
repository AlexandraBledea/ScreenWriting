//
// Created by Alexandra on 6/21/2021.
//

#include "DevelopWindow.h"

DevelopWindow::DevelopWindow(Idea &i, QWidget*parent): i{i}, QWidget(parent) {
    this->initGUI();
    this->connectSignals();
}

DevelopWindow::~DevelopWindow() {

}

void DevelopWindow::initGUI() {
    QFont buttonsFont("Consolas", 13, true);

    this->saveButton = new QPushButton("Save");
    this->saveButton->setFont(buttonsFont);

    this->ideaTextEdit = new QTextEdit();
    this->ideaTextEdit->setText(QString::fromStdString(this->i.getDescription()));
    this->ideaTextEdit->setFont(buttonsFont);

    this->mainLayout = new QVBoxLayout();

    this->mainLayout->addWidget(this->ideaTextEdit);
    this->mainLayout->addWidget(this->saveButton);

    this->setLayout(this->mainLayout);
    this->resize(700,500);

}

void DevelopWindow::connectSignals() {
    QObject::connect(this->saveButton, &QPushButton::clicked, this, &DevelopWindow::save);
}

void DevelopWindow::save() {
    string path = QFileDialog::getSaveFileName().toStdString();
    ofstream fOut(path);
    fOut<<this->ideaTextEdit->toPlainText().toStdString();
}
