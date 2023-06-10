#include "tableview.h"

#include <QFile>
#include <QTextStream>
#include <QStringList>
#include <QColor>
#include <iostream>
#include <sstream>

MainModel::MainModel(QObject *parent)
    : QAbstractTableModel(parent)
{
    QFile inputFile("/Users/danielbelikov/Desktop/ANIME/anime.csv");
    QFile synopsisFile("/Users/danielbelikov/Desktop/ANIME/anime_with_synopsis.csv");

    inputFile.open(QFile::ReadOnly | QFile::Text);
    synopsisFile.open(QFile::ReadOnly | QFile::Text);

    QTextStream inputStream(&inputFile);
    QTextStream synopsisStream(&synopsisFile);

    QString firstline = inputStream.readLine();     //TODO header
    QString first2line = synopsisStream.readLine(); //TODO header

    //setcentral widget

    for (QString& item : firstline.split(","))
    {
        _headers.append(item);
    }

    while(!inputStream.atEnd())
    {
        QString line = inputStream.readLine();
        QList<QString> tableLine;
        QList<QString> dataRow;
        bool second = true;
        size_t lineNumber = 0;
        for (QString& item : line.split(",")) {
            if (lineNumber == 1)
            {
                tableLine.append(item);
            }
            ++lineNumber;
            dataRow.append(item);
        }


        QString line2 = synopsisStream.readLine();
        std::string linestd = line2.toStdString();
        std::stringstream ss(linestd);
//        QTextStream lineStream(&line2, QIODevice::ReadOnly);


        for (size_t i = 0; i < 4; ++i)
        {
            if (i == 3)
            {
                std::string buf;
                getline(ss,buf,'"');
                getline(ss,buf,'"');
                getline(ss,buf,',');
                getline(ss,buf,'"');
//                lineStream.getline('"');
//                lineStream.readLine('"');
//                lineStream.readLine(',');
//                lineStream.readLine('"');

            }
            else
            {
                std::string buf;
                getline(ss,buf,',');

                std::cout << 1;

            }

        }
        std::string syn;
        getline(ss, syn);

        dataRow.append(QString::fromStdString(syn));
        tableLine.append(QString::fromStdString(syn));
        _exData.append(dataRow);
        _tableData.append(tableLine);
    }


    inputFile.close();
    synopsisFile.close();


}

QVariant MainModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole)
    {
        if (orientation == Qt::Vertical)
            return QVariant();

        return _tableHeaders.at(section);
    }
    return QVariant();
}

//bool ExampleModel::setHeaderData(int section, Qt::Orientation orientation, const QVariant &value, int role)
//{
//    if (value != headerData(section, orientation, role)) {

//        emit headerDataChanged(orientation, section, section);
//        return true;
//    }
//    return false;
//}


int MainModel::rowCount(const QModelIndex &parent) const
{
    //if (!parent.isValid())
    //    return 0;
    return _tableData.size();
    //return 3;

}

int MainModel::columnCount(const QModelIndex &parent) const
{
    //if (!parent.isValid())
    //    return 0;

    if (_tableData.size() == 0)
        return 0;

    return _tableData[0].size();
    //return 4;
}

QVariant MainModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    //    if (role == Qt::DisplayRole)
    //    {
    //        return QString::number(index.row()) + ", " + QString::number(index.column());
    //    }

    if (role == Qt::BackgroundRole)
    {
        if (index.row() % 2)
            return QColorConstants::LightGray;
    }

    if (index.row() <= this->rowCount() && index.column() <= this->columnCount())
    {
        if (role == Qt::DisplayRole)
            return _tableData.at(index.row()).at(index.column());
    }





    return QVariant();
}
