//
// Created by Alexandra on 6/21/2021.
//

#include "ScreenWriterWindow.h"

ScreenWriterWindow::ScreenWriterWindow(IdeasRepo &repo, ScreenWriter& s): repo{repo}, s{s} {
    this->repo.addObserver(this);
    this->initGUI();
    this->connectSignals();
    this->show();

}

ScreenWriterWindow::~ScreenWriterWindow() {

}

void ScreenWriterWindow::initGUI() {
    QFont buttonsFont("Consolas", 13, true);
    this->tableModel = new TableModel(this->repo);
    this->ideasTableView = new QTableView();

    this->ideasTableView->setModel(this->tableModel);
    this->ideasTableView->resizeColumnsToContents();

    this->addIdeaButton = new QPushButton("Add idea!");
    this->addIdeaButton->setFont(buttonsFont);

    this->developButton = new QPushButton("Develop!");
    this->developButton->setFont(buttonsFont);

    this->acceptIdeaButton = new QPushButton("Accept idea!");
    this->acceptIdeaButton->setFont(buttonsFont);

    this->savePlotButton = new QPushButton("Save plot!");
    this->savePlotButton->setFont(buttonsFont);

    this->actLineEdit = new QLineEdit();
    this->actLineEdit->setFont(buttonsFont);

    this->descriptionLineEdit = new QLineEdit();
    this->descriptionLineEdit->setFont(buttonsFont);

    QLabel* description = new QLabel("Description");
    description->setFont(buttonsFont);

    QLabel* act = new QLabel("Act");
    act->setFont(buttonsFont);

    this->mainLayout = new QVBoxLayout();
    this->buttonsLayout = new QGridLayout();

    this->mainLayout->addWidget(this->ideasTableView);

    this->buttonsLayout->addWidget(description, 0, 0);
    this->buttonsLayout->addWidget(this->descriptionLineEdit, 0, 1);
    this->buttonsLayout->addWidget(act, 1, 0);
    this->buttonsLayout->addWidget(this->actLineEdit, 1, 1);

    this->mainLayout->addLayout(this->buttonsLayout);
    this->mainLayout->addWidget(this->addIdeaButton);
    this->mainLayout->addWidget(this->acceptIdeaButton);
    this->mainLayout->addWidget(this->developButton);
    this->mainLayout->addWidget(this->savePlotButton);

    if(this->s.getExpertise() != "Senior")
        this->acceptIdeaButton->setEnabled(false);

    vector<Idea> i = this->repo.getAcceptedIdeas(this->s);
    if(i.empty())
        this->developButton->setEnabled(false);

    this->setLayout(this->mainLayout);
    this->setWindowTitle(QString::fromStdString(this->s.getName() + " - " +this->s.getExpertise()));
    this->resize(1200,700);

}

void ScreenWriterWindow::connectSignals() {
    QObject::connect(this->addIdeaButton, &QPushButton::clicked, this, &ScreenWriterWindow::addIdea);
    QObject::connect(this->ideasTableView, &QTableView::clicked, this, &ScreenWriterWindow::check);
    QObject::connect(this->acceptIdeaButton, &QPushButton::clicked, this, &ScreenWriterWindow::checkIdea);
    QObject::connect(this->developButton, &QPushButton::clicked, this, &ScreenWriterWindow::openApplication);
    QObject::connect(this->savePlotButton, &QPushButton::clicked, this, &ScreenWriterWindow::savePlot);
}

void ScreenWriterWindow::update() {
    this->notifyModel();
}

void ScreenWriterWindow::addIdea() {
    string description = this->descriptionLineEdit->text().toStdString();
    string act = this->actLineEdit->text().toStdString();

    if(description.empty()){
        QMessageBox::critical(this, "Error", "Invalid description!");
        this->actLineEdit->clear();
        this->descriptionLineEdit->clear();
        return;
    }

    if(act != "1" && act != "2" && act != "3"){
        QMessageBox::critical(this, "Error", "Invalid act!");
        this->actLineEdit->clear();
        this->descriptionLineEdit->clear();
        return;
    }

    string creator = this->s.getName();
    string status = "proposed";
    Idea i(description, status, creator, act);
    try{
        this->repo.addIdea(i);
        this->actLineEdit->clear();
        this->descriptionLineEdit->clear();
        QMessageBox::information(this, "Idea added!", "Idea added!");
    }
    catch(...){
        QMessageBox::critical(this, "Error", "There already exists an idea with the given description!");
        this->actLineEdit->clear();
        this->descriptionLineEdit->clear();
        return;
    }

}

void ScreenWriterWindow::notifyModel() {
    this->tableModel->updateInternalData();
}

void ScreenWriterWindow::check() {
    int index = this->getSelectedIndex();
    if(this->s.getExpertise() != "Senior") {
        this->acceptIdeaButton->setEnabled(false);
        return;
    }
    else{
        string status = this->repo.getIdeas()[index].getStatus();
        if(status == "accepted") {
            this->acceptIdeaButton->setEnabled(false);
            return;
        }
        else{
            this->acceptIdeaButton->setEnabled(true);
            return;
        }
    }
}

int ScreenWriterWindow::getSelectedIndex() {
    QModelIndexList selectedIndexes = this->ideasTableView->selectionModel()->selectedIndexes();
    if(selectedIndexes.isEmpty())
        return -1;
    int selectedIndex=selectedIndexes.at(0).row();
    return selectedIndex;
}

void ScreenWriterWindow::checkIdea() {
    int index = this->getSelectedIndex();
    Idea i = this->repo.getIdeas()[index];
    this->repo.acceptIdea(i);
    QMessageBox::information(this, "Idea accepted!", "Idea accepted!");
}

void ScreenWriterWindow::openApplication() {
    vector<Idea> ideas = this->repo.getAcceptedIdeas(this->s);
    for(auto & i: ideas)
    {
        DevelopWindow* de = new DevelopWindow(i);
        de->show();
    }

}

void ScreenWriterWindow::savePlot() {
    string path = QFileDialog::getSaveFileName().toStdString();
    ofstream fOut(path);
    fOut<<"Act 1"<<"\n";
    for(auto & i: this->repo.getIdeas()){
        if(i.getAct() == "1" && i.getStatus() == "accepted")
        fOut<<i.getDescription()<<" "<<"("<<i.getCreator()<<")"<<'\n';
    }

    fOut<<"Act 2"<<"\n";
    for(auto & i: this->repo.getIdeas()){
        if(i.getAct() == "2" && i.getStatus() == "accepted")
            fOut<<i.getDescription()<<" "<<"("<<i.getCreator()<<")"<<'\n';
    }

    fOut<<"Act 3"<<"\n";
    for(auto & i: this->repo.getIdeas()){
        if(i.getAct() == "3" && i.getStatus() == "accepted")
            fOut<<i.getDescription()<<" "<<"("<<i.getCreator()<<")"<<'\n';
    }

}
