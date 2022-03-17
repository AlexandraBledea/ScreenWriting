//
// Created by Alexandra on 6/21/2021.
//

#include <QFont>
#include "TableModel.h"

TableModel::TableModel(IdeasRepo &repository, QObject *parent): repository{repository}, QAbstractTableModel{parent} {

}

TableModel::~TableModel() {

}

int TableModel::rowCount(const QModelIndex &parent) const {
    return this->repository.getIdeas().size();
}

int TableModel::columnCount(const QModelIndex &parent) const {
    return 4;
}

QVariant TableModel::data(const QModelIndex &index, int role) const {
    int row = index.row();
    int column = index.column();
    if( role == Qt::DisplayRole || role == Qt::EditRole)
    {
        vector<Idea> ideas = this->repository.getIdeas();
        Idea f = ideas[row];
        switch(column)
        {
            case 0:
                return QString::fromStdString(f.getDescription());

            case 1:
                return QString::fromStdString(f.getStatus());

            case 2:
                return QString::fromStdString(f.getCreator());

            case 3:
                return QString::fromStdString(f.getAct());

            default:
                break;

        }
    }

    if(role == Qt::FontRole){
        QFont font("Times", 15, 10, true);
        font.setItalic(false);
        return font;
    }

    return QVariant{};
}

QVariant TableModel::headerData(int section, Qt::Orientation orientation, int role) const {
    if(role == Qt::DisplayRole)
    {
        if(orientation == Qt::Horizontal)
        {
            switch(section){
                case 0:
                    return QString{"Description"};

                case 1:
                    return QString{"Status"};

                case 2:
                    return QString{"Creator"};

                case 3:
                    return QString{"Act"};

                default:
                    break;
            }
        }
    }
    if(role == Qt::FontRole)
    {
        QFont font("Times", 15, 10, true);
        font.setBold(true);
        font.setItalic(false);
        return font;
    }

    return QVariant{};
}

Qt::ItemFlags TableModel::flags(const QModelIndex &index) const {
    return Qt::ItemIsSelectable | Qt::ItemIsEditable | Qt::ItemIsEnabled;
}

void TableModel::updateInternalData() {
    endResetModel();
}
